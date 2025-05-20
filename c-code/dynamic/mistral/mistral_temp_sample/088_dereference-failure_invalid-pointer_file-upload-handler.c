#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_FILE_SIZE 1048576

void handle_file(FILE *file) {
    char buffer[BUFFER_SIZE];
    char *data = malloc(MAX_FILE_SIZE);
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        memcpy(data + strlen(data), buffer, bytes_read);
        data[strlen(data) + bytes_read] = '\0';
    }

    // Dereference failure vulnerability here
    printf("File data: %s\n", data);
    free(data);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *filename = argv[1];

    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    file = fopen(filename, "r");

    if (!file) {
        perror("Error opening file");
        return 1;
    }

    handle_file(file);

    fclose(file);
    return 0;
}
