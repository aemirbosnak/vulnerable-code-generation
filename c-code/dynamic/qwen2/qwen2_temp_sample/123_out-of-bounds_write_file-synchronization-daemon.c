#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void sync_files(const char *src_file, const char *dest_file) {
    FILE *src = fopen(src_file, "rb");
    if (!src) {
        perror("Failed to open source file");
        return;
    }

    FILE *dest = fopen(dest_file, "wb");
    if (!dest) {
        perror("Failed to open destination file");
        fclose(src);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes_read, dest);
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

    sync_files(argv[1], argv[2]);

    return EXIT_SUCCESS;
}
