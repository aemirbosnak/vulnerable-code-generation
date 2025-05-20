#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Fake Encryption Library Interface
void encrypt(char* plaintext, char* ciphertext, int key) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = (char)(plaintext[i] + key);
    }
    ciphertext[i] = '\0';
}

int main() {
    char plaintext[10] = "secret";
    char ciphertext[10];
    int key = 10; // Key larger than ASCII table size, intentionally causing array bounds violation

    encrypt(plaintext, ciphertext, key);
    printf("Encrypted Text: %s\n", ciphertext);

    return 0;
}
