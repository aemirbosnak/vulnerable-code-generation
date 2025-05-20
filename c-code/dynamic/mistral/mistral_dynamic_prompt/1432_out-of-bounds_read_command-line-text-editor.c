#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void edit_file(char *filename) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    int current_line = 1;
    char c;

    if ((file = fopen(filename, "r+")) == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            current_line++;
            continue;
        }
        buffer[(current_line - 1) * BUFFER_SIZE + (current_line == 1 ? 0 : (current_line - 2))] = c;
    }

    // Deliberate out-of-bounds read vulnerability, reading past the allocated buffer
    printf("Enter text at line %d (more than %d characters will cause a buffer overflow):\n", current_line, BUFFER_SIZE);
    fseek(file, (current_line - 1) * BUFFER_SIZE + (current_line == 1 ? 0 : (current_line - 2)), SEEK_SET);
    fgets(buffer + BUFFER_SIZE, sizeof(buffer), stdin);

    rewind(file);

    while ((c = fgetc(file)) != EOF) {
        fputc(c, file);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    edit_file(argv[1]);
    return 0;
}
