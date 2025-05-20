//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 5
#define MAX_LEN 1024

void encrypt(char *input, char *output) {
    while (*input) {
        // Shift characters by KEY
        if (*input >= 'A' && *input <= 'Z') {
            *output = ((*input - 'A' + KEY) % 26) + 'A'; 
        } else if (*input >= 'a' && *input <= 'z') {
            *output = ((*input - 'a' + KEY) % 26) + 'a';
        } else {
            *output = *input; // Non-alphabetic characters remain unchanged
        }
        input++;
        output++;
    }
    *output = '\0'; // Null-terminate the output string
}

void decrypt(char *input, char *output) {
    while (*input) {
        // Reverse the key shift
        if (*input >= 'A' && *input <= 'Z') {
            *output = ((*input - 'A' - KEY + 26) % 26) + 'A';
        } else if (*input >= 'a' && *input <= 'z') {
            *output = ((*input - 'a' - KEY + 26) % 26) + 'a';
        } else {
            *output = *input; // Non-alphabetic characters remain unchanged
        }
        input++;
        output++;
    }
    *output = '\0'; // Null-terminate the output string
}

void print_menu() {
    printf("Menu:\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");
    printf("Choose an option (1-3): ");
}

int main() {
    char input[MAX_LEN];
    char output[MAX_LEN];
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter text to encrypt: ");
                fgets(input, MAX_LEN, stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline character
                encrypt(input, output);
                printf("Encrypted text: %s\n", output);
                break;
            case 2:
                printf("Enter text to decrypt: ");
                fgets(input, MAX_LEN, stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline character
                decrypt(input, output);
                printf("Decrypted text: %s\n", output);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}