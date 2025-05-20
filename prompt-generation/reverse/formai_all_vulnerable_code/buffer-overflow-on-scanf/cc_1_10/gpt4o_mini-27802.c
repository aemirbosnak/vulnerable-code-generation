//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        }
    }
}

void decrypt(char *text, int shift) {
    // Decrypting is simply shifting back
    encrypt(text, 26 - shift);
}

int main() {
    char text[MAX_LENGTH];
    int shift;
    int choice;
    
    printf("Welcome to the Grateful Encryption Program!\n");
    printf("Thank you for choosing to secure your messages with us!\n\n");

    while (1) {
        printf("Please select an option:\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume newline after choice input

        switch (choice) {
            case 1:
                printf("\nEnter the message to encrypt: ");
                fgets(text, MAX_LENGTH, stdin);
                text[strcspn(text, "\n")] = '\0'; // Remove trailing newline

                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                getchar(); // To consume newline

                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Please choose between 1-25.\n");
                    continue;
                }

                encrypt(text, shift);
                printf("Encrypted message: %s\n", text);
                printf("Thank you for trusting us with your encryption!\n\n");
                break;

            case 2:
                printf("\nEnter the message to decrypt: ");
                fgets(text, MAX_LENGTH, stdin);
                text[strcspn(text, "\n")] = '\0'; // Remove trailing newline

                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                getchar(); // To consume newline

                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Please choose between 1-25.\n");
                    continue;
                }

                decrypt(text, shift);
                printf("Decrypted message: %s\n", text);
                printf("Thank you for using our decryption service!\n\n");
                break;

            case 0:
                printf("Thank you for using the Grateful Encryption Program! Goodbye!\n");
                exit(0);
            
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
    }

    return 0;
}