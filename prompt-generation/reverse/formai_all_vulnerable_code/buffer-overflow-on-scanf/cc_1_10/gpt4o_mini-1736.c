//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: safe
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256

void encrypt(const char* plaintext, char* ciphertext, int shift) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A'; // Determine if lowercase or uppercase
            ciphertext[i] = (ch - base + shift) % 26 + base; // Encrypt the character
        } else {
            ciphertext[i] = ch; // Non-alpha characters remain unchanged
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the string
}

void decrypt(const char* ciphertext, char* plaintext, int shift) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A'; // Determine if lowercase or uppercase
            plaintext[i] = (ch - base - shift + 26) % 26 + base; // Decrypt the character
        } else {
            plaintext[i] = ch; // Non-alpha characters remain unchanged
        }
    }
    plaintext[i] = '\0'; // Null-terminate the string
}

int main() {
    int shift;
    char plaintext[MAX_LEN], ciphertext[MAX_LEN], decrypted_text[MAX_LEN];

    printf("Welcome to the Caesar Cipher Program!\n\n");
    
    printf("Enter the shift value (1-25): ");
    if (scanf("%d", &shift) != 1 || shift < 1 || shift > 25) {
        fprintf(stderr, "Invalid shift value! Must be between 1 and 25.\n");
        return 1;
    }
    
    // Clear the input buffer
    while (getchar() != '\n');

    printf("Enter the plaintext (max %d characters): ", MAX_LEN - 1);
    fgets(plaintext, MAX_LEN, stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; // Remove the newline character

    // Encrypt the plaintext
    encrypt(plaintext, ciphertext, shift);
    printf("Encrypted text: %s\n", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, decrypted_text, shift);
    printf("Decrypted text: %s\n", decrypted_text);

    printf("\nThank you for using the Caesar Cipher Program!\n");
    
    return 0;
}