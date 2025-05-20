#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char *filename, const char *data, size_t data_size) {
    char buffer[MAX_FILENAME_LENGTH];
    strcpy(buffer, filename);

    // Deliberate array bounds violation
    char *ptr = buffer + strlen(buffer);
    *ptr = 'a'; // This will overwrite the null terminator of buffer

    FILE *file = fopen(buffer, "wb");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    fwrite(data, 1, data_size, file);
    fclose(file);
}

int main() {
    const char *filename = "example.txt";
    const char *data = "Hello, world!";
    size_t data_size = strlen(data);

    handle_file_upload(filename, data, data_size);

    return 0;
}
