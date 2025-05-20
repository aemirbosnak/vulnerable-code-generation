//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "MySecretKey"
#define BLOCK_SIZE 16

void encrypt(char *input_file, char *output_file) {
    FILE *input, *output;
    char input_buffer[BLOCK_SIZE], output_buffer[BLOCK_SIZE + 1];
    int i, j, k;

    input = fopen(input_file, "rb");
    output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        printf("Error opening file(s)\n");
        exit(1);
    }

    while (fread(input_buffer, 1, BLOCK_SIZE, input)!= 0) {
        for (i = 0, j = 0; i < BLOCK_SIZE; i++) {
            output_buffer[j++] = input_buffer[i] ^ KEY[i % strlen(KEY)];
        }
        fwrite(output_buffer, 1, BLOCK_SIZE, output);
    }

    fclose(input);
    fclose(output);
}

void decrypt(char *input_file, char *output_file) {
    FILE *input, *output;
    char input_buffer[BLOCK_SIZE], output_buffer[BLOCK_SIZE + 1];
    int i, j, k;

    input = fopen(input_file, "rb");
    output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        printf("Error opening file(s)\n");
        exit(1);
    }

    while (fread(input_buffer, 1, BLOCK_SIZE, input)!= 0) {
        for (i = 0, j = 0; i < BLOCK_SIZE; i++) {
            output_buffer[j++] = input_buffer[i] ^ KEY[i % strlen(KEY)];
        }
        fwrite(output_buffer, 1, BLOCK_SIZE, output);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s [encrypt|decrypt] [input_file] [output_file]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt(argv[2], argv[3]);
    } else {
        printf("Invalid operation\n");
        return 1;
    }

    return 0;
}