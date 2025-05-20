#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char *key;
    char *plaintext;
    char *ciphertext;
} Encryptor;

void encrypt(Encryptor *encryptor) {
    int key_len = strlen(encryptor->key);
    int plaintext_len = strlen(encryptor->plaintext);

    encryptor->ciphertext = malloc((plaintext_len + 1) * sizeof(char));

    for (int i = 0; i < plaintext_len; i++) {
        encryptor->ciphertext[i] = encryptor->key[(encryptor->plaintext[i]) % key_len];
    }

    encryptor->ciphertext[plaintext_len] = '\0';
}

void print_ciphertext(Encryptor *encryptor) {
    printf("Ciphertext: %s\n", encryptor->ciphertext);
}

int main() {
    Encryptor my_encryptor = {
        .key = "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
        .plaintext = "THIS IS A SECRET MESSAGE"
    };

    encrypt(&my_encryptor);
    print_ciphertext(&my_encryptor);

    char *big_plaintext = malloc((1000 * 1000) * sizeof(char));
    for (int i = 0; i < (1000 * 1000); i++) {
        big_plaintext[i] = 'A';
    }
    big_plaintext[1000 * 1000] = '\0';

    encrypt(&my_encryptor);
    print_ciphertext(&my_encryptor);

    return 0;
}
