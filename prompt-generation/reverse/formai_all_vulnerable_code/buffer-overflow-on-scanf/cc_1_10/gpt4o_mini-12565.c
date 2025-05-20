//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 1000

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            text[i] = (c - base + shift) % 26 + base;
        }
    }
}

void decrypt(char *text, int shift) {
    encrypt(text, 26 - (shift % 26));  // Decryption is just encryption with a reversed shift
}

int main() {
    char text[MAX_TEXT_LENGTH];
    int shift;
    char choice;

    printf("Welcome to the Energetic Caesar Cipher Program!\n");
    printf("Let's encrypt and decrypt your messages with style!\n");

    while (1) {
        printf("\nPlease choose:\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit the program\n");
        printf("Enter your choice (1/2/3): ");
        scanf(" %c", &choice);  // Space before %c to consume any newline character
        
        switch (choice) {
            case '1':
                printf("Enter the message to encrypt: ");
                getchar();  // To consume newline after choice
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = 0;  // Remove newline character
                
                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);
                
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Must be between 1 and 25.\n");
                } else {
                    encrypt(text, shift);
                    printf("Encrypted message: %s\n", text);
                }
                break;

            case '2':
                printf("Enter the message to decrypt: ");
                getchar();  // To consume newline after choice
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = 0;  // Remove newline character

                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);
                
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Must be between 1 and 25.\n");
                } else {
                    decrypt(text, shift);
                    printf("Decrypted message: %s\n", text);
                }
                break;

            case '3':
                printf("Thank you for using the Energetic Caesar Cipher Program! Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    }
    return 0;
}