#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_FILE_SIZE 1023

void read_file(FILE *fp, char *buffer) {
    size_t bytes_read;

    if ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, fp)) > MAX_FILE_SIZE) {
        printf("Error: File is too large.\n");
        exit(EXIT_FAILURE);
    }

    buffer[bytes_read] = '\0';
}

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char *filename = argv[1];
    int len;

    if (argc != 2) {
        printf("Usage: ./file_uploader <filename>\n");
        return EXIT_FAILURE;
    }

    file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    read_file(file, buffer);

    len = strlen(buffer);
    char input[len + 1 + sizeof(buffer)];
    strcpy(input, buffer);

    // Intentional Integer Overflow Vulnerability
    // Adding a string to an array of integers without checking its size
    sprintf(input + len, "%s", "extra_data");

    // Write the content back to stdout (a pipe for real-world scenario)
    write(STDOUT_FILENO, input, strlen(input));

    fclose(file);
    return EXIT_SUCCESS;
}
