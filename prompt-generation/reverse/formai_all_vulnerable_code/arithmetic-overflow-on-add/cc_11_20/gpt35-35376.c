//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main() {
    // The plaintext message we want to encrypt
    char plaintext[] = "Hello, World!";
    printf("Original message: %s\n", plaintext);

    // Generate a random key and IV for AES encryption
    unsigned char key[EVP_MAX_KEY_LENGTH];
    unsigned char iv[EVP_MAX_IV_LENGTH];
    if (!RAND_bytes(key, 16)) {
        perror("Error generating key");
        return EXIT_FAILURE;
    }
    if (!RAND_bytes(iv, 16)) {
        perror("Error generating IV");
        return EXIT_FAILURE;
    }

    // Set up the encryption context
    EVP_CIPHER_CTX *context = EVP_CIPHER_CTX_new();
    if (context == NULL) {
        perror("Error creating encryption context");
        return EXIT_FAILURE;
    }
    if (!EVP_EncryptInit_ex(context, EVP_aes_128_cbc(), NULL, key, iv)) {
        perror("Error initializing encryption context");
        return EXIT_FAILURE;
    }

    // Determine the size of the ciphertext buffer
    int plaintext_size = strlen(plaintext) + 1; // Include null terminator
    int block_size = EVP_CIPHER_block_size(EVP_aes_128_cbc());
    int ciphertext_size = ((plaintext_size + block_size - 1) / block_size) * block_size;

    // Allocate memory for the ciphertext buffer
    unsigned char *ciphertext = malloc(ciphertext_size);
    if (ciphertext == NULL) {
        perror("Error allocating memory");
        return EXIT_FAILURE;
    }

    // Encrypt the plaintext message
    int encrypted_size;
    if (!EVP_EncryptUpdate(context, ciphertext, &encrypted_size, plaintext, plaintext_size)) {
        perror("Error encrypting message");
        return EXIT_FAILURE;
    }

    // Finalize the encryption process and get the final ciphertext size
    int final_size;
    if (!EVP_EncryptFinal_ex(context, ciphertext + encrypted_size, &final_size)) {
        perror("Error finalizing encryption process");
        return EXIT_FAILURE;
    }
    encrypted_size += final_size;

    // Clean up the encryption context
    EVP_CIPHER_CTX_free(context);

    // Print the ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < encrypted_size; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Set up the decryption context
    context = EVP_CIPHER_CTX_new();
    if (context == NULL) {
        perror("Error creating decryption context");
        return EXIT_FAILURE;
    }
    if (!EVP_DecryptInit_ex(context, EVP_aes_128_cbc(), NULL, key, iv)) {
        perror("Error initializing decryption context");
        return EXIT_FAILURE;
    }

    // Allocate memory for the plaintext buffer
    unsigned char *decrypted_plaintext = malloc(plaintext_size);
    if (decrypted_plaintext == NULL) {
        perror("Error allocating memory");
        return EXIT_FAILURE;
    }

    // Decrypt the ciphertext
    int decrypted_size;
    if (!EVP_DecryptUpdate(context, decrypted_plaintext, &decrypted_size, ciphertext, encrypted_size)) {
        perror("Error decrypting message");
        return EXIT_FAILURE;
    }

    // Finalize the decryption process and get the final plaintext size
    if (!EVP_DecryptFinal_ex(context, decrypted_plaintext + decrypted_size, &final_size)) {
        perror("Error finalizing decryption process");
        return EXIT_FAILURE;
    }
    decrypted_size += final_size;

    // Clean up the decryption context
    EVP_CIPHER_CTX_free(context);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free allocated memory
    free(ciphertext);
    free(decrypted_plaintext);

    return EXIT_SUCCESS;
}