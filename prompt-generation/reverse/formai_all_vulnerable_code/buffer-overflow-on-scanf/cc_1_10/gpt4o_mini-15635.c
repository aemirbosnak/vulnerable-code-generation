//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

long long gcd(long long a, long long b) {
    return (b == 0) ? a : gcd(b, a % b);
}

long long modular_inverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;

        m = a % m;
        a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

void generate_keys(long long *public_key, long long *private_key, long long *n) {
    long long p = 61; // Prime number 1
    long long q = 53; // Prime number 2
    *n = p * q; // n = pq
    long long phi = (p - 1) * (q - 1);

    *public_key = 17; // Chosen value for e
    *private_key = modular_inverse(*public_key, phi);
}

long long encrypt(long long plaintext, long long public_key, long long n) {
    return power_mod(plaintext, public_key, n);
}

long long decrypt(long long ciphertext, long long private_key, long long n) {
    return power_mod(ciphertext, private_key, n);
}

int main() {
    long long public_key, private_key, n;
    generate_keys(&public_key, &private_key, &n);

    printf("Public Key: %lld\n", public_key);
    printf("Private Key: %lld\n", private_key);
    printf("n: %lld\n", n);

    long long plaintext;
    printf("Enter a plaintext number (0 < plaintext < %lld): ", n);
    scanf("%lld", &plaintext);
    
    if (plaintext <= 0 || plaintext >= n) {
        printf("Invalid plaintext. Please enter a value within the valid range.\n");
        return 1;
    }

    long long ciphertext = encrypt(plaintext, public_key, n);
    printf("Encrypted text: %lld\n", ciphertext);

    long long decrypted_text = decrypt(ciphertext, private_key, n);
    printf("Decrypted text: %lld\n", decrypted_text);

    return 0;
}