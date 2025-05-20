//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define MAX_PIXELS (MAX_WIDTH * MAX_HEIGHT)
#define MAX_CHARS (MAX_PIXELS * 2)

typedef struct {
    int width;
    int height;
    char *data;
} Image;

typedef struct {
    int x;
    int y;
    int c;
} Pixel;

Pixel *pixels_to_ascii(Image *image, int threshold) {
    Pixel *ascii = malloc(sizeof(Pixel) * MAX_PIXELS);
    int pixels = 0;

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int value = (int) image->data[y * image->width + x] * 255;

            if (value >= threshold) {
                ascii[pixels].x = x;
                ascii[pixels].y = y;
                ascii[pixels].c = '@';
                pixels++;
            }
        }
    }

    return ascii;
}

void print_ascii(Pixel *ascii, int pixels) {
    for (int i = 0; i < pixels; i++) {
        printf("%c", ascii[i].c);
    }
}

int main() {
    FILE *fp = fopen("example.bmp", "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    Image image;
    fread(&image.width, sizeof(int), 1, fp);
    fread(&image.height, sizeof(int), 1, fp);

    image.data = malloc(sizeof(char) * image.width * image.height);
    fread(image.data, sizeof(char), image.width * image.height, fp);

    fclose(fp);

    Pixel *ascii = pixels_to_ascii(&image, 128);
    print_ascii(ascii, image.width * image.height);

    free(ascii);
    free(image.data);

    return 0;
}