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

    unsigned char* pixels = (unsigned char*)malloc(width * height * 3);
    fseek(file, 54, SEEK_SET);
    fread(pixels, 1, width * height * 3, file);
    fclose(file);

    const char* asciiChars = "@%#*+=-:. ";
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            int px = (x * width / WIDTH) + ((height - (y * height / HEIGHT)) * width);
            int r = pixels[px * 3];
            int g = pixels[px * 3 + 1];
            int b = pixels[px * 3 + 2];
            int gray = (r + g + b) / 3;
            putchar(asciiChars[gray * 6 / 256]);
        }
        putchar('\n');
    }

    free(pixels);
}

int main() {
    bmpToAscii("input.bmp");
    return 0;
}
