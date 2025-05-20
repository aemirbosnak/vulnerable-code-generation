//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <pthread.h>
#include <unistd.h>

#define AES_KEY_LENGTH 32 // AES-256
#define AES_BLOCK_SIZE 16
#define BUFFER_SIZE 1024

typedef struct {
    unsigned char *plaintext;
    int plaintext_len;
    unsigned char *ciphertext;
    int ciphertext_len;
    unsigned char *key;
    unsigned char *iv;
} EncryptionData;

// Function to handle AES Encryption
void *encrypt(void *arg) {
    EncryptionData *data = (EncryptionData *)arg;
    EVP_CIPHER_CTX *ctx;

    if (!(ctx = EVP_CIPHER_CTX_new())) {
        perror("Failed to create context");
        return NULL;
    }

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, data->key, data->iv) != 1) {
        perror("Failed to initialize encryption");
        EVP_CIPHER_CTX_free(ctx);
        return NULL;
    }

    if (EVP_EncryptUpdate(ctx, data->ciphertext, &data->ciphertext_len, data->plaintext, data->plaintext_len) != 1) {
        perror("Failed to encrypt data");
        EVP_CIPHER_CTX_free(ctx);
        return NULL;
    }

    int len;
    if (EVP_EncryptFinal_ex(ctx, data->ciphertext + data->ciphertext_len, &len) != 1) {
        perror("Failed to finalize encryption");
        EVP_CIPHER_CTX_free(ctx);
        return NULL;
    }
    data->ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return NULL;
}

// Function to handle AES Decryption
void *decrypt(void *arg) {
    EncryptionData *data = (EncryptionData *)arg;
    EVP_CIPHER_CTX *ctx;

    if (!(ctx = EVP_CIPHER_CTX_new())) {
        perror("Failed to create context");
        return NULL;
    }

    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, data->key, data->iv) != 1) {
        perror("Failed to initialize decryption");
        EVP_CIPHER_CTX_free(ctx);
        return NULL;
    }

    if (EVP_DecryptUpdate(ctx, data->plaintext, &data->plaintext_len, data->ciphertext, data->ciphertext_len) != 1) {
        perror("Failed to decrypt data");
        EVP_CIPHER_CTX_free(ctx);
        return NULL;
    }

    int len;
    if (EVP_DecryptFinal_ex(ctx, data->plaintext + data->plaintext_len, &len) != 1) {
        perror("Failed to finalize decryption");
        EVP_CIPHER_CTX_free(ctx);
        return NULL;
    }
    data->plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return NULL;
}

// Main function
int main() {
    unsigned char key[AES_KEY_LENGTH] = "01234567890123456789012345678901"; // 32 bytes key
    unsigned char iv[AES_BLOCK_SIZE] = "0123456789012345"; // 16 bytes IV

    char input[BUFFER_SIZE];
    printf("Enter a message to encrypt: ");
    fgets(input, BUFFER_SIZE, stdin);
    int input_len = strlen(input);
    if (input[input_len - 1] == '\n') {
        input[input_len - 1] = '\0';  // Remove newline character
        input_len--;
    }

    unsigned char *ciphertext = malloc(input_len + AES_BLOCK_SIZE);
    unsigned char *decryptedtext = malloc(input_len + AES_BLOCK_SIZE);
    EncryptionData data = {0};
    data.plaintext = (unsigned char *)input;
    data.plaintext_len = input_len;
    data.ciphertext = ciphertext;
    data.key = key;
    data.iv = iv;
    data.ciphertext_len = 0;

    pthread_t encrypt_thread, decrypt_thread;

    // encrypt the message
    pthread_create(&encrypt_thread, NULL, encrypt, (void *)&data);
    pthread_join(encrypt_thread, NULL);

    printf("Encrypted ciphertext is: ");
    for (int i = 0; i < data.ciphertext_len; i++) {
        printf("%02x", data.ciphertext[i]);
    }
    printf("\n");

    // Reset plaintext and prepare for decryption
    data.plaintext = decryptedtext;
    data.plaintext_len = input_len;

    // decrypt the message
    pthread_create(&decrypt_thread, NULL, decrypt, (void *)&data);
    pthread_join(decrypt_thread, NULL);

    printf("Decrypted message is: %s\n", decryptedtext);

    free(ciphertext);
    free(decryptedtext);
    return 0;
}