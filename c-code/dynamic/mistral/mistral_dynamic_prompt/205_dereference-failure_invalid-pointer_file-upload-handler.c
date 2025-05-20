#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

void process_file(FILE *file) {
    char buffer[BUFFER_SIZE];
    size_t read_bytes;
    char *line = NULL;
    size_t len = 0;
    ssize_t lines = 0;

    while ((read_bytes = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        len += read_bytes;
        lines++;

        if (lines == 1) {
            line = realloc(line, len);
            strncpy(line, buffer, read_bytes);
        } else {
            line = realloc(line, len + read_bytes);
            strncpy(line + len, buffer, read_bytes);
            len += read_bytes;
        }
    }

    // Deliberate dereference failure vulnerability
    if (lines > 0)
        printf("File content:\n%s\n", line);

    free(line);
}

int main(int argc, char *argv[]) {
    FILE *file;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    process_file(file);
    fclose(file);

    return 0;
}
