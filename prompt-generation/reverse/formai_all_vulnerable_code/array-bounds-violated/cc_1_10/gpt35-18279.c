//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/evp.h>

// Function to print output in hexadecimal format
void print_hex(unsigned char *output, int length) {
    for(int i=0; i<length; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");
}

int main(void) {
    // Encryption parameters
    const EVP_CIPHER *cipher;
    unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];
    const char *plaintext = "Hello World!";
    int plaintext_length = strlen(plaintext);
    unsigned char encrypted_text[1024], decrypted_text[1024];
    int ciphertext_length, decrypted_length;

    // Initialize cipher and generate random key and IV values
    OpenSSL_add_all_algorithms();
    cipher = EVP_get_cipherbyname("aes-256-cbc");
    if(!cipher) {
        printf("Cipher not available.\n");
        exit(-1);
    }
    if(!RAND_bytes(key, EVP_CIPHER_key_length(cipher))) {
        printf("Error generating key.\n");
        exit(-1);
    }
    if(!RAND_bytes(iv, EVP_CIPHER_iv_length(cipher))) {
        printf("Error generating IV.\n");
        exit(-1);
    }

    // Encrypt plaintext
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, cipher, NULL, key, iv);
    if(!EVP_EncryptUpdate(ctx, encrypted_text, &ciphertext_length, (unsigned char *)plaintext, plaintext_length)) {
        printf("Error encrypting.\n");
        EVP_CIPHER_CTX_free(ctx);
        exit(-1);
    }
    if(!EVP_EncryptFinal_ex(ctx, encrypted_text + ciphertext_length, &ciphertext_length)) {
        printf("Error finalizing encryption.\n");
        EVP_CIPHER_CTX_free(ctx);
        exit(-1);
    }
    ciphertext_length += plaintext_length;
    EVP_CIPHER_CTX_free(ctx);
    printf("Encrypted text: ");
    print_hex(encrypted_text, ciphertext_length);

    // Decrypt ciphertext
    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, cipher, NULL, key, iv);
    if(!EVP_DecryptUpdate(ctx, decrypted_text, &decrypted_length, encrypted_text, ciphertext_length)) {
        printf("Error decrypting.\n");
        EVP_CIPHER_CTX_free(ctx);
        exit(-1);
    }
    if(!EVP_DecryptFinal_ex(ctx, decrypted_text + decrypted_length, &decrypted_length)) {
        printf("Error finalizing decryption.\n");
        EVP_CIPHER_CTX_free(ctx);
        exit(-1);
    }
    decrypted_length += ciphertext_length;
    EVP_CIPHER_CTX_free(ctx);
    decrypted_text[decrypted_length] = '\0';
    printf("Decrypted text: %s\n", decrypted_text);

    // Clean up
    EVP_cleanup();
    return 0;
}