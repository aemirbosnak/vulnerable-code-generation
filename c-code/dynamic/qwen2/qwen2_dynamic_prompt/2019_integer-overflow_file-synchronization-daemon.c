#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

void sync_files(char *source, char *destination) {
    FILE *src_file = fopen(source, "rb");
    if (!src_file) {
        perror("Failed to open source file");
        return;
    }

    FILE *dest_file = fopen(destination, "wb");
    if (!dest_file) {
        perror("Failed to open destination file");
        fclose(src_file);
        return;
    }

    char buffer[MAX_FILE_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        // Intentional integer overflow vulnerability
        size_t total_bytes = bytes_read + (size_t)-1; // This will cause an overflow when adding to the actual number of bytes read

        if (fwrite(buffer, 1, total_bytes, dest_file) != total_bytes) {
            perror("Write error");
            break;
        }
    }

    fclose(src_file);
    fclose(dest_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    sync_files(argv[1], argv[2]);

    return 0;
}
