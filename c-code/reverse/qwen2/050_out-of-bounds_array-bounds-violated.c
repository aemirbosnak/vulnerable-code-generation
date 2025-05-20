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
    int width = *(int*)&header[18], height = *(int*)&header[22];

    unsigned char* data = (unsigned char*)malloc(width * height * 3);
    fread(data, 1, width * height * 3, file);
    fclose(file);

    const char* ascii = "@%#*+=-:. ";
    char output[HEIGHT][WIDTH + 1];

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = data[(y * width + x) * 3];
            int g = data[(y * width + x) * 3 + 1];
            int b = data[(y * width + x) * 3 + 2];
            int gray = (r + g + b) / 3;
            int index = gray * (sizeof(ascii) - 1) / 256;
            output[y][x] = ascii[index];
        }
        output[y][width] = '\0';
    }

    for (int y = 0; y < HEIGHT; y++) {
        printf("%s\n", output[y]);
    }

    free(data);
}

int main() {
    bmpToAscii("example.bmp");
    return 0;
}
