#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_BUF 1024

void process_file(FILE *file) {
    char buffer[MAX_BUF];
    char *temp_path = malloc(MAX_BUF);

    if (!temp_path) {
        perror("Memory allocation error");
        return;
    }

    size_t bytes_read = fread(buffer, sizeof(char), MAX_BUF, file);
    if (bytes_read <= 0) {
        free(temp_path);
        return;
    }

    strcpy(temp_path, "/tmp/");
    strncat(temp_path, buffer, MAX_BUF);
    strncat(temp_path, ".uploaded", MAX_BUF);

    FILE *temp_file = fopen(temp_path, "w");
    if (!temp_file) {
        perror("Failed to open temporary file");
        free(temp_path);
        return;
    }

    size_t written = fwrite(buffer, sizeof(char), bytes_read, temp_file);
    if (written != bytes_read) {
        perror("Failed to write file");
    }

    fclose(temp_file);
    free(temp_path);
}

int main(int argc, char **argv) {
    FILE *input_file = fopen(argv[1], "r");

    if (!input_file) {
        perror("Failed to open input file");
        return 1;
    }

    process_file(input_file);

    fclose(input_file);
    return 0;
}
