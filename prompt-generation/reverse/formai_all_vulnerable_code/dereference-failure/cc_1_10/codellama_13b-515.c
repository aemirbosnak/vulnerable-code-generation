//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: minimalist
/*
 * File Encryptor
 * Minimalist style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Define encryption key
#define KEY 0x12345678

// Define encryption algorithm
void encrypt(char *data, int len) {
    int i;
    for (i = 0; i < len; i++) {
        data[i] = data[i] ^ KEY;
    }
}

// Define decryption algorithm
void decrypt(char *data, int len) {
    int i;
    for (i = 0; i < len; i++) {
        data[i] = data[i] ^ KEY;
    }
}

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        printf("Usage: %s [mode] [file]\n", argv[0]);
        return 1;
    }

    // Check for correct mode
    if (strcmp(argv[1], "encrypt") != 0 && strcmp(argv[1], "decrypt") != 0) {
        printf("Invalid mode: %s\n", argv[1]);
        return 1;
    }

    // Open file
    FILE *fp = fopen(argv[2], "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[2]);
        return 1;
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for file data
    char *data = malloc(file_size);
    if (data == NULL) {
        printf("Error allocating memory for file data\n");
        fclose(fp);
        return 1;
    }

    // Read file data
    int bytes_read = fread(data, 1, file_size, fp);
    if (bytes_read != file_size) {
        printf("Error reading file data\n");
        fclose(fp);
        free(data);
        return 1;
    }

    // Encrypt/decrypt file data
    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt(data, file_size);
    } else {
        decrypt(data, file_size);
    }

    // Write encrypted/decrypted data to file
    fp = fopen(argv[2], "wb");
    if (fp == NULL) {
        printf("Error opening file for writing: %s\n", argv[2]);
        free(data);
        return 1;
    }
    fwrite(data, 1, file_size, fp);
    fclose(fp);

    // Free memory
    free(data);

    return 0;
}