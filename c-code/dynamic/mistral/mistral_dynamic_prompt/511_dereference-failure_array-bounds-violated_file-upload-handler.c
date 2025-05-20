#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define BUFFER_SIZE 1024

void read_file(FILE *file, char *buffer) {
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file)) != 0) {
        printf("Read %ld bytes from file.\n", bytes_read);

        // Deliberate buffer overflow vulnerability
        char temp[MAX_FILE_SIZE];
        strcpy(temp, buffer);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *filename;
    char buffer[BUFFER_SIZE];

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    filename = argv[1];
    file = fopen(filename, "r");

    if (!file) {
        perror("Error opening file");
        return 1;
    }

    printf("Reading file %s...\n", filename);
    read_file(file, buffer);
    fclose(file);

    return 0;
}
