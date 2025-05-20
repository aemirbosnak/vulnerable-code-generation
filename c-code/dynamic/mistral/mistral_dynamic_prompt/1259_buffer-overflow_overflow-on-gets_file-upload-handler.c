#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 512

void handle_file_upload(char *filename) {
    FILE *file = fopen(filename, "wb");

    if (!file) {
        fprintf(stderr, "Error: Could not open file %s.\n", filename);
        return;
    }

    char buffer[BUFFER_SIZE];
    printf("Enter file data (Ctrl+D to stop):\n");

    while (gets(buffer)) {
        if (fwrite(buffer, strlen(buffer), 1, file) != 1) {
            fprintf(stderr, "Error: Writing to file %s.\n", filename);
            break;
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    handle_file_upload(argv[1]);
    return 0;
}
