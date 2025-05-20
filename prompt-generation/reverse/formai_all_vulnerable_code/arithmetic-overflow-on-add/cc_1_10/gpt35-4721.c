//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// Function to perform SHA-256 hash
void sha256_hash(char *input, unsigned char *output){
    EVP_MD_CTX *mdctx;

    const EVP_MD *md;
    md = EVP_get_digestbyname("SHA256");

    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, input, strlen(input));
    EVP_DigestFinal_ex(mdctx, output, NULL);
    EVP_MD_CTX_free(mdctx);
}

// Function to perform encryption using AES-256 CBC mode
void aes_256_cbc_encrypt(char *input, unsigned char *key, unsigned char *iv, unsigned char *output){
    EVP_CIPHER_CTX *ctx;

    const EVP_CIPHER *cipher;
    cipher = EVP_aes_256_cbc();

    int len;
    int ciphertext_len;

    // Create and initialise the context
    if(!(ctx = EVP_CIPHER_CTX_new())) {
        printf("Encryption failed: unable to create context\n");
        return;
    }

    // Initialise the encryption operation
    if(1 != EVP_EncryptInit_ex(ctx, cipher, NULL, key, iv)) {
        printf("Encryption failed: unable to initialise context\n");
        return;
    }

    // Encrypt the plaintext
    if(1 != EVP_EncryptUpdate(ctx, output, &len, input, strlen(input))) {
        printf("Encryption failed: unable to encrypt\n");
        return;
    }
    ciphertext_len = len;

    // Finalise the encryption
    if(1 != EVP_EncryptFinal_ex(ctx, output + len, &len)) {
        printf("Encryption failed: unable to finalise encryption\n");
        return;
    }
    ciphertext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
}

// Function to perform decryption using AES-256 CBC mode
void aes_256_cbc_decrypt(unsigned char *input, int input_len, unsigned char *key, unsigned char *iv, char *output){
    EVP_CIPHER_CTX *ctx;

    const EVP_CIPHER *cipher;
    cipher = EVP_aes_256_cbc();

    int len;
    int plaintext_len;

    // Create and initialise the context
    if(!(ctx = EVP_CIPHER_CTX_new())) {
        printf("Decryption failed: unable to create context\n");
        return;
    }

    // Initialise the decryption operation
    if(!EVP_DecryptInit_ex(ctx, cipher, NULL, key, iv)) {
        printf("Decryption failed: unable to initialise context\n");
        return;
    }

    // Decrypt the ciphertext
    if(!EVP_DecryptUpdate(ctx, output, &len, input, input_len)) {
        printf("Decryption failed: unable to decrypt\n");
        return;
    }
    plaintext_len = len;

    // Finalise the decryption
    if(!EVP_DecryptFinal_ex(ctx, output + len, &len)) {
        printf("Decryption failed: unable to finalise decryption\n");
        return;
    }
    plaintext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
}

int main(){
    char *plaintext = "This is a secret message.";
    unsigned char sha256_output[EVP_MAX_MD_SIZE];
    unsigned char aes_key[EVP_MAX_KEY_LENGTH];
    unsigned char aes_iv[EVP_MAX_IV_LENGTH];
    unsigned char ciphertext[1024];
    char decrypted_text[1024];

    // Generate a random key and iv
    RAND_bytes(aes_key, 32);
    RAND_bytes(aes_iv, 16);

    printf("Plain text : %s\n", plaintext);

    // Hash the plaintext using SHA-256 to generate a key
    sha256_hash(plaintext, sha256_output);
    memcpy(aes_key, sha256_output, EVP_CIPHER_key_length(EVP_aes_256_cbc()));

    // Encrypt the plaintext
    aes_256_cbc_encrypt(plaintext, aes_key, aes_iv, ciphertext);
    printf("Ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++){
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the ciphertext
    aes_256_cbc_decrypt(ciphertext, strlen(plaintext), aes_key, aes_iv, decrypted_text);
    decrypted_text[strlen(plaintext)] = '\0';
    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}