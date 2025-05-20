//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024
#define MAX_KEY_LENGTH 64

void encrypt(char *plaintext, char *key, char *ciphertext, int text_length, int key_length) {
    for (int i = 0; i < text_length; i++) {
        ciphertext[i] = (plaintext[i] + key[i % key_length]) % 256; // Simple byte-wise encryption
    }
    ciphertext[text_length] = '\0'; // Null-terminate the ciphertext
}

void decrypt(char *ciphertext, char *key, char *plaintext, int text_length, int key_length) {
    for (int i = 0; i < text_length; i++) {
        plaintext[i] = (ciphertext[i] - key[i % key_length] + 256) % 256; // Decrypting
    }
    plaintext[text_length] = '\0'; // Null-terminate the plaintext
}

void getUserInput(char *prompt, char *buffer, size_t buffer_size) {
    printf("%s", prompt);
    fgets(buffer, buffer_size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
}

void displayMenu() {
    printf("=== Simple Encryption Program ===\n");
    printf("1. Encrypt text\n");
    printf("2. Decrypt text\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int main() {
    char plaintext[MAX_TEXT_LENGTH], ciphertext[MAX_TEXT_LENGTH], decryptedtext[MAX_TEXT_LENGTH];
    char key[MAX_KEY_LENGTH];
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Clear newline character left by scanf

        switch (choice) {
            case 1:
                getUserInput("Enter the plaintext: ", plaintext, sizeof(plaintext));
                getUserInput("Enter the encryption key: ", key, sizeof(key));

                int text_length = strlen(plaintext);
                int key_length = strlen(key);
                
                encrypt(plaintext, key, ciphertext, text_length, key_length);
                printf("Ciphertext: ");
                for (int i = 0; i < text_length; i++) {
                    printf("%02X ", (unsigned char)ciphertext[i]);
                }
                printf("\n");
                break;
            case 2:
                getUserInput("Enter the ciphertext (hex): ", plaintext, sizeof(plaintext));
                getUserInput("Enter the decryption key: ", key, sizeof(key));

                text_length = strlen(plaintext) / 3; // Each byte is represented by 2 hex digits + space
                key_length = strlen(key);
                
                int j = 0;
                for (int i = 0; i < text_length; i++) {
                    unsigned int val;
                    sscanf(plaintext + j, "%2X", &val); // Convert from hex
                    ciphertext[i] = (unsigned char) val;
                    j += 3; // Skip to next byte (2 hex + 1 space)
                }

                decrypt(ciphertext, key, decryptedtext, text_length, key_length);
                printf("Decrypted text: %s\n", decryptedtext);
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    return 0;
}