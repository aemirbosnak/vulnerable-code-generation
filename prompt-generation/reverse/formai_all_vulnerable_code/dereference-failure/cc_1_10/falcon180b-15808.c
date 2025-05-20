//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/evp.h>

#define MAX_KEY_SIZE 32
#define MAX_IV_SIZE 16
#define MAX_DATA_SIZE 1024

int main(void) {
    int key_size, iv_size, data_size;
    char *key = NULL, *iv = NULL, *data = NULL, *result = NULL;
    EVP_CIPHER_CTX *ctx = NULL;
    int len;

    // Get key, iv, and data sizes from user
    printf("Enter key size (1-32): ");
    scanf("%d", &key_size);
    printf("Enter iv size (1-16): ");
    scanf("%d", &iv_size);
    printf("Enter data size (1-1024): ");
    scanf("%d", &data_size);

    // Allocate memory for key, iv, and data
    key = malloc(key_size + 1);
    iv = malloc(iv_size + 1);
    data = malloc(data_size + 1);

    // Generate key and iv
    srand(time(NULL));
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 256;
    }
    for (int i = 0; i < iv_size; i++) {
        iv[i] = rand() % 256;
    }

    // Get data from user
    printf("Enter data to encrypt: ");
    fgets(data, data_size + 1, stdin);
    data[strcspn(data, "\n")] = '\0';

    // Encrypt data
    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    EVP_EncryptUpdate(ctx, NULL, &len, data, data_size);
    result = malloc(len + 1);
    EVP_EncryptFinal_ex(ctx, result, &len);

    // Print encrypted data
    printf("Encrypted data: %s\n", result);

    // Decrypt data
    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    EVP_DecryptUpdate(ctx, NULL, &len, result, len);
    EVP_DecryptFinal_ex(ctx, result, &len);

    // Print decrypted data
    printf("Decrypted data: %s\n", result);

    // Clean up
    free(key);
    free(iv);
    free(data);
    free(result);
    EVP_CIPHER_CTX_free(ctx);

    return 0;
}