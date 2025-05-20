//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STRING_LENGTH 1000

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int generatePrime(int max) {
    int n, i, j, flag;
    do {
        n = (rand() % max) + 1;
        flag = 0;
        for(i = 2; i <= sqrt(n); i++) {
            if(n % i == 0) {
                flag = 1;
                break;
            }
        }
        for(j = 2; j <= sqrt(max); j++) {
            if(max % j == 0 && n % j == 0) {
                flag = 1;
                break;
            }
        }
    } while(flag == 1);
    return n;
}

int generatePublicKey(int p, int q) {
    int n, e, phi;
    n = p * q;
    phi = (p - 1) * (q - 1);
    do {
        e = rand() % (phi - 2) + 2;
    } while(gcd(e, phi) != 1);
    return e;
}

int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) {
        return 0;
    }

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) {
        x1 += m0;
    }

    return x1;
}

int main() {
    int p, q, n, e, phi, d;
    char message[MAX_STRING_LENGTH];
    printf("Enter the message to encrypt: ");
    fgets(message, MAX_STRING_LENGTH, stdin);
    printf("Enter maximum value for prime number generator: ");
    scanf("%d", &n);
    p = generatePrime(n);
    q = generatePrime(n);
    while(p == q) {
        q = generatePrime(n);
    }
    e = generatePublicKey(p, q);
    phi = (p - 1) * (q - 1);
    d = modInverse(e, phi);
    printf("Public Key: (%d, %d)\n", e, p*q);
    printf("Private Key: (%d, %d)\n", d, p*q);
    return 0;
}