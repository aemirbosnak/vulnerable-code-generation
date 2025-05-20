#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

void process_file(FILE *file) {
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, file)) != 0) {
        // Deliberately access memory past the end of the buffer, causing a dereference failure
        printf("%c", buffer[MAX_FILE_SIZE]);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *filename = argv[1];

    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    file = fopen(filename, "rb");

    if (file == NULL) {
        perror("Error opening file");
        return 2;
    }

    process_file(file);

    fclose(file);
    return 0;
}
