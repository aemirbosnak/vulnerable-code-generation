//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX 100      // Maximum limit for array size
#define PRIME 11     // A prime number used as the base for the algorithm

bool is_prime(int x);
bool is_coprime(int a, int b);
int mod_pow(int base, int exp, int mod);

int main() {
    int p, q, n, e, d, msg, encrypted, decrypted;

    srand(time(NULL));   // Seed the random number generator

    // Generate two prime numbers
    do {
        p = rand() % MAX + 1;
    } while (!is_prime(p));

    do {
        q = rand() % MAX + 1;
    } while (!is_prime(q) || q == p);

    // Calculate n and Euler's totient function phi(n)
    n = p * q;
    int phi = (p - 1) * (q - 1);

    // Choose a random integer e that is coprime to phi
    do {
        e = rand() % phi + 1;
    } while (!is_coprime(e, phi));

    // Calculate the modular inverse of e, which is d
    int k = 1;
    while ((k * phi + 1) % e != 0) {
        k++;
    }
    d = (k * phi + 1) / e;

    printf("Public Key: (%d,%d)\n", e, n);
    printf("Private Key: (%d,%d)\n", d, n);

    // Enter the message to be encrypted
    printf("Enter the message to be encrypted: ");
    scanf("%d", &msg);

    // Encrypt the message by raising it to the power of e modulo n
    encrypted = mod_pow(msg, e, n);

    // Decrypt the message by raising it to the power of d modulo n
    decrypted = mod_pow(encrypted, d, n);

    printf("Encrypted Message: %d\n", encrypted);
    printf("Decrypted Message: %d\n", decrypted);

    return 0;
}

// Checks if a number is prime
bool is_prime(int x) {
    if (x <= 1) {
        return false;
    }
    for (int i = 2; i < x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

// Checks if two numbers are coprime
bool is_coprime(int a, int b) {
    for (int i = 2; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0) {
            return false;
        }
    }
    return true;
}

// Calculates the modular exponentiation of a number
int mod_pow(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp /= 2;
        base = (base * base) % mod;
    }
    return result;
}