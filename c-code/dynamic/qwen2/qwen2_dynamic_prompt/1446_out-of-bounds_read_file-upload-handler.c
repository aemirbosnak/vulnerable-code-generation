#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void handleFileUpload(char *filename, char *data) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Failed to open file\n");
        return;
    }

    fwrite(data, 1, strlen(data), file);
    fclose(file);

    // Out-of-bounds read vulnerability
    char buffer[BUFFER_SIZE];
    size_t len = fread(buffer, 1, sizeof(buffer), file);
    if (len > 0) {
        buffer[len] = '\0';
        printf("Read from file: %s\n", buffer);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <data>\n", argv[0]);
        return 1;
    }

    char filename[256];
    strncpy(filename, argv[1], sizeof(filename) - 1);
    filename[sizeof(filename) - 1] = '\0';

    char data[1024];
    strncpy(data, argv[2], sizeof(data) - 1);
    data[sizeof(data) - 1] = '\0';

    handleFileUpload(filename, data);

    return 0;
}
