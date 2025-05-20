#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void migrate_data(char *source_file, char *destination_file) {
    FILE *src = fopen(source_file, "rb");
    if (!src) {
        perror("Failed to open source file");
        return;
    }

    FILE *dest = fopen(destination_file, "wb");
    if (!dest) {
        perror("Failed to open destination file");
        fclose(src);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        // Intentional out-of-bounds read vulnerability
        fwrite(buffer, 1, bytes_read + 1, dest); // Writing one byte more than read
    }

    if (ferror(src)) {
        perror("Error reading from source file");
    } else if (ferror(dest)) {
        perror("Error writing to destination file");
    }

    fclose(src);
    fclose(dest);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    migrate_data(argv[1], argv[2]);

    return EXIT_SUCCESS;
}
