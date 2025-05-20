#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void write_file(const char *filename, const char *buffer, size_t size) {
    FILE *file = fopen(filename, "ab+");
    if (!file) {
        perror("Error opening file");
        return;
    }

    size_t written = fwrite(buffer, 1, size, file);
    if (written != size) {
        perror("Error writing to file");
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file> <data>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    const char *data = argv[2];

    char buffer[BUFFER_SIZE];
    size_t data_len = strlen(data);
    size_t i;

    for (i = 0; i < data_len + 100; ++i) { // Out-of-bounds write example
        buffer[i] = data[i % data_len];
    }

    write_file(filename, buffer, data_len + 100);

    return 0;
}
