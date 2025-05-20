//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: romantic
// A romantic C file encryptor program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
void encrypt_file(char *filename, char *key) {
    // Open the file to encrypt
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    // Create a buffer to store the encrypted data
    char *buffer = (char *)malloc(size);

    // Encrypt the file data
    while (size > 0) {
        // Read a block of data from the file
        int read_size = fread(buffer, 1, size, fp);

        // Encrypt the block of data
        for (int i = 0; i < read_size; i++) {
            buffer[i] = buffer[i] + key[i % strlen(key)];
        }

        // Write the encrypted data to the output file
        fwrite(buffer, 1, read_size, stdout);

        // Decrease the size of the file by the amount of data read
        size -= read_size;
    }

    // Close the file and free the buffer
    fclose(fp);
    free(buffer);
}

// Function to decrypt a file
void decrypt_file(char *filename, char *key) {
    // Open the file to decrypt
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    // Create a buffer to store the decrypted data
    char *buffer = (char *)malloc(size);

    // Decrypt the file data
    while (size > 0) {
        // Read a block of data from the file
        int read_size = fread(buffer, 1, size, fp);

        // Decrypt the block of data
        for (int i = 0; i < read_size; i++) {
            buffer[i] = buffer[i] - key[i % strlen(key)];
        }

        // Write the decrypted data to the output file
        fwrite(buffer, 1, read_size, stdout);

        // Decrease the size of the file by the amount of data read
        size -= read_size;
    }

    // Close the file and free the buffer
    fclose(fp);
    free(buffer);
}

int main(int argc, char *argv[]) {
    // Check if the program is being run with the correct number of arguments
    if (argc != 4) {
        printf("Usage: %s <filename> <key> <encrypt/decrypt>\n", argv[0]);
        return 1;
    }

    // Get the file name and key from the command line arguments
    char *filename = argv[1];
    char *key = argv[2];

    // Check if the encryption/decryption flag is set
    if (strcmp(argv[3], "encrypt") == 0) {
        encrypt_file(filename, key);
    } else if (strcmp(argv[3], "decrypt") == 0) {
        decrypt_file(filename, key);
    } else {
        printf("Invalid encryption/decryption flag\n");
        return 1;
    }

    return 0;
}