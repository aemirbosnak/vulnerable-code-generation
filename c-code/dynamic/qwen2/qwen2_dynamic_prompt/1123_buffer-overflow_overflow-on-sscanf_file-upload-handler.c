#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char *filename) {
    char buffer[MAX_FILENAME_LENGTH];
    int id;

    // Simulate receiving data from a client
    if (sscanf(filename, "%d %s", &id, buffer) != 2) {
        fprintf(stderr, "Invalid input format\n");
        return;
    }

    // Vulnerability: Buffer overflow due to insufficient check on filename length
    strcpy(buffer, filename);

    printf("File ID: %d, Filename: %s\n", id, buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    handle_file_upload(argv[1]);

    return 0;
}
