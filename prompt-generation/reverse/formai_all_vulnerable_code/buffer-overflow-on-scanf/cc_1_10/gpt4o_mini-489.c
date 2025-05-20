//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        // Encrypt uppercase letters
        if (isupper(message[i])) {
            message[i] = (message[i] + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(message[i])) {
            message[i] = (message[i] + shift - 'a') % 26 + 'a';
        }
        // Non-alphabetical characters remain unchanged
    }
}

void decrypt(char *message, int shift) {
    // To decrypt, we simply apply the negative shift
    encrypt(message, 26 - (shift % 26));
}

void display_menu() {
    printf("Caesar Cipher Encryption & Decryption\n");
    printf("---------------------------------------\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Choose an option (1-3): ");
}

int main() {
    char message[256];
    int shift;
    int option;

    while (1) {
        display_menu();
        scanf("%d", &option);

        // Handle exit condition
        if (option == 3) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        // Validate option
        if (option < 1 || option > 2) {
            printf("Invalid option! Please try again.\n");
            continue;
        }

        printf("Enter your message: ");
        getchar(); // To consume leftover newline from previous input
        fgets(message, sizeof(message), stdin);
        // Remove newline character from fgets
        message[strcspn(message, "\n")] = 0;

        printf("Enter the shift value: ");
        scanf("%d", &shift);

        if (option == 1) {
            encrypt(message, shift);
            printf("Encrypted message: %s\n", message);
        } else if (option == 2) {
            decrypt(message, shift);
            printf("Decrypted message: %s\n", message);
        }

        printf("\n");
    }

    return 0;
}