//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_VALUE 255
#define MIN_VALUE 0

void ascii_art(unsigned char *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int value = image[i * width + j];
            int ascii_value = round(value / (MAX_VALUE - MIN_VALUE) * (HEIGHT - 1));

            if (ascii_value < 0) {
                ascii_value = 0;
            } else if (ascii_value >= HEIGHT) {
                ascii_value = HEIGHT - 1;
            }

            printf("%c", ascii_value + 33);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    unsigned char header[3];
    int width, height, bpp;
    unsigned char *image;

    fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    fread(header, 1, 3, fp);

    if (header[0]!= 'B' || header[1]!= 'M') {
        printf("Error: Invalid file format.\n");
        exit(2);
    }

    width = *(int *)&header[18];
    height = *(int *)&header[22];
    bpp = *(int *)&header[28];

    if (bpp!= 24) {
        printf("Error: Only 24-bit BMP files are supported.\n");
        exit(3);
    }

    image = malloc(width * height * 3);
    fread(image, width * height * 3, 1, fp);

    ascii_art(image, width, height);

    free(image);
    fclose(fp);

    return 0;
}