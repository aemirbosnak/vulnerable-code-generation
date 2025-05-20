//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHIFT_FACTOR 4     // Define the shift factor for encryption
#define MAX_LENGTH 256     // Define max length for the string input

// Function prototypes
void encryptMessage(char *message, int shift);
void decryptMessage(char *message, int shift);
void printMenu();

int main() {
    char message[MAX_LENGTH];
    int choice;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(message, MAX_LENGTH, stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character
                encryptMessage(message, SHIFT_FACTOR);
                printf("Encrypted Message: %s\n", message);
                break;
            case 2:
                printf("Enter the message to decrypt: ");
                fgets(message, MAX_LENGTH, stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character
                decryptMessage(message, SHIFT_FACTOR);
                printf("Decrypted Message: %s\n", message);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}

// Function to encrypt the message using a simple shifting algorithm
void encryptMessage(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] += shift; // Shift character by the shift factor
    }
}

// Function to decrypt the message using the inverse of the shift
void decryptMessage(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        message[i] -= shift; // Shift character backward by the shift factor
    }
}

// Function to print the menu
void printMenu() {
    printf("===== Simple Encryption Program =====\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("=====================================\n");
}