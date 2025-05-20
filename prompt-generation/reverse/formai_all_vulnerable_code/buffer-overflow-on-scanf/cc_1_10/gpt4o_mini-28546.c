//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: ephemeral
#include <stdio.h>
#include <string.h>

// Function to encrypt the plaintext using Caesar Cipher
void encrypt(char *plaintext, int shift, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; ++i) {
        char c = plaintext[i];
        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            ciphertext[i] = (c + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            ciphertext[i] = (c + shift - 'a') % 26 + 'a';
        }
        // If it's not an alphabetic character, leave it unchanged
        else {
            ciphertext[i] = c;
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the encrypted string
}

// Function to decrypt the ciphertext using Caesar Cipher
void decrypt(char *ciphertext, int shift, char *plaintext) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; ++i) {
        char c = ciphertext[i];
        // Decrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            plaintext[i] = (c - shift - 'A' + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            plaintext[i] = (c - shift - 'a' + 26) % 26 + 'a';
        }
        // If it's not an alphabetic character, leave it unchanged
        else {
            plaintext[i] = c;
        }
    }
    plaintext[i] = '\0'; // Null-terminate the decrypted string
}

int main() {
    char plaintext[256];
    char ciphertext[256];
    char decryptedtext[256];
    int shift;

    // Get user input for plaintext
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove trailing newline

    // Get user input for the shift value
    printf("Enter the shift value (0-25): ");
    scanf("%d", &shift);
    
    // Normalize the shift value
    shift = shift % 26;

    // Encrypt the plaintext
    encrypt(plaintext, shift, ciphertext);
    printf("Encrypted Text: %s\n", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, shift, decryptedtext);
    printf("Decrypted Text: %s\n", decryptedtext);

    return 0;
}