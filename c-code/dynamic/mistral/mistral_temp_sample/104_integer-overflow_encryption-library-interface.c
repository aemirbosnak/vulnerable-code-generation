#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    char name[32];
    uint32_t key;
} Encryptor;

Encryptor create_encryptor(const char* name, uint32_t key) {
    Encryptor encryptor;
    strcpy(encryptor.name, name);
    encryptor.key = key;
    return encryptor;
}

void encrypt(const Encryptor* encryptor, char* plaintext, char* ciphertext, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        ciphertext[i] = plaintext[i] + encryptor->key;
    }
}

void print_ciphertext(const char* ciphertext, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        printf("%c", ciphertext[i]);
    }
    printf("\n");
}

int main() {
    Encryptor my_encryptor = create_encryptor("My Secret Encryptor", 0xFFFFFFFF);
    char plaintext[] = "Attack at dawn!";
    char ciphertext[64];

    encrypt(&my_encryptor, plaintext, ciphertext, sizeof(plaintext));
    print_ciphertext(ciphertext, sizeof(plaintext));

    // Intentionally overflow the buffer here
    encrypt(&my_encryptor, plaintext, ciphertext, sizeof(plaintext) + 1);

    return 0;
}
