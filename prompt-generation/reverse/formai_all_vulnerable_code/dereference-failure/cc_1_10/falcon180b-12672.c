//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_VALUE 255

// Define the watermark pattern
#define WATERMARK_WIDTH 64
#define WATERMARK_HEIGHT 64
#define WATERMARK_VALUE 128

// Define the frequency of the watermark pattern
#define FREQUENCY 4

void apply_watermark(unsigned char* image, int width, int height, int watermark_width, int watermark_height, int watermark_value, int frequency) {
    int i, j, k, l;
    int x, y;
    int value;

    // Iterate over the image pixels
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            value = image[i * width + j];

            // Apply the watermark pattern
            if ((i % frequency == 0) && (j % frequency == 0)) {
                value = watermark_value;
            }

            // Copy the pixel value to the output image
            image[i * width + j] = value;
        }
    }
}

int main() {
    unsigned char* image = (unsigned char*) malloc(WIDTH * HEIGHT * sizeof(unsigned char));
    int i, j;

    // Initialize the image with random values
    for (i = 0; i < WIDTH * HEIGHT; i++) {
        image[i] = rand() % MAX_VALUE;
    }

    // Apply the watermark
    apply_watermark(image, WIDTH, HEIGHT, WATERMARK_WIDTH, WATERMARK_HEIGHT, WATERMARK_VALUE, FREQUENCY);

    // Save the watermarked image
    FILE* fp = fopen("watermarked_image.bmp", "wb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);

    printf("Watermarked image saved as watermarked_image.bmp.\n");

    return 0;
}