//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LEN 1024

typedef struct {
    int n;
    int e;
    int d;
    int p;
    int q;
    int phi;
} RSA;

int gcd(int a, int b) {
    return b == 0? a : gcd(b, a % b);
}

int power(int a, int b, int p) {
    int r = 1;
    while (b) {
        if (b & 1) {
            r = (r * a) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    return r;
}

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void generate_primes(int *p, int *q) {
    int i;
    for (i = 2; i < LEN; i++) {
        if (is_prime(i)) {
            break;
        }
    }
    *p = i;
    for (i++; i < LEN; i++) {
        if (is_prime(i)) {
            break;
        }
    }
    *q = i;
}

void generate_keys(RSA *rsa, int p, int q) {
    int phi = (p - 1) * (q - 1);
    int e = 65537;
    while (gcd(e, phi)!= 1) {
        e++;
    }
    rsa->n = p * q;
    rsa->e = e;
    rsa->d = power(e, -1, phi);
}

char* encrypt(RSA *rsa, char* message) {
    int m = strlen(message);
    int n = rsa->n;
    int e = rsa->e;
    int* encrypted_message = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        encrypted_message[i] = message[i] ^ power(e, i, n);
    }
    return (char*)encrypted_message;
}

char* decrypt(RSA *rsa, char* encrypted_message) {
    int n = rsa->n;
    int d = rsa->d;
    int m = strlen(encrypted_message);
    int* decrypted_message = malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        decrypted_message[i] = encrypted_message[i] ^ power(d, i, n);
    }
    return (char*)decrypted_message;
}

int main() {
    srand(time(NULL));
    int p, q;
    generate_primes(&p, &q);
    RSA rsa;
    generate_keys(&rsa, p, q);
    char* message = "Hello, World!";
    char* encrypted_message = encrypt(&rsa, message);
    char* decrypted_message = decrypt(&rsa, encrypted_message);
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);
    return 0;
}