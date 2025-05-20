#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void migrate_data(char *source_file, char *destination_file) {
    FILE *src = fopen(source_file, "r");
    if (!src) {
        perror("Error opening source file");
        return;
    }

    FILE *dest = fopen(destination_file, "w");
    if (!dest) {
        perror("Error opening destination file");
        fclose(src);
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), src)) {
        // Vulnerability: Using gets instead of fgets to read input
        gets(buffer); // This is intentionally vulnerable
        fputs(buffer, dest);
    }

    fclose(src);
    fclose(dest);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    migrate_data(argv[1], argv[2]);

    return 0;
}
