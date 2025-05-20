#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char buffer[MAX_FILENAME_LENGTH];
    size_t bytes_read = fread(buffer, 1, sizeof(buffer), file);
    if (bytes_read == 0 && ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return;
    }

    // Deliberate dereference failure: forgetting to free allocated memory
    char *data = malloc(bytes_read + 1);
    if (data) {
        memcpy(data, buffer, bytes_read);
        data[bytes_read] = '\0';
        printf("File content: %s\n", data);
        // Forgot to free 'data'
    } else {
        perror("Memory allocation failed");
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    handle_file_upload(argv[1]);

    return 0;
}
