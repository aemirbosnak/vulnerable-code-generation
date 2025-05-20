//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define COLOR_RESET "\033[0m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_CYAN "\033[36m"

void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];
        if (ch >= 'a' && ch <= 'z') {
            message[i] = (ch - 'a' + shift) % 26 + 'a'; // Shift lowercase letters
        } else if (ch >= 'A' && ch <= 'Z') {
            message[i] = (ch - 'A' + shift) % 26 + 'A'; // Shift uppercase letters
        }
    }
}

void decrypt(char *message, int shift) {
    encrypt(message, 26 - shift); // To decrypt, shift backwards
}

int main() {
    char message[MAX_LENGTH];
    int shift;
    int choice;

    printf(COLOR_CYAN "\nWelcome to the Artistic Caesar Cipher!\n" COLOR_RESET);
    printf(COLOR_YELLOW "Select an option:\n" COLOR_RESET);
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");

    while (1) {
        printf(COLOR_GREEN "\nEnter your choice: " COLOR_RESET);
        scanf("%d", &choice);

        if (choice == 3) {
            printf(COLOR_CYAN "Exiting the program. Goodbye!\n" COLOR_RESET);
            break;
        }

        printf(COLOR_GREEN "Enter the message: " COLOR_RESET);
        getchar(); // To consume the newline character
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = 0; // Remove newline character

        printf(COLOR_GREEN "Enter the shift value (1-25): " COLOR_RESET);
        scanf("%d", &shift);

        if (shift < 1 || shift > 25) {
            printf(COLOR_YELLOW "Shift value must be between 1 and 25.\n" COLOR_RESET);
            continue;
        }

        if (choice == 1) {
            encrypt(message, shift);
            printf(COLOR_CYAN "Encrypted message: " COLOR_RESET "%s\n", message);
        } else if (choice == 2) {
            decrypt(message, shift);
            printf(COLOR_CYAN "Decrypted message: " COLOR_RESET "%s\n", message);
        } else {
            printf(COLOR_YELLOW "Invalid choice! Please select again.\n" COLOR_RESET);
        }
    }

    return 0;
}