//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/bio.h>
#include <openssl/evp.h>

void generate_key(unsigned char* key, int keylen) {
    int i;
    for (i = 0; i < keylen; i++)
        key[i] = rand() % 256;
}

int main(void) {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate a random 128-bit (16-byte) key
    unsigned char key[16];
    generate_key(key, 16);

    // Print the generated key
    printf("Generated Key: ");
    int i;
    for (i = 0; i < 16; i++)
        printf("%02X ", key[i]);
    printf("\n\n");

    // Initialize the OpenSSL library
    OPENSSL_init_ssl(0, NULL);

    // Allocate an EVP context
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    
    // Use AES-128 in CBC mode
    EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, NULL);
    
    // Input plaintext
    unsigned char* plaintext = "Hello, world!";
    int plaintext_len = strlen(plaintext);
    
    // Determine maximum possible ciphertext length
    int ciphertext_maxlen = plaintext_len + EVP_CIPHER_block_size(EVP_aes_128_cbc()) - 1;
    unsigned char* ciphertext = malloc(ciphertext_maxlen);
    
    // Encrypt the plaintext
    int ciphertext_len;
    EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, plaintext_len);
    
    // Finalize the encryption
    EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len);
    ciphertext_len += ciphertext_len;

    // Print the ciphertext
    printf("Ciphertext: ");
    for (i = 0; i < ciphertext_len; i++)
        printf("%02X ", ciphertext[i]);
    printf("\n\n");

    // Decryption
    // Use the same key and IV as before
    EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, NULL);
    
    // Determine maximum possible plaintext length
    int plaintext_maxlen = ciphertext_len + EVP_CIPHER_block_size(EVP_aes_128_cbc()) - 1;
    unsigned char* decrypted = malloc(plaintext_maxlen);
    
    // Decrypt the ciphertext
    int decrypted_len;
    EVP_DecryptUpdate(ctx, decrypted, &decrypted_len, ciphertext, ciphertext_len);
    
    // Finalize the decryption
    EVP_DecryptFinal_ex(ctx, decrypted + decrypted_len, &decrypted_len);
    decrypted_len += decrypted_len;
    decrypted[decrypted_len] = '\0';

    // Print the decrypted plaintext
    printf("Decrypted Plaintext: %s\n", decrypted);
    
    // Free memory
    EVP_CIPHER_CTX_free(ctx);
    free(ciphertext);
    free(decrypted);

    return 0;
}