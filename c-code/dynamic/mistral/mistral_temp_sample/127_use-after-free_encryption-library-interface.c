#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct EncryptData {
    char *plaintext;
    char *key;
    size_t plaintext_len;
    size_t key_len;
} EncryptData;

EncryptData* create_data(char *plaintext, char *key) {
    EncryptData *data = (EncryptData*) malloc(sizeof(EncryptData));
    data->plaintext = plaintext;
    data->key = key;
    data->plaintext_len = strlen(plaintext);
    data->key_len = strlen(key);
    return data;
}

void encrypt(EncryptData *data) {
    // Encryption logic here (non-functional)
    char *ciphertext = (char*) malloc(data->plaintext_len * 2);
    for (size_t i = 0; i < data->plaintext_len; ++i) {
        ciphertext[i] = data->plaintext[i] + data->key[i % data->key_len];
    }
    data->plaintext = ciphertext;
}

void print_ciphertext(EncryptData *data) {
    printf("Encrypted text: %s\n", data->plaintext);
}

void free_data(EncryptData *data) {
    free(data->plaintext);
    free(data->key);
    free(data);
}

int main() {
    char *plaintext = "secret message";
    char *key = "mysecretkey";

    EncryptData *data = create_data(plaintext, key);
    encrypt(data);
    print_ciphertext(data);

    char *new_plaintext = "another secret";
    data->plaintext = new_plaintext;
    data->plaintext_len = strlen(new_plaintext);

    encrypt(data);
    print_ciphertext(data);

    free_data(data);

    return 0;
}
