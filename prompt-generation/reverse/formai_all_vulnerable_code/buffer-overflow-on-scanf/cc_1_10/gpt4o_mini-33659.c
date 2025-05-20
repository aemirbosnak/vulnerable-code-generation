//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

// Function prototypes
void encrypt(char *plaintext, int key);
void decrypt(char *ciphertext, int key);
void print_menu();
void get_input(char *input_buffer, const char *prompt);

int main() {
    char input[MAX_LENGTH];
    int choice, key;

    printf("Welcome to the Peaceful Encryption Program!\n");
    print_menu();
    
    while (1) {
        // Get the user's choice
        printf("Please enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after the number input
        
        switch (choice) {
            case 1: // Encrypt
                get_input(input, "Enter the plaintext to encrypt: ");
                printf("Enter the encryption key (1-25): ");
                scanf("%d", &key);
                encrypt(input, key);
                break;

            case 2: // Decrypt
                get_input(input, "Enter the ciphertext to decrypt: ");
                printf("Enter the decryption key (1-25): ");
                scanf("%d", &key);
                decrypt(input, key);
                break;

            case 3: // Exit
                printf("Thank you for using the Peaceful Encryption Program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n");
                print_menu();
                break;
        }
    }
    return 0;
}

void encrypt(char *plaintext, int key) {
    char ciphertext[MAX_LENGTH];
    int i = 0;

    // Basic Caesar cipher encryption logic
    while (plaintext[i] != '\0') {
        // Shift only alphabet characters
        if ((plaintext[i] >= 'a' && plaintext[i] <= 'z')) {
            ciphertext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
        } else if ((plaintext[i] >= 'A' && plaintext[i] <= 'Z')) {
            ciphertext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
        } else {
            ciphertext[i] = plaintext[i]; // Non-alphabetical characters remain the same
        }
        i++;
    }
    ciphertext[i] = '\0'; // Null-terminate the string
    printf("Encrypted text: %s\n", ciphertext);
}

void decrypt(char *ciphertext, int key) {
    char plaintext[MAX_LENGTH];
    int i = 0;

    // Basic Caesar cipher decryption logic
    while (ciphertext[i] != '\0') {
        // Shift only alphabet characters
        if ((ciphertext[i] >= 'a' && ciphertext[i] <= 'z')) {
            plaintext[i] = ((ciphertext[i] - 'a' - key + 26) % 26) + 'a';
        } else if ((ciphertext[i] >= 'A' && ciphertext[i] <= 'Z')) {
            plaintext[i] = ((ciphertext[i] - 'A' - key + 26) % 26) + 'A';
        } else {
            plaintext[i] = ciphertext[i]; // Non-alphabetical characters remain the same
        }
        i++;
    }
    plaintext[i] = '\0'; // Null-terminate the string
    printf("Decrypted text: %s\n", plaintext);
}

void print_menu() {
    printf("======= Menu =======\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Exit\n");
    printf("====================\n");
}

void get_input(char *input_buffer, const char *prompt) {
    printf("%s", prompt);
    fgets(input_buffer, MAX_LENGTH, stdin);
    // Remove newline character from input
    input_buffer[strcspn(input_buffer, "\n")] = 0;
}