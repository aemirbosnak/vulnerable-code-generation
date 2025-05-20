#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 24

void convertToAscii(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    unsigned char header[1024];
    fread(header, 1, 1024, file);
    fclose(file);

    if (header[0] != 'P' || header[1] != '5') {
        printf("Unsupported file format.\n");
        return;
    }

    int maxval, width, height;
    sscanf((char *)header + 3, "%d %d\n%d", &width, &height, &maxval);

    if (width > WIDTH || height > HEIGHT) {
        printf("Image too large.\n");
        return;
    }

    unsigned char *image = malloc(width * height);
    if (!image) {
        printf("Memory allocation failed.\n");
        return;
    }

    file = fopen(filename, "rb");
    fseek(file, 5, SEEK_SET);
    fread(image, 1, width * height, file);
    fclose(file);

    const char *asciiChars = "@%#*+=-:. ";
    char asciiArt[HEIGHT][WIDTH + 1];

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int grayScale = image[y * width + x];
            int index = (grayScale * (strlen(asciiChars) - 1)) / maxval;
            asciiArt[y][x] = asciiChars[index];
        }
        asciiArt[y][width] = '\0';
    }

    for (int y = 0; y < height; y++) {
        printf("%s\n", asciiArt[y]);
    }

    free(image);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <pgm_file>\n", argv[0]);
        return 1;
    }

    convertToAscii(argv[1]);

    return 0;
}
