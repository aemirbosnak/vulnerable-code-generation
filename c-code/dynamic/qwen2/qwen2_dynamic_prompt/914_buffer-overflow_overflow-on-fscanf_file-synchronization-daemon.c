#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void sync_files(const char *source, const char *destination) {
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

    char buffer[BUFFER_SIZE];
    while (fscanf(src_file, "%s", buffer) != EOF) {
        fprintf(dest_file, "%s\n", buffer);
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
