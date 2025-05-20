#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char* filename) {
    char buffer[1024];
    size_t len = strlen(filename);

    // Integer overflow vulnerability
    if (len > sizeof(buffer)) {
        int offset = len - sizeof(buffer);
        memmove(buffer, &filename[offset], sizeof(buffer));
    }

    // Simulate file processing
    printf("Processing file: %s\n", buffer);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];

    printf("Enter file name to upload: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);

    // Remove newline character if present
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }

    handle_file_upload(filename);

    return 0;
}
