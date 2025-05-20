//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define HASH_SIZE 64
#define HASH_ALGORITHM "SHA-256"

// Function to generate a hash from a string
void hash_string(char *input_string, char *output_hash) {
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, input_string, strlen(input_string));
    SHA256_Final(output_hash, &ctx);
}

// Function to generate a hash from a file
void hash_file(char *file_path, char *output_hash) {
    FILE *file;
    char buffer[1024];
    SHA256_CTX ctx;
    file = fopen(file_path, "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", file_path);
        exit(1);
    }
    SHA256_Init(&ctx);
    while (fread(buffer, 1, 1024, file) > 0) {
        SHA256_Update(&ctx, buffer, 1024);
    }
    SHA256_Final(output_hash, &ctx);
    fclose(file);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_string/input_file> <output_hash>\n", argv[0]);
        exit(1);
    }
    char input_string[1024] = {0};
    char output_hash[HASH_SIZE] = {0};
    if (strcmp(argv[1], "-s") == 0) {
        strcpy(input_string, argv[2]);
        hash_string(input_string, output_hash);
    } else if (strcmp(argv[1], "-f") == 0) {
        strcpy(input_string, argv[2]);
        hash_file(input_string, output_hash);
    } else {
        printf("Invalid input type.\n");
        exit(1);
    }
    printf("Input: %s\n", input_string);
    printf("Output hash: %s\n", output_hash);
    return 0;
}