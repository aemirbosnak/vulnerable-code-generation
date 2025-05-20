//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGE_LENGTH 1000

// Function to encrypt the plaintext using Caesar Cipher
void encrypt(const char *plaintext, int key, char *ciphertext) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char c = plaintext[i];
        // Encrypt uppercase letters
        if (isupper(c)) {
            ciphertext[i] = (c + key - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(c)) {
            ciphertext[i] = (c + key - 'a') % 26 + 'a';
        }
        // Non-alphabetic characters remain unchanged
        else {
            ciphertext[i] = c;
        }
    }
    ciphertext[strlen(plaintext)] = '\0'; // Null-terminate the ciphertext
}

// Function to decrypt the ciphertext using Caesar Cipher
void decrypt(const char *ciphertext, int key, char *plaintext) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char c = ciphertext[i];
        // Decrypt uppercase letters
        if (isupper(c)) {
            plaintext[i] = (c - key + 26 - 'A') % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (islower(c)) {
            plaintext[i] = (c - key + 26 - 'a') % 26 + 'a';
        }
        // Non-alphabetic characters remain unchanged
        else {
            plaintext[i] = c;
        }
    }
    plaintext[strlen(ciphertext)] = '\0'; // Null-terminate the plaintext
}

// Function to get user input for the message and the key
void get_user_input(char *message, int *key) {
    printf("Enter the message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    // Remove newline from message
    message[strcspn(message, "\n")] = 0;

    printf("Enter the key (0-25): ");
    if (scanf("%d", key) != 1) {
        printf("Invalid input for the key. Setting key to 0.\n");
        *key = 0;
    } else if (*key < 0 || *key > 25) {
        printf("Key out of range. Setting key to 0.\n");
        *key = 0;
    }

    // Clear the input buffer
    while(getchar() != '\n');
}

// Main function to drive the program
int main() {
    char message[MAX_MESSAGE_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];
    int key;

    get_user_input(message, &key);

    encrypt(message, key, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}