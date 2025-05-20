//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define CHUNK_SIZE 4096

// Async operation callback function
void callback(EVP_MD_CTX *ctx, int status, void *arg) {
    char* hash = (char*)arg;

    //print the hashed message
    printf("Hashed message: %s\n", hash);

    // Free the context memory
    EVP_MD_CTX_free(ctx);
}

// Async function to hash the given file
void hash_file_async(char* filename, EVP_MD* hash_type, void (*callback)(EVP_MD_CTX *, int, void *)) {
    EVP_MD_CTX* ctx;
    int file_fd;
    char buf[CHUNK_SIZE];
    ssize_t n;
    struct stat file_stats;
    char* hash;

    // Allocate memory for the hash message
    hash = (char *)malloc(EVP_MD_size(hash_type) * 2 + 1);

    if((file_fd = open(filename, O_RDONLY)) < 0) {
        printf("Error: Input file could not be opened\n");
        exit(1);
    }

    if(fstat(file_fd, &file_stats) < 0) {
        perror("Stat");
        exit(1);
    }

    // Initialize the hash context
    if((ctx = EVP_MD_CTX_new()) == NULL) {
        printf("Error: EVP_MD_CTX_new() failed\n");
        exit(1);
    }

    // Initialize the hash function
    if(EVP_DigestInit_ex(ctx, hash_type, NULL) != 1) {
        printf("Error: EVP_DigestInit_ex() failed\n");
        exit(1);
    }

    // Read the file, hash the chunks
    while((n = read(file_fd, buf, CHUNK_SIZE)) > 0) {
        if(EVP_DigestUpdate(ctx, buf, n) != 1) {
            printf("Error: EVP_DigestUpdate() failed\n");
            exit(1);
        }
    }

    // Finalize the hash
    if(EVP_DigestFinal_ex(ctx, hash, NULL) != 1) {
        printf("Error: EVP_DigestFinal_ex() failed\n");
        exit(1);
    }

    // Close the file
    close(file_fd);

    // Execute the callback
    callback(ctx, 0, hash);
}

// Main async function to run hash_file_async method
int main(int argc, char *argv[]) {
    char* filename;
    EVP_MD* hash_type;

    if(argc < 3) {
        printf("Usage: %s [filename] [hash algorithm]\n", argv[0]);
        return 0;
    }

    // Get the filename and hash type
    filename = argv[1];
    hash_type = EVP_get_digestbyname(argv[2]);

    if(hash_type == NULL) {
        printf("Error: Invalid hash algorithm\n");
        exit(1);
    }

    printf("Starting hash of file: %s\n", filename);

    // Execute the hash_file_async and pass the callback function
    hash_file_async(filename, hash_type, callback);

    return 0;
}