//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/evp.h>

int main()
{
    printf("Welcome to my Cryptography Implementation example program!\n");

    // Initialize the OpenSSL library
    OpenSSL_add_all_algorithms();

    // Choose a message to encrypt
    char plaintext[] = "This is my secret message!";

    // Generate a random key
    unsigned char key[16];
    RAND_bytes(key, sizeof(key));

    // Generate a random initialization vector
    unsigned char iv[16];
    RAND_bytes(iv, sizeof(iv));

    // Allocate memory for the ciphertext
    unsigned char ciphertext[sizeof(plaintext)];

    // Initialize the encryption context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit(ctx, EVP_aes_256_cbc(), key, iv);

    // Encrypt the message
    int len;
    EVP_EncryptUpdate(ctx, ciphertext, &len, (unsigned char *) plaintext, sizeof(plaintext));

    // Finalize the encryption
    int ciphertext_len = len;
    EVP_EncryptFinal(ctx, ciphertext + len, &len);
    ciphertext_len += len;

    // Print the original message and the ciphertext
    printf("Original message: %s\n", plaintext);
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    // Initialize the decryption context
    EVP_DecryptInit(ctx, EVP_aes_256_cbc(), key, iv);

    // Allocate memory for the decrypted message
    unsigned char decrypted_message[sizeof(plaintext)];

    // Decrypt the message
    EVP_DecryptUpdate(ctx, decrypted_message, &len, ciphertext, ciphertext_len);

    // Finalize the decryption
    int decrypted_message_len = len;
    EVP_DecryptFinal(ctx, decrypted_message + len, &len);
    decrypted_message_len += len;

    // Print the decrypted message
    decrypted_message[decrypted_message_len] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    return 0;
}