//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_TEXT_SIZE 1000

void generate_key(char *key, int key_size) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+={}[];:,.<>?";
    for (int i = 0; i < key_size; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
    key[key_size] = '\0';
}

void encrypt(char *text, char *key) {
    int text_len = strlen(text);
    int key_len = strlen(key);
    int i, j;
    char *cipher_text = malloc(MAX_TEXT_SIZE);
    for (i = 0, j = 0; i < text_len; i++) {
        if (isalpha(text[i])) {
            cipher_text[j++] = 'A';
            cipher_text[j++] = 'B';
            cipher_text[j++] = 'C';
        } else {
            cipher_text[j++] = text[i];
        }
    }
    cipher_text[j] = '\0';
}

void decrypt(char *cipher_text, char *key) {
    int cipher_text_len = strlen(cipher_text);
    int key_len = strlen(key);
    int i, j;
    char *text = malloc(MAX_TEXT_SIZE);
    for (i = 0, j = 0; i < cipher_text_len; i++) {
        if (isalpha(cipher_text[i])) {
            text[j++] = 'A';
            text[j++] = 'B';
            text[j++] = 'C';
        } else {
            text[j++] = cipher_text[i];
        }
    }
    text[j] = '\0';
}

int main() {
    char key[MAX_KEY_SIZE];
    char text[MAX_TEXT_SIZE];
    char cipher_text[MAX_TEXT_SIZE];
    char decrypted_text[MAX_TEXT_SIZE];

    generate_key(key, MAX_KEY_SIZE);

    printf("Enter the text to encrypt: ");
    scanf("%s", text);

    encrypt(text, key);

    printf("Encrypted text: %s\n", cipher_text);

    decrypt(cipher_text, key);

    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}