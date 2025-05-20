//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 24
#define CHAR_SET ".,:;i1tf+\"#*$@"

void print_image(int image[], int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", CHAR_SET[image[y * width + x] / 32]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    int width, height, max_val;
    unsigned char *data;

    fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        printf("Error: Cannot open image file.\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET);
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);
    fread(&max_val, 4, 1, fp);

    data = (unsigned char*) malloc(3 * width * height);
    fread(data, 3 * width * height, 1, fp);

    int image[height][width];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = data[3 * (y * width + x)];
            int g = data[3 * (y * width + x) + 1];
            int b = data[3 * (y * width + x) + 2];

            int avg = (r + g + b) / 3;
            int val = avg * (max_val - 1) / 255;

            image[y][x] = val;
        }
    }

    print_image(image, width, height);

    free(data);
    fclose(fp);

    return 0;
}