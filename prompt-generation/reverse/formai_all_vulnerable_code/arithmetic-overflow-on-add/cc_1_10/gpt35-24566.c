//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int isPrime(long int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int generatePrime() {
    long int num = 0;
    while (1) {
        num = rand() % 1000;
        if (isPrime(num)) {
            return num;
        }
    }
}

int generatePublicKey(int phi) {
    int e;
    do {
        e = rand() % (phi - 2) + 2;
    } while (gcd(e, phi) != 1);
    return e;
}

int calculatePrivateKey(int e, int phi) {
    int k = 1;
    int d;
    while (1) {
        d = (k * phi + 1) / e;
        if ((k * phi + 1) % e == 0) {
            return d;
        }
        k++;
    }
}

int main() {
    srand(time(NULL));
    int p = generatePrime();
    int q = generatePrime();
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = generatePublicKey(phi);
    int d = calculatePrivateKey(e, phi);

    printf("Generated primes: p = %d, q = %d\n", p, q);
    printf("n = pq = %d\n", n);
    printf("phi(n) = (p-1)(q-1) = %d\n", phi);
    printf("Public key: e = %d\n", e);
    printf("Private key: d = %d\n", d);

    return 0;
}