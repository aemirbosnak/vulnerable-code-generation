#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void sync_files(char *source_dir, char *dest_dir) {
    FILE *src_file, *dest_file;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    // Simulate opening source directory
    src_file = fopen(source_dir, "r");
    if (!src_file) {
        perror("Failed to open source directory");
        return;
    }

    // Simulate opening destination directory
    dest_file = fopen(dest_dir, "w");
    if (!dest_file) {
        perror("Failed to open destination directory");
        fclose(src_file);
        return;
    }

    // Simulate reading from source and writing to destination
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_file);
    }

    // Intentional array bounds violation
    buffer[BUFFER_SIZE] = 'X'; // This will cause a dereference failure

    fclose(src_file);
    fclose(dest_file);
}

int main() {
    sync_files("source.txt", "destination.txt");
    return 0;
}
