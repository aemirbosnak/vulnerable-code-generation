//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define KEY_SIZE 16
#define IV_SIZE 16
#define BLOCK_SIZE 16
#define PLAINFORMAT

int main() {
    unsigned char key[KEY_SIZE];
    unsigned char iv[IV_SIZE];
    unsigned char plaintext[100];
    unsigned char ciphertext[100];
    unsigned char decrypted_text[100];
    int plaintext_len, ciphertext_len, decrypted_text_len;
    EVP_CIPHER_CTX *ctx;

    RAND_bytes(key, KEY_SIZE);
    RAND_bytes(iv, IV_SIZE);

    printf("Key: ");
    for (int i = 0; i < KEY_SIZE; i++) {
        printf("%02x ", key[i]);
    }
    printf("\n");

    printf("IV: ");
    for (int i = 0; i < IV_SIZE; i++) {
        printf("%02x ", iv[i]);
    }
    printf("\n");

    strcpy(plaintext, "This is a secret message.");
    plaintext_len = strlen(plaintext);

    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, plaintext_len);
    EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len);
    EVP_CIPHER_CTX_free(ctx);

    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x ", ciphertext[i]);
    }
    printf("\n");

    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    EVP_DecryptUpdate(ctx, decrypted_text, &decrypted_text_len, ciphertext, ciphertext_len);
    EVP_DecryptFinal_ex(ctx, decrypted_text + decrypted_text_len, &decrypted_text_len);
    EVP_CIPHER_CTX_free(ctx);

    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}