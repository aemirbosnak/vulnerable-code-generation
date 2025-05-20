//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HEIGHT 256
#define WIDTH 256

int main() {
    int width, height, x, y, i, j;
    FILE *fp;
    char filename[100];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    int *image = (int *)malloc(width * height * sizeof(int));

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fread(&image[i * width + j], sizeof(int), 1, fp);
        }
    }
    fclose(fp);

    int *new_image = (int *)malloc(width * height * sizeof(int));

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int r = image[i * width + j] >> 16 & 0xFF;
            int g = image[i * width + j] >> 8 & 0xFF;
            int b = image[i * width + j] & 0xFF;
            int avg = (r + g + b) / 3;

            int new_r = avg + 100;
            int new_g = avg + 100;
            int new_b = avg + 100;

            if (new_r > 255) {
                new_r = 255;
            }
            if (new_g > 255) {
                new_g = 255;
            }
            if (new_b > 255) {
                new_b = 255;
            }

            new_image[i * width + j] = (new_r << 16) | (new_g << 8) | new_b;
        }
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fwrite(&new_image[i * width + j], sizeof(int), 1, fp);
        }
    }

    fclose(fp);

    return 0;
}