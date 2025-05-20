#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *ext = strrchr(filename, '.');
    if (!ext || strcmp(ext, ".bmp") != 0) {
        printf("Invalid BMP file: %s\n", filename);
        return 1;
    }

    char *dimensions = strtok(filename, "x");
    if (!dimensions) {
        printf("Invalid BMP file dimensions in filename: %s\n", filename);
        return 1;
    }

    char *width = dimensions;
    dimensions = strtok(NULL, "x");
    if (!dimensions) {
        printf("Invalid BMP file dimensions in filename: %s\n", filename);
        return 1;
    }

    int w = atoi(width);
    int h = atoi(dimensions);

    printf("Width: %d\n", w);
    printf("Height: %d\n", h);

    return 0;
}
