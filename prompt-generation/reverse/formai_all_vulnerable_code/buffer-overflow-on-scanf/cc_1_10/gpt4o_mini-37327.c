//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256

// Function to encrypt the plaintext using a simple Caesar cipher
void encrypt(char *plaintext, int shift, char *ciphertext) {
    int i = 0;
    while (plaintext[i] != '\0') {
        char current_char = plaintext[i];

        // Encrypt uppercase letters
        if (isupper(current_char)) {
            ciphertext[i] = (current_char + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(current_char)) {
            ciphertext[i] = (current_char + shift - 'a') % 26 + 'a';
        }
        // Non-alphabetic characters remain the same
        else {
            ciphertext[i] = current_char;
        }
        i++;
    }
    ciphertext[i] = '\0';  // Null terminate the ciphertext
}

// Function to decrypt the ciphertext using the same Caesar cipher
void decrypt(char *ciphertext, int shift, char *plaintext) {
    int i = 0;
    while (ciphertext[i] != '\0') {
        char current_char = ciphertext[i];

        // Decrypt uppercase letters
        if (isupper(current_char)) {
            plaintext[i] = (current_char - shift - 'A' + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (islower(current_char)) {
            plaintext[i] = (current_char - shift - 'a' + 26) % 26 + 'a';
        }
        // Non-alphabetic characters remain the same
        else {
            plaintext[i] = current_char;
        }
        i++;
    }
    plaintext[i] = '\0';  // Null terminate the plaintext
}

// Main function to handle input and output
int main() {
    char plaintext[MAX_LEN];
    char ciphertext[MAX_LEN];
    char decrypted_text[MAX_LEN];
    int shift;

    printf("Enter the plaintext (max %d characters): ", MAX_LEN - 1);
    fgets(plaintext, MAX_LEN, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';  // Remove trailing newline

    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);
    
    // Ensure valid shift value
    if (shift < 1 || shift > 25) {
        printf("Error: Shift must be between 1 and 25.\n");
        return 1;
    }

    // Perform encryption
    encrypt(plaintext, shift, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);
    
    // Perform decryption
    decrypt(ciphertext, shift, decrypted_text);
    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}