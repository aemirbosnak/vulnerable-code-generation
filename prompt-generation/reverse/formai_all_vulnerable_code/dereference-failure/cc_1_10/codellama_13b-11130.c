//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

void encrypt_file(const char *input_file, const char *output_file) {
    FILE *input, *output;
    char buffer[BUFFER_SIZE];
    int buffer_size;

    input = fopen(input_file, "rb");
    output = fopen(output_file, "wb");

    while ((buffer_size = fread(buffer, sizeof(char), BUFFER_SIZE, input)) > 0) {
        for (int i = 0; i < buffer_size; i++) {
            buffer[i] = buffer[i] ^ (char)time(NULL);
        }
        fwrite(buffer, sizeof(char), buffer_size, output);
    }

    fclose(input);
    fclose(output);
}

void decrypt_file(const char *input_file, const char *output_file) {
    FILE *input, *output;
    char buffer[BUFFER_SIZE];
    int buffer_size;

    input = fopen(input_file, "rb");
    output = fopen(output_file, "wb");

    while ((buffer_size = fread(buffer, sizeof(char), BUFFER_SIZE, input)) > 0) {
        for (int i = 0; i < buffer_size; i++) {
            buffer[i] = buffer[i] ^ (char)time(NULL);
        }
        fwrite(buffer, sizeof(char), buffer_size, output);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <encrypt/decrypt>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[3], "encrypt") == 0) {
        encrypt_file(argv[1], argv[2]);
    } else if (strcmp(argv[3], "decrypt") == 0) {
        decrypt_file(argv[1], argv[2]);
    } else {
        printf("Invalid operation: %s\n", argv[3]);
        return 1;
    }

    return 0;
}