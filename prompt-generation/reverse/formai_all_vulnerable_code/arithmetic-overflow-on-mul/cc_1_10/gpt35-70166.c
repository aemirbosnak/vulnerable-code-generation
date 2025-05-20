//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Helper function to calculate GCD
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

// Recursive function to calculate the power of a number
int power(int x, unsigned int y, int p) {
    int res = 1;
    x = x % p;
 
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1) {
            res = (res * x) % p;
        }
 
        // y must be even now
        y >>= 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Function to generate keys
void generate_keys(int p, int q, int *public_key, int *private_key) {
    int n = p * q; // Calculate n
    int phi_n = (p - 1) * (q - 1); // Calculate phi_n

    // Choose e such that gcd(e, phi_n) = 1
    int e = 2;
    while (e < phi_n) {
        if (gcd(e, phi_n) == 1) {
            break;
        } else {
            e++;
        }
    }

    *public_key = e; // Set public key to e

    // Calculate d such that (d * e) % phi_n = 1
    int k = 2;
    while (1) {
        int d = (k * phi_n + 1) / e;
        if ((k * phi_n + 1) % e == 0 && d > 0) {
            *private_key = d; // Set private key to d
            break;
        } else {
            k++;
        }
    }
}

// Function to encrypt message
int encrypt(int message, int public_key, int n) {
    return power(message, public_key, n);
}

// Function to decrypt message
int decrypt(int message, int private_key, int n) {
    return power(message, private_key, n);
}

int main() {
    int p, q, public_key, private_key, message, encrypted_message, decrypted_message;

    printf("Enter two prime numbers (p and q): ");
    scanf("%d %d", &p, &q);

    generate_keys(p, q, &public_key, &private_key);

    printf("Public key: %d\n", public_key);
    printf("Private key: %d\n", private_key);

    printf("Enter a message to encrypt: ");
    scanf("%d", &message);

    int n = p * q; // Calculate n

    encrypted_message = encrypt(message, public_key, n);
    printf("Encrypted message: %d\n", encrypted_message);

    decrypted_message = decrypt(encrypted_message, private_key, n);
    printf("Decrypted message: %d\n", decrypted_message);

    return 0;
}