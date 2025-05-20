//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

// Function to encrypt the plaintext
int encrypt(const unsigned char *plaintext, int plaintext_len, unsigned char *key,
            unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        fprintf(stderr, "Could not create cipher context.\n");
        return -1;
    }

    // Initialize the encryption operation
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        fprintf(stderr, "Could not initialize encryption.\n");
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    // Provide the message to be encrypted
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) {
        fprintf(stderr, "Encryption failed during update.\n");
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }
    ciphertext_len = len;

    // Finalize the encryption
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) {
        fprintf(stderr, "Encryption finalization failed.\n");
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }
    ciphertext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    return ciphertext_len;
}

// Function to print a hex representation of a byte array
void print_hex(const char *desc, const unsigned char *data, int len) {
    printf("%s", desc);
    for (int i = 0; i < len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

// Function to generate a random key and IV
void generate_key_iv(unsigned char *key, unsigned char *iv) {
    if (!RAND_bytes(key, 32) || !RAND_bytes(iv, EVP_MAX_IV_LENGTH)) {
        fprintf(stderr, "Could not generate random bytes.\n");
        exit(EXIT_FAILURE);
    }
}

// Function to create a romantic message
void romantic_message() {
    printf("Our hearts beat like a silent symphony,\n");
    printf("Whispering secrets entwined through the night.\n");
    printf("With words wrapped in the elegance of love,\n");
    printf("Let us encapsulate our passion in this digital light.\n");
}

int main() {
    // Message to be encrypted
    const unsigned char *message = (unsigned char *)"To love and be loved is a treasure of a lifetime.";
    
    // Key and IV buffers
    unsigned char key[32]; // AES-256 key size
    unsigned char iv[EVP_MAX_IV_LENGTH]; // IV buffer for AES

    // Generate random key and IV
    generate_key_iv(key, iv);

    // Prepare the ciphertext buffer
    unsigned char ciphertext[128];
    int ciphertext_len;

    // Show a romantic message
    romantic_message();

    // Encrypt the message
    ciphertext_len = encrypt(message, strlen((const char *)message), key, iv, ciphertext);
    if (ciphertext_len < 0) {
        fprintf(stderr, "Encryption process failed.\n");
        return EXIT_FAILURE;
    }

    // Print the encrypted message
    print_hex("Ciphertext: ", ciphertext, ciphertext_len);
    print_hex("Key: ", key, sizeof(key));
    print_hex("IV: ", iv, sizeof(iv));

    return EXIT_SUCCESS;
}