//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// Function to print error message and exit
void printError(char *msg) {
    perror(msg);
    exit(1);
}

// Function to encrypt data with AES256 CBC mode
void encrypt(char *key, char *iv, char *plaintext, size_t plaintextLen, char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len, ciphertextLen;

    // Allocate memory for cipher context
    if (!(ctx = EVP_CIPHER_CTX_new()))
        printError("error: EVP_CIPHER_CTX_new failed\n");

    // Initialise cipher context
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        printError("error: EVP_EncryptInit_ex failed\n");

    // Encrypt plaintext
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintextLen))
        printError("error: EVP_EncryptUpdate failed\n");
    ciphertextLen = len;

    // Finalise encryption
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext+len, &len))
        printError("error: EVP_EncryptFinal_ex failed\n");
    ciphertextLen += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
}

// Function to decrypt data with AES256 CBC mode
void decrypt(char *key, char *iv, char *ciphertext, size_t ciphertextLen, char *plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len, plaintextLen;

    // Allocate memory for cipher context
    if (!(ctx = EVP_CIPHER_CTX_new()))
        printError("error: EVP_CIPHER_CTX_new failed\n");

    // Initialise cipher context
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        printError("error: EVP_DecryptInit_ex failed\n");

    // Decrypt ciphertext
    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertextLen))
        printError("error: EVP_DecryptUpdate failed\n");
    plaintextLen = len;

    // Finalise decryption
    if (1 != EVP_DecryptFinal_ex(ctx, plaintext+len, &len))
        printError("error: EVP_DecryptFinal_ex failed\n");
    plaintextLen += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
}

// Main function
int main() {
    char key[] = "mysecretpassword";  // 256-bit key
    char iv[] = "myinitialvector";    // 128-bit initialisation vector
    char plaintext[] = "Hello, World! This is a test.";  // Plaintext to be encrypted
    char ciphertext[256];  // Encrypted ciphertext
    char decryptedPlaintext[256];   // Decrypted plaintext

    // Encrypt plaintext
    encrypt(key, iv, plaintext, strlen(plaintext)+1, ciphertext);

    // Print ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < strlen(plaintext)+16; i++) {
        printf("%02x ", (unsigned char)ciphertext[i]);
    }
    printf("\n");

    // Decrypt ciphertext
    decrypt(key, iv, ciphertext, strlen(plaintext)+16, decryptedPlaintext);

    // Print decrypted plaintext
    printf("Decrypted plaintext: %s\n", decryptedPlaintext);

    return 0;
}