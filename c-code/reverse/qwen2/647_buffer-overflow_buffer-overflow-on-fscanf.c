#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

void print_ascii_art(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char format[3];
    int width, height, max_val;
    fscanf(file, "%s %d %d %d", format, &width, &height, &max_val);
    if (strcmp(format, "P2") != 0 || max_val != 255) {
        fprintf(stderr, "Unsupported PGM format\n");
        fclose(file);
        return;
    }

    unsigned char pixels[MAX_HEIGHT][MAX_WIDTH];
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            fscanf(file, "%hhu", &pixels[i][j]);
        }
    }

    const char *ascii_chars = "@%#*+=-:. ";
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int index = pixels[i][j] / (256 / (strlen(ascii_chars) - 1));
            putchar(ascii_chars[index]);
        }
        putchar('\n');
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pgm_file>\n", argv[0]);
        return 1;
    }

    print_ascii_art(argv[1]);

    return 0;
}
