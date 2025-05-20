//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"
#define BLOCK_SIZE 16

void encrypt(char *filename, char *key) {
    FILE *file;
    char input_buffer[BLOCK_SIZE];
    char output_buffer[BLOCK_SIZE + 1];
    int i, j, n;

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    while ((n = fread(input_buffer, 1, BLOCK_SIZE, file)) > 0) {
        for (i = 0, j = 0; i < n; i++) {
            output_buffer[j++] = input_buffer[i] ^ KEY[i % strlen(KEY)];
        }
        output_buffer[j] = '\0';
        fwrite(output_buffer, 1, j, stdout);
    }

    fclose(file);
}

void decrypt(char *filename, char *key) {
    FILE *file;
    char input_buffer[BLOCK_SIZE];
    char output_buffer[BLOCK_SIZE + 1];
    int i, j, n;

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    while ((n = fread(input_buffer, 1, BLOCK_SIZE, file)) > 0) {
        for (i = 0, j = 0; i < n; i++) {
            output_buffer[j++] = input_buffer[i] ^ KEY[i % strlen(KEY)];
        }
        output_buffer[j] = '\0';
        fwrite(output_buffer, 1, j, stdout);
    }

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s [encrypt|decrypt] [filename] [key]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt(argv[2], argv[3]);
    } else {
        printf("Error: Invalid operation\n");
        return 1;
    }

    return 0;
}