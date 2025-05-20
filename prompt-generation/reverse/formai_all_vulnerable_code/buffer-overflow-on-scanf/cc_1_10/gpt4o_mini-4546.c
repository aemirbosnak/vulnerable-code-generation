//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string using Caesar Cipher
void encrypt(char *input, int shift, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        char current = input[i];
        // Encrypt uppercase letters
        if (current >= 'A' && current <= 'Z') {
            output[i] = (current + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (current >= 'a' && current <= 'z') {
            output[i] = (current + shift - 'a') % 26 + 'a';
        }
        // If it's not a letter, keep it unchanged
        else {
            output[i] = current;
        }
    }
    output[strlen(input)] = '\0'; // Null-terminate the output string
}

// Function to decrypt a string using Caesar Cipher
void decrypt(char *input, int shift, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        char current = input[i];
        // Decrypt uppercase letters
        if (current >= 'A' && current <= 'Z') {
            output[i] = (current - shift - 'A' + 26) % 26 + 'A'; // Adding 26 to handle negative values
        }
        // Decrypt lowercase letters
        else if (current >= 'a' && current <= 'z') {
            output[i] = (current - shift - 'a' + 26) % 26 + 'a'; // Adding 26 to handle negative values
        }
        // If it's not a letter, keep it unchanged
        else {
            output[i] = current;
        }
    }
    output[strlen(input)] = '\0'; // Null-terminate the output string
}

int main() {
    char input[256];
    char encrypted[256];
    char decrypted[256];
    int shift;

    // Input from the user
    printf("Enter a string to encrypt (max 255 characters): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline

    printf("Enter encryption shift value: ");
    scanf("%d", &shift);
    shift = shift % 26; // Normalize shift to be within 0-25

    // Encryption
    encrypt(input, shift, encrypted);
    printf("Encrypted string: %s\n", encrypted);

    // Decryption
    decrypt(encrypted, shift, decrypted);
    printf("Decrypted string: %s\n", decrypted);

    return 0;
}