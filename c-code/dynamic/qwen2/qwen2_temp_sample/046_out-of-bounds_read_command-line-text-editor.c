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
    char *out_of_bounds_buffer = malloc(BUFFER_SIZE);
    if (out_of_bounds_buffer) {
        out_of_bounds_buffer[BUFFER_SIZE] = 'A'; // This is out-of-bounds
        free(out_of_bounds_buffer);
    }

    return 0;
}
