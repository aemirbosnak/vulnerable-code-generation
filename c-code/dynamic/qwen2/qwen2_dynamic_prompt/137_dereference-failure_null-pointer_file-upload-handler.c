#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char buffer[MAX_FILENAME_LENGTH];
    size_t bytes_read = fread(buffer, 1, sizeof(buffer), file);
    fclose(file);

    if (bytes_read == 0) {
        printf("No data read from file\n");
        return;
    }

    // Deliberate null pointer dereference vulnerability
    char* malicious_data = NULL;
    *malicious_data = 'A'; // This will cause a segmentation fault

    printf("Data read: %.*s\n", (int)bytes_read, buffer);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    handle_file_upload(filename);

    return 0;
}
