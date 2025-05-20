//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512

#define PI 3.14159265359

int main() {

    int i, j, k;
    int image[WIDTH][HEIGHT];
    int watermark[WIDTH][HEIGHT];
    int watermarked_image[WIDTH][HEIGHT];
    int message[4][4];

    // Load the image
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        printf("Error loading image.\n");
        exit(1);
    }

    fseek(fp, 54, SEEK_SET);
    fread(image, sizeof(int), WIDTH * HEIGHT, fp);
    fclose(fp);

    // Load the watermark
    fp = fopen("watermark.bmp", "rb");
    if (fp == NULL) {
        printf("Error loading watermark.\n");
        exit(1);
    }

    fseek(fp, 54, SEEK_SET);
    fread(watermark, sizeof(int), WIDTH * HEIGHT, fp);
    fclose(fp);

    // Generate the message
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            message[i][j] = rand() % 256;
        }
    }

    // Embed the message in the image
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            if (image[i][j] == 0) {
                for (k = 0; k < 4; k++) {
                    watermarked_image[i][j] += message[k][0] * cos(2 * PI * k * i / WIDTH);
                    watermarked_image[i][j] += message[k][1] * cos(2 * PI * k * j / HEIGHT);
                }
            } else {
                watermarked_image[i][j] = image[i][j];
            }
        }
    }

    // Save the watermarked image
    fp = fopen("watermarked_image.bmp", "wb");
    if (fp == NULL) {
        printf("Error saving watermarked image.\n");
        exit(1);
    }

    fwrite(watermarked_image, sizeof(int), WIDTH * HEIGHT, fp);
    fclose(fp);

    return 0;
}