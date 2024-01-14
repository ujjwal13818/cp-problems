#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define frn(i, x , n) for(int i = x ; i < n ; i++)
#define out(x) cout << x << endl
#define in(x) cin >> x
#define arrin(a , n) for(int i = 0 ; i < n ; i++)in(a[i])
#define arrout(a , n)  for(int i = 0 ; i < n ; i++)cout << a[i] << " " ; cout<<endl
#define eb emplace_back
#define e emplace
#define pb push_back
#define srt(a,n) sort(a,a+n)
#define vsrt(a) sort(a.begin(),a.end())
#define bs(a,n,x) binary_search(a, a+n, x)
#define vub(c,x) (upper_bound(c.begin(),c.end(),x)-c.begin())-1
#define minpq priority_queue<int, vector<int>, greater<int> >
#define maxpq priority_queue<int>
#define ff first
#define ss second
#define vHas(v,x) (find(v.begin(), v.end(), x) != v.end())
#define setHas(s,x) (s.find(x) != s.end())


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int,int> mii;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll>> vvll;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//functions

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
vector<int> primeFact(int n) { vector<int> v; for (int i = 2; i <= n; i++) { if (n % i == 0) v.push_back(i); while (n % i == 0) n /= i; } return v; }
int lb(vi &v, int x) { int low = 0, high = v.size(), ans = -1; while (low < high) { int mid = low + (high - low) / 2; if (v[mid] >= x) high = mid - 1; else { ans = mid; low = mid + 1; } } if (low <= v.size() - 1 && v[low] < x) ans++; return ans; }
//gives the index at which value is just shorter.
int ub(vi &v, int x) { int low = 0, high = v.size(), ans = high; while (low < high) { int mid = low + (high - low) / 2; if (v[mid] <= x) low = mid + 1; else { ans = mid; high = mid - 1; } } if (high >= 0 && v[high] > x) ans--; return ans; }
//gives the index at which  value is just greater.
//gives sum of vector from index a to b both inclusive;
ll findSum(const vector<ll> &v, ll a , ll b) {if(a < 0 || b > v.size())return -1; ll ts = 0 ; frn(i,a,b+1)ts += v[i]; return ts; };
//KMP algo
vector<ll> KMP(string &s, string &t) { int n = s.size(), m = t.size(); vector<ll> lps(m, 0); int l = 0; for(int r = 1; r < m; r++) { if(t[l] == t[r]) { lps[r] = l + 1; l++; } else { if(l != 0) { l = lps[l - 1]; } else { lps[r] = 0; } } } vector<ll> ans; int j = 0; for(int i = 0; i < n; i++) { if(t[j] == s[i]) j++; else { if(j != 0) { j = lps[j - 1]; i--; } } if(j == m) { ans.pb(i - m + 1); j = 0; } } return ans; }


int main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
  
 return 0;
}
