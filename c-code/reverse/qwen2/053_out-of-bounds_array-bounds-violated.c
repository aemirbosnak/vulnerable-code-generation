#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 24

void convertToAscii(char *bmpData, int width, int height) {
    char ascii[] = "@%#*+=-:. ";
    unsigned char *image = (unsigned char *)bmpData;
    int pixelSize = width * height * 3;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = image[(y * width + x) * 3];
            int g = image[(y * width + x) * 3 + 1];
            int b = image[(y * width + x) * 3 + 2];
            int gray = (r * 30 + g * 59 + b * 11) / 100;
            int index = gray / 25;
            printf("%c", ascii[index]);
        }
        printf("\n");
    }
}

int main() {
    FILE *file = fopen("input.bmp", "rb");
    if (!file) return 1;

    fseek(file, 10, SEEK_SET);
    long offset;
    fread(&offset, sizeof(long), 1, file);

    fseek(file, offset, SEEK_SET);
    unsigned char header[54];
    fread(header, 54, 1, file);

    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    int rowSize = ((width * 3 + 3) & ~3);
    int pixelSize = rowSize * height;

    char *data = malloc(pixelSize);
    fseek(file, offset + 54, SEEK_SET);
    fread(data, 1, pixelSize, file);

    fclose(file);

    convertToAscii(data, width, height);

    free(data);
    return 0;
}
