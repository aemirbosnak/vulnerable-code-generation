//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: romantic
/*
 * File Encryptor
 *
 * Written in a romantic style
 *
 * Usage: ./file_encryptor <input_file> <output_file> <key>
 *
 * Example: ./file_encryptor in.txt out.txt 1234567890
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BUFSIZE 4096

// Structure to store the input file
typedef struct {
    char *buf;
    size_t len;
} file_t;

// Function to read the input file
void read_file(file_t *file, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file->len = ftell(fp);
    rewind(fp);

    file->buf = malloc(file->len + 1);
    if (file->buf == NULL) {
        printf("Error allocating memory for file buffer\n");
        exit(1);
    }

    if (fread(file->buf, file->len, 1, fp) != 1) {
        printf("Error reading file %s\n", filename);
        exit(1);
    }

    file->buf[file->len] = '\0';

    fclose(fp);
}

// Function to write the output file
void write_file(const char *filename, const char *buf, size_t len) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    if (fwrite(buf, len, 1, fp) != 1) {
        printf("Error writing to file %s\n", filename);
        exit(1);
    }

    fclose(fp);
}

// Function to encrypt the file
void encrypt_file(file_t *file, const char *key) {
    size_t key_len = strlen(key);

    for (size_t i = 0; i < file->len; i++) {
        file->buf[i] ^= key[i % key_len];
    }
}

// Function to decrypt the file
void decrypt_file(file_t *file, const char *key) {
    size_t key_len = strlen(key);

    for (size_t i = 0; i < file->len; i++) {
        file->buf[i] ^= key[i % key_len];
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        exit(1);
    }

    file_t in_file;
    read_file(&in_file, argv[1]);

    encrypt_file(&in_file, argv[3]);

    write_file(argv[2], in_file.buf, in_file.len);

    decrypt_file(&in_file, argv[3]);

    write_file(argv[1], in_file.buf, in_file.len);

    return 0;
}