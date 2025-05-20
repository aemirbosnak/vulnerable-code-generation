//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 101
#define Z 26
#define E 5
#define D 29

// Function to generate public and private keys
void generate_keys(int *public_key, int *private_key) {
    int i;
    // Generate a random prime number for public key
    for (i = 2; i <= N; i++) {
        if (is_prime(i)) {
            *public_key = i;
            break;
        }
    }
    // Generate a random number for private key
    *private_key = rand() % Z;
}

// Function to encrypt the message
void encrypt(int public_key, char *message, char *cipher_text) {
    int i, j;
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            // Shift the alphabet by public key
            cipher_text[i] = (message[i] - 'a' + public_key) % Z + 'a';
        } else {
            // Copy non-alphabetic characters as is
            cipher_text[i] = message[i];
        }
    }
    cipher_text[i] = '\0';
}

// Function to decrypt the message
void decrypt(int private_key, char *cipher_text, char *message) {
    int i, j;
    for (i = 0; cipher_text[i]!= '\0'; i++) {
        if (isalpha(cipher_text[i])) {
            // Shift the alphabet back by private key
            message[i] = (cipher_text[i] - 'a' - private_key + Z) % Z + 'a';
        } else {
            // Copy non-alphabetic characters as is
            message[i] = cipher_text[i];
        }
    }
    message[i] = '\0';
}

// Function to check if a number is prime
int is_prime(int n) {
    int i;
    if (n == 2) {
        return 1;
    } else if (n % 2 == 0) {
        return 0;
    } else {
        for (i = 3; i <= sqrt(n); i += 2) {
            if (n % i == 0) {
                return 0;
            }
        }
        return 1;
    }
}

// Function to generate a random number between 0 and Z-1
int rand_int(int max) {
    return rand() % max;
}

// Function to generate a random prime number
int rand_prime() {
    int i;
    for (i = 2; i <= N; i++) {
        if (is_prime(i)) {
            return i;
        }
    }
}

// Main function
int main() {
    int public_key, private_key;
    char message[100], cipher_text[100];
    generate_keys(&public_key, &private_key);
    printf("Public key: %d\n", public_key);
    printf("Private key: %d\n", private_key);
    printf("Enter the message to encrypt: ");
    scanf("%s", message);
    encrypt(public_key, message, cipher_text);
    printf("Encrypted message: %s\n", cipher_text);
    decrypt(private_key, cipher_text, message);
    printf("Decrypted message: %s\n", message);
    return 0;
}