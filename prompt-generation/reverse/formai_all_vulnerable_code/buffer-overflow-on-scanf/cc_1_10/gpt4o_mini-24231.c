//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char current = text[i];

        if (current >= 'a' && current <= 'z') {
            text[i] = (current - 'a' + shift) % 26 + 'a';
        } else if (current >= 'A' && current <= 'Z') {
            text[i] = (current - 'A' + shift) % 26 + 'A';
        }
        // Non-alphabetic characters remain unchanged
    }
}

void decrypt(char *text, int shift) {
    encrypt(text, 26 - (shift % 26)); // Decrypting is just encrypting with the negative shift
}

void display_menu() {
    printf("\n--- Simple Caesar Cipher ---\n");
    printf("1. Encrypt text\n");
    printf("2. Decrypt text\n");
    printf("3. Exit\n");
    printf("----------------------------\n");
}

int main() {
    char text[256];
    int choice, shift;

    while (1) {
        display_menu();
        printf("Select an option: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting the program.\n");
            break;
        }

        printf("Enter the text (max 255 characters): ");
        getchar(); // Clear the newline character after scanf
        fgets(text, sizeof(text), stdin);
        
        // Remove newline character from fgets
        size_t len = strlen(text);
        if (len > 0 && text[len - 1] == '\n') {
            text[len - 1] = '\0';
        }

        printf("Enter shift value (1-25): ");
        scanf("%d", &shift);
        
        // Ensure valid shift value
        if (shift < 1 || shift > 25) {
            printf("Invalid shift value! Please enter a value between 1 and 25.\n");
            continue;
        }

        switch (choice) {
            case 1:
                encrypt(text, shift);
                printf("Encrypted text: %s\n", text);
                break;
            case 2:
                decrypt(text, shift);
                printf("Decrypted text: %s\n", text);
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }

    return 0;
}