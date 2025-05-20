//Falcon2-11B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int gcd(int a, int b) {
    return b == 0? a : gcd(b, a % b);
}

int modInverse(int a) {
    return gcd(a, MOD) == 1? 1 : 0;
}

void generate_public_key(int *public_key, int *private_key) {
    int n = 0, p = 0, q = 0, g = 0, e = 0, d = 0;

    do {
        n = rand() % MOD + 1;
        p = rand() % MOD + 1;
        q = rand() % MOD + 1;
        g = (p - 1) * (q - 1);
    } while (g == 0 || g == 1);

    do {
        e = rand() % MOD + 1;
    } while (gcd(e, MOD)!= 1 || e == 0);

    d = modInverse(e);

    *public_key = n * e;
    *private_key = n * d;
}

int encrypt(int plaintext, int public_key, int mod) {
    return (plaintext * public_key) % mod;
}

int decrypt(int ciphertext, int private_key, int mod) {
    return (ciphertext * private_key) % mod;
}

int main() {
    int public_key, private_key, mod, plaintext, ciphertext;
    int i;

    printf("Generating public and private keys...\n");
    generate_public_key(&public_key, &private_key);
    printf("Public key: %d\n", public_key);
    printf("Private key: %d\n", private_key);

    printf("Encrypting message (plaintext) %d with public key %d\n", plaintext, public_key);
    ciphertext = encrypt(plaintext, public_key, MOD);
    printf("Ciphertext: %d\n", ciphertext);

    printf("Decrypting ciphertext %d with private key %d\n", ciphertext, private_key);
    plaintext = decrypt(ciphertext, private_key, MOD);
    printf("Plaintext: %d\n", plaintext);

    return 0;
}