//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int encrypt(int m, int e, int n) {
    if (e == 0) {
        return 1;
    }
    int temp = encrypt(m, e/2, n);
    if (e % 2 == 0) {
        return (temp * temp) % n;
    }
    return (m * temp * temp) % n;
}

int decrypt(int c, int d, int n) {
    if (d == 0) {
        return 1;
    }
    int temp = decrypt(c, d/2, n);
    if (d % 2 == 0) {
        return (temp * temp) % n;
    }
    return (c * temp * temp) % n;
}

int main() {
    int p, q, n, phi, e, d, m, c;
    printf("Enter two prime numbers: ");
    scanf("%d %d", &p, &q);
    n = p * q;
    phi = (p - 1) * (q - 1);

    // find e
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1) {
            break;
        }
    }

    // find d
    d = 0;
    int k = 1;
    while (1) {
        d = (k * phi + 1) / e;
        if ((k * phi + 1) % e == 0) {
            break;
        }
        k++;
    }

    printf("Public Key: (%d, %d)\n", e, n);
    printf("Private Key: (%d, %d)\n", d, n);

    // encryption
    printf("Enter a message to encrypt: ");
    scanf("%d", &m);
    c = encrypt(m, e, n);
    printf("Encrypted Message: %d\n", c);

    // decryption
    printf("Enter a message to decrypt: ");
    scanf("%d", &c);
    m = decrypt(c, d, n);
    printf("Decrypted Message: %d\n", m);

    return 0;
}