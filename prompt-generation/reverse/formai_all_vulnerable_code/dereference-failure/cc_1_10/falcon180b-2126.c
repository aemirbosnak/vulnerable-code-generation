//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 64

void encrypt(char* input_file, char* output_file, char* key) {
    FILE* input;
    FILE* output;
    char buffer[BLOCK_SIZE];
    int i;
    char* encrypted_buffer;
    int buffer_size;
    char* xor_key;

    input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening output file.\n");
        fclose(input);
        exit(1);
    }

    encrypted_buffer = (char*) malloc(BLOCK_SIZE + 1);
    if (encrypted_buffer == NULL) {
        printf("Error allocating memory for encrypted buffer.\n");
        fclose(input);
        fclose(output);
        exit(1);
    }

    xor_key = (char*) malloc(KEY_SIZE + 1);
    if (xor_key == NULL) {
        printf("Error allocating memory for XOR key.\n");
        free(encrypted_buffer);
        fclose(input);
        fclose(output);
        exit(1);
    }

    for (i = 0; i < KEY_SIZE; ++i) {
        xor_key[i] = key[i % strlen(key)];
    }

    while (fread(buffer, sizeof(char), BLOCK_SIZE, input) > 0) {
        buffer_size = fwrite(buffer, sizeof(char), BLOCK_SIZE, output);
        if (buffer_size!= BLOCK_SIZE) {
            printf("Error writing to output file.\n");
            fclose(input);
            fclose(output);
            free(encrypted_buffer);
            free(xor_key);
            exit(1);
        }

        for (i = 0; i < BLOCK_SIZE; ++i) {
            encrypted_buffer[i] = buffer[i] ^ xor_key[i % KEY_SIZE];
        }

        fwrite(encrypted_buffer, sizeof(char), BLOCK_SIZE + 1, output);
    }

    fclose(input);
    fclose(output);
    free(encrypted_buffer);
    free(xor_key);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }

    encrypt(argv[1], argv[2], argv[3]);

    return 0;
}