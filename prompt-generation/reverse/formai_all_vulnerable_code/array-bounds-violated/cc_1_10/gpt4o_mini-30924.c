//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 256
#define SHIFT_AMOUNT 3 // Caesar Cipher shift

// Function to encrypt the message using Caesar Cipher
void encrypt_message(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char current_char = message[i];
        
        // Encrypt uppercase letters
        if (current_char >= 'A' && current_char <= 'Z') {
            message[i] = (current_char - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (current_char >= 'a' && current_char <= 'z') {
            message[i] = (current_char - 'a' + shift) % 26 + 'a';
        }
        // Non-alphabetic characters remain the same
    }
}

// Function to decrypt the message using Caesar Cipher
void decrypt_message(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char current_char = message[i];

        // Decrypt uppercase letters
        if (current_char >= 'A' && current_char <= 'Z') {
            message[i] = (current_char - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (current_char >= 'a' && current_char <= 'z') {
            message[i] = (current_char - 'a' - shift + 26) % 26 + 'a';
        }
        // Non-alphabetic characters remain the same
    }
}

int main() {
    char original_message[MAX_MESSAGE_LENGTH];
    char choice[10];
    
    printf("Welcome to the Retro C Encryption Program!\n");
    
    // Get input message from user
    printf("Please enter your message (max %d characters): ", MAX_MESSAGE_LENGTH - 1);
    fgets(original_message, sizeof(original_message), stdin);
    
    // Remove newline character if exists
    size_t message_length = strlen(original_message);
    if (original_message[message_length - 1] == '\n') {
        original_message[message_length - 1] = '\0';
    }
    
    // Encrypt the original message
    char encrypted_message[MAX_MESSAGE_LENGTH];
    strcpy(encrypted_message, original_message);
    encrypt_message(encrypted_message, SHIFT_AMOUNT);
    
    // Output the original and encrypted messages
    printf("\n--- Original Message ---\n");
    printf("%s\n", original_message);
    
    printf("\n--- Encrypted Message (Caesar Cipher) ---\n");
    printf("%s\n", encrypted_message);
    
    // Ask if the user wants to decrypt the message
    printf("\nWould you like to decrypt the message? (yes/no): ");
    fgets(choice, sizeof(choice), stdin);
    if (strncmp(choice, "yes", 3) == 0 || strncmp(choice, "Yes", 3) == 0) {
        // Decrypt the message
        decrypt_message(encrypted_message, SHIFT_AMOUNT);
        printf("\n--- Decrypted Message ---\n");
        printf("%s\n", encrypted_message);
    } else {
        printf("\nThank you for using the Retro C Encryption Program! Stay safe!\n");
    }

    return 0;
}