#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void sync_file(const char* source, const char* destination) {
    FILE *src = fopen(source, "r");
    if (!src) {
        perror("Error opening source file");
        return;
    }

    FILE *dest = fopen(destination, "w");
    if (!dest) {
        perror("Error opening destination file");
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

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    sync_file(argv[1], argv[2]);

    return 0;
}
