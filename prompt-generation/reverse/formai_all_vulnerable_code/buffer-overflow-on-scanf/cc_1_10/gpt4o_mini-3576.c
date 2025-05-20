//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate GCD
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to calculate modular inverse
int mod_inverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return 0; // Return 0 if inverse doesn't exist
}

// Function to check if number is prime
int is_prime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

// Function to generate prime numbers up to n
void generate_primes(int n, int *primes, int *count) {
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            primes[(*count)++] = i;
        }
    }
}

// Function to perform modular exponentiation
int power(int x, unsigned int y, int p) {
    int res = 1; 
    x = x % p; 
    while (y > 0) {
        if (y & 1) 
            res = (res * x) % p; 
        y = y >> 1; 
        x = (x * x) % p; 
    }
    return res; 
}

// RSA algorithm implementation
void rsa_generate_keys(int *e, int *d, int *n) {
    int p, q;
    printf("Enter two prime numbers (p and q): ");
    scanf("%d %d", &p, &q);

    if (!is_prime(p) || !is_prime(q)) {
        printf("Both numbers must be prime.\n");
        exit(1);
    }

    *n = p * q;
    int phi = (p - 1) * (q - 1);

    // Choosing e such that 1 < e < phi and gcd(e, phi) = 1
    for (*e = 2; *e < phi; (*e)++) {
        if (gcd(*e, phi) == 1) {
            break;
        }
    }

    // Calculate d, the modular multiplicative inverse of e
    *d = mod_inverse(*e, phi);
}

// Function to encrypt plaintext
int rsa_encrypt(int plaintext, int e, int n) {
    return power(plaintext, e, n);
}

// Function to decrypt ciphertext
int rsa_decrypt(int ciphertext, int d, int n) {
    return power(ciphertext, d, n);
}

// Main function
int main() {
    int e, d, n;
    rsa_generate_keys(&e, &d, &n);

    printf("Public Key: (e: %d, n: %d)\n", e, n);
    printf("Private Key: (d: %d)\n", d);

    int plaintext;
    printf("Enter plaintext (integer): ");
    scanf("%d", &plaintext);

    int ciphertext = rsa_encrypt(plaintext, e, n);
    printf("Encrypted ciphertext: %d\n", ciphertext);

    int decrypted_text = rsa_decrypt(ciphertext, d, n);
    printf("Decrypted plaintext: %d\n", decrypted_text);

    return 0;
}