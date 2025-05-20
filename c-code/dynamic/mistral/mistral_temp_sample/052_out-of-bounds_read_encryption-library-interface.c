#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[10];
    char key[20];
} Encryptor;

void encrypt(Encryptor* encryptor, char* plaintext, char* ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = plaintext[i] ^ encryptor->key[i % strlen(encryptor->key)];
    }
    ciphertext[i] = '\0';
}

int main() {
    Encryptor myEncryptor = {"SecretKey", "A"};
    char plaintext[] = "Hello, World!";
    char ciphertext[50];

    encrypt(&myEncryptor, plaintext, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
