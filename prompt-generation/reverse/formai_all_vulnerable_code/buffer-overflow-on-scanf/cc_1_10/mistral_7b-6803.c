//MISTRAL-7B DATASET v1.0 Category: Modern Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 26

void encrypt(char *plaintext, char *key, int length) {
    int i;
    for (i = 0; i < length; i++) {
        plaintext[i] = (plaintext[i] + key[(plaintext[i] - 'A' + KEY_SIZE) % KEY_SIZE]) % 26 + 'A';
    }
}

void decrypt(char *ciphertext, char *key, int length) {
    int i;
    for (i = 0; i < length; i++) {
        ciphertext[i] = (ciphertext[i] - key[(ciphertext[i] - 'A') % KEY_SIZE]) % 26 + 'A';
    }
}

int main() {
    char plaintext[100], ciphertext[100], key[KEY_SIZE + 1];
    int plaintext_length, i;

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);
    plaintext_length = strlen(plaintext);

    printf("Enter the key: ");
    scanf("%s", key);

    encrypt(plaintext, key, plaintext_length);

    printf("\nEncrypted text: ");
    for (i = 0; i < plaintext_length; i++) {
        putchar(plaintext[i]);
    }
    putchar('\n');

    printf("\nEnter the ciphertext to decrypt: ");
    scanf("%s", ciphertext);

    decrypt(ciphertext, key, plaintext_length);

    printf("\nDecrypted text: ");
    for (i = 0; i < plaintext_length; i++) {
        putchar(ciphertext[i]);
    }
    putchar('\n');

    return 0;
}