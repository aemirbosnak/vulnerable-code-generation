//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 32
#define MAX_TEXT_SIZE 1000

void generate_key(char *key, int key_size) {
    int i;
    for (i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

void encrypt(char *text, char *key, char *cipher_text) {
    int i, j;
    for (i = 0, j = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            if (isupper(text[i])) {
                cipher_text[j++] = (char) (((int) text[i] - 65 + (int) key[i % strlen(key)]) % 26 + 65);
            } else {
                cipher_text[j++] = (char) (((int) text[i] - 97 + (int) key[i % strlen(key)]) % 26 + 97);
            }
        } else {
            cipher_text[j++] = text[i];
        }
    }
    cipher_text[j] = '\0';
}

void decrypt(char *cipher_text, char *key, char *text) {
    int i, j;
    for (i = 0, j = 0; i < strlen(cipher_text); i++) {
        if (isalpha(cipher_text[i])) {
            if (isupper(cipher_text[i])) {
                text[j++] = (char) (((int) cipher_text[i] - 65 - (int) key[i % strlen(key)]) % 26 + 65);
            } else {
                text[j++] = (char) (((int) cipher_text[i] - 97 - (int) key[i % strlen(key)]) % 26 + 97);
            }
        } else {
            text[j++] = cipher_text[i];
        }
    }
    text[j] = '\0';
}

int main() {
    char text[MAX_TEXT_SIZE], key[MAX_KEY_SIZE], cipher_text[MAX_TEXT_SIZE];
    int text_size, key_size;

    printf("Enter the text to encrypt: ");
    scanf("%s", text);
    text_size = strlen(text);

    printf("Enter the key: ");
    scanf("%s", key);
    key_size = strlen(key);

    if (key_size > MAX_KEY_SIZE) {
        printf("Key size is too large.\n");
        return 1;
    }

    generate_key(key, key_size);
    encrypt(text, key, cipher_text);

    printf("Encrypted text: %s\n", cipher_text);
    printf("Decrypted text: %s\n", cipher_text);

    return 0;
}