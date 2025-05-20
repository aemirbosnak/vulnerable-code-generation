#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char *filename) {
    char buffer[MAX_FILENAME_LENGTH];
    FILE *file;
    size_t bytes_read;

    // Simulate reading the filename from user input
    strncpy(buffer, filename, sizeof(buffer));
    buffer[sizeof(buffer) - 1] = '\0'; // Ensure null-termination

    // Open the file
    file = fopen(buffer, "rb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    // Read data from the file
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        // Process the data (simulated)
        for (size_t i = 0; i <= bytes_read; i++) { // Out-of-bounds read vulnerability
            printf("%c", buffer[i]);
        }
    }

    fclose(file);
}

int main() {
    const char *filename = "example.txt";
    handle_file_upload(filename);
    return 0;
}
