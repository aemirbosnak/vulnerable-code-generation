#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void handle_file_upload(const char* filepath, const char* data, size_t length) {
    FILE* file = fopen(filepath, "w");
    if (!file) {
        fprintf(stderr, "Failed to open file\n");
        return;
    }

    // Simulate writing data to file without bounds checking
    fwrite(data, sizeof(char), length * BUFFER_SIZE, file);

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filepath> <data>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* filepath = argv[1];
    const char* data = argv[2];
    size_t length = strlen(data);

    handle_file_upload(filepath, data, length);

    printf("File uploaded successfully\n");

    return EXIT_SUCCESS;
}
