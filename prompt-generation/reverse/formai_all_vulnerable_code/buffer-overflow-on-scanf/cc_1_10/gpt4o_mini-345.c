//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 256

// Function to encrypt a string using Caesar cipher
void encrypt(char *input, int shift, char *output) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        
        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            output[i] = ((ch - 'A' + shift) % 26) + 'A';
        } 
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            output[i] = ((ch - 'a' + shift) % 26) + 'a';
        } 
        // Non-alphabetical characters remain unchanged
        else {
            output[i] = ch;
        }
    }
    output[i] = '\0'; // Null-terminate the output string
}

// Function to decrypt a string using Caesar cipher
void decrypt(char *input, int shift, char *output) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        char ch = input[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            output[i] = ((ch - 'A' - shift + 26) % 26) + 'A';
        } 
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            output[i] = ((ch - 'a' - shift + 26) % 26) + 'a';
        } 
        // Non-alphabetical characters remain unchanged
        else {
            output[i] = ch;
        }
    }
    output[i] = '\0'; // Null-terminate the output string
}

// Function to display menu and handle user input
void displayMenu() {
    printf("==== Caesar Cipher Encryption ====\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("==================================\n");
}

// Main function
int main() {
    int choice;
    char input[MAX_INPUT_SIZE];
    char output[MAX_INPUT_SIZE];
    int shift;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(input, MAX_INPUT_SIZE, stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline
                
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                getchar();
                
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Please choose between 1 and 25.\n");
                    break;
                }

                encrypt(input, shift, output);
                printf("Encrypted message: %s\n", output);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                fgets(input, MAX_INPUT_SIZE, stdin);
                input[strcspn(input, "\n")] = 0; // Remove newline

                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                getchar();

                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Please choose between 1 and 25.\n");
                    break;
                }

                decrypt(input, shift, output);
                printf("Decrypted message: %s\n", output);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    }
    return 0;
}