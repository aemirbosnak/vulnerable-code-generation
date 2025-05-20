#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple Encrypt Function with Integer Overflow
void encrypt(char* plaintext, int* key) {
    int buffer[50]; // Large enough to overflow
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        buffer[(key[i % 3] + buffer[i]) % 100] = plaintext[i];
    }
    // Overflow possible if the sum of (key[i % 3] + buffer[i]) exceeds 100

    // Write the encrypted text to stdout
    for (i = 0; i < 50; i++) {
        if (buffer[i] != '\0') {
            putchar(buffer[i]);
        }
    }
}

// Main Function
int main() {
    char plaintext[] = "SECRETMESSAGE";
    int key[strlen(plaintext)];

    // Fake key generation, key should not be hardcoded or known
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        key[i] = i * 13; // Increase the multiplier for stronger encryption
    }

    encrypt(plaintext, key);

    return 0;
}
