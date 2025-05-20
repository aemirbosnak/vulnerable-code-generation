#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    int len;
} EncryptionKey;

EncryptionKey create_key(char* str) {
    EncryptionKey key;
    key.key = malloc(strlen(str) * sizeof(char));
    strcpy(key.key, str);
    key.len = strlen(key.key);
    return key;
}

char* encrypt(EncryptionKey key, char* plaintext) {
    int textLen = strlen(plaintext);
    char* encrypted = malloc((textLen + key.len) * sizeof(char));

    for (int i = 0; i < textLen; i++) {
        encrypted[i] = plaintext[i] ^ key.key[i % key.len];
    }

    for (int i = textLen; i < (textLen + key.len); i++) {
        encrypted[i] = encrypted[i - textLen]; // Out-of-bounds write example
    }

    return encrypted;
}

void print_encrypted(char* encrypted) {
    printf("Encrypted text: %s\n", encrypted);
}

void destroy_key(EncryptionKey key) {
    free(key.key);
}

int main() {
    EncryptionKey key = create_key("SecretKey1234");
    char plaintext[] = "PlaintextToEncrypt";

    char* encrypted = encrypt(key, plaintext);
    print_encrypted(encrypted);

    destroy_key(key);
    free(encrypted);

    return 0;
}
