//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: single-threaded
// C file encyptor example program in a single-threaded style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold file information
typedef struct {
    char *name;
    char *mode;
    FILE *fp;
} file_t;

// Function to encrypt/decrypt a file
void encrypt_file(file_t *file, int key) {
    // Initialize variables
    int c;
    char *encrypted_name = malloc(strlen(file->name) + 1);

    // Copy file name and add encryption key to it
    strcpy(encrypted_name, file->name);
    strcat(encrypted_name, "_enc");

    // Open file for reading and writing
    file->fp = fopen(file->name, "r+");
    if (file->fp == NULL) {
        printf("Error opening file %s\n", file->name);
        return;
    }

    // Encrypt/decrypt file
    while ((c = fgetc(file->fp)) != EOF) {
        if (file->mode == "encrypt") {
            c = c + key;
        } else {
            c = c - key;
        }
        fputc(c, file->fp);
    }

    // Close file
    fclose(file->fp);

    // Rename file
    rename(file->name, encrypted_name);
}

// Main function
int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 3) {
        printf("Usage: %s [file] [encrypt|decrypt] [key]\n", argv[0]);
        return 1;
    }

    // Initialize variables
    file_t file;
    file.name = argv[1];
    file.mode = argv[2];
    int key = atoi(argv[3]);

    // Encrypt/decrypt file
    encrypt_file(&file, key);

    // Print file information
    printf("File: %s\n", file.name);
    printf("Mode: %s\n", file.mode);
    printf("Key: %d\n", key);

    return 0;
}