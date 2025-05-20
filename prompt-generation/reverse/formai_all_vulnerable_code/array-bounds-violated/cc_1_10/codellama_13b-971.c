//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: safe
/*
 * File Encryptor Example Program in a Safe Style
 *
 * This program encrypts a file using a simple substitution cipher.
 * The encryption key is read from the file "key.txt".
 *
 * Usage:
 *  ./file_encryptor <input_file> <output_file>
 *
 * Example:
 *  ./file_encryptor secret.txt encrypted.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define KEY_FILE "key.txt"
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // Open input file
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        perror("fopen");
        return 1;
    }

    // Open output file
    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        perror("fopen");
        fclose(input_file);
        return 1;
    }

    // Read encryption key from file
    char key[BUF_SIZE];
    FILE *key_file = fopen(KEY_FILE, "rb");
    if (key_file == NULL) {
        perror("fopen");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }
    fread(key, 1, BUF_SIZE, key_file);
    fclose(key_file);

    // Encrypt input file
    char buf[BUF_SIZE];
    int len;
    while ((len = fread(buf, 1, BUF_SIZE, input_file)) > 0) {
        for (int i = 0; i < len; i++) {
            buf[i] = key[buf[i] % BUF_SIZE];
        }
        fwrite(buf, 1, len, output_file);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}