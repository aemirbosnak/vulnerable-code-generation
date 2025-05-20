//Falcon-180B DATASET v1.0 Category: Encryption ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_TEXT_LEN 1000

typedef struct {
    char key[MAX_KEY_LEN];
    int key_len;
    int shift;
} CaesarCipher;

CaesarCipher* create_caesar_cipher(char* key, int key_len) {
    CaesarCipher* cipher = (CaesarCipher*)malloc(sizeof(CaesarCipher));
    strcpy(cipher->key, key);
    cipher->key_len = key_len;
    cipher->shift = 0;
    return cipher;
}

void destroy_caesar_cipher(CaesarCipher* cipher) {
    free(cipher);
}

void encrypt(CaesarCipher* cipher, char* text) {
    int text_len = strlen(text);
    char* encrypted_text = (char*)malloc((text_len + 1) * sizeof(char));
    encrypted_text[0] = '\0';

    for (int i = 0; i < text_len; i++) {
        char c = toupper(text[i]);
        if (isalpha(c)) {
            int shift = (cipher->shift + (int)c - 65) % 26;
            if (isupper(c)) {
                encrypted_text[i] = (char)(shift + 65);
            } else {
                encrypted_text[i] = (char)(shift + 97);
            }
        } else {
            encrypted_text[i] = c;
        }
    }

    encrypted_text[text_len] = '\0';
    strcpy(text, encrypted_text);
    free(encrypted_text);
}

int main() {
    char* key = "secretkey";
    int key_len = strlen(key);
    CaesarCipher* cipher = create_caesar_cipher(key, key_len);

    char* text = "Hello, world!";
    encrypt(cipher, text);

    printf("Encrypted text: %s\n", text);

    destroy_caesar_cipher(cipher);

    return 0;
}