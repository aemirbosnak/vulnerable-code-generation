//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/aes.h>

#define BLOCK_SIZE 16

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext) {
    AES_KEY enc_key;
    AES_set_encrypt_key(key, 128, &enc_key);
    AES_cbc_encrypt(plaintext, ciphertext, plaintext_len, &enc_key, iv, AES_ENCRYPT);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext) {
    AES_KEY dec_key;
    AES_set_decrypt_key(key, 128, &dec_key);
    AES_cbc_encrypt(ciphertext, plaintext, ciphertext_len, &dec_key, iv, AES_DECRYPT);
}

int main() {
    unsigned char key[] = "1234567890123456";
    unsigned char iv[] = "1234567890123456";
    unsigned char ciphertext[64];
    unsigned char plaintext[64];
    char input[100];
    int length;

    printf("Enter a message to encrypt: ");
    fgets(input, 100, stdin);
    length = strlen(input);
    if (input[length-1] == '\n') {
        input[length-1] = '\0';
        length--;
    }

    if (length > 64) {
        printf("Message too long. Max length is 64 characters.\n");
        exit(1);
    }

    memset(plaintext, 0, 64);
    strncpy(plaintext, input, length);

    encrypt(plaintext, BLOCK_SIZE, key, iv, ciphertext);

    printf("\nEncrypted message: ");
    for (int i=0; i<BLOCK_SIZE; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    decrypt(ciphertext, BLOCK_SIZE, key, iv, plaintext);
    printf("Decrypted message: %s\n", plaintext);

    return 0;
}