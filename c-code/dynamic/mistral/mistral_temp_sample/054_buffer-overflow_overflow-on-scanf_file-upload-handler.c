#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void handle_file_upload(char *filename) {
    FILE *file;
    char buffer[BUFFER_SIZE];

    printf("Uploading file: %s\n", filename);
    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("Reading file...\n");
    while (fgets(buffer, BUFFER_SIZE, file)) {
        // Intentionally creating a buffer overflow by reading more data than the buffer can hold
        char extra_data[100];
        fgets(extra_data, sizeof(extra_data), file);
        strcat(buffer, extra_data);
    }

    fclose(file);

    printf("File uploaded successfully.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    handle_file_upload(argv[1]);

    return 0;
}
