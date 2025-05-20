//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "MySecretK" // Change this to your own key
#define BUF_SIZE 1024

void encrypt(char *plaintext, char *ciphertext) {
    int i, j, k;
    int keylen = strlen(KEY);

    for (i = 0, j = 0, k = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = plaintext[i] ^ KEY[j];
        j = (j + 1) % keylen;
        k++;
        if (k == keylen) {
            k = 0;
            j = 0;
        }
    }
    ciphertext[i] = '\0';
}

void decrypt(char *ciphertext, char *plaintext) {
    int i, j, k;
    int keylen = strlen(KEY);

    for (i = 0, j = 0, k = 0; ciphertext[i] != '\0'; i++) {
        plaintext[i] = ciphertext[i] ^ KEY[j];
        j = (j + 1) % keylen;
        k++;
        if (k == keylen) {
            k = 0;
            j = 0;
        }
    }
    plaintext[i] = '\0';
}

int main() {
    char plaintext[BUF_SIZE], ciphertext[BUF_SIZE];

    printf("Enter the plaintext to encrypt: ");
    gets(plaintext);

    encrypt(plaintext, ciphertext);

    printf("Encrypted ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, plaintext);

    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}