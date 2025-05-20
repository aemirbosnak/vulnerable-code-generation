#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 24

void convertBMPtoASCII(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) return;

    unsigned char bmpHeader[54];
    fread(bmpHeader, 1, 54, file);

    int width = *(int*)&bmpHeader[18];
    int height = *(int*)&bmpHeader[22];

    unsigned char* imageData = (unsigned char*)malloc(width * height * 3);
    fseek(file, 54, SEEK_SET);
    fread(imageData, 1, width * height * 3, file);
    fclose(file);

    const char* asciiChars = "@%#*+=-:. ";
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = imageData[(y * width + x) * 3];
            int g = imageData[(y * width + x) * 3 + 1];
            int b = imageData[(y * width + x) * 3 + 2];
            int gray = (r + g + b) / 3;
            int index = gray * (sizeof(asciiChars) - 1) / 256;
            printf("%c", asciiChars[index]);
        }
        printf("\n");
    }

    free(imageData);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.bmp>\n", argv[0]);
        return 1;
    }
    convertBMPtoASCII(argv[1]);
    return 0;
}
