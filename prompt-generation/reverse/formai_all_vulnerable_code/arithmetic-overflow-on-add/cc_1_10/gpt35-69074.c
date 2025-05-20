//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// Function to encrypt given plain text using AES-128-CBC algorithm and secret key
int encrypt(char *plain_text, int plain_text_len, char *key, char *cipher_text){
    EVP_CIPHER_CTX *ctx;
    int len;
    int cipher_text_len;

    // Initialize the encryption context with AES-128-CBC algorithm and secret key
    if(!(ctx = EVP_CIPHER_CTX_new()))
        return -1;

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, NULL))
        return -1;

    EVP_CIPHER_CTX_set_padding(ctx, 0); // to turn off padding

    if(1 != EVP_EncryptUpdate(ctx, cipher_text, &len, plain_text, plain_text_len))
        return -1;

    cipher_text_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, cipher_text+len, &len))
        return -1;

    cipher_text_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return cipher_text_len;
}

// Function to decrypt given cipher text using AES-128-CBC algorithm and secret key
int decrypt(char *cipher_text, int cipher_text_len, char *key, char *plain_text){
    EVP_CIPHER_CTX *ctx;
    int len;
    int plain_text_len;
    int res;

    // Initialize the decryption context with AES-128-CBC algorithm and secret key
    if(!(ctx = EVP_CIPHER_CTX_new()))
        return -1;

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, NULL))
        return -1;

    EVP_CIPHER_CTX_set_padding(ctx, 0); // to turn off padding

    if(1 != EVP_DecryptUpdate(ctx, plain_text, &len, cipher_text, cipher_text_len))
        return -1;

    plain_text_len = len;

    res = EVP_DecryptFinal_ex(ctx, plain_text+len, &len);

    if(res == 0)
        return -1;

    plain_text_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return plain_text_len;
}

int main(){
    char *key = "B3A5FC0A037AB2DBF49C779E55A0ED5B"; // secret key in hexadecimal format
    char *plain_text = "This is a secret message!"; // plain text
    int plain_text_len = strlen(plain_text); // length of plain text
    char cipher_text[1024]; // buffer for cipher text
    int cipher_text_len; // length of cipher text
    char decrypted_text[1024]; // buffer for decrypted text
    int decrypted_text_len; // length of decrypted text

    printf("Plain text: %s\n", plain_text);

    // Encrypt the plain text using AES-128-CBC algorithm and secret key
    cipher_text_len = encrypt(plain_text, plain_text_len, key, cipher_text);

    if(cipher_text_len == -1)
        printf("Error encrypting data\n");
    else
        printf("Cipher text: %s\n", cipher_text);

    // Decrypt the cipher text using AES-128-CBC algorithm and secret key
    decrypted_text_len = decrypt(cipher_text, cipher_text_len, key, decrypted_text);

    if(decrypted_text_len == -1)
        printf("Error decrypting data\n");
    else
        printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}