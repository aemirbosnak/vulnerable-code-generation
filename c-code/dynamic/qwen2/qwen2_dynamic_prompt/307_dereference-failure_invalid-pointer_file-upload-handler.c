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
    fclose(file);

    // Deliberate dereference failure: invalid pointer
    int *ptr = NULL;
    *ptr = 42; // This will cause a segmentation fault

    printf("Bytes read: %zu\n", bytes_read);
}

int main() {
    const char *filename = "example.txt";
    handle_file_upload(filename);
    return 0;
}
