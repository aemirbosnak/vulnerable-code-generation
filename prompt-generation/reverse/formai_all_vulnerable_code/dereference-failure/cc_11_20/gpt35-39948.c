//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main(int argc, char **argv)
{
    // Check if the user provided the correct number of arguments
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s <algorithm> <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the algorithm provided by the user
    const EVP_CIPHER *cipher;
    if (strcmp(argv[1], "aes-128-cbc") == 0)
    {
        cipher = EVP_aes_128_cbc();
    }
    else if (strcmp(argv[1], "aes-256-cbc") == 0)
    {
        cipher = EVP_aes_256_cbc();
    }
    else if (strcmp(argv[1], "des-ede3-cbc") == 0)
    {
        cipher = EVP_des_ede3_cbc();
    }
    else
    {
        fprintf(stderr, "Invalid algorithm: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Open the input file for reading
    FILE *in_file = fopen(argv[2], "rb");
    if (in_file == NULL)
    {
        fprintf(stderr, "Failed to open input file: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    // Open the output file for writing
    FILE *out_file = fopen(argv[3], "wb");
    if (out_file == NULL)
    {
        fprintf(stderr, "Failed to open output file: %s\n", argv[3]);
        return EXIT_FAILURE;
    }

    // Allocate memory for the key, IV, and input buffer
    unsigned char key[EVP_MAX_KEY_LENGTH];
    unsigned char iv[EVP_MAX_IV_LENGTH];
    unsigned char *in_buf = malloc(4096);

    // Generate a random key and IV
    if (EVP_BytesToKey(cipher, EVP_sha1(), NULL, key, sizeof(key), 1, NULL, NULL) != sizeof(key) || EVP_CIPHER_iv_length(cipher) > 0 && EVP_BytesToKey(cipher, EVP_sha1(), NULL, iv, sizeof(iv), 1, NULL, NULL) != sizeof(iv))
    {
        fprintf(stderr, "Failed to generate key and IV\n");
        return EXIT_FAILURE;
    }

    // Initialize the encryption or decryption context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_CIPHER_CTX_init(ctx);
    EVP_CipherInit_ex(ctx, cipher, NULL, key, iv, (argc == 5) ? atoi(argv[4]) : -1);

    // Read data from the input file, encrypt or decrypt it, and write it to the output file
    int in_len, out_len;
    unsigned char *out_buf = malloc(4096 + EVP_CIPHER_block_size(cipher));
    while ((in_len = fread(in_buf, 1, 4096, in_file)) > 0)
    {
        if (EVP_CipherUpdate(ctx, out_buf, &out_len, in_buf, in_len) != 1)
        {
            fprintf(stderr, "Failed to encrypt or decrypt data\n");
            return EXIT_FAILURE;
        }
        fwrite(out_buf, 1, out_len, out_file);
    }
    if (EVP_CipherFinal_ex(ctx, out_buf, &out_len) != 1)
    {
        fprintf(stderr, "Failed to encrypt or decrypt data\n");
        return EXIT_FAILURE;
    }
    fwrite(out_buf, 1, out_len, out_file);

    // Clean up
    fclose(in_file);
    fclose(out_file);
    free(in_buf);
    free(out_buf);
    EVP_CIPHER_CTX_free(ctx);

    return EXIT_SUCCESS;
}