//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

// Function to encrypt a string using a simple Caesar Cipher
void encrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + key) % 26 + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + key) % 26 + 'A';
        }
    }
}

// Function to decrypt a string using a simple Caesar Cipher
void decrypt(char *text, int key) {
    encrypt(text, 26 - key);  // Decrypting is encryption in reverse
}

// Function to get user input safely
void getInput(char *buffer, size_t length) {
    printf("Enter a string to encrypt (max %zu characters): ", length - 1);
    if (fgets(buffer, length, stdin) != NULL) {
        // Remove newline character if it exists
        buffer[strcspn(buffer, "\n")] = 0; 
    }
}

// Function to display menu for user interaction
void displayMenu() {
    printf("\n--- C Encryption Program ---\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("----------------------------\n");
}

// Main function which drives the program
int main() {
    char message[MAX_LEN];
    int key, choice;

    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar();  // Clear newline after choice input

        switch (choice) {
            case 1:
                printf("Enter the shift key (1-25): ");
                scanf("%d", &key);
                getchar();  // Clear newline
                if (key < 1 || key > 25) {
                    printf("Invalid key. Please enter a value between 1 and 25.\n");
                    break;
                }
                getInput(message, sizeof(message));
                encrypt(message, key);
                printf("Encrypted message: %s\n", message);
                break;

            case 2:
                printf("Enter the shift key (1-25): ");
                scanf("%d", &key);
                getchar();  // Clear newline
                if (key < 1 || key > 25) {
                    printf("Invalid key. Please enter a value between 1 and 25.\n");
                    break;
                }
                getInput(message, sizeof(message));
                decrypt(message, key);
                printf("Decrypted message: %s\n", message);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid option. Please choose a valid menu item.\n");
                break;
        }
    }

    return 0;
}