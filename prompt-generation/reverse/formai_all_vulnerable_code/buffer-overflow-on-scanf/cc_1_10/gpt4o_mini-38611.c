//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to encrypt a string using Caesar Cipher
void encrypt(char *input, char *output, int shift) {
    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        // Check if character is an uppercase letter
        if (ch >= 'A' && ch <= 'Z') {
            output[i] = (ch - 'A' + shift) % 26 + 'A';
        }
        // Check if character is a lowercase letter
        else if (ch >= 'a' && ch <= 'z') {
            output[i] = (ch - 'a' + shift) % 26 + 'a';
        }
        // Non-alphabetic characters remain unchanged
        else {
            output[i] = ch;
        }
    }
    output[strlen(input)] = '\0'; // Null terminate the output string
}

// Function to decrypt a string using Caesar Cipher
void decrypt(char *input, char *output, int shift) {
    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        // Check if character is an uppercase letter
        if (ch >= 'A' && ch <= 'Z') {
            output[i] = (ch - 'A' - shift + 26) % 26 + 'A'; // Add 26 for negative modulo
        }
        // Check if character is a lowercase letter
        else if (ch >= 'a' && ch <= 'z') {
            output[i] = (ch - 'a' - shift + 26) % 26 + 'a'; // Add 26 for negative modulo
        }
        // Non-alphabetic characters remain unchanged
        else {
            output[i] = ch;
        }
    }
    output[strlen(input)] = '\0'; // Null terminate the output string
}

int main() {
    char input[MAX_SIZE];
    char encrypted[MAX_SIZE];
    char decrypted[MAX_SIZE];
    int shift;

    // Get input string from the user
    printf("Enter the string to encrypt: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    
    // Remove the newline character if present
    input[strcspn(input, "\n")] = '\0';

    // Get shift value from the user
    printf("Enter shift value (1-25): ");
    if (scanf("%d", &shift) != 1 || shift < 1 || shift > 25) {
        printf("Invalid shift value.\n");
        return 1;
    }

    // Encrypt the input string
    encrypt(input, encrypted, shift);
    printf("Encrypted string: %s\n", encrypted);

    // Decrypt the encrypted string
    decrypt(encrypted, decrypted, shift);
    printf("Decrypted string: %s\n", decrypted);

    return 0;
}