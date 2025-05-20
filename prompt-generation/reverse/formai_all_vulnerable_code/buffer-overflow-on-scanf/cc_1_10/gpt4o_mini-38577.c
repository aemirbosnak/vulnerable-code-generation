//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *text, int key) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        text[i] = text[i] + key; // Simple Caesar Cipher
    }
}

void decrypt(char *text, int key) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        text[i] = text[i] - key; // Reversing the Caesar Cipher
    }
}

void basic_menu() {
    printf("\n=== C Encryption Program ===\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");
    printf("===================\n");
}

int main() {
    int choice, key;
    char text[256];

    while (1) {
        basic_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter text to encrypt: ");
                getchar();  // Clear the newline left by scanf
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = 0; // Remove newline character
            
                printf("Enter encryption key (integer): ");
                scanf("%d", &key);
                
                encrypt(text, key);
                printf("Encrypted Text: %s\n\n", text);
                break;

            case 2:
                printf("Enter text to decrypt: ");
                getchar();  // Clear the newline left by scanf
                fgets(text, sizeof(text), stdin);
                text[strcspn(text, "\n")] = 0; // Remove newline character
            
                printf("Enter decryption key (integer): ");
                scanf("%d", &key);
                
                decrypt(text, key);
                printf("Decrypted Text: %s\n\n", text);
                break;

            case 3:
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }
    }

    return 0;
}