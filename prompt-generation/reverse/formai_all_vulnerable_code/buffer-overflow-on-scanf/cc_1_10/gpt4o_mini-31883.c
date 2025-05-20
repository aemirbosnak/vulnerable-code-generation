//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' + shift) % 26 + 'A';
        } else if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' + shift) % 26 + 'a';
        }
    }
}

void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' - shift + 26) % 26 + 'A'; // + 26 to handle negative mod
        } else if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' - shift + 26) % 26 + 'a'; // + 26 to handle negative mod
        }
    }
}

void display_menu() {
    printf("Welcome to the Caesar Cipher Program!\n");
    printf("Please choose an option:\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
}

int main() {
    int choice, shift;
    char text[256];

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Thank you for using the Caesar Cipher Program. Goodbye!\n");
            break;
        }

        printf("Enter the shift value (1-25): ");
        scanf("%d", &shift);
        if (shift < 1 || shift > 25) {
            printf("Invalid shift value. Please try again.\n");
            continue;
        }

        printf("Enter your message: ");
        getchar(); // To consume the newline character left in buffer
        fgets(text, sizeof(text), stdin);
        // Remove newline character from input
        text[strcspn(text, "\n")] = '\0';

        if (choice == 1) {
            encrypt(text, shift);
            printf("Encrypted message: %s\n\n", text);
        } else if (choice == 2) {
            decrypt(text, shift);
            printf("Decrypted message: %s\n\n", text);
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}