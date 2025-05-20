//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 10000000

void encrypt(char *filename, char *key) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char *buffer = malloc(MAX_FILE_SIZE);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        fclose(fp);
        return;
    }

    size_t bytes_read = fread(buffer, 1, MAX_FILE_SIZE, fp);
    if (ferror(fp)) {
        printf("Error reading file: %s\n", filename);
        fclose(fp);
        free(buffer);
        return;
    }

    fclose(fp);

    // Encrypt the file using the key
    for (size_t i = 0; i < bytes_read; i++) {
        buffer[i] = buffer[i] ^ key[i % strlen(key)];
    }

    // Write the encrypted data to a new file
    char *new_filename = malloc(strlen(filename) + 1);
    if (new_filename == NULL) {
        printf("Error allocating memory\n");
        free(buffer);
        return;
    }

    strcpy(new_filename, filename);
    strcat(new_filename, ".enc");

    fp = fopen(new_filename, "wb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", new_filename);
        free(new_filename);
        free(buffer);
        return;
    }

    fwrite(buffer, 1, bytes_read, fp);
    fclose(fp);

    free(new_filename);
    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <key>\n", argv[0]);
        return 1;
    }

    encrypt(argv[1], argv[2]);

    return 0;
}