//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt the input string using Caesar Cipher
void encrypt(char *input, int shift, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];

        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            output[i] = 'A' + (c - 'A' + shift) % 26;
        // Encrypt lowercase letters
        } else if (c >= 'a' && c <= 'z') {
            output[i] = 'a' + (c - 'a' + shift) % 26;
        // Leave other characters unchanged
        } else {
            output[i] = c;
        }
    }
    output[strlen(input)] = '\0'; // Null-terminate the output string
}

// Function to decrypt the input string using Caesar Cipher
void decrypt(char *input, int shift, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];

        // Decrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            output[i] = 'A' + (c - 'A' - shift + 26) % 26; // Adding 26 to avoid negative index
        // Decrypt lowercase letters
        } else if (c >= 'a' && c <= 'z') {
            output[i] = 'a' + (c - 'a' - shift + 26) % 26; // Adding 26 to avoid negative index
        // Leave other characters unchanged
        } else {
            output[i] = c;
        }
    }
    output[strlen(input)] = '\0'; // Null-terminate the output string
}

// Function to display menu
void displayMenu() {
    printf("================================\n");
    printf("           Caesar Cipher       \n");
    printf("================================\n");
    printf("1. Encrypt a Message\n");
    printf("2. Decrypt a Message\n");
    printf("3. Exit\n");
    printf("================================\n");
    printf("Please choose an option: ");
}

int main() {
    char input[100];
    char output[100];
    int shift;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline

                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Please enter a number between 1 and 25.\n");
                    break;
                }
                
                encrypt(input, shift, output);
                printf("Encrypted message: %s\n", output);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0; // Remove trailing newline

                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Please enter a number between 1 and 25.\n");
                    break;
                }

                decrypt(input, shift, output);
                printf("Decrypted message: %s\n", output);
                break;

            case 3:
                printf("Exiting program... Goodbye!\n");
                return 0;

            default:
                printf("Invalid option! Please choose again.\n");
        }
    }
    return 0;
}