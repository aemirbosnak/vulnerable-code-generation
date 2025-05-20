//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 32
#define MAX_PLAIN_TEXT_LENGTH 256
#define MAX_CIPHER_TEXT_LENGTH (MAX_PLAIN_TEXT_LENGTH + 1)

void generate_key(char* key) {
    for (int i = 0; i < MAX_KEY_LENGTH; i++) {
        char c = rand() % 26 + 'a';
        key[i] = c;
    }
    key[MAX_KEY_LENGTH - 1] = '\0';
}

void encrypt(char* key, char* plain_text, char* cipher_text) {
    int plain_text_length = strlen(plain_text);
    int cipher_text_length = 0;
    for (int i = 0; i < plain_text_length; i++) {
        char c = tolower(plain_text[i]);
        if (isalpha(c)) {
            int index = tolower(key[i % MAX_KEY_LENGTH]) - 'a';
            if (isalpha(c)) {
                c = (c - 'a' + index) % 26 + 'a';
            }
        }
        cipher_text[cipher_text_length++] = c;
    }
    cipher_text[cipher_text_length] = '\0';
}

void decrypt(char* key, char* cipher_text, char* plain_text) {
    int cipher_text_length = strlen(cipher_text);
    int plain_text_length = 0;
    for (int i = 0; i < cipher_text_length; i++) {
        char c = tolower(cipher_text[i]);
        if (isalpha(c)) {
            int index = tolower(key[i % MAX_KEY_LENGTH]) - 'a';
            if (isalpha(c)) {
                c = (c - 'a' - index + 26) % 26 + 'a';
            }
        }
        plain_text[plain_text_length++] = c;
    }
    plain_text[plain_text_length] = '\0';
}

int main() {
    char key[MAX_KEY_LENGTH];
    char plain_text[MAX_PLAIN_TEXT_LENGTH];
    char cipher_text[MAX_CIPHER_TEXT_LENGTH];

    printf("Enter the plain text: ");
    scanf("%s", plain_text);

    generate_key(key);
    encrypt(key, plain_text, cipher_text);

    printf("Encrypted text: %s\n", cipher_text);

    decrypt(key, cipher_text, plain_text);
    printf("Decrypted text: %s\n", plain_text);

    return 0;
}