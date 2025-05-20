#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_file(FILE *file) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        printf("Read %d bytes: %s\n", bytes_read, buffer);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *filename = argv[1];

    if (argc != 2) {
        printf("Usage: %s <file_to_process>\n", argv[0]);
        return 1;
    }

    file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    process_file(file);
    fclose(file);

    return 0;
}
