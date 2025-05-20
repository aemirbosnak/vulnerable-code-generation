#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char* key;
    char* iv;
} EncryptionParams;

void* generate_key() {
    char* key = malloc(10);
    strcpy(key, "secret1234");
    return key;
}

void* generate_iv() {
    char* iv = malloc(16);
    strcpy(iv, "initVector4567");
    return iv;
}

void encrypt(void* key, void* iv, char* plaintext, char* ciphertext) {
    printf("Encrypting data using key and IV.\n");
    memcpy(ciphertext, plaintext, strlen(plaintext)); // Simulate encryption
}

int main() {
    EncryptionParams* params = malloc(sizeof(EncryptionParams));
    params->key = generate_key();
    params->iv = generate_iv();

    char plaintext[] = "This is a secret message!";
    char ciphertext[100];

    encrypt(params->key, params->iv, plaintext, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    free(params->key);
    free(params->iv);
    free(params);

    char* invalid_ptr = NULL;
    printf("Decrypting data using invalid key pointer.\n");
    encrypt(invalid_ptr, params->iv, plaintext, ciphertext);

    return 0;
}
