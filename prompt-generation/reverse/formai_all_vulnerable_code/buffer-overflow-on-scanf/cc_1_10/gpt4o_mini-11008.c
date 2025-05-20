//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char c = text[i];
        
        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            text[i] = (c + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            text[i] = (c + shift - 'a') % 26 + 'a';
        }
        // Non-letter characters remain unchanged
    }
}

void decrypt(char *text, int shift) {
    // Decrypting is just shifting backwards
    encrypt(text, 26 - shift);
}

void display_menu() {
    printf("\n*** Welcome to the Caesar Cipher Program! ***\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    char text[MAX_LEN];
    int shift;
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a message to encrypt: ");
                getchar(); // To consume the newline character
                fgets(text, MAX_LEN, stdin);
                // Remove newline character from the input string
                text[strcspn(text, "\n")] = 0;

                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);

                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Please enter a value between 1 and 25.\n");
                    break;
                }

                encrypt(text, shift);
                printf("Encrypted message: %s\n\n", text);
                break;

            case 2:
                printf("Enter a message to decrypt: ");
                getchar(); // To consume the newline character
                fgets(text, MAX_LEN, stdin);
                // Remove newline character from the input string
                text[strcspn(text, "\n")] = 0;

                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);

                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Please enter a value between 1 and 25.\n");
                    break;
                }

                decrypt(text, shift);
                printf("Decrypted message: %s\n\n", text);
                break;

            case 3:
                printf("Exiting the program. Thank you for using the Caesar Cipher!\n");
                return 0;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}