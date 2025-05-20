//Falcon-180B DATASET v1.0 Category: Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 16
#define MAX_PLAIN_TEXT_LEN 1024
#define MAX_CIPHER_TEXT_LEN (MAX_PLAIN_TEXT_LEN + 1)

void generate_key(char* key, int key_len) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < key_len; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
    key[key_len] = '\0';
}

void encrypt(char* plain_text, char* key, char* cipher_text) {
    int plain_text_len = strlen(plain_text);
    int key_len = strlen(key);
    for (int i = 0; i < plain_text_len; i++) {
        char ch = plain_text[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 'a' - 'A';
        } else if (ch >= 'a' && ch <= 'z') {
            ch = ch + 'A' - 'a';
        }
        int key_idx = ch % key_len;
        cipher_text[i] = key[key_idx];
    }
    cipher_text[plain_text_len] = '\0';
}

void decrypt(char* cipher_text, char* key, char* plain_text) {
    int cipher_text_len = strlen(cipher_text);
    int key_len = strlen(key);
    for (int i = 0; i < cipher_text_len; i++) {
        char ch = cipher_text[i];
        int key_idx = ch % key_len;
        char plain_ch = key[key_idx];
        if (plain_ch >= 'a' && plain_ch <= 'z') {
            plain_ch = plain_ch + 'A' - 'a';
        }
        plain_text[i] = plain_ch;
    }
    plain_text[cipher_text_len] = '\0';
}

int main() {
    char plain_text[MAX_PLAIN_TEXT_LEN];
    char key[MAX_KEY_LEN];
    char cipher_text[MAX_CIPHER_TEXT_LEN];

    printf("Enter plain text: ");
    scanf("%s", plain_text);

    generate_key(key, MAX_KEY_LEN);

    encrypt(plain_text, key, cipher_text);

    printf("Encrypted text: %s\n", cipher_text);

    decrypt(cipher_text, key, plain_text);

    printf("Decrypted text: %s\n", plain_text);

    return 0;
}