//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

long long gcd(long long a, long long b);
long long modinv(long long a, long long m);
long long power(long long base, long long exp, long long mod);
long long generate_prime(int bits);
void generate_keypair(long long* n, long long* e, long long* d);
long long encrypt(long long plain, long long e, long long n);
long long decrypt(long long cipher, long long d, long long n);

int main() {
    long long n, e, d, plain, cipher;
    
    printf("RSA Public-Key Algorithm Implementation\n\n");
    
    generate_keypair(&n, &e, &d);

    printf("Public Key: (n = %lld, e = %lld)\n", n, e);
    printf("Private Key: (n = %lld, d = %lld)\n\n", n, d);
    
    printf("Enter a number to encrypt: ");
    scanf("%lld", &plain);

    cipher = encrypt(plain, e, n);
    printf("Encrypted number: %lld\n", cipher);
    
    plain = decrypt(cipher, d, n);
    printf("Decrypted number: %lld\n", plain);
    
    return 0;
}

long long gcd(long long a, long long b) {
    return (b == 0) ? a : gcd(b, a % b);
}

long long modinv(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) { // If exp is odd
            res = (res * base) % mod;
        }
        exp = exp >> 1; // exp /= 2
        base = (base * base) % mod;
    }
    
    return res;
}

long long generate_prime(int bits) {
    long long num;
    int is_prime, i;

    while (1) {
        num = rand() % (1 << bits); // Random number
        is_prime = 1;

        for (i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                is_prime = 0;
                break;
            }
        }

        if (is_prime && num > 1) break;
    }
    
    return num;
}

void generate_keypair(long long* n, long long* e, long long* d) {
    long long p = generate_prime(10);
    long long q = generate_prime(10);
    
    *n = p * q;
    long long phi = (p - 1) * (q - 1);

    // Choosing e
    *e = 3; // Common choice

    while (gcd(*e, phi) != 1) {
        (*e) += 2; // Keep increasing e to find coprime
    }

    *d = modinv(*e, phi);
}

long long encrypt(long long plain, long long e, long long n) {
    return power(plain, e, n);
}

long long decrypt(long long cipher, long long d, long long n) {
    return power(cipher, d, n);
}