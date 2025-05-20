//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

void encrypt(char *input, char *output, int shift);
void decrypt(char *input, char *output, int shift);
void displayMenu();
void clearBuffer();

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    int shift;
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option (1-3): ");
        if (scanf("%d", &choice) != 1) {
            clearBuffer();
            printf("Invalid input. Please enter a number between 1 and 3.\n");
            continue;
        }

        clearBuffer(); // Clear the input buffer after reading choice

        switch (choice) {
            case 1:
                printf("Enter the text to encrypt: ");
                fgets(input, MAX_LENGTH, stdin);
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                clearBuffer();
                if (shift < 1 || shift > 25) {
                    printf("Shift value must be between 1 and 25.\n");
                    break;
                }
                encrypt(input, output, shift);
                printf("Encrypted text: %s\n", output);
                break;

            case 2:
                printf("Enter the text to decrypt: ");
                fgets(input, MAX_LENGTH, stdin);
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                clearBuffer();
                if (shift < 1 || shift > 25) {
                    printf("Shift value must be between 1 and 25.\n");
                    break;
                }
                decrypt(input, output, shift);
                printf("Decrypted text: %s\n", output);
                break;

            case 3:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Please select a valid option (1-3).\n");
        }
    }
    return 0;
}

// Function to encrypt a string using a simple Caesar cipher
void encrypt(char *input, char *output, int shift) {
    int i;
    for (i = 0; input[i] != '\0' && i < MAX_LENGTH; i++) {
        char ch = input[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            output[i] = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            output[i] = (ch - 'a' + shift) % 26 + 'a';
        }
        // Copy non-letter characters as they are
        else {
            output[i] = ch;
        }
    }
    output[i] = '\0'; // Null-terminate the output string
}

// Function to decrypt a string using a simple Caesar cipher
void decrypt(char *input, char *output, int shift) {
    int i;
    for (i = 0; input[i] != '\0' && i < MAX_LENGTH; i++) {
        char ch = input[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            output[i] = (ch - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            output[i] = (ch - 'a' - shift + 26) % 26 + 'a';
        }
        // Copy non-letter characters as they are
        else {
            output[i] = ch;
        }
    }
    output[i] = '\0'; // Null-terminate the output string
}

// Function to display the menu 
void displayMenu() {
    printf("=== Simple C Encryption Program ===\n");
    printf("1. Encrypt text\n");
    printf("2. Decrypt text\n");
    printf("3. Exit\n");
}

// Function to clear the input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}