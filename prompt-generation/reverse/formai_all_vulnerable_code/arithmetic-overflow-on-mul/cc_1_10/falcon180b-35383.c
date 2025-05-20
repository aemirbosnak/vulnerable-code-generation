//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1000

typedef struct {
    int n;
    int e;
    int d;
} PublicKey;

PublicKey generate_key() {
    PublicKey key;
    int p, q, phi, temp;
    srand(time(NULL));
    p = rand() % MAX + 2;
    q = rand() % MAX + 2;
    while (gcd(p, q)!= 1) {
        p = rand() % MAX + 2;
        q = rand() % MAX + 2;
    }
    phi = (p - 1) * (q - 1);
    temp = rand() % phi + 1;
    key.e = temp;
    key.d = temp + 1;
    key.n = p * q;
    return key;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int encrypt(int message, PublicKey key) {
    return power(message, key.e) % key.n;
}

int decrypt(int encrypted_message, PublicKey key) {
    return power(encrypted_message, key.d) % key.n;
}

int main() {
    PublicKey public_key = generate_key();
    printf("Public Key:\n");
    printf("n = %d\n", public_key.n);
    printf("e = %d\n", public_key.e);
    int message;
    printf("Enter message to encrypt: ");
    scanf("%d", &message);
    int encrypted_message = encrypt(message, public_key);
    printf("Encrypted message: %d\n", encrypted_message);
    int decrypted_message = decrypt(encrypted_message, public_key);
    printf("Decrypted message: %d\n", decrypted_message);
    return 0;
}