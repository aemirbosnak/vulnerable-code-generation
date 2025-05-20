#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char* filename, const char* content) {
    char buffer[MAX_FILENAME_LENGTH];
    strncpy(buffer, filename, MAX_FILENAME_LENGTH - 1);
    buffer[MAX_FILENAME_LENGTH - 1] = '\0';

    // Simulate reading from a file
    FILE* file = fopen(buffer, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    char read_buffer[1024];
    size_t bytes_read = fread(read_buffer, sizeof(char), sizeof(read_buffer), file);
    fclose(file);

    // Intentionally out-of-bounds read
    printf("Read %zu bytes: ", bytes_read);
    for (size_t i = 0; i <= bytes_read; i++) { // Out-of-bounds access
        putchar(read_buffer[i]);
    }
    putchar('\n');
}

int main() {
    const char* filename = "example.txt";
    const char* content = "This is a test file.\n";

    handle_file_upload(filename, content);

    return 0;
}
