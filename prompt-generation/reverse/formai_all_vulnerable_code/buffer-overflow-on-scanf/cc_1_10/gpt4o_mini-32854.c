//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a message using Caesar cipher
void encryptMessage(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char c = message[i];
        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            message[i] = (c + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            message[i] = (c + shift - 'a') % 26 + 'a';
        }
        // Non-alphabetic characters remain unchanged
    }
}

// Function to decrypt a message using Caesar cipher
void decryptMessage(char *message, int shift) {
    // To decrypt, we just shift back by the same amount
    encryptMessage(message, 26 - shift);
}

// Function to get shift value with input validation
int getShift() {
    int shift;
    printf("Enter shift value (1-25): ");
    while (1) {
        scanf("%d", &shift);
        if (shift >= 1 && shift <= 25) {
            break;
        } else {
            printf("Invalid input. Please enter a value between 1 and 25: ");
        }
    }
    return shift;
}

// Function to get a message from the user
void getMessage(char *message, int maxLength) {
    printf("Enter the message (max %d characters): ", maxLength - 1);
    getchar(); // Clear buffer
    fgets(message, maxLength, stdin);
    // Remove newline character if present
    size_t len = strlen(message);
    if (len > 0 && message[len - 1] == '\n') {
        message[len - 1] = '\0';
    }
}

// Function to display the menu and return the user's choice
int displayMenu() {
    int choice;
    printf("\n--- Caesar Cipher Menu ---\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Please choose an option (1-3): ");
    scanf("%d", &choice);
    return choice;
}

// Main function to run the program
int main() {
    char message[256];
    int shift, choice;

    while (1) {
        choice = displayMenu();

        switch (choice) {
            case 1: // Encrypt
                shift = getShift();
                getMessage(message, sizeof(message));
                encryptMessage(message, shift);
                printf("Encrypted Message: %s\n", message);
                break;

            case 2: // Decrypt
                shift = getShift();
                getMessage(message, sizeof(message));
                decryptMessage(message, shift);
                printf("Decrypted Message: %s\n", message);
                break;

            case 3: // Exit
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid selection. Please choose again.\n");
        }
    }
    
    return 0;
}