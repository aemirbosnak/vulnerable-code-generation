//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 2048

typedef struct {
    long long n; // modulus
    long long e; // public exponent
    long long d; // private exponent
} RSAKeyPair;

// Function prototypes
long long gcd(long long a, long long b);
long long mod_inverse(long long e, long long phi);
long long power(long long base, long long exp, long long mod);
long long generate_prime(int lower, int upper);
RSAKeyPair generate_keypair(int p, int q);
long long encrypt(long long plaintext, long long e, long long n);
long long decrypt(long long ciphertext, long long d, long long n);

int main() {
    int p, q;
    printf("Enter two prime numbers (p and q):\n");
    scanf("%d %d", &p, &q);

    RSAKeyPair keys = generate_keypair(p, q);
    printf("Public Key: (n: %lld, e: %lld)\n", keys.n, keys.e);
    printf("Private Key: (n: %lld, d: %lld)\n", keys.n, keys.d);

    long long plaintext;
    printf("Enter a message to encrypt:\n");
    scanf("%lld", &plaintext);

    long long ciphertext = encrypt(plaintext, keys.e, keys.n);
    printf("Encrypted message: %lld\n", ciphertext);

    long long decrypted_message = decrypt(ciphertext, keys.d, keys.n);
    printf("Decrypted message: %lld\n", decrypted_message);

    return 0;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long mod_inverse(long long e, long long phi) {
    for (long long d = 1; d < phi; d++) {
        if ((e * d) % phi == 1) {
            return d;
        }
    }
    return -1; // Modular inverse does not exist
}

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

long long generate_prime(int lower, int upper) {
    long long prime;
    int is_prime;
    do {
        prime = rand() % (upper - lower + 1) + lower;
        is_prime = 1;
        for (long long i = 2; i <= sqrt(prime); i++) {
            if (prime % i == 0) {
                is_prime = 0;
                break;
            }
        }
    } while (!is_prime);
    return prime;
}

RSAKeyPair generate_keypair(int p, int q) {
    RSAKeyPair keys;
    keys.n = p * q;
    long long phi = (p - 1) * (q - 1); 
    keys.e = 3; // Common choice for e

    while (gcd(keys.e, phi) != 1) {
        keys.e += 2; // Increment e until it's coprime with phi
    }

    keys.d = mod_inverse(keys.e, phi);
    return keys;
}

long long encrypt(long long plaintext, long long e, long long n) {
    return power(plaintext, e, n);
}

long long decrypt(long long ciphertext, long long d, long long n) {
    return power(ciphertext, d, n);
}