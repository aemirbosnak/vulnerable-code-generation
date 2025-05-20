#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256

void sync_files(const char* source, const char* destination) {
    FILE *src_file = fopen(source, "r");
    if (!src_file) {
        perror("Failed to open source file");
        return;
    }

    FILE *dest_file = fopen(destination, "w");
    if (!dest_file) {
        perror("Failed to open destination file");
        fclose(src_file);
        return;
    }

    char filename[MAX_FILENAME_LENGTH];
    while (fscanf(src_file, "%s", filename) != EOF) {
        // Vulnerability: No bounds checking on fscanf input
        printf("Syncing %s\n", filename);
        // Simulate file processing
        sleep(1);
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
