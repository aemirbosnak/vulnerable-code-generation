#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char *filename) {
    FILE *file;
    char buffer[1024];
    size_t bytes_read;

    // Simulate file opening
    if (strcmp(filename, "safe.txt") == 0) {
        file = fopen("safe.txt", "r");
    } else {
        file = fopen(filename, "w");
    }

    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    // Simulate reading from file
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        fwrite(buffer, 1, bytes_read, stdout);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];

    // Deliberate null pointer dereference vulnerability
    if (filename == NULL) {
        printf("Filename is NULL\n");
        return 1;
    }

    handle_file_upload(filename);

    return 0;
}
