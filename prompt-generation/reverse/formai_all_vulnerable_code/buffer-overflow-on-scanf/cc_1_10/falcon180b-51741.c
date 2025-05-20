//Falcon-180B DATASET v1.0 Category: Encryption ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 1024
#define MAX_TEXT_SIZE 1024

void generate_key(char *key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char *text, char *key, char *encrypted_text) {
    int text_size = strlen(text);
    int key_size = strlen(key);
    int encrypted_text_size = text_size + 1;

    encrypted_text[encrypted_text_size - 1] = '\0';

    for (int i = 0; i < text_size; i++) {
        encrypted_text[i] = text[i] ^ key[i % key_size];
    }
}

void decrypt(char *encrypted_text, char *key, char *decrypted_text) {
    int encrypted_text_size = strlen(encrypted_text);
    int key_size = strlen(key);
    int decrypted_text_size = encrypted_text_size;

    decrypted_text[decrypted_text_size - 1] = '\0';

    for (int i = 0; i < encrypted_text_size; i++) {
        decrypted_text[i] = encrypted_text[i] ^ key[i % key_size];
    }
}

int main() {
    char key[MAX_KEY_SIZE];
    char text[MAX_TEXT_SIZE];
    char encrypted_text[MAX_TEXT_SIZE];
    char decrypted_text[MAX_TEXT_SIZE];

    printf("Enter a key (up to %d characters): ", MAX_KEY_SIZE - 1);
    scanf("%s", key);

    printf("Enter some text to encrypt (up to %d characters): ", MAX_TEXT_SIZE - 1);
    scanf("%s", text);

    generate_key(key, strlen(key));

    encrypt(text, key, encrypted_text);

    printf("Encrypted text: %s\n", encrypted_text);

    decrypt(encrypted_text, key, decrypted_text);

    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}