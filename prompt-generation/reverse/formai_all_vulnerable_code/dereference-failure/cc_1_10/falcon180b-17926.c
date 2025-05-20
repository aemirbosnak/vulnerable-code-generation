//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define WATERMARK_WIDTH 64
#define WATERMARK_HEIGHT 64

int main() {
    unsigned char* image = (unsigned char*)malloc(WIDTH * HEIGHT * 3);
    unsigned char* watermark = (unsigned char*)malloc(WATERMARK_WIDTH * WATERMARK_HEIGHT * 3);

    // Initialize the image with random values
    for (int i = 0; i < WIDTH * HEIGHT * 3; i++) {
        image[i] = rand() % 256;
    }

    // Initialize the watermark with a medieval pattern
    for (int i = 0; i < WATERMARK_WIDTH * WATERMARK_HEIGHT * 3; i++) {
        int x = i % WATERMARK_WIDTH;
        int y = i / WATERMARK_WIDTH;
        if ((x + y) % 2 == 0) {
            watermark[i] = 128;
        } else {
            watermark[i] = 0;
        }
    }

    // Embed the watermark into the image
    for (int i = 0; i < WIDTH * HEIGHT * 3; i++) {
        int x = i % WIDTH;
        int y = i / WIDTH;
        int wm_x = x / 8;
        int wm_y = y / 8;
        int wm_offset = (wm_y * WATERMARK_WIDTH + wm_x) * 3;
        image[i] ^= watermark[wm_offset];
    }

    // Save the watermarked image as a file
    FILE* outfile = fopen("medieval_watermark.png", "wb");
    if (outfile == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }
    fprintf(outfile, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, 3, WIDTH * HEIGHT, outfile);
    fclose(outfile);

    // Free the memory
    free(image);
    free(watermark);

    return 0;
}