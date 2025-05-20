//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024
#define KEY_LENGTH 26

void displayMenu() {
    printf("\n--- Caesar Cipher Encryption Program ---\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("----------------------------------------\n");
}

void encryptMessage(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + shift) % KEY_LENGTH + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + shift) % KEY_LENGTH + 'a';
        }
    }
}

void decryptMessage(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' - shift + KEY_LENGTH) % KEY_LENGTH + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' - shift + KEY_LENGTH) % KEY_LENGTH + 'a';
        }
    }
}

int main() {
    char text[MAX_TEXT_LENGTH];
    int choice, shift;
    
    printf("Welcome to the Caesar Cipher program!\n");

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = 0; // Remove newline character

                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);

                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Please enter a value between 1 and 25.\n");
                } else {
                    encryptMessage(text, shift);
                    printf("Encrypted message: %s\n", text);
                }
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = 0; // Remove newline character

                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);

                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Please enter a value between 1 and 25.\n");
                } else {
                    decryptMessage(text, shift);
                    printf("Decrypted message: %s\n", text);
                }
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid option! Please select a valid choice.\n");
        }
    } while (choice != 3);
    
    return 0;
}