#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    char* data;
} EncryptedData;

EncryptedData* create_encrypted_data(char* key, char* data) {
    EncryptedData* new_encrypted_data = malloc(sizeof(EncryptedData));
    new_encrypted_data->key = key;
    new_encrypted_data->data = data;
    return new_encrypted_data;
}

void encrypt_data(EncryptedData* encrypted_data) {
    // Simple XOR encryption for the sake of brevity.
    for (size_t i = 0; encrypted_data->data[i]; ++i) {
        encrypted_data->data[i] ^= encrypted_data->key[i % strlen(encrypted_data->key)];
    }
}

void free_encrypted_data(EncryptedData* encrypted_data) {
    free(encrypted_data->key);
    free(encrypted_data->data);
    free(encrypted_data);
}

int main() {
    char key[] = "secret_key";
    char data[] = "Hello, World!";
    EncryptedData* encrypted_data = create_encrypted_data(key, data);
    encrypt_data(encrypted_data);
    printf("Encrypted Data: %s\n", encrypted_data->data);
    free_encrypted_data(encrypted_data); // Oops, now the memory is leaked!
    system("pause");
    return 0;
}
