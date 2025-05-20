//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main() {

    // Let's generate a random key using the EVP library
    EVP_CIPHER_CTX *ctx;
    const EVP_CIPHER *cipher_type;
    unsigned char key[16], iv[16];
    int key_length = 16, iv_length = 16;

    // Initialize the context
    ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        printf("Context could not be created\n");
        return -1;
    }

    // Let's select a cipher type - Symmetric cipher - AES-128-CBC
    cipher_type = EVP_aes_128_cbc();
    if (cipher_type == NULL) {
        printf("Cipher type selection failed\n");
        return -1;
    }

    // Generate the random key and initialization vector (IV)
    if (!EVP_BytesToKey(cipher_type, EVP_sha256(),
                        NULL, key, key_length, 1, iv, NULL)) {
        printf("Random key and IV generation failed\n");
        return -1;
    }

    // Let's print the random key and IV
    printf("Random key generated: ");
    for (int i = 0; i < key_length; i++) {
        printf("%02x", key[i]);
    }
    printf("\n");

    printf("IV generated: ");
    for (int i = 0; i < iv_length; i++) {
        printf("%02x", iv[i]);
    }
    printf("\n");

    // Now we will use this key and iv to encrypt a message
    char *message = "Hello World!";
    int message_length = strlen(message);

    // Allocate memory for the encrypted message
    unsigned char *enc_message = (unsigned char *) malloc(message_length + 16);

    int enc_message_length = 0;

    // Initialize the encryption context
    if (!EVP_EncryptInit_ex(ctx, cipher_type, NULL, key, iv)) {
        printf("Encryption initialization failed\n");
        return -1;
    }

    // Encrypt the message
    if (!EVP_EncryptUpdate(ctx, enc_message, &enc_message_length, (unsigned char *) message, message_length)) {
        printf("Encryption failed\n");
        return -1;
    }

    int final_length = 0;
    if (!EVP_EncryptFinal_ex(ctx, enc_message + enc_message_length, &final_length)) {
        printf("Final encryption step failed\n");
        return -1;
    }
    enc_message_length += final_length;

    printf("Encrypted message: ");
    for (int i = 0; i < enc_message_length; i++) {
        printf("%02x", enc_message[i]);
    }
    printf("\n");

    // Now let's decrypt the message
    unsigned char *dec_message = (unsigned char *) malloc(enc_message_length + 16);
    int dec_message_length = 0;

    // Initialize the decryption context
    if (!EVP_DecryptInit_ex(ctx, cipher_type, NULL, key, iv)) {
        printf("Decryption initialization failed\n");
        return -1;
    }

    // Decrypt the message
    if (!EVP_DecryptUpdate(ctx, dec_message, &dec_message_length, enc_message, enc_message_length)) {
        printf("Decryption failed\n");
        return -1;
    }

    final_length = 0;
    if (!EVP_DecryptFinal_ex(ctx, dec_message + dec_message_length, &final_length)) {
        printf("Final decryption step failed\n");
        return -1;
    }
    dec_message_length += final_length;

    printf("Decrypted message: %s\n", dec_message);

    // Cleanup
    EVP_CIPHER_CTX_free(ctx);
    free(enc_message);
    free(dec_message);

    return 0;
}