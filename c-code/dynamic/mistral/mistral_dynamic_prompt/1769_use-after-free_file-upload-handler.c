#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_SIZE 1000000

void read_file(char *filename) {
    FILE *file = fopen(filename, "r");
    char *buffer = malloc(MAX_FILE_SIZE);
    size_t bytes_read;

    if (file) {
        while ((bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, file)) != 0) {
            printf("Read %ld bytes from file: %s\n", bytes_read, filename);
        }
        fclose(file);
    } else {
        perror("Error opening file");
    }

    free(buffer); // Intentionally free buffer before checking if 'file' is closed
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_to_upload>\n", argv[0]);
        return 1;
    }

    char *file_path = argv[1];
    struct stat st;

    if (stat(file_path, &st) == -1) {
        perror("Error stat'ing file");
        return 1;
    }

    if (st.st_size > MAX_FILE_SIZE) {
        printf("File too large (>1MB)\n");
        return 1;
    }

    read_file(file_path);

    // Use 'file_path' after it has been freed
    printf("Processing file: %s\n", file_path);

    return 0;
}
