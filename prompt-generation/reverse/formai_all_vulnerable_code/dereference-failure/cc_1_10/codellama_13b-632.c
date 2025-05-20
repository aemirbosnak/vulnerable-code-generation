//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

void encrypt_file(FILE *input_file, FILE *output_file, int key) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, input_file)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] = (char)((buffer[i] + key) % 256);
        }
        fwrite(buffer, sizeof(char), bytes_read, output_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file: %s\n", argv[1]);
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file: %s\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    int key = atoi(argv[3]);
    if (key < 0 || key > 255) {
        printf("Invalid key: %d\n", key);
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    encrypt_file(input_file, output_file, key);

    fclose(input_file);
    fclose(output_file);

    return 0;
}