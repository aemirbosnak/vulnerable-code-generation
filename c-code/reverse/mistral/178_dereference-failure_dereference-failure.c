#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file);
    fclose(file);

    size_t i, j = 0;
    for (i = 0; i < bytes_read; ++i) {
        if (isascii(buffer[i]) && !isprint(buffer[i])) {
            printf("Non-ASCII character found in the file.\n");
            return 1;
        }
        if (buffer[i] != '\0' && buffer[i] != ' ') {
            buffer[j++] = buffer[i];
        }
    }
    buffer[j] = '\0';

    printf("Successfully processed file %s\n", argv[1]);
    return 0;
}
