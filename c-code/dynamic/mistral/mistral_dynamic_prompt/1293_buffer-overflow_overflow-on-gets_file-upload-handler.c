#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

void save_file(const char *filename, const char *data) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return;
    }

    size_t bytes_written = fwrite(data, sizeof(char), strlen(data), file);
    fclose(file);

    if (bytes_written != strlen(data)) {
        fprintf(stderr, "Error writing to file: %s\n", filename);
    }
}

void display_usage() {
    printf("Usage: ./uploader filename data\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage();
        return 1;
    }

    char filename[MAX_BUFFER];
    char data[MAX_BUFFER];

    strcpy(filename, argv[1]);
    strcpy(data, argv[2]);

    save_file(filename, data);
    return 0;
}
