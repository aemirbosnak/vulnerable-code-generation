//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 256

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isalpha(c)) {
            char offset = isupper(c) ? 'A' : 'a';
            text[i] = (c - offset + shift) % 26 + offset;
        }
    }
}

void decrypt(char *text, int shift) {
    encrypt(text, 26 - shift);
}

void get_user_input(char *input, int max_size) {
    printf("Enter your secret message: ");
    fgets(input, max_size, stdin);
    // Remove newline character
    input[strcspn(input, "\n")] = 0;
}

void display_menu() {
    printf("\n======================\n");
    printf(" Welcome to the Fun Cipher!\n");
    printf("======================\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("======================\n");
}

int main() {
    char message[MAX_SIZE];
    int choice, shift;

    printf("Welcome to the Fun Cipher Program!\n");
    
    do {
        display_menu();
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);
        getchar(); // Consume the newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter the shift amount (1-25): ");
                scanf("%d", &shift);
                getchar(); // Consume the newline

                if (shift < 1 || shift > 25) {
                    printf("Invalid shift! Please choose between 1 and 25.\n");
                    continue;
                }

                get_user_input(message, MAX_SIZE);
                encrypt(message, shift);
                printf("Encrypted message: %s\n", message);
                break;

            case 2:
                printf("Enter the shift amount (1-25): ");
                scanf("%d", &shift);
                getchar(); // Consume the newline

                if (shift < 1 || shift > 25) {
                    printf("Invalid shift! Please choose between 1 and 25.\n");
                    continue;
                }

                get_user_input(message, MAX_SIZE);
                decrypt(message, shift);
                printf("Decrypted message: %s\n", message);
                break;

            case 3:
                printf("Exiting... Have a great day!\n");
                break;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }

    } while (choice != 3);

    return 0;
}