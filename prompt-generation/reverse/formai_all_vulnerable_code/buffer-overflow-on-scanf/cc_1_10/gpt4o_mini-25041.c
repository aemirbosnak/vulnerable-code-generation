//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

// Function to encrypt the plaintext using Caesar Cipher
void encrypt(char *plaintext, int shift, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char current = plaintext[i];
        // Encrypt uppercase letters
        if (current >= 'A' && current <= 'Z') {
            ciphertext[i] = (current - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (current >= 'a' && current <= 'z') {
            ciphertext[i] = (current - 'a' + shift) % 26 + 'a';
        } else {
            ciphertext[i] = current; // Non-alphabetic characters remain unchanged
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the ciphertext string
}

// Function to decrypt the ciphertext using Caesar Cipher
void decrypt(char *ciphertext, int shift, char *plaintext) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        char current = ciphertext[i];
        // Decrypt uppercase letters
        if (current >= 'A' && current <= 'Z') {
            plaintext[i] = (current - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (current >= 'a' && current <= 'z') {
            plaintext[i] = (current - 'a' - shift + 26) % 26 + 'a';
        } else {
            plaintext[i] = current; // Non-alphabetic characters remain unchanged
        }
    }
    plaintext[i] = '\0'; // Null-terminate the plaintext string
}

// Function to read user input
void read_input(char *buffer, size_t size) {
    printf("Enter your text (max %zu characters): ", size - 1);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline character
}

// Function to show menu options
void show_menu() {
    printf("\n*** Caesar Cipher Encryption Tool ***\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

// Main function to drive the program
int main() {
    char text[MAX_LEN];
    char result[MAX_LEN];
    int choice;
    int shift;

    while (1) {
        show_menu();
        scanf("%d", &choice);
        getchar(); // Consume trailing newline

        if (choice == 3) {
            printf("Exiting the program.\n");
            break;
        }

        if (choice < 1 || choice > 3) {
            printf("Invalid option. Please try again.\n");
            continue;
        }

        read_input(text, sizeof(text));
        
        printf("Enter shift value (1-25): ");
        scanf("%d", &shift);
        getchar(); // Consume trailing newline
        
        // Validate shift value
        if (shift < 1 || shift > 25) {
            printf("Shift value must be between 1 and 25.\n");
            continue;
        }

        if (choice == 1) {
            encrypt(text, shift, result);
            printf("Encrypted Text: %s\n", result);
        } else if (choice == 2) {
            decrypt(text, shift, result);
            printf("Decrypted Text: %s\n", result);
        }
    }

    return 0;
}