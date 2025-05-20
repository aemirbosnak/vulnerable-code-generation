//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *plaintext, int shift, char *ciphertext) {
    int i = 0;
    while (plaintext[i] != '\0') {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            ciphertext[i] = (plaintext[i] - base + shift) % 26 + base;
        } else {
            ciphertext[i] = plaintext[i]; // Copy non-alphabet characters as-is
        }
        i++;
    }
    ciphertext[i] = '\0'; // Null-terminate the string
}

void decrypt(char *ciphertext, int shift, char *plaintext) {
    int i = 0;
    while (ciphertext[i] != '\0') {
        if (isalpha(ciphertext[i])) {
            char base = islower(ciphertext[i]) ? 'a' : 'A';
            plaintext[i] = (ciphertext[i] - base - shift + 26) % 26 + base; // Add 26 to handle negative shifts
        } else {
            plaintext[i] = ciphertext[i]; // Copy non-alphabet characters as-is
        }
        i++;
    }
    plaintext[i] = '\0'; // Null-terminate the string
}

int main() {
    char plaintext[256], ciphertext[256], decrypted[256];
    int shift;

    printf("Enter a message to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove trailing newline

    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);

    if (shift < 1 || shift > 25) {
        printf("Invalid shift value. It must be between 1 and 25.\n");
        return 1;
    }

    // Encrypt
    encrypt(plaintext, shift, ciphertext);
    printf("Encrypted message: %s\n", ciphertext);

    // Decrypt
    decrypt(ciphertext, shift, decrypted);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}