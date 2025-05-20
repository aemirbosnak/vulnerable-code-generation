#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void handle_file(char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[MAX_SIZE];
    if (file) {
        int bytes_read = fread(buffer, sizeof(char), MAX_SIZE, file);
        fclose(file);
        printf("File content:\n");
        printf("%s\n", buffer);

        // Intentionally vulnerable gets function call
        gets(buffer);
    } else {
        printf("Error: Unable to open file.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./file_uploader <filename>\n");
        return 1;
    }

    handle_file(argv[1]);

    return 0;
}
