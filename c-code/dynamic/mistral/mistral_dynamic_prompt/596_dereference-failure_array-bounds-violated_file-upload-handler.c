#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

int main(int argc, char **argv) {
    char *buffer = malloc(BUFFER_SIZE);
    FILE *file;
    size_t read_bytes;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "rb");
    if (!file) {
        perror("Failed to open file");
        return 2;
    }

    read_bytes = fread(buffer, 1, BUFFER_SIZE, file);
    if (read_bytes < BUFFER_SIZE) {
        printf("File is smaller than buffer size\n");
    }

    // Dereference past the end of the allocated buffer
    printf("First byte from the file: %c\n", *(buffer + read_bytes));

    fclose(file);
    free(buffer);
    return 0;
}
