#include <iostream>
#include <chrono> 
using namespace std::chrono;
using std::cout;
using std::endl;

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
    // write your code here
    if (n == 0) return 0;
    int fib_prev = 0;
    int fib = 1;
    for (int i = 2; i <= n; ++i) {
        int fib_new = (fib + fib_prev) % 10;
        fib_prev = fib;
        fib = fib_new;
    }
    return fib;
}

int main() {
    int n;
    std::cin >> n;
    auto start = high_resolution_clock::now();
    // int c = get_fibonacci_last_digit_naive(n);
    int c = get_fibonacci_last_digit_fast(n);
    auto stop = high_resolution_clock::now();
    std::cout << c << '\n';
    auto duration = duration_cast<milliseconds>(stop - start); 
    std::cout << "Elapsed Time [ms]: " << duration.count() << std::endl;
    }
