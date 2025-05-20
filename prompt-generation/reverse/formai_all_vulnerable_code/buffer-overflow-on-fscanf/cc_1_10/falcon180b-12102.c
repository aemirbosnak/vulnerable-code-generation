//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 256

void add_watermark(int *image, int *watermark, int width, int height) {
    int i, j, k;
    int alpha = 50;
    int beta = 150;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int pixel = image[i * width + j];

            for (k = 0; k < 3; k++) {
                int w = watermark[k * width + j];
                int dw = w - pixel;
                int v = (dw * alpha) / 255;
                pixel += v;
            }

            image[i * width + j] = pixel;
        }
    }
}

void save_image(int *image, int width, int height, char *filename) {
    FILE *fp;
    int i, j;

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fprintf(fp, "%d ", image[i * width + j]);
        }
    }

    fclose(fp);
}

int main() {
    int image[WIDTH * HEIGHT], watermark[WIDTH * HEIGHT];
    int i, j;

    // Load image
    FILE *fp;
    fp = fopen("image.txt", "rb");
    if (fp == NULL) {
        printf("Error: Could not open file image.txt\n");
        exit(1);
    }

    for (i = 0; i < WIDTH * HEIGHT; i++) {
        fscanf(fp, "%d", &image[i]);
    }

    fclose(fp);

    // Load watermark
    fp = fopen("watermark.txt", "rb");
    if (fp == NULL) {
        printf("Error: Could not open file watermark.txt\n");
        exit(1);
    }

    for (i = 0; i < WIDTH * HEIGHT; i++) {
        fscanf(fp, "%d", &watermark[i]);
    }

    fclose(fp);

    // Add watermark
    add_watermark(image, watermark, WIDTH, HEIGHT);

    // Save watermarked image
    save_image(image, WIDTH, HEIGHT, "watermarked.txt");

    return 0;
}