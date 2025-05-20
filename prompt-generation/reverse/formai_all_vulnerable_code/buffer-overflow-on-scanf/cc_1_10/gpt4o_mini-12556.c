//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 256

void caesar_cipher(char *input, char *output, int shift) {
    int i;

    for (i = 0; input[i] != '\0'; ++i) {
        char c = input[i];

        if (c >= 'A' && c <= 'Z') {
            output[i] = (c - 'A' + shift) % 26 + 'A';
        } else if (c >= 'a' && c <= 'z') {
            output[i] = (c - 'a' + shift) % 26 + 'a';
        } else {
            output[i] = c; // Non-alphabetic characters remain unchanged
        }
    }
    output[i] = '\0'; // Null terminate the output string.
}

void caesar_decipher(char *input, char *output, int shift) {
    int i;

    for (i = 0; input[i] != '\0'; ++i) {
        char c = input[i];

        if (c >= 'A' && c <= 'Z') {
            output[i] = (c - 'A' - shift + 26) % 26 + 'A';
        } else if (c >= 'a' && c <= 'z') {
            output[i] = (c - 'a' - shift + 26) % 26 + 'a';
        } else {
            output[i] = c; // Non-alphabetic characters remain unchanged
        }
    }
    output[i] = '\0'; // Null terminate the output string.
}

void display_menu() {
    printf("Caesar Cipher Program\n");
    printf("=====================\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Exit\n");
    printf("=====================\n");
    printf("Please choose an option (1-3): ");
}

int main() {
    char input[BUF_SIZE];
    char output[BUF_SIZE];
    int shift, choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // To consume newline left by scanf

        if (choice == 3) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 3) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        printf("Enter the shift value (0-25): ");
        scanf("%d", &shift);
        getchar(); // To consume newline left by scanf

        if (shift < 0 || shift > 25) {
            printf("Invalid shift value. Please enter a value between 0 and 25.\n");
            continue;
        }

        printf("Enter the input text: ");
        fgets(input, BUF_SIZE, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character from input

        if (choice == 1) {
            caesar_cipher(input, output, shift);
            printf("Encrypted text: %s\n", output);
        } else if (choice == 2) {
            caesar_decipher(input, output, shift);
            printf("Decrypted text: %s\n", output);
        }
    }

    return 0;
}