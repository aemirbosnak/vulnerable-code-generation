//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024
#define KEY_SIZE 32
#define IV_SIZE 16

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

void encrypt(unsigned char *plaintext, int plaintext_len, 
             unsigned char *key, unsigned char *iv,
             unsigned char *ciphertext, int *ciphertext_len) {
    EVP_CIPHER_CTX *ctx;
    
    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, ciphertext_len, plaintext, plaintext_len))
        handleErrors();

    int len;
    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + *ciphertext_len, &len))
        handleErrors();
    
    *ciphertext_len += len;
    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, 
             unsigned char *key, unsigned char *iv,
             unsigned char *plaintext, int *plaintext_len) {
    EVP_CIPHER_CTX *ctx;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_DecryptUpdate(ctx, plaintext, plaintext_len, ciphertext, ciphertext_len))
        handleErrors();

    int len;
    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + *plaintext_len, &len))
        handleErrors();
    
    *plaintext_len += len;
    EVP_CIPHER_CTX_free(ctx);
}

void generate_key_iv(unsigned char *key, unsigned char *iv) {
    if (!RAND_bytes(key, KEY_SIZE)) {
        fprintf(stderr, "Error generating random key.\n");
        exit(EXIT_FAILURE);
    }
    if (!RAND_bytes(iv, IV_SIZE)) {
        fprintf(stderr, "Error generating random IV.\n");
        exit(EXIT_FAILURE);
    }
}

void display_hexa(unsigned char *buf, int len) {
    for (int i = 0; i < len; i++) {
        printf("%02x", buf[i]);
    }
    printf("\n");
}

int main() {
    unsigned char key[KEY_SIZE]; 
    unsigned char iv[IV_SIZE];  
    unsigned char plaintext[BUFFER_SIZE] = "This is a sample plaintext message to encrypt!";
    unsigned char ciphertext[BUFFER_SIZE + EVP_MAX_BLOCK_LENGTH]; 
    unsigned char decryptedtext[BUFFER_SIZE]; 

    int decryptedtext_len, ciphertext_len;

    printf("Generating key and IV...\n");
    generate_key_iv(key, iv);
    
    printf("Plaintext: %s\n", plaintext);
    
    // Encrypt the plaintext
    encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext, &ciphertext_len);
    
    printf("Ciphertext: ");
    display_hexa(ciphertext, ciphertext_len);
    
    // Decrypt the ciphertext
    decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext, &decryptedtext_len);
    decryptedtext[decryptedtext_len] = '\0'; // NULL terminate the decrypted text

    printf("Decrypted text: %s\n", decryptedtext);
    
    // Display keys and IV in hexadecimal
    printf("Key: ");
    display_hexa(key, sizeof(key));
    printf("IV: ");
    display_hexa(iv, sizeof(iv));

    // The paranoid part: Avoid storing key and IV in plaintext in any logs.
    FILE *fp = fopen("keys.txt", "w");
    if (!fp) {
        fprintf(stderr, "Can't open keys.txt for writing.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "Key: ");
    for (int i = 0; i < KEY_SIZE; i++) {
        fprintf(fp, "%02x", key[i]);
    }
    fprintf(fp, "\nIV: ");
    for (int i = 0; i < IV_SIZE; i++) {
        fprintf(fp, "%02x", iv[i]);
    }
    fprintf(fp, "\n");
    fclose(fp);

    printf("Keys and IV saved to keys.txt securely. Do not share this file!\n");

    return 0;
}