//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Euclid's algorithm for finding the greatest common divisor (GCD)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Extended Euclidean algorithm for finding the greatest common divisor (GCD)
// and the coefficients of Bezout's identity
int gcd_extended(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int gcd = gcd_extended(b, a % b, x, y);
    int temp = *x;
    *x = *y;
    *y = temp - (a / b) * *y;
    return gcd;
}

// Modular exponentiation using the binary exponentiation algorithm
long long modpow(long long base, long long exponent, long long modulus) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return result;
}

// Miller-Rabin primality test
int is_prime(long long n) {
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    long long s = n - 1;
    while (s % 2 == 0)
        s /= 2;
    for (int i = 0; i < 10; i++) {
        long long a = rand() % (n - 1) + 1;
        long long temp = modpow(a, s, n);
        if (temp != 1 && temp != n - 1) {
            for (long long j = 0; j < s - 1; j++) {
                temp = (temp * temp) % n;
                if (temp == n - 1)
                    break;
            }
            if (temp != n - 1)
                return 0;
        }
    }
    return 1;
}

// Main function
int main() {
    int a, b;
    printf("Enter two integers to find their gcd: ");
    scanf("%d %d", &a, &b);
    printf("GCD of %d and %d is %d.\n\n", a, b, gcd(a, b));

    int x, y;
    printf("Enter two integers to find their gcd using extended Euclidean algorithm: ");
    scanf("%d %d", &a, &b);
    gcd_extended(a, b, &x, &y);
    printf("GCD of %d and %d is %d.\n", a, b, gcd_extended(a, b, &x, &y));
    printf("Coefficients of Bezout's identity: x = %d, y = %d.\n\n", x, y);

    long long base, exponent, modulus;
    printf("Enter a base, exponent, and modulus for modular exponentiation: ");
    scanf("%lld %lld %lld", &base, &exponent, &modulus);
    printf("Result of %lld^%lld mod %lld is %lld.\n\n", base, exponent, modulus, modpow(base, exponent, modulus));

    long long n;
    printf("Enter a number to test for primality: ");
    scanf("%lld", &n);
    printf("%lld is %s prime.\n", n, is_prime(n) ? "" : "not");

    return 0;
}