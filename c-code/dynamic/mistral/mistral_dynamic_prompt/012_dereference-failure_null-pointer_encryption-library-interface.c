#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *ciphertext;
} Encryptor;

Encryptor create_encryptor(char *key) {
    Encryptor encryptor;
    encryptor.key = key;
    encryptor.ciphertext = (char*) malloc(strlen(key) * 2); // Allocate space for double the length of key
    return encryptor;
}

void encrypt(Encryptor *encryptor) {
    for (int i = 0; encryptor->key[i] != '\0'; ++i) {
        encryptor->ciphertext[i] = encryptor->key[i] + 3; // Simple encryption method (adding 3 to each character)
    }
}

void print_ciphertext(Encryptor *encryptor) {
    printf("Ciphertext: %s\n", encryptor->ciphertext);
}

int main() {
    Encryptor my_encryptor = create_encryptor("SECRET_KEY");
    encrypt(&my_encryptor);
    print_ciphertext(&my_encryptor);

    char *null_key = NULL;
    Encryptor broken_encryptor = create_encryptor(null_key); // Null key provided, creating a null pointer exception
    encrypt(&broken_encryptor); // Attempt to use the broken_encryptor, resulting in undefined behavior

    return 0;
}
