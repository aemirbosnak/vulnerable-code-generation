#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void handle_file_upload(const char *filename, const char *data) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    // Simulate an out-of-bounds write vulnerability
    char buffer[BUFFER_SIZE];
    size_t data_len = strlen(data);
    if (data_len > BUFFER_SIZE - 1) {
        data_len = BUFFER_SIZE - 1;
    }
    memcpy(buffer, data, data_len);
    buffer[data_len] = '\0'; // Null-terminate the string

    fwrite(buffer, 1, data_len, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <data>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    const char *data = argv[2];

    handle_file_upload(filename, data);

    printf("File uploaded successfully.\n");

    return 0;
}
