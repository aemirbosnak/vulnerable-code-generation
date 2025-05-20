#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define BUFFER_OVERFLOW_OFFSET 100

void handle_file(char *filename) {
    FILE *file = fopen(filename, "rb");
    char buffer[MAX_BUFFER];
    char *data_ptr;

    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    size_t bytes_read = fread(buffer, 1, MAX_BUFFER, file);
    if (bytes_read <= 0) {
        fprintf(stderr, "Error reading file: %s\n", filename);
        fclose(file);
        return;
    }

    data_ptr = (char *) malloc(bytes_read + BUFFER_OVERFLOW_OFFSET);
    if (!data_ptr) {
        fprintf(stderr, "Out of memory\n");
        fclose(file);
        return;
    }

    memcpy(data_ptr, buffer, bytes_read);
    // Dereference failure vulnerability intentionally inserted here
    printf("Data size: %d\n", data_ptr[bytes_read]);

    fclose(file);
    free(data_ptr);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    handle_file(argv[1]);
    return 0;
}
