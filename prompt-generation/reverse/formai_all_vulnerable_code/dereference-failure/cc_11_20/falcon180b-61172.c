//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512

int main() {
    int **image = (int **)malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        image[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    // Initialize image with random values
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = rand() % 256;
        }
    }

    // Flip image horizontally
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH / 2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][WIDTH - j - 1];
            image[i][WIDTH - j - 1] = temp;
        }
    }

    // Change brightness
    float brightness = 1.5;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = (int)round(image[i][j] * brightness);
        }
    }

    // Change contrast
    float contrast = 2.0;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int temp = image[i][j];
            temp = temp < 128? temp + 128 : temp - 128;
            image[i][j] = (int)round(temp * contrast);
        }
    }

    // Save modified image to file
    FILE *fp = fopen("modified_image.bmp", "wb");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    fprintf(fp, "BM\n");
    fprintf(fp, "%d %d\n", WIDTH, HEIGHT);
    fprintf(fp, "%d\n", 54);

    for (int i = HEIGHT - 1; i >= 0; i--) {
        fwrite(image[i], sizeof(int), WIDTH, fp);
    }

    fclose(fp);

    for (int i = 0; i < HEIGHT; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}