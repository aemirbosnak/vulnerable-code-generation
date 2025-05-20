//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 64
#define MAX_MESSAGE_LENGTH 1024

typedef struct {
    char key[MAX_KEY_LENGTH + 1];
    int key_length;
    int shift;
} CaesarCipher;

void generate_key(CaesarCipher *cipher) {
    char letters[26] = "abcdefghijklmnopqrstuvwxyz";
    cipher->key_length = rand() % MAX_KEY_LENGTH + 1;
    for (int i = 0; i < cipher->key_length; i++) {
        cipher->key[i] = letters[rand() % 26];
    }
    cipher->key[cipher->key_length] = '\0';
}

void caesar_cipher_encrypt(char *message, CaesarCipher *cipher) {
    int message_length = strlen(message);
    for (int i = 0; i < message_length; i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            c = (c - 97 + cipher->shift) % 26 + 97;
        }
        message[i] = c;
    }
}

void caesar_cipher_decrypt(char *message, CaesarCipher *cipher) {
    int message_length = strlen(message);
    for (int i = 0; i < message_length; i++) {
        char c = tolower(message[i]);
        if (isalpha(c)) {
            c = (c - 97 - cipher->shift + 26) % 26 + 97;
        }
        message[i] = c;
    }
}

int main() {
    CaesarCipher cipher;
    generate_key(&cipher);
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    caesar_cipher_encrypt(message, &cipher);
    printf("Encrypted message: %s\n", message);
    caesar_cipher_decrypt(message, &cipher);
    printf("Decrypted message: %s\n", message);
    return 0;
}