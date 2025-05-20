//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

// Function Prototypes
void encrypt(char *plaintext, const char *key, int shift);
void decrypt(char *ciphertext, const char *key, int shift);
void caesarCipher(char *text, int shift);
void xorCipher(char *text, const char *key);

int main() {
    char plaintext[MAX_LEN];
    char key[] = "secretkey";
    int shift;

    printf("Enter plaintext (max 255 characters): ");
    fgets(plaintext, MAX_LEN, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove newline character

    printf("Enter shift for Caesar cipher (0-25): ");
    scanf("%d", &shift);

    if (shift < 0 || shift > 25) {
        fprintf(stderr, "Shift must be between 0 and 25.\n");
        return EXIT_FAILURE;
    }

    // Encryption
    encrypt(plaintext, key, shift);
    
    // Display the ciphertext
    printf("Ciphertext: %s\n", plaintext);

    // Decryption
    decrypt(plaintext, key, shift);
    
    // Display the decrypted text
    printf("Decrypted text: %s\n", plaintext);

    return EXIT_SUCCESS;
}

void encrypt(char *plaintext, const char *key, int shift) {
    // First apply the XOR cipher
    xorCipher(plaintext, key);
    // Then apply the Caesar cipher
    caesarCipher(plaintext, shift);
}

void decrypt(char *ciphertext, const char *key, int shift) {
    // First apply the inverse Caesar cipher
    caesarCipher(ciphertext, -shift);
    // Then apply the XOR cipher to decrypt
    xorCipher(ciphertext, key);
}

void caesarCipher(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char c = text[i];
        // Encrypt lowercase letters
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + shift + 26) % 26 + 'a'; // Modulo wrap-around for lowercase
        }
        // Encrypt uppercase letters
        else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + shift + 26) % 26 + 'A'; // Modulo wrap-around for uppercase
        }
        text[i] = c;
    }
}

void xorCipher(char *text, const char *key) {
    int len = strlen(key);
    for (int i = 0; text[i] != '\0'; ++i) {
        text[i] = text[i] ^ key[i % len]; // XOR with the key cyclically
    }
}