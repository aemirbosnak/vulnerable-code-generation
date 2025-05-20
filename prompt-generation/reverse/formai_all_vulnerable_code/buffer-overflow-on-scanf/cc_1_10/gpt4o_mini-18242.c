//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 256
#define SHIFT 4 // Shift value for a futuristic Caesar Cipher
#define ALPHA_SIZE 26

void encrypt(char *input, char *output) {
    int i, shifted_char;

    for (i = 0; i < strlen(input); i++) {
        // Process only alphabetic characters
        if (input[i] >= 'A' && input[i] <= 'Z') {
            shifted_char = ((input[i] - 'A' + SHIFT) % ALPHA_SIZE) + 'A';
            output[i] = shifted_char;
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            shifted_char = ((input[i] - 'a' + SHIFT) % ALPHA_SIZE) + 'a';
            output[i] = shifted_char;
        } else {
            output[i] = input[i]; // Non-alphabet characters remain unchanged
        }
    }
    output[i] = '\0'; // Null-terminating the encrypted string
}

void decrypt(char *input, char *output) {
    int i, shifted_char;

    for (i = 0; i < strlen(input); i++) {
        // Process only alphabetic characters
        if (input[i] >= 'A' && input[i] <= 'Z') {
            shifted_char = ((input[i] - 'A' - SHIFT + ALPHA_SIZE) % ALPHA_SIZE) + 'A';
            output[i] = shifted_char;
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            shifted_char = ((input[i] - 'a' - SHIFT + ALPHA_SIZE) % ALPHA_SIZE) + 'a';
            output[i] = shifted_char;
        } else {
            output[i] = input[i]; // Non-alphabet characters remain unchanged
        }
    }
    output[i] = '\0'; // Null-terminating the decrypted string
}

void display_menu() {
    printf("=== Futuristic Encryption System ===\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("====================================\n");
}

int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_INPUT_SIZE];
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left in input buffer

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(input, MAX_INPUT_SIZE, stdin);
                // Remove newline character if present
                input[strcspn(input, "\n")] = '\0';
                encrypt(input, output);
                printf("Encrypted Message: %s\n", output);
                break;
            case 2:
                printf("Enter the message to decrypt: ");
                fgets(input, MAX_INPUT_SIZE, stdin);
                // Remove newline character if present
                input[strcspn(input, "\n")] = '\0';
                decrypt(input, output);
                printf("Decrypted Message: %s\n", output);
                break;
            case 3:
                printf("Exiting the system. Stay safe in the digital universe!\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
        printf("\n");
    }

    return 0;
}