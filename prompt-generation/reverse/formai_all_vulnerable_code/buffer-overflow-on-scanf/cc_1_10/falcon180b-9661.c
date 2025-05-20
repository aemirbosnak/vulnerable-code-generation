//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 256

int main(int argc, char **argv) {
    unsigned char image[WIDTH * HEIGHT * 3];
    FILE *fp;
    int i, j, k;
    int brightness, contrast;

    fp = fopen("image.raw", "rb");
    if (fp == NULL) {
        printf("Error: Could not open image file.\n");
        exit(1);
    }

    fread(image, sizeof(char), WIDTH * HEIGHT * 3, fp);
    fclose(fp);

    printf("Enter brightness (0-100): ");
    scanf("%d", &brightness);
    printf("Enter contrast (0-100): ");
    scanf("%d", &contrast);

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            for (k = 0; k < 3; k++) {
                int value = image[(i * WIDTH + j) * 3 + k];
                int new_value = (int) ((double) value * (double) contrast / 100.0);
                if (new_value > 255) {
                    new_value = 255;
                } else if (new_value < 0) {
                    new_value = 0;
                }
                image[(i * WIDTH + j) * 3 + k] = (unsigned char) new_value;
            }
        }
    }

    fp = fopen("output.raw", "wb");
    if (fp == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    fwrite(image, sizeof(char), WIDTH * HEIGHT * 3, fp);
    fclose(fp);

    printf("Done.\n");
    return 0;
}