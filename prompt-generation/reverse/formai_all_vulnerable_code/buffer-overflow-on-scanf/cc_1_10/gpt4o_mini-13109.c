//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TEXT_LEN 256

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }
        text[i] = ch;
    }
}

void decrypt(char *text, int shift) {
    // Call encrypt with negative shift
    encrypt(text, 26 - (shift % 26));
}

int main() {
    char text[MAX_TEXT_LEN];
    int shift;
    int choice;
    
    printf("Welcome to the Simple Caesar Cipher Encryption Program!\n");
    
    do {
        printf("\nMenu:\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar(); // Consume newline character after choice
        
        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(text, MAX_TEXT_LEN, stdin);
                text[strcspn(text, "\n")] = 0; // Remove newline character
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value. Please enter a number between 1 and 25.\n");
                } else {
                    encrypt(text, shift);
                    printf("Encrypted message: %s\n", text);
                }
                break;
                
            case 2:
                printf("Enter the message to decrypt: ");
                fgets(text, MAX_TEXT_LEN, stdin);
                text[strcspn(text, "\n")] = 0; // Remove newline character
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value. Please enter a number between 1 and 25.\n");
                } else {
                    decrypt(text, shift);
                    printf("Decrypted message: %s\n", text);
                }
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please select from the menu options.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}