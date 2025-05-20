#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 256
#define MAX_HEIGHT 256

void convertBmpToAscii(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    unsigned char header[54];
    fread(header, 1, 54, file);

    int width, height;
    if (sscanf(filename, "%dx%d.bmp", &width, &height) != 2) {
        fprintf(stderr, "Invalid filename format: %s\n", filename);
        fclose(file);
        return;
    }

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        fprintf(stderr, "Image size too large: %dx%d\n", width, height);
        fclose(file);
        return;
    }

    unsigned char *data = malloc(width * height * 3);
    if (!data) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return;
    }

    fseek(file, 54, SEEK_SET);
    fread(data, 1, width * height * 3, file);
    fclose(file);

    const char *asciiChars = "@%#*+=-:. ";
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int index = (y * width + x) * 3;
            int grayScale = data[index] * 0.3 + data[index + 1] * 0.59 + data[index + 2] * 0.11;
            int asciiIndex = grayScale / 25;
            printf("%c", asciiChars[asciiIndex]);
        }
        printf("\n");
    }

    free(data);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    convertBmpToAscii(argv[1]);

    return 0;
}
