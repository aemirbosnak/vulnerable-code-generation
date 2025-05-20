//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/rand.h>
#include <openssl/evp.h>

// Function to generate a random key using OpenSSL
void generate_key(unsigned char *key, int size) {
    RAND_bytes(key, size);
    key[size-1] = '\0';
}

// Function to encrypt the plaintext using the generated key
char *encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
  unsigned char *iv, int *ciphertext_len) {

    EVP_CIPHER_CTX *ctx;
    int len, ciphertext_len_temp;
    char *ciphertext;

    // Create and initialise the context for encryption
    if(!(ctx = EVP_CIPHER_CTX_new())) {
        printf("Error: could not create context.\n");
        return NULL;
    }

    // Initialise the encryption operation.
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        printf("Error: could not initialise encryption.\n");
        return NULL;
    }

    // Determine the size of ciphertext buffer
    ciphertext_len_temp = plaintext_len + EVP_CIPHER_CTX_block_size(ctx);
    ciphertext = malloc(ciphertext_len_temp);

    // Perform the encryption operation
    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) {
        printf("Error: could not encrypt.\n");
        return NULL;
    }
    ciphertext_len_temp = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) {
        printf("Error: could not finalise encryption.\n");
        return NULL;
    }
    ciphertext_len_temp += len;

    EVP_CIPHER_CTX_free(ctx);

    *ciphertext_len = ciphertext_len_temp;

    return ciphertext;
}

// Function to decrypt the ciphertext using the generated key
char *decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
  unsigned char *iv, int *plaintext_len) {

    EVP_CIPHER_CTX *ctx;
    int len, plaintext_len_temp;
    char *plaintext;

    // Create and initialise the context for decryption
    if(!(ctx = EVP_CIPHER_CTX_new())) {
        printf("Error: could not create context.\n");
        return NULL;
    }

    // Initialise the decryption operation.
    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        printf("Error: could not initialise decryption.\n");
        return NULL;
    }

    // Determine the size of plaintext buffer
    plaintext_len_temp = ciphertext_len;
    plaintext = malloc(plaintext_len_temp);

    // Perform the decryption operation
    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)) {
        printf("Error: could not decrypt.\n");
        return NULL;
    }
    plaintext_len_temp = len;

    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) {
        printf("Error: could not finalise decryption.\n");
        return NULL;
    }
    plaintext_len_temp += len;

    EVP_CIPHER_CTX_free(ctx);

    *plaintext_len = plaintext_len_temp;

    return plaintext;
}

int main(int argc, char const *argv[]) {

    // Initialize variables for plaintext, ciphertext, key and iv.
    unsigned char *plaintext = "This is a test message.";
    unsigned char iv[EVP_MAX_IV_LENGTH], key[32], *ciphertext;
    int plaintext_len = strlen(plaintext), ciphertext_len = 0, decryptedtext_len = 0;

    // Generate a random key and iv
    generate_key(key, sizeof(key));
    RAND_bytes(iv, sizeof(iv));

    // Perform the encryption
    ciphertext = encrypt(plaintext, plaintext_len, key, iv, &ciphertext_len);

    // Print the encrypted ciphertext
    printf("Ciphertext: ");
    for(int i = 0; i < ciphertext_len; i++) {
        printf("%02x", (unsigned int)ciphertext[i]);
    }
    printf("\n");

    // Perform the decryption
    unsigned char *decryptedtext = decrypt(ciphertext, ciphertext_len, key, iv, &decryptedtext_len);

    // Print the decrypted plaintext
    printf("Decrypted text: %s\n", decryptedtext);

    // Free memory
    free(ciphertext);
    free(decryptedtext);

    return 0;
}