//FormAI DATASET v1.0 Category: Modern Encryption ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// Define the maximum input buffer size
#define MAX_BUFFER_SIZE 1024

// Function to print out the encrypted and decrypted strings
void print_strings(unsigned char* encrypted_string, int encrypted_length, unsigned char* decrypted_string, int decrypted_length) {
    printf("Encrypted string: ");
    for(int i = 0; i < encrypted_length; i++) {
        printf("%02x", encrypted_string[i]);
    }
    printf("\n");

    printf("Decrypted string: %s\n", decrypted_string);
}

int main() {
    unsigned char message[MAX_BUFFER_SIZE] = "Hello, world!";
    unsigned char* encrypted_message = NULL;
    unsigned char* decrypted_message = NULL;

    int message_length = strlen(message);
    int encrypted_length = 0;
    int decrypted_length = 0;

    // Set up the encryption context
    EVP_CIPHER_CTX* context = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(context, EVP_aes_256_cbc(), NULL, NULL, NULL);

    // Allocate memory for the encrypted text buffer
    encrypted_message = (unsigned char*) malloc(message_length + EVP_CIPHER_block_size(EVP_aes_256_cbc()));

    // Encrypt the plaintext
    EVP_EncryptUpdate(context, encrypted_message, &encrypted_length, message, message_length);

    // Finalize the encryption process and get the final block
    EVP_EncryptFinal_ex(context, encrypted_message + encrypted_length, &encrypted_length);

    // Set up the decryption context
    EVP_DecryptInit_ex(context, EVP_aes_256_cbc(), NULL, NULL, NULL);

    // Allocate memory for the decrypted text buffer
    decrypted_message = (unsigned char*) malloc(encrypted_length + EVP_CIPHER_block_size(EVP_aes_256_cbc()));

    // Decrypt the ciphertext
    EVP_DecryptUpdate(context, decrypted_message, &decrypted_length, encrypted_message, encrypted_length);

    // Finalize the decryption process
    EVP_DecryptFinal_ex(context, decrypted_message + decrypted_length, &decrypted_length);

    // Reset the encryption and decryption contexts
    EVP_CIPHER_CTX_cleanup(context);

    // Print out the encrypted and decrypted strings
    print_strings(encrypted_message, encrypted_length, decrypted_message, decrypted_length);

    // Free the memory used by the encrypted and decrypted strings
    free(encrypted_message);
    free(decrypted_message);

    return 0;
}