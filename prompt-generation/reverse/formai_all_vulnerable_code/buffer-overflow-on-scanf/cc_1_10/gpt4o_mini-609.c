//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char base = 'A';
        if (text[i] >= 'a' && text[i] <= 'z') {
            base = 'a';
        }
        if (text[i] >= 'a' && text[i] <= 'z' || text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - base + shift) % 26 + base;
        }
    }
}

void decrypt(char *text, int shift) {
    encrypt(text, 26 - shift); // Decrypting is just encrypting with (26 - shift)
}

void menu() {
    printf("\n--- Caesar Cipher Encryption/Decryption ---\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Please choose an option (1-3): ");
}

int main() {
    char text[256];
    int choice, shift;

    while (1) {
        menu();
        scanf("%d", &choice);
        
        if (choice == 3) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
        
        if (choice < 1 || choice > 2) {
            printf("Invalid choice. Please select again.\n");
            continue;
        }

        printf("Enter the shift amount (0-25): ");
        scanf("%d", &shift);
        
        // Ensure shift is within bounds
        if (shift < 0 || shift > 25) {
            printf("Shift must be between 0 and 25. Please try again.\n");
            continue;
        }

        printf("Enter the message: ");
        getchar();  // Clear the newline character from the input buffer
        fgets(text, sizeof(text), stdin);
        
        // Removing the newline character from fgets
        text[strcspn(text, "\n")] = '\0'; 

        if (choice == 1) {
            encrypt(text, shift);
            printf("Encrypted message: %s\n", text);
        } else if (choice == 2) {
            decrypt(text, shift);
            printf("Decrypted message: %s\n", text);
        }
    }

    return 0;
}