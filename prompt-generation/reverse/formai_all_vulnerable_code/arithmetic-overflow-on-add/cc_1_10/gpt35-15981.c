//FormAI DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16
#define KEY_SIZE   32
#define IV_SIZE    16

void generate_random_key(unsigned char *key, size_t key_size) {
    // Fill the key buffer with random bytes
    for(size_t i = 0; i < key_size; i++) {
        key[i] = (unsigned char) rand() % 256;
    }
}

void generate_random_iv(unsigned char *iv, size_t iv_size) {
    // Fill the IV buffer with random bytes
    for(size_t i = 0; i < iv_size; i++) {
        iv[i] = (unsigned char) rand() % 256;
    }
}

void encrypt(unsigned char *message, size_t message_length,
             unsigned char *key, size_t key_size,
             unsigned char *iv, size_t iv_size) {
    // Calculate the number of blocks in the message
    size_t num_blocks = message_length / BLOCK_SIZE + ((message_length % BLOCK_SIZE) ? 1 : 0);
    
    // Allocate memory for the padded message
    unsigned char *padded_message = malloc(num_blocks * BLOCK_SIZE * sizeof(unsigned char));
    memcpy(padded_message, message, message_length);
    
    // Pad the message
    size_t padding = BLOCK_SIZE - (message_length % BLOCK_SIZE);
    for(size_t i = 0; i < padding; i++) {
        padded_message[(num_blocks - 1) * BLOCK_SIZE + i] = padding;
    }
    
    // Allocate memory for the ciphertext
    unsigned char *ciphertext = malloc(num_blocks * BLOCK_SIZE * sizeof(unsigned char));
    
    // Initialize the encryption context
    void *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    
    // Encrypt each block of the message
    int ciphertext_length = 0;
    for(size_t i = 0; i < num_blocks; i++) {
        unsigned char *block = padded_message + (i * BLOCK_SIZE);
        unsigned char *out = ciphertext + (i * BLOCK_SIZE);
        int out_length;
        EVP_EncryptUpdate(ctx, out, &out_length, block, BLOCK_SIZE);
        ciphertext_length += out_length;
    }
    
    // Finalize the encryption
    int final_out_length;
    EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_length, &final_out_length);
    ciphertext_length += final_out_length;
    
    // Clean up the context
    EVP_CIPHER_CTX_free(ctx);
    
    // Print the ciphertext
    printf("Ciphertext: ");
    for(size_t i = 0; i < ciphertext_length; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
    
    // Free the memory
    free(padded_message);
    free(ciphertext);
}

int main(int argc, char *argv[]) {
    // Initialize the random seed
    srand(time(NULL));
    
    // Generate a random key and IV
    unsigned char key[KEY_SIZE];
    unsigned char iv[IV_SIZE];
    generate_random_key(key, KEY_SIZE);
    generate_random_iv(iv, IV_SIZE);
    
    // Read the message from the command line arguments
    if(argc != 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }
    unsigned char *message = (unsigned char *) argv[1];
    size_t message_length = strlen((char *) message);
    
    // Encrypt the message
    encrypt(message, message_length, key, KEY_SIZE, iv, IV_SIZE);
    
    return 0;
}