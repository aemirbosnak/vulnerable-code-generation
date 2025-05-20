//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

// Function prototypes
void encrypt(char *text, int shift);
void decrypt(char *text, int shift);
void clear_input_buffer();

int main() {
    char text[MAX_LENGTH];
    int shift;
    int choice;

    while (1) {
        printf("\nCaesar Cipher Encryption Program\n");
        printf("1. Encrypt Text\n");
        printf("2. Decrypt Text\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer(); // Clear input buffer to handle string input after int

        switch (choice) {
            case 1:
                printf("Enter text to encrypt: ");
                fgets(text, MAX_LENGTH, stdin);
                text[strcspn(text, "\n")] = '\0'; // Remove trailing newline
                printf("Enter shift value: ");
                scanf("%d", &shift);
                clear_input_buffer();
                encrypt(text, shift);
                printf("Encrypted text: %s\n", text);
                break;

            case 2:
                printf("Enter text to decrypt: ");
                fgets(text, MAX_LENGTH, stdin);
                text[strcspn(text, "\n")] = '\0'; // Remove trailing newline
                printf("Enter shift value: ");
                scanf("%d", &shift);
                clear_input_buffer();
                decrypt(text, shift);
                printf("Decrypted text: %s\n", text);
                break;

            case 3:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}

// Function to encrypt the text using Caesar Cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char current = text[i];

        if (current >= 'A' && current <= 'Z') {
            text[i] = (current - 'A' + shift) % 26 + 'A';
        } else if (current >= 'a' && current <= 'z') {
            text[i] = (current - 'a' + shift) % 26 + 'a';
        }
        // Non-alphabetic characters are unchanged
    }
}

// Function to decrypt the text using Caesar Cipher
void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char current = text[i];

        if (current >= 'A' && current <= 'Z') {
            text[i] = (current - 'A' - shift + 26) % 26 + 'A'; // +26 for correct wrap-around
        } else if (current >= 'a' && current <= 'z') {
            text[i] = (current - 'a' - shift + 26) % 26 + 'a'; // +26 for correct wrap-around
        }
        // Non-alphabetic characters are unchanged
    }
}

// Function to clear the input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}