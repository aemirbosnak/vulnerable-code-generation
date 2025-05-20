#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF_SIZE 4096

void upload_file(const char *filename) {
    char buffer[MAX_BUFF_SIZE];
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Unable to open file '%s'\n", filename);
        return;
    }

    size_t bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), MAX_BUFF_SIZE, file)) > 0) {
        printf("Received %ld bytes from file '%s'\n", bytes_read, filename);
        gets(buffer); // buffer overflow vulnerability
    }

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: uploader <filename>\n");
        return 1;
    }

    upload_file(argv[1]);

    return 0;
}
