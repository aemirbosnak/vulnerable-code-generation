//FormAI DATASET v1.0 Category: Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <openssl/evp.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 32

int main(int argc, char **argv)
{
    // Check for valid command line arguments
    if(argc != 4)
    {
        printf("Usage: async_crypt <plain_filepath> <encrypted_filepath> <key>\n");
        return -1;
    }

    int plain_fd, encrypted_fd;
    unsigned char key[KEY_SIZE], iv[BLOCK_SIZE], block[BLOCK_SIZE];
    int bytes_read = 0, bytes_written = 0, total_bytes_read = 0, num_blocks = 0;

    // Initialize the OpenSSL library and get the cipher type
    EVP_CIPHER_CTX *ctx;
    const EVP_CIPHER *cipher = EVP_aes_256_cbc();
    ctx = EVP_CIPHER_CTX_new();
    EVP_CIPHER_CTX_init(ctx);
    EVP_EncryptInit_ex(ctx, cipher, NULL, key, iv);

    // Open the input and output files
    plain_fd = open(argv[1], O_RDONLY);
    if(plain_fd == -1)
    {
        printf("Error opening file %s. %s\n", argv[1], strerror(errno));
        return -1;
    }
    encrypted_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if(encrypted_fd == -1)
    {
        printf("Error opening file %s. %s\n", argv[2], strerror(errno));
        return -1;
    }

    // Convert the key from a string to binary
    if(strlen(argv[3]) != KEY_SIZE * 2)
    {
        printf("Error: Key must be exactly %d bytes.\n", KEY_SIZE);
        return -1;
    }
    int i;
    for(i = 0; i < KEY_SIZE; i++)
    {
        sscanf(&argv[3][i*2], "%2x", &key[i]);
    }

    // Generate a random IV
    if(RAND_bytes(iv, BLOCK_SIZE) == 0)
    {
        printf("Error generating random IV. %s\n", strerror(errno));
        return -1;
    }

    // Write the IV to the beginning of the encrypted file
    if(write(encrypted_fd, iv, BLOCK_SIZE) != BLOCK_SIZE)
    {
        printf("Error writing IV to file. %s\n", strerror(errno));
        return -1;
    }

    // Encrypt the file block by block
    while((bytes_read = read(plain_fd, block, BLOCK_SIZE)) > 0)
    {
        bytes_written = 0;
        num_blocks++;

        // Encrypt the block asynchronously
        EVP_EncryptUpdate(ctx, block, &bytes_written, block, bytes_read);

        // Write the encrypted block to the output file
        if(write(encrypted_fd, block, bytes_written) != bytes_written)
        {
            printf("Error writing encrypted data to file. %s\n", strerror(errno));
            return -1;
        }

        total_bytes_read += bytes_read;
    }

    // Encrypt the final block
    EVP_EncryptFinal_ex(ctx, block, &bytes_written);

    // Write the final encrypted block to the output file
    if(write(encrypted_fd, block, bytes_written) != bytes_written)
    {
        printf("Error writing encrypted data to file. %s\n", strerror(errno));
        return -1;
    }

    // Close the files and free the OpenSSL context
    close(plain_fd);
    close(encrypted_fd);
    EVP_CIPHER_CTX_free(ctx);

    printf("%d blocks (%d bytes) encrypted successfully.\n", num_blocks, total_bytes_read);

    return 0;
}