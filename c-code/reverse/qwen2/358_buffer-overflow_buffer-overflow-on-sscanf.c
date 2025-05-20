#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 24

void bmp_to_ascii(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return;

    unsigned char header[54];
    fread(header, 1, 54, file);
    int width = *(int *)&header[18], height = *(int *)&header[22];

    unsigned char pixels[height][width];
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            fread(&pixels[y][x], 3, 1, file);
        }
    }

    fclose(file);

    const char *ascii_chars = "@%#*+=-:. ";
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int gray = pixels[y][x] * 0.299 + pixels[y][x] * 0.587 + pixels[y][x] * 0.114;
            putchar(ascii_chars[gray / 25]);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) return 1;
    bmp_to_ascii(argv[1]);
    return 0;
}
