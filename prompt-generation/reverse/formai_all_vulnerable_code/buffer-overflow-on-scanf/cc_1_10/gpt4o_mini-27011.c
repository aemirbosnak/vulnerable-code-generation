//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to encrypt or decrypt a message using XOR
void xorEncryptDecrypt(char *input, const char *key, char *output) {
    size_t keyLength = strlen(key);
    for (size_t i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key[i % keyLength];
    }
    output[strlen(input)] = '\0'; // Null-terminate the output string
}

// Function to read a message from the user
void readMessage(char *buffer, size_t size) {
    printf("Enter your message: ");
    fgets(buffer, size, stdin);
    // Remove newline character from the end if present
    buffer[strcspn(buffer, "\n")] = 0;
}

// Function to use the encryption/decryption process
void processMessages() {
    char message[BUFFER_SIZE];
    char key[BUFFER_SIZE];
    char encryptedMessage[BUFFER_SIZE];
    char decryptedMessage[BUFFER_SIZE];

    readMessage(message, BUFFER_SIZE);
    
    printf("Enter a key for encryption (max %d characters): ", BUFFER_SIZE - 1);
    readMessage(key, BUFFER_SIZE);

    // Encrypt the message
    xorEncryptDecrypt(message, key, encryptedMessage);
    printf("Encrypted message: %s\n", encryptedMessage);

    // Decrypt the message
    xorEncryptDecrypt(encryptedMessage, key, decryptedMessage);
    printf("Decrypted message: %s\n", decryptedMessage);
}

// Main function
int main() {
    printf("Welcome to the XOR Encryption & Decryption Program!\n");
    
    // Loop through until user decides to exit
    while (1) {
        processMessages();
        char choice;
        
        printf("Do you want to process another message? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // Consume the newline character left by scanf
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    printf("Thank you for using the program. Goodbye!\n");
    return 0;
}