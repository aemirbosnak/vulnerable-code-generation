//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: paranoid
/*
 * Unique C File Encryptor
 *
 * Paranoid style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
void encrypt_file(char *file_path, char *key) {
    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s for reading\n", file_path);
        return;
    }

    // Read the entire file into memory
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *file_content = malloc(file_size);
    fread(file_content, file_size, 1, fp);
    fclose(fp);

    // Encrypt the file content using the given key
    for (int i = 0; i < file_size; i++) {
        file_content[i] ^= key[i % strlen(key)];
    }

    // Write the encrypted file content back to the file
    fp = fopen(file_path, "w");
    if (fp == NULL) {
        printf("Error: Unable to open file %s for writing\n", file_path);
        return;
    }
    fwrite(file_content, file_size, 1, fp);
    fclose(fp);

    // Free the memory allocated for the file content
    free(file_content);
}

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments were provided
    if (argc != 3) {
        printf("Usage: %s <file_path> <key>\n", argv[0]);
        return 1;
    }

    // Encrypt the file using the given key
    encrypt_file(argv[1], argv[2]);

    return 0;
}