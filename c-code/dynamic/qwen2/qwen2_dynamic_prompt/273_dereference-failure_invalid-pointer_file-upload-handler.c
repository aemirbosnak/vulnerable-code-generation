#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char *filename) {
    FILE *file;
    char buffer[1024];
    size_t bytes_read;

    // Simulate file opening
    if (strcmp(filename, "safe.txt") == 0) {
        file = fopen("safe.txt", "r");
    } else {
        file = fopen("unsafe.txt", "w");
    }

    if (!file) {
        perror("Failed to open file");
        return;
    }

    // Simulate reading from file
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        fwrite(buffer, 1, bytes_read, stdout);
    }

    fclose(file);

    // Dereference failure vulnerability
    int *ptr = NULL;
    printf("%d\n", *ptr);  // Invalid pointer dereference
}

int main() {
    const char *filename = "example.txt";
    handle_file_upload(filename);
    return 0;
}
