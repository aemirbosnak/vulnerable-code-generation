//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 16
#define MAX_TEXT_LENGTH 100
#define MAX_CIPHER_TEXT_LENGTH (MAX_TEXT_LENGTH + 1)

void encrypt(char* key, char* text, char* cipher_text) {
    int key_length = strlen(key);
    int text_length = strlen(text);
    int i, j;
    for (i = 0, j = 0; i < text_length; i++, j++) {
        if (j == key_length) {
            j = 0;
        }
        cipher_text[i] = tolower(text[i]) ^ key[j];
    }
    cipher_text[text_length] = '\0';
}

void decrypt(char* key, char* cipher_text, char* text) {
    int key_length = strlen(key);
    int cipher_text_length = strlen(cipher_text);
    int i, j;
    for (i = 0, j = 0; i < cipher_text_length; i++, j++) {
        if (j == key_length) {
            j = 0;
        }
        text[i] = tolower(cipher_text[i]) ^ key[j];
    }
    text[cipher_text_length] = '\0';
}

int main() {
    char key[MAX_KEY_LENGTH];
    char text[MAX_TEXT_LENGTH];
    char cipher_text[MAX_CIPHER_TEXT_LENGTH];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the text to encrypt/decrypt: ");
    scanf("%s", text);

    encrypt(key, text, cipher_text);

    printf("Encrypted text: %s\n", cipher_text);

    decrypt(key, cipher_text, text);

    printf("Decrypted text: %s\n", text);

    return 0;
}