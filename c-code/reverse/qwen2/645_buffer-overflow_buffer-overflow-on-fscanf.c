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
        perror("Error opening file");
        return;
    }

    unsigned char header[1024];
    fread(header, 1, sizeof(header), file);
    fclose(file);

    int width = 0, height = 0, maxval = 0;
    sscanf((char *)header, "P5\n%d %d\n%d", &width, &height, &maxval);

    if (width > WIDTH || height > HEIGHT) {
        printf("Image too large for conversion.\n");
        return;
    }

    unsigned char *image = malloc(width * height);
    if (!image) {
        perror("Memory allocation failed");
        return;
    }

    file = fopen(filename, "rb");
    fseek(file, 54, SEEK_SET);
    fread(image, 1, width * height, file);
    fclose(file);

    const char *asciiChars = "@%#*+=-:. ";
    char asciiArt[HEIGHT][WIDTH + 1];

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int grayScale = image[y * width + x] * 9 / maxval;
            asciiArt[y][x] = asciiChars[grayScale];
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
        fprintf(stderr, "Usage: %s <pgm_image_file>\n", argv[0]);
        return 1;
    }

    convertToAscii(argv[1]);

    return 0;
}
