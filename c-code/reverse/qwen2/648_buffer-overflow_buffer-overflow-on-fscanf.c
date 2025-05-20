#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    FILE *file = fopen("input.pgm", "r");
    if (!file) return 1;

    char format[3];
    int width, height, maxval;
    fscanf(file, "%s %d %d %d", format, &width, &height, &maxval);

    char *ascii_art = (char *)malloc(width * height);
    if (!ascii_art) return 1;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            unsigned char pixel;
            fscanf(file, "%hhu", &pixel);
            ascii_art[i * width + j] = (pixel > 127) ? '*' : ' ';
        }
    }

    fclose(file);
    free(ascii_art);

    return 0;
}
