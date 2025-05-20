//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define KEY_SIZE 3

void encrypt(char *plaintext, char *ciphertext) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char ch = plaintext[i];
            int shift = (isupper(ch) ? 65 : 97);
            ciphertext[i] = (char) ((int)ch + (KEY_SIZE * shift));
            if (isupper(ciphertext[i])) {
                ciphertext[i] = (char) ((int)ciphertext[i] - 26);
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
}

void decrypt(char *ciphertext, char *plaintext) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char ch = ciphertext[i];
            int shift = (isupper(ch) ? 65 : 97);
            plaintext[i] = (char) ((int)ch - (KEY_SIZE * shift));
            if (isupper(plaintext[i])) {
                plaintext[i] = (char) ((int)plaintext[i] + 26);
            }
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    char plaintext[100], ciphertext[100], decryptedtext[100];

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    encrypt(plaintext, ciphertext);

    printf("Encrypted Text: %s\n", ciphertext);

    char decrypt_text[100];
    decrypt(ciphertext, decryptedtext);

    printf("Decrypted Text: %s\n", decryptedtext);

    return 0;
}