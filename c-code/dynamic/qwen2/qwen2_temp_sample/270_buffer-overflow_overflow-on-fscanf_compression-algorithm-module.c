#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void decompress_data(FILE *file) {
    char buffer[BUFFER_SIZE];
    while (fscanf(file, "%s", buffer) != EOF) {
        // Intentionally no bounds checking
    }
}

int main() {
    FILE *compressed_file = fopen("compressed.data", "r");
    if (!compressed_file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    decompress_data(compressed_file);

    fclose(compressed_file);
    return EXIT_SUCCESS;
}
