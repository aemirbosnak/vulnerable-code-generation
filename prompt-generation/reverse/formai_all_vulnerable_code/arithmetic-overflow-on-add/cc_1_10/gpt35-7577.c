//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<openssl/evp.h>

// Function to encrypt plaintext
int encrypt(unsigned char *plaintext, int plaintext_len, 
            unsigned char *key, unsigned char *iv,
            unsigned char *ciphertext){
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    if(!(ctx = EVP_CIPHER_CTX_new()))
        return -1;

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        return -1;

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        return -1;
    ciphertext_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        return -1;
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

// Function to decrypt ciphertext
int decrypt(unsigned char *ciphertext, int ciphertext_len,
            unsigned char *key, unsigned char *iv, 
            unsigned char *plaintext){
            
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;
    
    if(!(ctx = EVP_CIPHER_CTX_new()))
        return -1;

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        return -1;

    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        return -1;
    plaintext_len = len;

    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
        return -1;
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

// Main function to test encryption and decryption
int main(){
    unsigned char *key = (unsigned char *)"01234567890123456789012345678901";
    unsigned char *iv = (unsigned char *)"0123456789012345";

    char plaintext[100] = "This is a test plaintext.";
    size_t plaintext_len = strlen(plaintext);
    unsigned char ciphertext[1000];
    unsigned char decryptedtext[1000];

    int ciphertext_len = encrypt(plaintext, plaintext_len, key, iv, ciphertext);
    printf("Ciphertext is:\n");
    for (int i = 0; i < ciphertext_len; i++){
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    int decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);
    decryptedtext[decryptedtext_len] = '\0';

    printf("Decrypted text is:\n");
    printf("%s\n", decryptedtext);

    return 0;
}