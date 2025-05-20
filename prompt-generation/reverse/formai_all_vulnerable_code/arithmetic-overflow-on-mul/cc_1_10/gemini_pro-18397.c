//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

int main() {
    // Open the input image
    FILE *input = fopen("input.bmp", "rb");
    if (input == NULL) {
        printf("Error opening input image\n");
        return 1;
    }

    // Read the header
    unsigned char header[54];
    fread(header, 54, 1, input);

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Read the pixel data
    pixel *pixels = malloc(width * height * sizeof(pixel));
    fread(pixels, width * height * sizeof(pixel), 1, input);

    // Close the input image
    fclose(input);

    // Flip the image vertically
    for (int y = 0; y < height / 2; y++) {
        for (int x = 0; x < width; x++) {
            pixel temp = pixels[y * width + x];
            pixels[y * width + x] = pixels[(height - y - 1) * width + x];
            pixels[(height - y - 1) * width + x] = temp;
        }
    }

    // Increase the brightness
    for (int i = 0; i < width * height; i++) {
        pixels[i].r += 50;
        pixels[i].g += 50;
        pixels[i].b += 50;
    }

    // Decrease the contrast
    for (int i = 0; i < width * height; i++) {
        pixels[i].r = (pixels[i].r - 128) * 0.5 + 128;
        pixels[i].g = (pixels[i].g - 128) * 0.5 + 128;
        pixels[i].b = (pixels[i].b - 128) * 0.5 + 128;
    }

    // Open the output image
    FILE *output = fopen("output.bmp", "wb");
    if (output == NULL) {
        printf("Error opening output image\n");
        return 1;
    }

    // Write the header
    fwrite(header, 54, 1, output);

    // Write the pixel data
    fwrite(pixels, width * height * sizeof(pixel), 1, output);

    // Close the output image
    fclose(output);

    // Free the pixel data
    free(pixels);

    return 0;
}