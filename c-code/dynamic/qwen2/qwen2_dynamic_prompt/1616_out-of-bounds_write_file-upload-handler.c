#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 128

void handle_file_upload(const char* filename, const char* content) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Failed to open file for writing.\n");
        return;
    }

    // Simulate an out-of-bounds write by writing more data than expected
    size_t content_length = strlen(content);
    size_t buffer_size = content_length + 1024; // Allocate more space than needed
    char* buffer = (char*)malloc(buffer_size);
    if (!buffer) {
        fclose(file);
        printf("Memory allocation failed.\n");
        return;
    }

    memcpy(buffer, content, content_length);
    memset(buffer + content_length, 'A', 1024); // Fill the rest with 'A'

    fwrite(buffer, 1, buffer_size, file);

    free(buffer);
    fclose(file);
}

int main() {
    const char* filename = "test.txt";
    const char* content = "This is a test file upload.";

    handle_file_upload(filename, content);

    return 0;
}
