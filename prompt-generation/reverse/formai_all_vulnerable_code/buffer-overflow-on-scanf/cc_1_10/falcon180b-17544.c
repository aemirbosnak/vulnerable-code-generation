//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum length of the message to be encrypted
#define MAX_MESSAGE_LENGTH 1000

// Define the prime number
#define PRIME_NUMBER 31

// Define the public key and private key
int public_key;
int private_key;

// Function to generate the public and private keys
void generate_keys() {
    // Generate the public key
    public_key = rand() % PRIME_NUMBER;

    // Generate the private key
    private_key = (PRIME_NUMBER - public_key) % PRIME_NUMBER;
}

// Function to encrypt the message using the public key
void encrypt_message(char* message, int message_length) {
    int i;
    for (i = 0; i < message_length; i++) {
        // Convert the ASCII value of the character to an integer
        int ascii_value = message[i];

        // Encrypt the character using the public key
        int encrypted_value = (ascii_value * public_key) % PRIME_NUMBER;

        // Convert the encrypted integer back to an ASCII character
        char encrypted_char = encrypted_value + 'A';

        // Print the encrypted character
        printf("%c", encrypted_char);
    }
}

// Function to decrypt the message using the private key
void decrypt_message(char* message, int message_length) {
    int i;
    for (i = 0; i < message_length; i++) {
        // Convert the ASCII value of the character to an integer
        int ascii_value = message[i];

        // Decrypt the character using the private key
        int decrypted_value = (ascii_value * private_key) % PRIME_NUMBER;

        // Convert the decrypted integer back to an ASCII character
        char decrypted_char = decrypted_value + 'A';

        // Print the decrypted character
        printf("%c", decrypted_char);
    }
}

int main() {
    // Generate the public and private keys
    generate_keys();

    // Get the message to be encrypted from the user
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Encrypt the message using the public key
    printf("Encrypted message: ");
    encrypt_message(message, strlen(message));
    printf("\n");

    // Decrypt the encrypted message using the private key
    printf("Decrypted message: ");
    decrypt_message(message, strlen(message));
    printf("\n");

    return 0;
}