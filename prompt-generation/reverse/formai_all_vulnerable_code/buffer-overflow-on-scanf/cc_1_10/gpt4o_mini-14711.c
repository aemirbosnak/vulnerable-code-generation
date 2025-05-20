//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using Caesar Cipher
void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch + shift - 'a') % 26 + 'a';
        }

        message[i] = ch;
    }
}

// Function to decrypt the message using Caesar Cipher
void decrypt(char *message, int shift) {
    // To decrypt, we can just shift in the opposite direction
    encrypt(message, 26 - (shift % 26));
}

// Function to display the menu and get user choice
int displayMenu() {
    int choice;
    printf("*********************\n");
    printf(" Caesar Cipher Menu \n");
    printf("*********************\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to get user input for the message
void getMessage(char *message, int size) {
    printf("Enter your message (max %d characters): ", size - 1);
    getchar();  // Clear the newline character from the input buffer
    fgets(message, size, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline character
}

// Main function
int main() {
    const int MESSAGE_SIZE = 256;
    char message[MESSAGE_SIZE];
    int shift, choice;

    while (1) {
        choice = displayMenu();

        switch (choice) {
            case 1:
                printf("Enter the shift value for encryption: ");
                scanf("%d", &shift);
                getMessage(message, MESSAGE_SIZE);
                encrypt(message, shift);
                printf("Encrypted message: %s\n", message);
                break;

            case 2:
                printf("Enter the shift value for decryption: ");
                scanf("%d", &shift);
                getMessage(message, MESSAGE_SIZE);
                decrypt(message, shift);
                printf("Decrypted message: %s\n", message);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}