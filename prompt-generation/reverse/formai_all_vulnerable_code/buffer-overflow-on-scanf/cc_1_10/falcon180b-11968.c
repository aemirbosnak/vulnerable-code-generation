//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ALPHABET_SIZE 26
#define KEY_SIZE 16

typedef struct {
    char *plain_text;
    char *cipher_text;
    char *key;
} message;

void generate_key(char *key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = 'a' + rand() % ALPHABET_SIZE;
    }
    key[KEY_SIZE] = '\0';
}

int is_uppercase(char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_lowercase(char c) {
    return (c >= 'a' && c <= 'z');
}

void shift_letter(char *letter, int shift) {
    if (is_uppercase(*letter)) {
        *letter = 'A' + ((*letter - 'A') + shift) % ALPHABET_SIZE;
    } else if (is_lowercase(*letter)) {
        *letter = 'a' + ((*letter - 'a') + shift) % ALPHABET_SIZE;
    }
}

void encrypt(char *plain_text, char *key) {
    int plain_text_length = strlen(plain_text);
    char *cipher_text = malloc(plain_text_length + 1);

    for (int i = 0; i < plain_text_length; i++) {
        if (is_uppercase(plain_text[i])) {
            shift_letter(&plain_text[i], (key[i % KEY_SIZE] - 'a') % ALPHABET_SIZE);
        } else if (is_lowercase(plain_text[i])) {
            shift_letter(&plain_text[i], (key[i % KEY_SIZE] - 'a') % ALPHABET_SIZE);
        }
    }

    strcpy(cipher_text, plain_text);
}

void decrypt(char *cipher_text, char *key) {
    int cipher_text_length = strlen(cipher_text);
    char *plain_text = malloc(cipher_text_length + 1);

    for (int i = 0; i < cipher_text_length; i++) {
        if (is_uppercase(cipher_text[i])) {
            shift_letter(&cipher_text[i], (26 - (key[i % KEY_SIZE] - 'a') % ALPHABET_SIZE));
        } else if (is_lowercase(cipher_text[i])) {
            shift_letter(&cipher_text[i], (26 - (key[i % KEY_SIZE] - 'a') % ALPHABET_SIZE));
        }
    }

    strcpy(plain_text, cipher_text);
}

int main() {
    message message;

    printf("Enter plain text: ");
    scanf("%s", message.plain_text);

    generate_key(message.key);

    printf("Enter key: ");
    scanf("%s", message.key);

    encrypt(message.plain_text, message.key);

    printf("Cipher text: %s\n", message.cipher_text);

    decrypt(message.cipher_text, message.key);

    printf("Plain text: %s\n", message.plain_text);

    return 0;
}