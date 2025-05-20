#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void sync_files(const char *source_path, const char *dest_path) {
    FILE *source_file = fopen(source_path, "rb");
    if (!source_file) {
        perror("Failed to open source file");
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        // Simulate writing past the end of the destination file
        fwrite(buffer, 1, bytes_read + 10, stdout); // Writing out-of-bounds
    }

    fclose(source_file);
}

int main() {
    const char *source_path = "example.txt";
    const char *dest_path = "synced_example.txt";

    printf("Starting file synchronization...\n");
    sync_files(source_path, dest_path);
    printf("Synchronization completed.\n");

    return 0;
}
