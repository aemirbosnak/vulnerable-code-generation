//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: interoperable
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <openssl/evp.h>

int main() {
    char plaintext[] = "This is a test message";
    uint8_t key[32] = {0x45, 0x6f, 0x68, 0x60, 0x73, 0x48, 0x41, 0x69, 0x6e, 0x6d, 0x6f, 0x6b, 0x75, 0x6e, 0x61, 0x6d,
                       0x69, 0x73, 0x26, 0x53, 0x68, 0x61, 0x6e, 0x74, 0x69, 0x9c, 0x55, 0x73, 0x74, 0x65, 0x65, 0x6d};
    uint8_t iv[16] = {0x74, 0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20, 0x69, 0x76, 0x3a, 0x65, 0x72, 0x79, 0x74, 0x68};
    uint8_t ciphertext[256], decryptedtext[256];
    int plaintext_len, ciphertext_len, decryptedtext_len;

    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();
    if(ctx == NULL) {
        printf("Error creating context\n");
        return 1;
    }

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        printf("Encryption initialization failed\n");
        return 1;
    }

    plaintext_len = strlen(plaintext);

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, (uint8_t*)plaintext, plaintext_len)) {
        printf("Encryption failed\n");
        return 1;
    }

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len)) {
        printf("Encryption finalization failed\n");
        return 1;
    }

    printf("Ciphertext: ");
    for(int i = 0; i < ciphertext_len; i++) {
        printf("%02x ", ciphertext[i]);
    }

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        printf("Decryption initialization failed\n");
        return 1;
    }

    if(1 != EVP_DecryptUpdate(ctx, decryptedtext, &decryptedtext_len, ciphertext, ciphertext_len)) {
        printf("Decryption failed\n");
        return 1;
    }

    if(1 != EVP_DecryptFinal_ex(ctx, decryptedtext + decryptedtext_len, &decryptedtext_len)) {
        printf("Decryption finalization failed\n");
        return 1;
    }

    decryptedtext[decryptedtext_len] = '\0';

    printf("\nDecrypted text: %s\n", decryptedtext);

    EVP_CIPHER_CTX_free(ctx);

    return 0;
}