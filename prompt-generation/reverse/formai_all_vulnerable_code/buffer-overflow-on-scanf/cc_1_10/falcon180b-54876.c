//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 16
#define MAX_TEXT_LENGTH 256

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    int shift;
} CaesarCipher;

void caesar_cipher_init(CaesarCipher* cipher, const char* key) {
    strncpy(cipher->key, key, MAX_KEY_LENGTH);
    cipher->key_length = strlen(cipher->key);
    cipher->shift = 0;
}

void caesar_cipher_encrypt(CaesarCipher* cipher, char* text) {
    int i, j, k;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                text[i] = 'A' + ((text[i] - 'A' + cipher->shift) % 26);
            } else {
                text[i] = 'a' + ((text[i] - 'a' + cipher->shift) % 26);
            }
        }
    }
}

void caesar_cipher_decrypt(CaesarCipher* cipher, char* text) {
    int i, j, k;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                text[i] = 'A' + ((text[i] - 'A' - cipher->shift + 26) % 26);
            } else {
                text[i] = 'a' + ((text[i] - 'a' - cipher->shift + 26) % 26);
            }
        }
    }
}

int main() {
    char key[MAX_KEY_LENGTH];
    char text[MAX_TEXT_LENGTH];
    int key_length;

    // Get the key from the user
    printf("Enter the key (up to %d characters): ", MAX_KEY_LENGTH);
    scanf("%s", key);
    key_length = strlen(key);

    // Initialize the Caesar cipher
    CaesarCipher cipher;
    caesar_cipher_init(&cipher, key);

    // Get the text from the user
    printf("Enter the text to encrypt/decrypt: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);

    // Encrypt the text
    caesar_cipher_encrypt(&cipher, text);
    printf("Encrypted text: %s\n", text);

    // Decrypt the text
    caesar_cipher_decrypt(&cipher, text);
    printf("Decrypted text: %s\n", text);

    return 0;
}