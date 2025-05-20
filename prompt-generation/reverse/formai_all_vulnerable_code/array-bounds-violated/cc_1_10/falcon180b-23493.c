//Falcon-180B DATASET v1.0 Category: Encryption ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_KEY_SIZE 100
#define MAX_PLAIN_TEXT_SIZE 1000
#define MAX_CIPHER_TEXT_SIZE 2000

void generate_random_key(char *key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char *plain_text, char *key, char *cipher_text) {
    int i, j;
    for (i = 0, j = 0; i < strlen(plain_text); i++) {
        if (isalpha(plain_text[i])) {
            cipher_text[j] = (char) (((int) plain_text[i] + (int) key[i % strlen(key)]) % 26 + 'a');
            j++;
        }
    }
    cipher_text[j] = '\0';
}

void decrypt(char *cipher_text, char *key, char *plain_text) {
    int i, j;
    for (i = 0, j = 0; i < strlen(cipher_text); i++) {
        if (isalpha(cipher_text[i])) {
            plain_text[j] = (char) (((int) cipher_text[i] - (int) key[i % strlen(key)]) % 26 + 'a');
            j++;
        }
    }
    plain_text[j] = '\0';
}

int main() {
    char plain_text[MAX_PLAIN_TEXT_SIZE];
    char key[MAX_KEY_SIZE];
    char cipher_text[MAX_CIPHER_TEXT_SIZE];
    int plain_text_size, cipher_text_size;

    printf("Enter the plain text: ");
    fgets(plain_text, MAX_PLAIN_TEXT_SIZE, stdin);
    plain_text_size = strlen(plain_text);

    printf("Enter the key: ");
    fgets(key, MAX_KEY_SIZE, stdin);
    key[strlen(key) - 1] = '\0'; // remove newline character

    generate_random_key(key);

    encrypt(plain_text, key, cipher_text);

    printf("Encrypted text: %s\n", cipher_text);

    decrypt(cipher_text, key, plain_text);

    printf("Decrypted text: %s\n", plain_text);

    return 0;
}