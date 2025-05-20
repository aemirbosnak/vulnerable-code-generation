//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: brave
/*
 * Brave File Encryptor
 *
 * A simple file encryptor program written in C.
 *
 * Usage:
 *  ./brave_encryptor <file_to_encrypt> <encryption_key>
 *
 * Example:
 *  ./brave_encryptor example_file.txt my_secret_key
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void encrypt(char *file_path, char *key) {
    FILE *file_to_encrypt = fopen(file_path, "rb");
    FILE *encrypted_file = fopen("encrypted_file.txt", "wb");

    if (file_to_encrypt == NULL) {
        fprintf(stderr, "Error: Unable to open file %s for reading\n", file_path);
        exit(EXIT_FAILURE);
    }

    if (encrypted_file == NULL) {
        fprintf(stderr, "Error: Unable to open file encrypted_file.txt for writing\n");
        exit(EXIT_FAILURE);
    }

    int c;
    while ((c = fgetc(file_to_encrypt)) != EOF) {
        fputc(c ^ key[0], encrypted_file);
        key++;
    }

    fclose(file_to_encrypt);
    fclose(encrypted_file);
}

void decrypt(char *file_path, char *key) {
    FILE *encrypted_file = fopen(file_path, "rb");
    FILE *decrypted_file = fopen("decrypted_file.txt", "wb");

    if (encrypted_file == NULL) {
        fprintf(stderr, "Error: Unable to open file %s for reading\n", file_path);
        exit(EXIT_FAILURE);
    }

    if (decrypted_file == NULL) {
        fprintf(stderr, "Error: Unable to open file decrypted_file.txt for writing\n");
        exit(EXIT_FAILURE);
    }

    int c;
    while ((c = fgetc(encrypted_file)) != EOF) {
        fputc(c ^ key[0], decrypted_file);
        key++;
    }

    fclose(encrypted_file);
    fclose(decrypted_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file_to_encrypt> <encryption_key>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    encrypt(argv[1], argv[2]);
    decrypt("encrypted_file.txt", argv[2]);

    return 0;
}