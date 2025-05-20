//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/err.h>

int main() {

    OpenSSL_add_all_algorithms();

    // Create input string to be encoded
    char message[] = "Hello, World! This is a cryptography example program.";

    // Set up encryption context
    EVP_CIPHER_CTX *enc_ctx = EVP_CIPHER_CTX_new();
    const EVP_CIPHER *cipher = EVP_get_cipherbyname("AES-256-CBC");

    unsigned char key[EVP_MAX_KEY_LENGTH] = "this is the key"; // Replace with a secure random key
    unsigned char iv[EVP_MAX_IV_LENGTH] = "this is an iv"; // Replace with a secure random iv

    // Initialize encryption context
    EVP_EncryptInit(enc_ctx, cipher, key, iv);

    // Determine output buffer size
    int message_len = strlen(message) + 1;
    int ciphertext_len = message_len + EVP_CIPHER_block_size(cipher);
    unsigned char *ciphertext = (unsigned char *) malloc(ciphertext_len);

    // Encrypt the message
    int len = 0;
    EVP_EncryptUpdate(enc_ctx, ciphertext, &len, (unsigned char *) message, message_len);
    int ciphertext_written = len;

    // Add any final blocks and get final ciphertext length
    EVP_EncryptFinal_ex(enc_ctx, ciphertext + len, &len);
    ciphertext_written += len;

    // Clean up encryption context
    EVP_CIPHER_CTX_free(enc_ctx);

    // Print ciphertext
    printf("Ciphertext:\n");
    for(int i=0; i<ciphertext_written; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n\n");

    // Set up decryption context
    EVP_CIPHER_CTX *dec_ctx = EVP_CIPHER_CTX_new();

    // Initialize decryption context
    EVP_DecryptInit(dec_ctx, cipher, key, iv);

    // Determine decrypted message buffer size
    int decrypted_len = ciphertext_written;
    unsigned char *decrypted_message = (unsigned char *) malloc(decrypted_len);

    // Decrypt the message
    EVP_DecryptUpdate(dec_ctx, decrypted_message, &len, ciphertext, ciphertext_written);
    int decrypted_written = len;

    // Add any final blocks and get final decrypted length
    EVP_DecryptFinal_ex(dec_ctx, decrypted_message + len, &len);
    decrypted_written += len;

    // Clean up decryption context
    EVP_CIPHER_CTX_free(dec_ctx);

    // Print decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    free(ciphertext);
    free(decrypted_message);

    ERR_free_strings();
    return 0;
}