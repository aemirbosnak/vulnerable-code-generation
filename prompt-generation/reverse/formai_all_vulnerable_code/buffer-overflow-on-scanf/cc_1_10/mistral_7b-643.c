//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define KEY_SIZE 26

void encrypt(char *plaintext, char key) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i]))
                plaintext[i] = ((int)plaintext[i] - 65 + key) % 26 + 65;
            else
                plaintext[i] = ((int)plaintext[i] - 97 + key) % 26 + 97;
        }
    }
}

void decrypt(char *ciphertext, char key) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i]))
                ciphertext[i] = ((int)ciphertext[i] - 65 - key + 26) % 26 + 65;
            else
                ciphertext[i] = ((int)ciphertext[i] - 97 - key + 26) % 26 + 97;
        }
    }
}

int main() {
    char plaintext[100];
    char ciphertext[100];
    char key;

    printf("Enter the message to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strlen(plaintext) - 1] = '\0';

    printf("Enter the encryption key (1-26): ");
    scanf("%c", &key);
    key = key - 'a' + 1; // Convert ASCII character to integer

    encrypt(plaintext, key);

    strcpy(ciphertext, plaintext);

    printf("\nEncrypted message: %s\n", ciphertext);

    printf("\nEnter the decryption key (1-26): ");
    scanf("%c", &key);
    key = key - 'a' + 1;

    decrypt(ciphertext, key);

    printf("\nDecrypted message: %s\n", plaintext);

    return 0;
}