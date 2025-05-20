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

    unsigned char* data = (unsigned char*)malloc(width * height * 3);
    fseek(file, 54, SEEK_SET);
    fread(data, 1, width * height * 3, file);
    fclose(file);

    const char* asciiChars = "@%#*+=-:. ";
    int asciiWidth = strlen(asciiChars);
    int asciiHeight = HEIGHT;
    int asciiScale = width / asciiWidth;

    for (int y = 0; y < height; y += asciiScale) {
        for (int x = 0; x < width; x += asciiScale) {
            int r = 0, g = 0, b = 0;
            for (int i = 0; i < asciiScale; i++) {
                for (int j = 0; j < asciiScale; j++) {
                    int index = ((y + i) * width + (x + j)) * 3;
                    r += data[index];
                    g += data[index + 1];
                    b += data[index + 2];
                }
            }
            r /= asciiScale * asciiScale;
            g /= asciiScale * asciiScale;
            b /= asciiScale * asciiScale;
            int gray = (r * 30 + g * 59 + b * 11) / 100;
            int asciiIndex = gray * asciiWidth / 256;
            printf("%c", asciiChars[asciiIndex]);
        }
        printf("\n");
    }

    free(data);
}

int main() {
    bmpToAscii("input.bmp");
    return 0;
}
