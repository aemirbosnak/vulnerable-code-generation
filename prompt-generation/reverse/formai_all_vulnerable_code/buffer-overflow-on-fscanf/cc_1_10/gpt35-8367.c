//FormAI DATASET v1.0 Category: Image Editor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct pixel {
    unsigned char r, g, b;
} Pixel;

void copy_image(Pixel *dst, Pixel *src, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            *(dst + i * width + j) = *(src + i * width + j);
        }
    }
}

void grayscale(Pixel *pixels, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            unsigned char avg = ((*(pixels + i * width + j)).r + (*(pixels + i * width + j)).g + (*(pixels + i * width + j)).b) / 3;
            (*(pixels + i * width + j)).r = avg;
            (*(pixels + i * width + j)).g = avg;
            (*(pixels + i * width + j)).b = avg;
        }
    }
}

int main() {
    // Load input image
    FILE *f = fopen("input.ppm", "rb");
    if (!f) {
        printf("Error: Input file does not exist.\n");
        return 1;
    }
    char magic_num[2];
    fscanf(f, "%s", magic_num);
    if (strcmp(magic_num, "P6") != 0) {
        printf("Error: Input file must be a P6 PPM image.\n");
        return 1;
    }
    int width, height, maxval;
    fscanf(f, "%d%d%d", &width, &height, &maxval);
    if (maxval != 255) {
        printf("Error: Only 8-bit color format is supported.\n");
        return 1;
    }
    Pixel *pixels = (Pixel *) malloc(sizeof(Pixel) * width * height);
    fread(pixels, sizeof(char), width * height * 3, f);
    fclose(f);
    
    // Make a backup copy of the image
    Pixel *original = (Pixel *) malloc(sizeof(Pixel) * width * height);
    copy_image(original, pixels, width, height);
    
    // Apply grayscale filter
    printf("Applying grayscale filter...\n");
    grayscale(pixels, width, height);
    
    // Save output image
    f = fopen("output.ppm", "wb");
    fprintf(f, "P6\n%d %d\n255\n", width, height);
    fwrite(pixels, sizeof(char), width * height * 3, f);
    printf("Output image saved to output.ppm.\n");
    fclose(f);
    
    // Revert to original image
    printf("Reverting to original image...\n");
    copy_image(pixels, original, width, height);
    
    // Apply inverted filter
    printf("Applying inverted filter...\n");
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            (*(pixels + i * width + j)).r = 255 - (*(pixels + i * width + j)).r;
            (*(pixels + i * width + j)).g = 255 - (*(pixels + i * width + j)).g;
            (*(pixels + i * width + j)).b = 255 - (*(pixels + i * width + j)).b;
        }
    }
    
    // Save output image
    f = fopen("output_inverted.ppm", "wb");
    fprintf(f, "P6\n%d %d\n255\n", width, height);
    fwrite(pixels, sizeof(char), width * height * 3, f);
    printf("Output image saved to output_inverted.ppm.\n");

    return 0;
}