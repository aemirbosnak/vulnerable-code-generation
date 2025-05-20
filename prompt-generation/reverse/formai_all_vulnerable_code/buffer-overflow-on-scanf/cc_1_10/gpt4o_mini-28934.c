//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

void encrypt(char *plaintext, int shift, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ciphertext[i] = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ciphertext[i] = (ch - 'a' + shift) % 26 + 'a';
        }
        // If not a letter, leave unchanged
        else {
            ciphertext[i] = ch;
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the encrypted string
}

void decrypt(char *ciphertext, int shift, char *plaintext) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];
        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            plaintext[i] = (ch - 'A' - shift + 26) % 26 + 'A'; // Add 26 to ensure positive index
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            plaintext[i] = (ch - 'a' - shift + 26) % 26 + 'a'; // Add 26 to ensure positive index
        }
        // If not a letter, leave unchanged
        else {
            plaintext[i] = ch;
        }
    }
    plaintext[i] = '\0'; // Null-terminate the decrypted string
}

int main() {
    char plaintext[MAX_LENGTH];
    char ciphertext[MAX_LENGTH];
    char decrypted_text[MAX_LENGTH];
    int shift;
    
    // User input for plaintext
    printf("Enter the plaintext: ");
    fgets(plaintext, MAX_LENGTH, stdin);
    
    // Remove newline character if present
    plaintext[strcspn(plaintext, "\n")] = 0;

    // User input for shift value
    printf("Enter shift value (0-25): ");
    scanf("%d", &shift);
    
    // Validate shift value
    if (shift < 0 || shift > 25) {
        fprintf(stderr, "Error: Shift value must be in the range 0-25.\n");
        return 1;
    }

    // Encrypt the plaintext
    encrypt(plaintext, shift, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, shift, decrypted_text);
    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}