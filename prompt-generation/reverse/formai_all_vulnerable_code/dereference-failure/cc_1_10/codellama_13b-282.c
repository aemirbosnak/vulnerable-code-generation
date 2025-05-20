//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

void encrypt(char* data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] = data[i] + 1;
    }
}

void decrypt(char* data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] = data[i] - 1;
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <file_name> <key>\n", argv[0]);
        return 1;
    }

    char* file_name = argv[1];
    char* key = argv[2];
    int key_size = strlen(key);

    FILE* file = fopen(file_name, "r+");
    if (file == NULL) {
        printf("Failed to open file: %s\n", file_name);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    char* buffer = malloc(file_size);
    if (buffer == NULL) {
        printf("Failed to allocate memory for buffer\n");
        return 1;
    }

    fread(buffer, 1, file_size, file);
    fclose(file);

    encrypt(buffer, file_size);
    decrypt(buffer, file_size);

    file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Failed to open file: %s\n", file_name);
        return 1;
    }

    fwrite(buffer, 1, file_size, file);
    fclose(file);

    free(buffer);

    return 0;
}