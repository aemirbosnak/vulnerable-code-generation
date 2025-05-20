//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGE_LENGTH 1024
#define KEY_LENGTH 26  // Size of our shift for Caesar Cipher

// Function to clean input text
void cleanString(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to encrypt the message using Caesar Cipher
void encrypt(char *message, int key, char *encrypted) {
    for (int i = 0; message[i] != '\0'; i++) {
        if (isalpha(message[i])) {
            char offset = isupper(message[i]) ? 'A' : 'a';
            encrypted[i] = (message[i] - offset + key) % 26 + offset;
        } else {
            encrypted[i] = message[i]; // Non-alphabetic characters remain unchanged
        }
    }
    encrypted[strlen(message)] = '\0'; // Null-terminate the encrypted string
}

// Function to decrypt the message using Caesar Cipher
void decrypt(char *encrypted, int key, char *decrypted) {
    for (int i = 0; encrypted[i] != '\0'; i++) {
        if (isalpha(encrypted[i])) {
            char offset = isupper(encrypted[i]) ? 'A' : 'a';
            decrypted[i] = (encrypted[i] - offset - key + 26) % 26 + offset; // Add 26 to handle negative modulus
        } else {
            decrypted[i] = encrypted[i]; // Non-alphabetic characters remain unchanged
        }
    }
    decrypted[strlen(encrypted)] = '\0'; // Null-terminate the decrypted string
}

// Function to get user input for the message and key
void getInput(char *message, int *key) {
    printf("Enter your message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character

    printf("Enter the shift key (1-25): ");
    scanf("%d", key);
    // Validation for key
    while (*key < 1 || *key > 25) {
        printf("Key must be between 1 and 25. Please enter again: ");
        scanf("%d", key);
    }
}

// Main function to drive the program
int main() {
    char message[MAX_MESSAGE_LENGTH];
    char encrypted[MAX_MESSAGE_LENGTH];
    char decrypted[MAX_MESSAGE_LENGTH];
    int key = 0;
    
    // Get user input
    getInput(message, &key);
    
    // Clean the string for uniformity
    cleanString(message);

    // Perform encryption
    encrypt(message, key, encrypted);
    printf("Encrypted Message: %s\n", encrypted);
    
    // Perform decryption
    decrypt(encrypted, key, decrypted);
    printf("Decrypted Message: %s\n", decrypted);
    
    return 0;
}