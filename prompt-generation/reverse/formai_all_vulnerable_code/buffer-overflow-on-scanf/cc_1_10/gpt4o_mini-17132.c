//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt a plaintext using Caesar cipher
void encrypt(char* plaintext, int shift, char* ciphertext) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            ciphertext[i] = (plaintext[i] - base + shift) % 26 + base;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0'; // Null terminate the ciphertext
}

// Function to decrypt a ciphertext using Caesar cipher
void decrypt(char* ciphertext, int shift, char* plaintext) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char base = islower(ciphertext[i]) ? 'a' : 'A';
            plaintext[i] = (ciphertext[i] - base - shift + 26) % 26 + base;  // Added 26 for wrap-around
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0'; // Null terminate the plaintext
}

int main() {
    char plaintext[256];
    char ciphertext[256];
    char decryptedtext[256];
    int shift;

    printf("Enter text to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; // Remove newline character

    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);

    // Ensure the shift is within a valid range
    if (shift < 1 || shift > 25) {
        printf("Shift value must be between 1 and 25.\n");
        return 1;
    }

    encrypt(plaintext, shift, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);

    decrypt(ciphertext, shift, decryptedtext);
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}