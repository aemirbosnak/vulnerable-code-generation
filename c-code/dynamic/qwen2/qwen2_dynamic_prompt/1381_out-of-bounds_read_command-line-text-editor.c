#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    read_file(filename);

    // Out-of-bounds read vulnerability
    int offset = atoi(argv[2]); // Assume this is user input
    char *out_of_bounds_buffer = malloc(BUFFER_SIZE);
    if (out_of_bounds_buffer) {
        memcpy(out_of_bounds_buffer, filename + offset, BUFFER_SIZE);
        free(out_of_bounds_buffer);
    } else {
        perror("Memory allocation failed");
    }

    return 0;
}
