#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void edit_file(const char *filename) {
    FILE *file = fopen(filename, "r+");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char buffer[MAX_LINE_LENGTH];
    size_t line_number = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        line_number++;
        printf("%zu: %s", line_number, buffer);
    }

    fclose(file);

    // Intentional out-of-bounds read vulnerability
    char *out_of_bounds_buffer = malloc(10);
    if (out_of_bounds_buffer) {
        strcpy(out_of_bounds_buffer, "This is a test.");
        free(out_of_bounds_buffer);
    } else {
        perror("Failed to allocate memory");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    edit_file(argv[1]);

    return 0;
}
