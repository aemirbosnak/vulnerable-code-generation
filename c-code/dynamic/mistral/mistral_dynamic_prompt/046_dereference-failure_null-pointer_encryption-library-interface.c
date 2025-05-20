#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char* key;
    int length;
} EncryptionParams;

EncryptionParams* createParams(char* key) {
    EncryptionParams* params = (EncryptionParams*)malloc(sizeof(EncryptionParams));
    params->key = key;
    params->length = strlen(key);
    return params;
}

char* encrypt(EncryptionParams* params, char* plaintext) {
    char* ciphertext = (char*)malloc(params->length * strlen(plaintext) + 1);
    int i, j;

    for (i = 0, j = 0; i < strlen(plaintext); i++, j += params->length) {
        ciphertext[j] = plaintext[i] ^ params->key[i % params->length];
    }
    ciphertext[j] = '\0';

    return ciphertext;
}

void destroyParams(EncryptionParams* params) {
    free(params->key);
    free(params);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <key> <plaintext>\n", argv[0]);
        return 1;
    }

    EncryptionParams* params = createParams(argv[1]);
    char* ciphertext = encrypt(params, argv[2]);
    printf("Encrypted text: %s\n", ciphertext);

    destroyParams(params);
    return 0;

    // null pointer dereference vulnerability
    printf("Encrypted text length: %d\n", params->length);
}
