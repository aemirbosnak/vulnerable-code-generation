#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 78
#define HEIGHT 45

void convertToAscii(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file\n");
        return;
    }

    unsigned char bmpHeader[54];
    fread(bmpHeader, 1, 54, file);
    int width = *(int*)&bmpHeader[18];
    int height = *(int*)&bmpHeader[22];

    int padding = (width % 4 == 0) ? 0 : (4 - (width % 4));
    int totalSize = ((width + padding) * 3) * abs(height);

    unsigned char *imageData = (unsigned char *)malloc(totalSize);
    fseek(file, 54, SEEK_SET);
    fread(imageData, 1, totalSize, file);
    fclose(file);

    char asciiArt[HEIGHT][WIDTH + 1];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int imgX = (x * width) / WIDTH;
            int imgY = (y * height) / HEIGHT;
            int index = (imgY * (width + padding) + imgX) * 3;
            int grayScale = imageData[index] * 0.3 + imageData[index + 1] * 0.59 + imageData[index + 2] * 0.11;
            char ch = (grayScale < 64) ? 'S' : (grayScale < 128) ? '@' : (grayScale < 192) ? '#' : '*';
            asciiArt[y][x] = ch;
        }
        asciiArt[y][WIDTH] = '\0';
    }

    for (int y = 0; y < HEIGHT; y++) {
        printf("%s\n", asciiArt[y]);
    }

    free(imageData);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <BMP filename>\n", argv[0]);
        return 1;
    }
    convertToAscii(argv[1]);
    return 0;
}
