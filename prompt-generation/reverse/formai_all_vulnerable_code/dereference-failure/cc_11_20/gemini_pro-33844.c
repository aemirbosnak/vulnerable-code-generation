//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: enthusiastic
#include <openssl/evp.h>
#include <openssl/err.h>

int main(int argc, char* argv[]) {
    // Check that the user has provided enough arguments.
    if (argc < 4) {
        printf("Usage: %s <input_file> <output_file> <password>\n", argv[0]);
        return 1;
    }
    
    // Obtain the input and output filenames.
    char* input_file = argv[1];
    char* output_file = argv[2];
    
    // Obtain the password.
    char* password = argv[3];
    
    // Create an encryption context.
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        printf("Error creating encryption context.\n");
        return 1;
    }

    // Initialize the encryption context.
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, NULL, NULL) != 1) {
        printf("Error initializing encryption context.\n");
        return 1;
    }

    unsigned char key[EVP_CIPHER_CTX_key_length(ctx)];

    unsigned char iv[EVP_CIPHER_CTX_iv_length(ctx)];
    
    // Set the encryption key and IV.
    if (EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha256(), NULL, (unsigned char*)password, strlen(password), 1, key, iv) != 32) {
        printf("Error setting encryption key and IV.\n");
        return 1;
    }

    // Set the encryption key and IV in the context.
    if (EVP_CipherInit_ex(ctx, NULL, NULL, key, iv, 1) != 1) {
        printf("Error setting encryption key and IV in the context.\n");
        return 1;
    }

    // Open the input file.
    FILE* input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open the output file.
    FILE* output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Encrypt the data.
    int block_size = EVP_CIPHER_CTX_block_size(ctx);
    unsigned char* input_buffer = malloc(block_size);
    unsigned char* output_buffer = malloc(block_size);
    int num_bytes_read;
    while ((num_bytes_read = fread(input_buffer, 1, block_size, input)) > 0) {
        if (EVP_EncryptUpdate(ctx, output_buffer, &num_bytes_read, input_buffer, num_bytes_read) != 1) {
            printf("Error encrypting data.\n");
            return 1;
        }
        fwrite(output_buffer, 1, num_bytes_read, output);
    }

    // Finalize the encryption.
    if (EVP_EncryptFinal_ex(ctx, output_buffer, &num_bytes_read) != 1) {
        printf("Error finalizing encryption.\n");
        return 1;
    }
    fwrite(output_buffer, 1, num_bytes_read, output);

    // Clean up.
    EVP_CIPHER_CTX_free(ctx);
    fclose(input);
    fclose(output);
    free(input_buffer);
    free(output_buffer);
    
    return 0;
}