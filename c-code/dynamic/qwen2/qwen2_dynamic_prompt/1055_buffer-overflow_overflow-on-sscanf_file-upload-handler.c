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
    float size;

    // Simulate reading from user input
    printf("Enter file ID: ");
    if (scanf("%d", &id) != 1) {
        fprintf(stderr, "Invalid input for file ID\n");
        return;
    }

    printf("Enter file size: ");
    if (scanf("%f", &size) != 1) {
        fprintf(stderr, "Invalid input for file size\n");
        return;
    }

    printf("Enter filename: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        fprintf(stderr, "Failed to read filename\n");
        return;
    }

    // Remove newline character if present
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    // Vulnerable line: buffer overflow due to insufficient check on sscanf
    if (sscanf(buffer, "%s", buffer) != 1) {
        fprintf(stderr, "Failed to parse filename\n");
        return;
    }

    // Simulate saving file information
    printf("File uploaded successfully with ID %d, size %.2f MB, name %s\n", id, size, buffer);
}

int main() {
    const char *test_filename = "A very long string that will cause a buffer overflow because it exceeds the MAX_FILENAME_LENGTH";
    handle_file_upload(test_filename);
    return 0;
}
