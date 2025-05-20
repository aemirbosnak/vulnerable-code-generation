//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 1000

int isPrime(int n) {
    if (n <= 1) return 0;
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int findE(int phi) {
    int e = 2;
    while (e < phi) {
        if (gcd(e, phi) == 1) return e;
        e++;
    }
    return e;
}

int powerModulo(int b, int p, int m) {
    int result = 1;
    while (p > 0) {
        if (p % 2 == 1) {
            result = (result * b) % m;
        }
        b = (b * b) % m;
        p = p / 2;
    }
    return result;
}

int findD(int e, int phi) {
    int k = 1;
    while (1) {
        if ((k * phi + 1) % e == 0) return (k * phi + 1) / e;
        k++;
    }
}

int main() {
    int p, q, n, phi, e, d;
    srand(time(NULL));
    do {
        p = 1 + rand() % (MAX - 1);
    } while (!isPrime(p));
    do {
        q = 1 + rand() % (MAX - 1);
    } while (!isPrime(q));

    n = p * q;
    phi = (p - 1) * (q - 1);
    e = findE(phi);
    d = findD(e, phi);

    printf("p: %d\n", p);
    printf("q: %d\n", q);
    printf("n: %d\n", n);
    printf("phi: %d\n", phi);
    printf("e: %d\n", e);
    printf("d: %d\n", d);

    int m = 123456;
    printf("Message: %d\n", m);

    int c = powerModulo(m, e, n);
    printf("Encrypted message: %d\n", c);

    int decryptedMessage = powerModulo(c, d, n);
    printf("Decrypted message: %d\n", decryptedMessage);

    return 0;
}