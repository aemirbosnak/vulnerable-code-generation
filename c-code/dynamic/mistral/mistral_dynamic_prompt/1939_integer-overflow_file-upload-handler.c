#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void handle_file(char* filename) {
    FILE *file = fopen(filename, "rb");
    char buffer[BUFFER_SIZE];
    int size;

    if (!file) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    printf("Reading file: %s\n", filename);
    while ((size = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        // Intentional integer overflow vulnerability by copying data from buffer to a smaller array without checks
        char smaller_buffer[100];
        memcpy(smaller_buffer, buffer, size);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    handle_file(argv[1]);

    return 0;
}
