//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_KEY_LENGTH 256 // AES key length in bits

void handleErrors() {
    fprintf(stderr, "An error occurred.\n");
    exit(EXIT_FAILURE);
}

void generateAESKey(unsigned char *key, size_t length) {
    if (!RAND_bytes(key, length)) {
        handleErrors();
    }
}

void aesEncrypt(unsigned char *input, unsigned char *output, unsigned char *key, unsigned char *iv) {
    AES_KEY encryptKey;
    if (AES_set_encrypt_key(key, AES_KEY_LENGTH, &encryptKey) < 0) {
        handleErrors();
    }
    AES_cbc_encrypt(input, output, AES_BLOCK_SIZE, &encryptKey, iv, AES_ENCRYPT);
}

void aesDecrypt(unsigned char *input, unsigned char *output, unsigned char *key, unsigned char *iv) {
    AES_KEY decryptKey;
    if (AES_set_decrypt_key(key, AES_KEY_LENGTH, &decryptKey) < 0) {
        handleErrors();
    }
    AES_cbc_encrypt(input, output, AES_BLOCK_SIZE, &decryptKey, iv, AES_DECRYPT);
}

int main() {
    unsigned char key[AES_KEY_LENGTH / 8]; // AES key
    unsigned char iv[AES_BLOCK_SIZE]; // Initialization vector
    unsigned char plaintext[] = "This is a secret message.";
    unsigned char ciphertext[AES_BLOCK_SIZE]; // Placeholder for ciphertext
    unsigned char decryptedtext[AES_BLOCK_SIZE]; // Placeholder for decrypted text

    // Generate a random AES key
    generateAESKey(key, sizeof(key));

    // Generate a random IV
    if (!RAND_bytes(iv, sizeof(iv))) {
        handleErrors();
    }

    // Ensure plaintext is a multiple of AES_BLOCK_SIZE
    size_t pl_len = strlen((char *)plaintext);
    while (pl_len % AES_BLOCK_SIZE != 0) {
        plaintext[pl_len++] = '\0'; // Pad with null bytes
    }

    // Encrypt the plaintext
    printf("Plaintext: %s\n", plaintext);
    aesEncrypt(plaintext, ciphertext, key, iv);
    printf("Ciphertext (hex): ");
    for (int i = 0; i < sizeof(ciphertext); i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the ciphertext
    aesDecrypt(ciphertext, decryptedtext, key, iv);
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}