#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 24

void bmpToAscii(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) return;

    unsigned char header[54];
    fread(header, 1, 54, file);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    unsigned char imgData[HEIGHT][WIDTH];
    fseek(file, 54, SEEK_SET);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            imgData[y][x] = fgetc(file);
        }
    }

    const char* asciiChars = "@%#*+=-:. ";
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int grayScale = imgData[y][x];
            int index = (grayScale * 69) / 256;
            putchar(asciiChars[index]);
        }
        putchar('\n');
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    bmpToAscii(argv[1]);
    return 0;
}
