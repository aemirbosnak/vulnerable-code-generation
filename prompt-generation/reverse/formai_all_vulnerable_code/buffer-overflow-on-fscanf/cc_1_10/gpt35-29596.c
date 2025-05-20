//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

/**
 * This function flips the image vertically
 *
 * @param image The image to flip
 * @param width The width of the image
 * @param height The height of the image
 */
void flip_vertical(Pixel* image, int width, int height) {
    Pixel* buffer = malloc(width * sizeof(Pixel));
    int y;
    for (y = 0; y < height/2; y++) {
        int y2 = height - y - 1;
        int x;
        for (x = 0; x < width; x++) {
            buffer[x] = image[y*width + x];
            image[y*width + x] = image[y2*width + x];
            image[y2*width + x] = buffer[x];
        }
    }
    free(buffer);
}

/**
 * This function adjusts the brightness and contrast of the image
 *
 * @param image The image to adjust
 * @param width The width of the image
 * @param height The height of the image
 * @param brightness The amount to change the brightness by
 * @param contrast The amount to change the contrast by
 */
void adjust_brightness_contrast(Pixel* image, int width, int height, int brightness, float contrast) {
    int i;
    for (i = 0; i < width*height; i++) {
        image[i].r = (unsigned char)((float)(image[i].r + brightness - 128)*contrast + 128);
        image[i].g = (unsigned char)((float)(image[i].g + brightness - 128)*contrast + 128);
        image[i].b = (unsigned char)((float)(image[i].b + brightness - 128)*contrast + 128);
    }
}

int main() {
    FILE* infile = fopen("input.ppm", "rb");
    if (!infile) {
        printf("Error: could not open input file.\n");
        return 1;
    }
    char magic[3];
    int width, height, maxval;
    fscanf(infile, "%2s\n%d %d\n%d\n", magic, &width, &height, &maxval);
    if (magic[0] != 'P' || magic[1] != '6') {
        printf("Error: input file is not a PPM file.\n");
        fclose(infile);
        return 2;
    }
    if (maxval != 255) {
        printf("Error: input file must have a maximum value of 255.\n");
        fclose(infile);
        return 3;
    }
    Pixel* image = malloc(width * height * sizeof(Pixel));
    if (!image) {
        printf("Error: could not allocate memory for image.\n");
        fclose(infile);
        return 4;
    }
    int i;
    for (i = 0; i < width*height; i++) {
        image[i].r = fgetc(infile);
        image[i].g = fgetc(infile);
        image[i].b = fgetc(infile);
    }
    fclose(infile);
    flip_vertical(image, width, height);
    adjust_brightness_contrast(image, width, height, 20, 1.2);
    FILE* outfile = fopen("output.ppm", "wb");
    if (!outfile) {
        printf("Error: could not open output file.\n");
        free(image);
        return 5;
    }
    fprintf(outfile, "P6\n%d %d\n%d\n", width, height, maxval);
    for (i = 0; i < width*height; i++) {
        fputc(image[i].r, outfile);
        fputc(image[i].g, outfile);
        fputc(image[i].b, outfile);
    }
    fclose(outfile);
    free(image);
    return 0;
}