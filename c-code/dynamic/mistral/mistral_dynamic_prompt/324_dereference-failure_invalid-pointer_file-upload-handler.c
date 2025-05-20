#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void read_file(char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    if (!file) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return;
    }

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        printf("%.*s", (int)bytes_read, buffer);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *file_content = malloc(strlen(filename) * sizeof(char));
    strcpy(file_content, filename);

    read_file(file_content);

    free(file_content); // Oops, forgot to dereference the pointer before freeing

    return 0;
}
