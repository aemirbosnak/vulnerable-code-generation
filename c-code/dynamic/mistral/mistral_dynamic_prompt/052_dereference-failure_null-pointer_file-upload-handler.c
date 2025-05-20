#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_file_upload(char *buffer) {
    char *data = (char *) malloc(1024);
    char *end = data + 1024;
    char *current = data;

    printf("Start processing file...\n");

    while (*buffer != '\0') {
        *current++ = *buffer++;
        if (current >= end) {
            data = (char *) realloc(data, (current - data) * 2 + 1024);
            end = data + 1024;
        }
    }

    printf("File processed successfully. Data: %s\n", data);

    free(data);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./a.out <filename>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        handle_file_upload(buffer);
    }

    fclose(file);

    return 0;
}
