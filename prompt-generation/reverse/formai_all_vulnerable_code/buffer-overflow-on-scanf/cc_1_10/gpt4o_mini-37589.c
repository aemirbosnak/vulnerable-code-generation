//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Fun function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;

    if (num % 2 == 0 || num % 3 == 0) return 0;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

// Fun function to generate a random prime number
int generate_prime() {
    int num;
    while (1) {
        num = rand() % 100 + 1;
        if (is_prime(num)) {
            return num;
        }
    }
}

// Fun function to calculate modular exponentiation
int mod_exp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    if (base == 0) return 0; // In case base is divisible by mod

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1; // Exp = Exp / 2
        base = (base * base) % mod;
    }
    return result;
}

// Main function to implement the RSA algorithm
int main() {
    printf("Welcome to the Happy RSA Public-Key Algorithm Implementation!\n");
    
    // Generate two distinct prime numbers
    int p = generate_prime();
    int q = generate_prime();

    // Ensure p and q are different
    while (p == q) {
        q = generate_prime();
    }

    // Calculate n = p * q
    int n = p * q;

    // Calculate phi(n) = (p-1)(q-1)
    int phi_n = (p - 1) * (q - 1);

    // Choose e, a small prime number
    int e = 3; // Small prime number as public exponent

    // Check that e and phi(n) are coprime
    while (phi_n % e == 0) {
        e += 2; // Increment by 2 to keep e as an odd number
    }

    printf("Generated Prime Numbers:\n");
    printf("p = %d\n", p);
    printf("q = %d\n", q);
    printf("n = p * q = %d\n", n);
    printf("phi(n) = (p-1)(q-1) = %d\n", phi_n);
    printf("Public Exponent e = %d\n", e);

    // Calculate the private key d
    int d = 0;
    for (int i = 1; i < phi_n; i++) {
        if ((e * i) % phi_n == 1) {
            d = i;
            break;
        }
    }

    printf("Private Exponent d = %d\n", d);

    // Example message to encrypt
    char message[100];
    printf("Enter the message to encrypt (as an integer): ");
    scanf("%s", message);
    int m = atoi(message); // Convert string input to integer

    // Encrypt the message
    int encrypted = mod_exp(m, e, n);
    printf("Encrypted message: %d\n", encrypted);

    // Decrypt the message
    int decrypted = mod_exp(encrypted, d, n);
    printf("Decrypted message: %d\n", decrypted);

    // Display original message and decrypted message
    printf("Original Message: %s\n", message);
    printf("Decrypted Message: %s\n", decrypted == m ? "Match!" : "Mismatch!");

    printf("Thank you for using the Happy RSA Algorithm!\nHave a great day!\n");
    return 0;
}