//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

void encrypt(char *input, char *output, int key) {
    for (int i = 0; i < strlen(input); i++) {
        output[i] = input[i] + key; // Simple Caesar Cipher
    }
    output[strlen(input)] = '\0'; // Null-terminate the string
}

void decrypt(char *input, char *output, int key) {
    for (int i = 0; i < strlen(input); i++) {
        output[i] = input[i] - key; // Reverse the Caesar Cipher
    }
    output[strlen(input)] = '\0'; // Null-terminate the string
}

void display_menu() {
    printf("=== Simple Encryption Program ===\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

int main() {
    char input[MAX_LEN];
    char output[MAX_LEN];
    int choice, key;

    while (1) {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // flush the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                getchar(); // Consume newline
                fgets(input, MAX_LEN, stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline
                printf("Enter encryption key (a number): ");
                if (scanf("%d", &key) != 1) {
                    fprintf(stderr, "Invalid key. Please enter a number.\n");
                    continue;
                }
                encrypt(input, output, key);
                printf("Encrypted message: %s\n", output);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                getchar(); // Consume newline
                fgets(input, MAX_LEN, stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline
                printf("Enter decryption key (a number): ");
                if (scanf("%d", &key) != 1) {
                    fprintf(stderr, "Invalid key. Please enter a number.\n");
                    continue;
                }
                decrypt(input, output, key);
                printf("Decrypted message: %s\n", output);
                break;

            case 3:
                printf("Exiting the program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    }
    return 0;
}