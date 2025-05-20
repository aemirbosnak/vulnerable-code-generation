//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: retro
#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];
        if (ch >= 'a' && ch <= 'z') {
            message[i] = 'a' + (ch - 'a' + shift) % 26;
        } else if (ch >= 'A' && ch <= 'Z') {
            message[i] = 'A' + (ch - 'A' + shift) % 26;
        }
    }
}

void decrypt(char *message, int shift) {
    // Decrypt by shifting negatively
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];
        if (ch >= 'a' && ch <= 'z') {
            message[i] = 'a' + (ch - 'a' - shift + 26) % 26;
        } else if (ch >= 'A' && ch <= 'Z') {
            message[i] = 'A' + (ch - 'A' - shift + 26) % 26;
        }
    }
}

void showMenu() {
    printf("*********************************\n");
    printf("          CAESAR CIPHER          \n");
    printf("*********************************\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    char message[MAX_LEN];
    int shift, choice;

    while (1) {
        showMenu();
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the buffer

        if (choice == 1) {
            printf("Enter the message to encrypt: ");
            fgets(message, MAX_LEN, stdin);
            message[strcspn(message, "\n")] = 0; // Remove the newline

            printf("Enter shift value: ");
            scanf("%d", &shift);

            encrypt(message, shift);
            printf("Encrypted Message: %s\n", message);
        } else if (choice == 2) {
            printf("Enter the message to decrypt: ");
            fgets(message, MAX_LEN, stdin);
            message[strcspn(message, "\n")] = 0; // Remove the newline

            printf("Enter shift value: ");
            scanf("%d", &shift);

            decrypt(message, shift);
            printf("Decrypted Message: %s\n", message);
        } else if (choice == 3) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please enter again.\n");
        }
    }

    return 0;
}