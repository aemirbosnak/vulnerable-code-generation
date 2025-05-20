//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 256

void encrypt(char *text, int shift) {
    for (int i = 0; i < strlen(text); i++) {
        char ch = text[i];
        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }
        text[i] = ch; // Replace the original character with the encrypted one
    }
}

void decrypt(char *text, int shift) {
    // To decrypt, we shift the letters back in the reverse direction
    for (int i = 0; i < strlen(text); i++) {
        char ch = text[i];
        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - shift + 26) % 26 + 'A'; // Adding 26 ensures we don't get negative
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - shift + 26) % 26 + 'a'; // Adding 26 ensures we don't get negative
        }
        text[i] = ch; // Replace the original character with the decrypted one
    }
}

void display_menu() {
    printf("\n*** Caesar Cipher Encryption Program ***\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Choose an option (1-3): ");
}

int main() {
    char text[MAX_TEXT_LENGTH];
    int shift, choice;
    
    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        // Handling options
        switch (choice) {
            case 1:
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Please select between 1-25.\n");
                    continue;
                }
                printf("Enter the message to encrypt: ");
                getchar(); // To consume leftover newline character
                fgets(text, MAX_TEXT_LENGTH, stdin);
                text[strcspn(text, "\n")] = 0; // Remove trailing newline
                encrypt(text, shift);
                printf("Encrypted message: %s\n", text);
                break;

            case 2:
                printf("Enter shift value (1-25) for decryption: ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Please select between 1-25.\n");
                    continue;
                }
                printf("Enter the message to decrypt: ");
                getchar(); // To consume leftover newline character
                fgets(text, MAX_TEXT_LENGTH, stdin);
                text[strcspn(text, "\n")] = 0; // Remove trailing newline
                decrypt(text, shift);
                printf("Decrypted message: %s\n", text);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice! Please select between 1-3.\n");
                break;
        }
    }
    
    return 0;
}