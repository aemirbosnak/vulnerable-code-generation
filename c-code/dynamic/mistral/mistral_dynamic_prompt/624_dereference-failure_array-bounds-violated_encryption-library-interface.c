#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Insecure encryption library function
void encrypt(char* plaintext, char* ciphertext, int key) {
    int len = strlen(plaintext);

    for (int i = 0; i < len; i++) {
        char c = plaintext[i];
        if (isalpha(c)) {
            ciphertext[i] = (c + key) % 26 + 'A'; // Violates bounds if key > 26
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
}

int main() {
    char plaintext[] = "secret message";
    char ciphertext[strlen(plaintext)];
    int key = 52; // Intentionally too large for bounds violation

    encrypt(plaintext, ciphertext, key);
    printf("Encrypted text: %s\n", ciphertext);

    return 0;
}
