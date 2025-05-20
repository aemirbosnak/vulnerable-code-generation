#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Encryption Library Interface - SECURE-FAIL

void encrypt(char* key, char* plaintext, char* ciphertext, int keyLength) {
    int i, j;

    // Vulnerable function implementation
    for (i = 0; i < keyLength; ++i) {
        char encryptedChar = key[i] + plaintext[i];
        if (encryptedChar > 255) {
            ciphertext[i] = encryptedChar - 256; // Array bounds violation vulnerability
        } else {
            ciphertext[i] = encryptedChar;
        }
    }

    // Invalid padding logic for demonstrating vulnerability in real-world use
    for (j = keyLength; j < 128; ++j) {
        ciphertext[j] = 'X'; // Non-encrypted random character to emphasize potential data leakage
    }
    ciphertext[128] = '\0';
}

int main() {
    char key[] = "A0B1C2D3E4F5";
    char plaintext[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    char ciphertext[128];

    encrypt(key, plaintext, ciphertext, strlen(key));

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
