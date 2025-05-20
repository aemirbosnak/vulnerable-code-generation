//Falcon-180B DATASET v1.0 Category: Encryption ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY "secretkey"

void encrypt(char *plaintext, char *ciphertext) {
    int i, j, k;
    char ch;

    for (i = 0, j = 0; plaintext[i]!= '\0'; i++) {
        ch = plaintext[i];
        if (isalpha(ch)) {
            ch = (ch - 'a' + 13) % 26 + 'a';
            if (isupper(ch)) {
                ch = tolower(ch);
            }
        }
        ciphertext[j++] = ch;
    }
    ciphertext[j] = '\0';
}

void decrypt(char *ciphertext, char *plaintext) {
    int i, j, k;
    char ch;

    for (i = 0, j = 0; ciphertext[i]!= '\0'; i++) {
        ch = ciphertext[i];
        if (isalpha(ch)) {
            ch = (ch - 'a' - 13 + 26) % 26 + 'a';
            if (isupper(ch)) {
                ch = tolower(ch);
            }
        }
        plaintext[j++] = ch;
    }
    plaintext[j] = '\0';
}

int main() {
    char plaintext[100], ciphertext[100];

    printf("Enter a message to encrypt: ");
    scanf("%s", plaintext);

    encrypt(plaintext, ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    decrypt(ciphertext, plaintext);

    printf("Decrypted message: %s\n", plaintext);

    return 0;
}