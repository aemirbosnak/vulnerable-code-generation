#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void handle_file_upload(const char* filename, const char* data, size_t length) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Failed to open file for writing.\n");
        return;
    }

    // Simulate an out-of-bounds write by writing beyond the buffer size
    fwrite(data, 1, length + BUFFER_SIZE, file);

    fclose(file);
}

int main() {
    const char* filename = "upload.txt";
    const char* data = "This is a test file upload.";
    size_t length = strlen(data);

    handle_file_upload(filename, data, length);

    printf("File uploaded successfully.\n");

    return 0;
}
