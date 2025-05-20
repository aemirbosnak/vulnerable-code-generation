//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16
#define AES_ROUNDS 10

void encrypt(unsigned char* data, size_t data_size, unsigned char* key) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, KEY_SIZE * 8, &aes_key);
    unsigned char* output = (unsigned char*)malloc(data_size);
    AES_encrypt(data, output, &aes_key);
    for (size_t i = 0; i < data_size; i += BLOCK_SIZE) {
        AES_encrypt(data + i, output + i, &aes_key);
    }
    memcpy(data, output, data_size);
    free(output);
}

void decrypt(unsigned char* data, size_t data_size, unsigned char* key) {
    AES_KEY aes_key;
    AES_set_decrypt_key(key, KEY_SIZE * 8, &aes_key);
    unsigned char* output = (unsigned char*)malloc(data_size);
    AES_decrypt(data, output, &aes_key);
    for (size_t i = 0; i < data_size; i += BLOCK_SIZE) {
        AES_decrypt(data + i, output + i, &aes_key);
    }
    memcpy(data, output, data_size);
    free(output);
}

int main() {
    unsigned char data[] = "Hello, World!";
    unsigned char key[] = "1234567890123456";
    encrypt(data, sizeof(data), key);
    printf("Encrypted data: ");
    for (size_t i = 0; i < sizeof(data); i++) {
        printf("%02X", data[i]);
    }
    printf("\n");
    decrypt(data, sizeof(data), key);
    printf("Decrypted data: ");
    for (size_t i = 0; i < sizeof(data); i++) {
        printf("%c", data[i]);
    }
    printf("\n");
    return 0;
}