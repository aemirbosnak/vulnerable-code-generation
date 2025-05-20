#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Fake encryption library interface
void encrypt(char* key, char* plaintext, char* ciphertext, int size) {
    int i;
    for (i = 0; i < size; ++i) {
        ciphertext[i] = plaintext[i] ^ key[i % strlen(key)];
    }
}

int main() {
    char key[10];
    char plaintext[256];
    char ciphertext[256];
    int size;

    printf("Welcome to the Vulnerable Encryption Library v1.0\n");
    printf("Enter the encryption key (max 10 characters): ");
    scanf("%s", key); // Vulnerable line containing buffer overflow

    printf("Enter the plaintext to encrypt (max 255 characters): ");
    scanf("%s", plaintext); // Another vulnerable line containing buffer overflow

    printf("Enter the size of the plaintext: ");
    scanf("%d", &size);

    // Intentionally overflowing 'ciphertext' buffer due to incorrect size calculation
    encrypt(key, plaintext, ciphertext, size + 1);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
