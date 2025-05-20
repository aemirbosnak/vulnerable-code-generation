//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for encryption
#define SHIFT 4
#define MAXLEN 100

// Function prototypes
void encrypt(char *input, char *output);
void decrypt(char *input, char *output);
void displayMenu();

int main() {
    char input[MAXLEN];
    char output[MAXLEN];
    int choice;

    // Infinite loop until user decides to exit
    while (1) {
        displayMenu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar(); // consume the newline character after input

        switch (choice) {
            case 1:
                printf("Enter text to encrypt: ");
                fgets(input, MAXLEN, stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline character
                encrypt(input, output);
                printf("Encrypted text: %s\n", output);
                break;
            case 2:
                printf("Enter text to decrypt: ");
                fgets(input, MAXLEN, stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline character
                decrypt(input, output);
                printf("Decrypted text: %s\n", output);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}

void encrypt(char *input, char *output) {
    int i;
    for (i = 0; input[i] != '\0' && i < MAXLEN; i++) {
        // Simple caesar cipher shifting by 'SHIFT' characters
        if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = (input[i] - 'A' + SHIFT) % 26 + 'A';
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = (input[i] - 'a' + SHIFT) % 26 + 'a';
        } else {
            output[i] = input[i]; // Non-alphabet characters are unchanged
        }
    }
    output[i] = '\0'; // Null-terminate the output string
}

void decrypt(char *input, char *output) {
    int i;
    for (i = 0; input[i] != '\0' && i < MAXLEN; i++) {
        // Simple caesar cipher shifting back by 'SHIFT' characters
        if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = (input[i] - 'A' - SHIFT + 26) % 26 + 'A';
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = (input[i] - 'a' - SHIFT + 26) % 26 + 'a';
        } else {
            output[i] = input[i]; // Non-alphabet characters are unchanged
        }
    }
    output[i] = '\0'; // Null-terminate the output string
}

void displayMenu() {
    printf("\n--- Simple C Encryption Program ---\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");
}