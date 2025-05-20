//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LEN 16

void encrypt(char *plaintext, char *key) {
    int i, j;
    char ciphertext[strlen(plaintext)];

    for (i = 0, j = 0; plaintext[i]!= '\0'; i++, j++) {
        if (j == KEY_LEN) {
            j = 0;
        }

        ciphertext[i] = plaintext[i] ^ key[j];
    }

    ciphertext[i] = '\0';

    printf("Encrypted text: %s\n", ciphertext);
}

void decrypt(char *ciphertext, char *key) {
    int i, j;
    char plaintext[strlen(ciphertext)];

    for (i = 0, j = 0; ciphertext[i]!= '\0'; i++, j++) {
        if (j == KEY_LEN) {
            j = 0;
        }

        plaintext[i] = ciphertext[i] ^ key[j];
    }

    plaintext[i] = '\0';

    printf("Decrypted text: %s\n", plaintext);
}

int main() {
    char plaintext[100] = "Hello, World!";
    char key[KEY_LEN] = "secretkey12345";

    printf("Plaintext: %s\n", plaintext);
    encrypt(plaintext, key);
    decrypt(plaintext, key);

    return 0;
}