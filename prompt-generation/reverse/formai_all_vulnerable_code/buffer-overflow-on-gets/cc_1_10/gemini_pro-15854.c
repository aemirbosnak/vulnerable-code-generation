//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define KEY_SIZE 26
#define ALPHABET_SIZE 26

// Global variables
char key[KEY_SIZE];
char alphabet[ALPHABET_SIZE];

// Function declarations
void generate_key();
void generate_alphabet();
char encrypt_character(char character);
char decrypt_character(char character);
void encrypt_message(char *message);
void decrypt_message(char *message);

int main() {
    // Generate the key and alphabet
    generate_key();
    generate_alphabet();

    // Get the message to be encrypted or decrypted
    printf("Enter the message to be encrypted or decrypted: ");
    char message[100];
    gets(message);

    // Encrypt or decrypt the message based on user input
    int choice;
    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);
    if (choice == 1) {
        encrypt_message(message);
    } else if (choice == 2) {
        decrypt_message(message);
    } else {
        printf("Invalid choice. Please enter 1 or 2.\n");
        return 1;
    }

    // Print the encrypted or decrypted message
    printf("The encrypted or decrypted message is: %s\n", message);

    return 0;
}

// Function to generate the key
void generate_key() {
    // Get the key from the user
    printf("Enter the key: ");
    gets(key);

    // Convert the key to uppercase
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = toupper(key[i]);
    }
}

// Function to generate the alphabet
void generate_alphabet() {
    // Generate the alphabet
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        alphabet[i] = 'A' + i;
    }
}

// Function to encrypt a character
char encrypt_character(char character) {
    // Get the index of the character in the alphabet
    int index = character - 'A';

    // Get the index of the encrypted character in the alphabet
    int encrypted_index = (index + key[index % KEY_SIZE] - 'A') % ALPHABET_SIZE;

    // Return the encrypted character
    return alphabet[encrypted_index];
}

// Function to decrypt a character
char decrypt_character(char character) {
    // Get the index of the character in the alphabet
    int index = character - 'A';

    // Get the index of the decrypted character in the alphabet
    int decrypted_index = (index - key[index % KEY_SIZE] - 'A') % ALPHABET_SIZE;

    // If the decrypted index is negative, add 26 to it
    if (decrypted_index < 0) {
        decrypted_index += ALPHABET_SIZE;
    }

    // Return the decrypted character
    return alphabet[decrypted_index];
}

// Function to encrypt a message
void encrypt_message(char *message) {
    // Loop through each character in the message and encrypt it
    for (int i = 0; i < strlen(message); i++) {
        message[i] = encrypt_character(message[i]);
    }
}

// Function to decrypt a message
void decrypt_message(char *message) {
    // Loop through each character in the message and decrypt it
    for (int i = 0; i < strlen(message); i++) {
        message[i] = decrypt_character(message[i]);
    }
}