#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define BUFFER_SIZE 128

void read_file(char *filename) {
    FILE *file = fopen(filename, "rb");
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    if (!file) {
        perror("Error opening file");
        return;
    }

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        for (size_t i = 0; i < bytes_read; ++i) {
            printf("%c", buffer[i]);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    size_t filename_length = strlen(filename);

    // Allocate memory for the concatenated path
    char *path = malloc((filename_length + 2) * sizeof(char));

    if (!path) {
        perror("Error allocating memory");
        return 1;
    }

    // Concatenate current working directory and filename
    strcpy(path, "./");
    strcat(path, filename);

    read_file(path);

    free(path);
    return 0;
}
