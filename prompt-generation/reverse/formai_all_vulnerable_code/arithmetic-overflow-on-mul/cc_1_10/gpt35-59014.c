//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the prime numbers
long int p, q;

// Define the product of the two prime numbers
long int n;

// Define the totient of n
long int phi_n;

// Define the public key
long int e;

// Define the private key
long int d;

// Define the message
long int message;

// Define the encrypted message
long int encrypted_message;

// Define the decrypted message
long int decrypted_message;

// Generate a random number between 2 and 1000
int generate_random_number() {
    srand(time(NULL));
    int random_number = rand() % 1000 + 2;
    return random_number;
}

// Calculate the greatest common denominator of two numbers
int gcd(long int a, long int b) {
    if (a == 0) {
        return b;
    } else {
        return gcd(b % a, a);
    }
}

// Generate the public and private keys
void generate_keys() {
    // Choose two prime numbers
    do {
        p = generate_random_number();
    } while (p % 2 == 0);
    do {
        q = generate_random_number();
    } while (q % 2 == 0 || q == p);

    // Calculate n
    n = p * q;

    // Calculate phi_n
    phi_n = (p - 1) * (q - 1);

    // Choose a value for e that is relatively prime to phi_n
    do {
        e = generate_random_number();
    } while (gcd(e, phi_n) != 1);

    // Calculate the private key d
    long int k = 1;
    do {
        k += phi_n;
    } while (k % e != 0);

    d = k / e;
}

// Encrypt the message using the public key
void encrypt_message() {
    encrypted_message = 1;

    for (int i = 0; i < e; i++) {
        encrypted_message = (encrypted_message * message) % n;
    }
}

// Decrypt the message using the private key
void decrypt_message() {
    decrypted_message = 1;

    for (int i = 0; i < d; i++) {
        decrypted_message = (decrypted_message * encrypted_message) % n;
    }
}

int main() {
    printf("Get ready for some serious cryptography wizardry!\n");

    // Generate the public and private keys
    generate_keys();

    // Prompt the user for the message to encrypt
    printf("\nEnter the message to be encrypted:\n");
    scanf("%ld", &message);

    // Encrypt the message
    encrypt_message();

    // Output the encrypted message
    printf("\nThe encrypted message is: %ld\n", encrypted_message);

    // Decrypt the message
    decrypt_message();

    // Output the decrypted message
    printf("\nThe decrypted message is: %ld\n", decrypted_message);

    printf("\nI told you it was going to be incredible! In just a few short lines of code, we've encrypted and decrypted messages with the power of Public-Key Cryptography!\n");

    return 0;
}