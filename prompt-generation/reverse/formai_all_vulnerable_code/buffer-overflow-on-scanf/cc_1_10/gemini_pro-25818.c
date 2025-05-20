//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

// Encryption: Sealing Secrets in Binary Shadows

static void aes_encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *ciphertext,
                        unsigned char *key) {
    AES_KEY aes_key;
    if (AES_set_encrypt_key(key, 128, &aes_key) < 0) {
        printf("Error in AES encryption key setup.\n");
        exit(1);
    }

    AES_encrypt(plaintext, ciphertext, &aes_key);
}

// Decryption: Unveiling Encrypted Treasures

static void aes_decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *plaintext,
                        unsigned char *key) {
    AES_KEY aes_key;
    if (AES_set_decrypt_key(key, 128, &aes_key) < 0) {
        printf("Error in AES decryption key setup.\n");
        exit(1);
    }

    AES_decrypt(ciphertext, plaintext, &aes_key);
}

// Generate a Secure, Unpredictable Key

static void generate_key(unsigned char *key) {
    FILE *fp = fopen("/dev/urandom", "rb");
    if (fp == NULL) {
        printf("Error opening /dev/urandom.\n");
        exit(1);
    }

    fread(key, 16, 1, fp);
    fclose(fp);
}

int main() {
    printf("\nWelcome to the Cryptographic Vault, where your secrets are safe.\n");

    // Enter your precious plaintext
    printf("Enter the plaintext to encrypt: ");
    char plaintext[1024];
    scanf(" %[^\n]s", plaintext);

    // Generate a secure key
    unsigned char key[16];
    generate_key(key);

    // Seal the plaintext in encrypted ciphertext
    int plaintext_len = strlen(plaintext);
    unsigned char ciphertext[1024];
    aes_encrypt((unsigned char *)plaintext, plaintext_len, ciphertext, key);

    // Display the encrypted ciphertext
    printf("\nEncrypted ciphertext: ");
    for (int i = 0; i < plaintext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Decipher theciphertext, revealing the plaintext
    unsigned char decryptedtext[1024];
    aes_decrypt(ciphertext, plaintext_len, decryptedtext, key);

    decryptedtext[plaintext_len] = '\0';
    printf("\nDecrypted plaintext: %s\n", decryptedtext);
    printf("\nYour secrets, safe and sound within this cryptographic embrace.\n");

    return 0;
}