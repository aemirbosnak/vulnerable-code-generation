//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to perform modular exponentiation
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1; // Divide exp by 2
        base = (base * base) % mod;
    }
    return result;
}

// Function to generate a prime number
int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return 0;
    return 1;
}

int generate_prime() {
    int prime;
    do {
        prime = rand() % 100 + 2; // Generate a random number between 2 and 101
    } while (!is_prime(prime));
    return prime;
}

// Function to compute the modular inverse
int mod_inverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

// Function to generate RSA keys
void generate_keys(int *e, int *d, int *n) {
    srand(time(NULL)); // Seed for random number generation

    int p = generate_prime();
    int q = generate_prime();
    
    *n = p * q; // n is the product of two primes
    int phi = (p - 1) * (q - 1); // Euler's totient function

    // Choose e (must be coprime to phi)
    do {
        *e = rand() % (phi - 2) + 2; // Randomly select 'e'
    } while (gcd(*e, phi) != 1);

    // Calculate d, the modular inverse of e
    *d = mod_inverse(*e, phi);
}

// Function to encrypt the message
long long encrypt(int message, int e, int n) {
    return mod_exp(message, e, n);
}

// Function to decrypt the message
long long decrypt(long long cipher_text, int d, int n) {
    return mod_exp(cipher_text, d, n);
}

// Main program to demonstrate RSA encryption and decryption
int main() {
    int public_key_exponent, private_key_exponent, modulus;
    generate_keys(&public_key_exponent, &private_key_exponent, &modulus);

    printf("RSA Public Key: (e: %d, n: %d)\n", public_key_exponent, modulus);
    printf("RSA Private Key: (d: %d, n: %d)\n", private_key_exponent, modulus);

    int message;
    printf("Enter a message (integer) to encrypt: ");
    scanf("%d", &message);

    long long cipher_text = encrypt(message, public_key_exponent, modulus);
    printf("Encrypted Message (Cipher Text): %lld\n", cipher_text);

    long long decrypted_message = decrypt(cipher_text, private_key_exponent, modulus);
    printf("Decrypted Message: %lld\n", decrypted_message);

    if (message == decrypted_message) {
        printf("Success! The original message is recovered.\n");
    } else {
        printf("Oops! Something went wrong.\n");
    }

    return 0;
}