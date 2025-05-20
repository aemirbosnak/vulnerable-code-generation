#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 2048

void handle_file(char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[BUFFER_SIZE];
    size_t read_size;

    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    while ((read_size = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        // Intentionally vulnerable: Write the data directly to a fixed-size array
        char data[10];
        strcpy(data, buffer);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_to_upload>\n", argv[0]);
        return 1;
    }

    handle_file(argv[1]);

    return 0;
}
