//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
#define PRIME 101

typedef struct {
    int n;
    int e;
    int d;
} publicKey;

publicKey generatePublicKey(int p, int q) {
    publicKey key;
    int phi = (p-1)*(q-1);
    int e = 2;
    while (phi % e!= 0) {
        e++;
    }
    key.n = p*q;
    key.e = e;
    key.d = (p-1)*(q-1)/e;
    return key;
}

int encrypt(int m, publicKey key) {
    int c = (m % key.n) + 1;
    c = (c * key.e) % key.n;
    return c;
}

int decrypt(int c, publicKey key) {
    int m = (c * key.d) % key.n;
    m = (m - 1) % key.n;
    return m;
}

int main() {
    int p, q;
    printf("Enter two prime numbers: ");
    scanf("%d %d", &p, &q);
    publicKey key = generatePublicKey(p, q);
    printf("Public Key: (n, e) = (%d, %d)\n", key.n, key.e);
    printf("Private Key: (n, d) = (%d, %d)\n", key.n, key.d);
    int m, c;
    printf("Enter message to encrypt: ");
    scanf("%d", &m);
    c = encrypt(m, key);
    printf("Encrypted message: %d\n", c);
    m = decrypt(c, key);
    printf("Decrypted message: %d\n", m);
    return 0;
}