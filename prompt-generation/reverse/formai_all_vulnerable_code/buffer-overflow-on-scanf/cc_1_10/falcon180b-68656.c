//Falcon-180B DATASET v1.0 Category: Encryption ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_PLAINTEXT_LENGTH 1000

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j, k;
    char ch;
    int key_length = strlen(key);
    int plaintext_length = strlen(plaintext);

    for (i = 0, j = 0; i < plaintext_length; i++, j++) {
        if (j == key_length) {
            j = 0;
        }
        ch = toupper(plaintext[i]);
        if (isalpha(ch)) {
            ch = ch + key[j] - 'A';
            if (ch > 'Z') {
                ch = ch - 26;
            } else if (ch < 'A') {
                ch = ch + 26;
            }
            ciphertext[i] = ch;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[plaintext_length] = '\0';
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i, j, k;
    char ch;
    int key_length = strlen(key);
    int ciphertext_length = strlen(ciphertext);

    for (i = 0, j = 0; i < ciphertext_length; i++, j++) {
        if (j == key_length) {
            j = 0;
        }
        ch = toupper(ciphertext[i]);
        if (isalpha(ch)) {
            ch = ch - key[j] + 'A';
            if (ch > 'Z') {
                ch = ch - 26;
            } else if (ch < 'A') {
                ch = ch + 26;
            }
            plaintext[i] = ch;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[ciphertext_length] = '\0';
}

int main() {
    char plaintext[MAX_PLAINTEXT_LENGTH];
    char key[MAX_KEY_LENGTH];
    char ciphertext[MAX_PLAINTEXT_LENGTH];

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    printf("Enter key: ");
    scanf("%s", key);

    encrypt(plaintext, key, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key, plaintext);

    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}