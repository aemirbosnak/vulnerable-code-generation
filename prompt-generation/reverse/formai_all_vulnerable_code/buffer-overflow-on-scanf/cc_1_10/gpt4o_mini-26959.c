//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 256

// Function to encrypt the message using Caesar Cipher
void encrypt_message(char *message, int key, char *encrypted_message) {
    for (int i = 0; message[i] != '\0'; i++) {
        // Encrypt uppercase letters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted_message[i] = (message[i] + key - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted_message[i] = (message[i] + key - 'a') % 26 + 'a';
        } else {
            // Non-alphabetic characters remain unchanged
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[strlen(message)] = '\0'; // Null-terminate the string
}

// Function to decrypt the message using Caesar Cipher
void decrypt_message(char *encrypted_message, int key, char *decrypted_message) {
    for (int i = 0; encrypted_message[i] != '\0'; i++) {
        // Decrypt uppercase letters
        if (encrypted_message[i] >= 'A' && encrypted_message[i] <= 'Z') {
            decrypted_message[i] = (encrypted_message[i] - key - 'A' + 26) % 26 + 'A'; 
        }
        // Decrypt lowercase letters
        else if (encrypted_message[i] >= 'a' && encrypted_message[i] <= 'z') {
            decrypted_message[i] = (encrypted_message[i] - key - 'a' + 26) % 26 + 'a'; 
        } else {
            // Non-alphabetic characters remain unchanged
            decrypted_message[i] = encrypted_message[i];
        }
    }
    decrypted_message[strlen(encrypted_message)] = '\0'; // Null-terminate the string
}

// Main function to interact with the user
int main() {
    char message[MAX_MESSAGE_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];
    int key;

    printf("Welcome to the Mysterious Library!\n");
    printf("This is the secure message vault.\n");

    // Get user input for the message and key
    printf("Enter your secret message (max %d characters): ", MAX_MESSAGE_LENGTH - 1);
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character

    printf("Enter your mystical key (a number between 1 and 25): ");
    scanf("%d", &key);

    // Validate key
    if (key < 1 || key > 25) {
        printf("Invalid key! Please use a value from 1 to 25.\n");
        return 1;
    }

    // Encrypt the message
    encrypt_message(message, key, encrypted_message);
    printf("\nYour encrypted message is: %s\n", encrypted_message);

    // Decrypt the message
    decrypt_message(encrypted_message, key, decrypted_message);
    printf("Your decrypted message is: %s\n", decrypted_message);

    printf("\nThank you for visiting the Mysterious Library! The secrets are safe with you.\n");
    
    return 0;
}