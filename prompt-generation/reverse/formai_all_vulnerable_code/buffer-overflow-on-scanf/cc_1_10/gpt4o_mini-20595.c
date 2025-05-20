//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_MESSAGE_LENGTH 1024
#define SHIFT 3

void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char c = message[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            message[i] = (c - base + shift) % 26 + base;
        }
    }
}

void decrypt(char *message, int shift) {
    encrypt(message, 26 - (shift % 26));
}

void getInput(char *buffer, int length) {
    printf("Enter your message (max %d characters): ", length - 1);
    fgets(buffer, length, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
}

void displayMenu() {
    printf("\nCryptography Tool\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // clear the newline character from the input buffer

        switch (choice) {
            case 1:
                printf("You chose to encrypt a message.\n");
                getInput(message, MAX_MESSAGE_LENGTH);
                encrypt(message, SHIFT);
                printf("Encrypted message: %s\n", message);
                break;
                
            case 2:
                printf("You chose to decrypt a message.\n");
                getInput(message, MAX_MESSAGE_LENGTH);
                decrypt(message, SHIFT);
                printf("Decrypted message: %s\n", message);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 3);
    
    return 0;
}