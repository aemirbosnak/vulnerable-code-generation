//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

void encrypt(char *input, char *output, int key);
void decrypt(char *input, char *output, int key);
void showMenu();

int main() {
    int choice, key;
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];

    showMenu();

    while (1) {
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter a key for encryption: ");
                scanf("%d", &key);
                getchar();  // Consume newline character
                printf("Enter the string to encrypt: ");
                fgets(input, MAX_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0;  // Remove newline character
                encrypt(input, output, key);
                printf("Encrypted message: %s\n", output);
                break;

            case 2:
                printf("Enter a key for decryption: ");
                scanf("%d", &key);
                getchar();  // Consume newline character
                printf("Enter the string to decrypt: ");
                fgets(input, MAX_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0;  // Remove newline character
                decrypt(input, output, key);
                printf("Decrypted message: %s\n", output);
                break;

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

void encrypt(char *input, char *output, int key) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A'; // check if lowercase or uppercase
            output[i] = (ch - base + key) % 26 + base;
        } else {
            output[i] = ch; // Non-alphabet character remains unchanged
        }
    }
    output[i] = '\0'; // Null-terminate the output string
}

void decrypt(char *input, char *output, int key) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A'; // check if lowercase or uppercase
            output[i] = (ch - base - key + 26) % 26 + base; // Adding 26 to avoid negative values
        } else {
            output[i] = ch; // Non-alphabet character remains unchanged
        }
    }
    output[i] = '\0'; // Null-terminate the output string
}

void showMenu() {
    printf("Welcome to the Sherlock Holmes Encryption and Decryption Utility!\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
}