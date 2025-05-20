#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void handle_file_upload(char *filename, char *data) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Failed to open file\n");
        return;
    }

    fwrite(data, 1, strlen(data), file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <data>\n", argv[0]);
        return 1;
    }

    char filename[BUFFER_SIZE];
    strncpy(filename, argv[1], sizeof(filename) - 1);
    filename[sizeof(filename) - 1] = '\0';

    char data[BUFFER_SIZE];
    strncpy(data, argv[2], sizeof(data) - 1);
    data[sizeof(data) - 1] = '\0';

    handle_file_upload(filename, data);

    return 0;
}
