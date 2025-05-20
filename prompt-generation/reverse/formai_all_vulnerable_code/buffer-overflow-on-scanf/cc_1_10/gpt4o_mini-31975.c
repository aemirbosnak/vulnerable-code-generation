//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the text using a simple Caesar cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) { // Traverse the input text
        char c = text[i]; // store the current character
        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' + shift) % 26 + 'a';
        }
        // Leave all other characters unchanged
    }
}

// Function to decrypt the text using a simple Caesar cipher
void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) { // Traverse the input text
        char c = text[i]; // store the current character
        // Decrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' - shift + 26) % 26 + 'A'; // added 26 for non-negative result
        }
        // Decrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' - shift + 26) % 26 + 'a'; // added 26 for non-negative result
        }
        // Leave all other characters unchanged
    }
}

// Main function to drive the program
int main() {
    int choice; // variable to store user choice
    char text[100]; // buffer to hold the text
    int shift; // variable to hold the shift value
    
    printf("Welcome to the Enigma Encryption Program!\n");
    printf("Please select an operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Your choice: ");
    scanf("%d", &choice); // get user choice
    getchar(); // consume newline character left by scanf
    
    switch (choice) {
        case 1: // user chose encryption
            printf("Enter the text to encrypt: ");
            fgets(text, sizeof(text), stdin); // get the text
            printf("Enter shift value (1-25): ");
            scanf("%d", &shift); // get the shift value
            
            // Validate shift value
            if (shift < 1 || shift > 25) {
                printf("Invalid shift value. It should be between 1 and 25.\n");
                return 1;
            }
            encrypt(text, shift); // call encrypt function
            printf("Encrypted text: %s", text); // display encrypted text
            break;
        
        case 2: // user chose decryption
            printf("Enter the text to decrypt: ");
            fgets(text, sizeof(text), stdin); // get the text
            printf("Enter shift value (1-25): ");
            scanf("%d", &shift); // get the shift value
            
            // Validate shift value
            if (shift < 1 || shift > 25) {
                printf("Invalid shift value. It should be between 1 and 25.\n");
                return 1;
            }
            decrypt(text, shift); // call decrypt function
            printf("Decrypted text: %s", text); // display decrypted text
            break;
        
        default:
            printf("Invalid choice. Please select 1 or 2.\n");
            return 1;
    }

    return 0; // terminate program
}