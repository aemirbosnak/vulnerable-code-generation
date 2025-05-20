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
        fprintf(stderr, "Failed to open file for writing\n");
        return;
    }

    // Simulate an out-of-bounds write by writing more data than the buffer size
    fwrite(data, 1, BUFFER_SIZE + 100, file);

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

    printf("File uploaded successfully\n");

    return 0;
}
