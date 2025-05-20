//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define OFFSET 5  // Simple shift for character encryption

void encrypt(char *input, char *output) {
    int i, len = strlen(input);
    for (i = 0; i < len; i++) {
        // Encrypt only alphabetic characters
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = 'a' + (input[i] - 'a' + OFFSET) % 26;
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = 'A' + (input[i] - 'A' + OFFSET) % 26;
        } else {
            output[i] = input[i]; // Non-alphabetic characters unchanged
        }
    }
    output[len] = '\0'; // Null-terminate output string
}

void decrypt(char *input, char *output) {
    int i, len = strlen(input);
    for (i = 0; i < len; i++) {
        // Decrypt only alphabetic characters
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = 'a' + (input[i] - 'a' - OFFSET + 26) % 26; // +26 to ensure positive value
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = 'A' + (input[i] - 'A' - OFFSET + 26) % 26;
        } else {
            output[i] = input[i]; // Non-alphabetic characters unchanged
        }
    }
    output[len] = '\0'; // Null-terminate output string
}

void print_menu() {
    printf("\nSimple C Encryption Program\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
}

int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_INPUT_SIZE];
    int choice;

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter message to encrypt: ");
                fgets(input, MAX_INPUT_SIZE, stdin);
                // Remove trailing newline
                input[strcspn(input, "\n")] = '\0'; 
                encrypt(input, output);
                printf("Encrypted message: %s\n", output);
                break;

            case 2:
                printf("Enter message to decrypt: ");
                fgets(input, MAX_INPUT_SIZE, stdin);
                // Remove trailing newline
                input[strcspn(input, "\n")] = '\0';
                decrypt(input, output);
                printf("Decrypted message: %s\n", output);
                break;

            case 3:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0; // Return success
}