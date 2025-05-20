#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void sync_files(const char *source, const char *destination) {
    char buffer[BUFFER_SIZE];
    FILE *src_file = fopen(source, "r");
    if (!src_file) {
        perror("Failed to open source file");
        return;
    }

    while (fgets(buffer, sizeof(buffer), src_file)) {
        // Simulate file writing to destination
        printf("Writing to %s: %s", destination, buffer);
    }

    fclose(src_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    sync_files(argv[1], argv[2]);

    return 0;
}
