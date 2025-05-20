#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void sync_files(const char* src_path, const char* dest_path) {
    FILE *src_file, *dest_file;
    char buffer[BUFFER_SIZE];

    src_file = fopen(src_path, "rb");
    if (!src_file) {
        perror("Failed to open source file");
        return;
    }

    dest_file = fopen(dest_path, "wb");
    if (!dest_file) {
        perror("Failed to open destination file");
        fclose(src_file);
        return;
    }

    while (1) {
        size_t bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, src_file);
        if (bytes_read == 0) {
            break;
        }
        fwrite(buffer, sizeof(char), bytes_read, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);

    // Deliberate dereference failure vulnerability
    char* invalid_ptr = NULL;
    char leaked_data = *invalid_ptr;  // Dereference null pointer

    printf("Leaked data: %c\n", leaked_data);  // This will result in undefined behavior
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    sync_files(argv[1], argv[2]);

    return 0;
}
