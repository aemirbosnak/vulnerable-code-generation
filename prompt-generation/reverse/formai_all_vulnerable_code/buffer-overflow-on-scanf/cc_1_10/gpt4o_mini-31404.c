//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the input text using a Caesar cipher
void encrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        // Shift only alphabetic characters
        if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' + key) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' + key) % 26 + 'A';
        }
    }
}

// Function to decrypt the input text using a Caesar cipher
void decrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        // Shift only alphabetic characters
        if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' - key + 26) % 26 + 'a'; // +26 ensures positive value
        } else if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' - key + 26) % 26 + 'A'; // +26 ensures positive value
        }
    }
}

int main() {
    char text[1024];
    int key;
    int choice;

    printf("Welcome to the C Encryption Program!\n");
    printf("You can encrypt and decrypt messages using a Caesar cipher.\n");
    
    printf("Enter your message (up to 1023 characters): ");
    fgets(text, sizeof(text), stdin);
    
    // Remove the newline character if present
    text[strcspn(text, "\n")] = 0;

    printf("Enter the encryption key (0-25): ");
    scanf("%d", &key);

    // Validate the key
    if (key < 0 || key > 25) {
        printf("Invalid key! Please enter a key between 0 and 25.\n");
        return 1;
    }

    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Perform the chosen operation
    switch (choice) {
        case 1:
            printf("Original Text: %s\n", text);
            encrypt(text, key);
            printf("Encrypted Text: %s\n", text);
            break;
        case 2:
            printf("Original Text: %s\n", text);
            decrypt(text, key);
            printf("Decrypted Text: %s\n", text);
            break;
        default:
            printf("Invalid choice! Please restart the program and choose 1 or 2.\n");
            return 1;
    }

    printf("Thank you for using the C Encryption Program!\n");
    return 0;
}