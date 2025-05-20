//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_KEY_LENGTH 128 // AES key length in bits
#define AES_BLOCK_SIZE 16

void handleErrors() {
    fprintf(stderr, "An error occurred!\n");
    exit(1);
}

// Function to generate a random AES key
void generate_key(unsigned char *key) {
    if (!RAND_bytes(key, AES_KEY_LENGTH / 8)) {
        handleErrors();
    }
}

// AES encryption function
void aes_encrypt(const unsigned char *input, const unsigned char *key, unsigned char *output) {
    AES_KEY encryptKey;
    if (AES_set_encrypt_key(key, AES_KEY_LENGTH, &encryptKey) < 0) {
        handleErrors();
    }
    AES_encrypt(input, output, &encryptKey);
}

// AES decryption function
void aes_decrypt(const unsigned char *input, const unsigned char *key, unsigned char *output) {
    AES_KEY decryptKey;
    if (AES_set_decrypt_key(key, AES_KEY_LENGTH, &decryptKey) < 0) {
        handleErrors();
    }
    AES_decrypt(input, output, &decryptKey);
}

// Function to pad input data
void pad_input(const unsigned char *input, unsigned char *output, int length) {
    int padding_length = AES_BLOCK_SIZE - (length % AES_BLOCK_SIZE);
    memcpy(output, input, length);
    memset(output + length, padding_length, padding_length);
}

// Function to print data in hexadecimal format
void print_hex(const unsigned char *data, size_t length) {
    for (size_t i = 0; i < length; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {
    unsigned char key[AES_KEY_LENGTH / 8];
    unsigned char input[AES_BLOCK_SIZE];
    unsigned char encrypted_output[AES_BLOCK_SIZE];
    unsigned char decrypted_output[AES_BLOCK_SIZE + 1];

    // Generate a random AES key
    generate_key(key);
    printf("AES Key: ");
    print_hex(key, sizeof(key));

    // Input data
    printf("Enter a 16-character string to encrypt: ");
    if (fgets((char *)input, sizeof(input), stdin) == NULL) {
        handleErrors();
    }
    input[strcspn((char *)input, "\n")] = '\0'; // Remove newline character
    int length = strlen((char *)input);

    // Pad input if necessary
    unsigned char padded_input[AES_BLOCK_SIZE];
    pad_input(input, padded_input, length);

    // Encrypt the input
    aes_encrypt(padded_input, key, encrypted_output);
    printf("Encrypted Output: ");
    print_hex(encrypted_output, sizeof(encrypted_output));

    // Decrypt the output
    aes_decrypt(encrypted_output, key, decrypted_output);
    int padding_length = decrypted_output[AES_BLOCK_SIZE - 1];
    decrypted_output[AES_BLOCK_SIZE - padding_length] = '\0'; // Null-terminate the decrypted string
    printf("Decrypted Output: %s\n", decrypted_output);

    return 0;
}