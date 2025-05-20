//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 1000000

int main() {
    int num, n, i, j, k, m, flag = 0, count = 0;
    int a[MAX], b[MAX], c[MAX];
    int prime[MAX], p[MAX], q[MAX], n1, n2;
    int e, d, temp, sum = 0;
    int phi_n, phi_p, phi_q;
    int gcd(int a, int b);
    int is_prime(int n);
    int power(int base, int exponent);

    printf("Enter two prime numbers: ");
    scanf("%d %d", &n1, &n2);

    for (i = 2; i <= n1; i++) {
        if (n1 % i == 0) {
            flag = 1;
            break;
        }
    }

    for (j = 2; j <= n2; j++) {
        if (n2 % j == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("Invalid input. Please enter two prime numbers.\n");
        return 0;
    }

    prime[0] = n1;
    prime[1] = n2;

    phi_n = (prime[0] - 1) * (prime[1] - 1);

    for (i = 0; i < 2; i++) {
        e = rand() % phi_n + 1;
        while (gcd(e, phi_n)!= 1) {
            e = rand() % phi_n + 1;
        }
        d = power(e, -1) % phi_n;
    }

    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);

    return 0;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int is_prime(int n) {
    int i, flag = 1;

    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            flag = 0;
            break;
        }
    }

    return flag;
}

int power(int base, int exponent) {
    int result = 1;

    while (exponent > 0) {
        result *= base;
        exponent--;
    }

    return result;
}