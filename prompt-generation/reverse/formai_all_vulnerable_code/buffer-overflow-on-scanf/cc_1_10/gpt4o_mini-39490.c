//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to generate random prime numbers
int is_prime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int generate_random_prime() {
    int prime;
    do {
        prime = rand() % 100 + 2; // Random numbers between 2 and 101
    } while (!is_prime(prime));
    return prime;
}

// Function to compute the greatest common divisor
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to calculate the modular inverse using the Extended Euclidean Algorithm
int mod_inverse(int e, int phi) {
    int m0 = phi, y = 0, x = 1;
    if (phi == 1) return 0;

    while (e > 1) {
        int q = e / phi;
        int t = phi;

        phi = e % phi;
        e = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0) x += m0;

    return x;
}

// Function to encrypt a message using RSA
int encrypt(int message, int e, int n) {
    int result = 1;
    for (int i = 0; i < e; i++) {
        result = (result * message) % n;
    }
    return result;
}

// Function to decrypt the message using RSA
int decrypt(int cipher, int d, int n) {
    int result = 1;
    for (int i = 0; i < d; i++) {
        result = (result * cipher) % n;
    }
    return result;
}

int main() {
    srand(time(NULL)); // Seed for randomness

    printf("Welcome to the Exciting RSA Public-Key Cryptography Program!\n");

    // Generate two random prime numbers
    int p = generate_random_prime();
    int q = generate_random_prime();
    printf("Generated primes p = %d and q = %d\n", p, q);

    // Compute n = p * q
    int n = p * q;
    printf("Computed n = p * q = %d\n", n);
    
    // Compute phi(n) = (p-1)(q-1)
    int phi = (p - 1) * (q - 1);
    printf("Computed phi(n) = (p-1)(q-1) = %d\n", phi);

    // Choose public key exponent e
    int e;
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1) break;
    }
    printf("Chosen public key exponent e = %d\n", e);

    // Calculate private key exponent d
    int d = mod_inverse(e, phi);
    printf("Calculated private key exponent d = %d\n", d);

    // Message to be encrypted
    int message;
    printf("Enter a message as an integer to encrypt (0 to %d): ", n-1);
    scanf("%d", &message);
    
    if (message < 0 || message >= n) {
        printf("Message must be between 0 and %d. Exiting...\n", n-1);
        return 1;
    }

    // Encrypt the message
    int cipher = encrypt(message, e, n);
    printf("Encrypted message (ciphertext) = %d\n", cipher);

    // Decrypt the message
    int decrypted_message = decrypt(cipher, d, n);
    printf("Decrypted message = %d\n", decrypted_message);

    // Confirm that the decrypted message matches the original message
    if (decrypted_message == message) {
        printf("Success! Decrypted message matches the original message!\n");
    } else {
        printf("Oh no! Decrypted message does NOT match the original message!\n");
    }

    return 0;
}