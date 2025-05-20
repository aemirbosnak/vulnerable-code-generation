//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

void encrypt(char *str, int shift) {
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];

        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            str[i] = (c - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            str[i] = (c - 'a' + shift) % 26 + 'a';
        }
    }
}

void decrypt(char *str, int shift) {
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];

        // Decrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            str[i] = (c - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            str[i] = (c - 'a' - shift + 26) % 26 + 'a';
        }
    }
}

int main() {
    char input[MAX_LEN];
    int shift;
    int choice;

    printf("Welcome to the Caesar Cipher Program!\n");
    printf("Please enter the text you want to encrypt: ");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline

    printf("Enter a shift value (1-25): ");
    scanf("%d", &shift);
    shift = shift % 26; // Ensure shift is within 0-25

    while (1) {
        printf("\nOptions:\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("3. Exit\n");
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Original text: %s\n", input);
                encrypt(input, shift);
                printf("Encrypted text: %s\n", input);
                break;
            case 2:
                printf("Encrypted text: %s\n", input);
                decrypt(input, shift);
                printf("Decrypted text: %s\n", input);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}