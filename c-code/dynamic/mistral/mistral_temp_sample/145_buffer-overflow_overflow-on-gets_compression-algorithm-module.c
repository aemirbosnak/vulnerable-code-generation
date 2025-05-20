#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

void compress(char *input) {
    char output[BUFFER_SIZE];
    char *ptr = output;
    int count = 0;

    while (*input) {
        count++;
        input++;
    }

    input = input - count;
    strcpy(ptr, input);
    ptr += count;

    printf("Compressed data: %s\n", output);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 2;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        compress(buffer);
        bzero(buffer, BUFFER_SIZE);
    }

    fclose(file);
    return 0;
}
