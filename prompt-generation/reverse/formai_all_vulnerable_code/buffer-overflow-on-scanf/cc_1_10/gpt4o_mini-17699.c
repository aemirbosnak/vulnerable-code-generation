//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the input string
void encrypt(char *input, char *output, int key) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        // Shift character and handle wrapping
        if (isalpha(input[i])) {
            char base = islower(input[i]) ? 'a' : 'A';
            output[i] = (input[i] - base + key) % 26 + base;
        } else {
            output[i] = input[i]; // Non-alphabetic characters remain unchanged
        }
    }
    output[i] = '\0'; // Null-terminate the output string
}

// Function to decrypt the input string
void decrypt(char *input, char *output, int key) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        // Shift character and handle wrapping
        if (isalpha(input[i])) {
            char base = islower(input[i]) ? 'a' : 'A';
            output[i] = (input[i] - base - key + 26) % 26 + base;
        } else {
            output[i] = input[i]; // Non-alphabetic characters remain unchanged
        }
    }
    output[i] = '\0'; // Null-terminate the output string
}

// Main function to drive the program
int main() {
    char input[256];
    char encrypted[256];
    char decrypted[256];
    int key;

    printf("Welcome to Ken's C Encryption Program!\n");
    printf("Please enter a string to encrypt (max 255 characters): ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // Asking for the encryption key
    printf("Enter an encryption key (0-25): ");
    scanf("%d", &key);

    // Key normalization: We can wrap the key if it's outside 0-25 range
    key = ((key % 26) + 26) % 26;

    // Encrypt the input
    encrypt(input, encrypted, key);
    printf("Encrypted string: %s\n", encrypted);

    // Decrypt the encrypted string
    decrypt(encrypted, decrypted, key);
    printf("Decrypted string: %s\n", decrypted);

    // Additional demo: Encrypting and decrypting multiple times
    printf("\nDemonstrating multiple encryption/decryption cycles:\n");
    for (int cycle = 1; cycle <= 3; cycle++) {
        printf("Cycle %d:\n", cycle);
        
        encrypt(encrypted, encrypted, key);
        printf("Encrypted after cycle %d: %s\n", cycle, encrypted);
        
        decrypt(encrypted, decrypted, key);
        printf("Decrypted after cycle %d: %s\n", cycle, decrypted);
    }

    printf("\nThanks for trying out Ken's C Encryption Program! Goodbye!\n");
    return 0;
}