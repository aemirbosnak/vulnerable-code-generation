//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

unsigned char clamp(int value) {
    if (value < 0) return 0;
    if (value > 255) return 255;
    return value;
}

void flip_horizontal(pixel* image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            pixel temp = image[y * width + x];
            image[y * width + x] = image[y * width + width - x - 1];
            image[y * width + width - x - 1] = temp;
        }
    }
}

void flip_vertical(pixel* image, int width, int height) {
    for (int y = 0; y < height / 2; y++) {
        for (int x = 0; x < width; x++) {
            pixel temp = image[y * width + x];
            image[y * width + x] = image[(height - y - 1) * width + x];
            image[(height - y - 1) * width + x] = temp;
        }
    }
}

void adjust_brightness(pixel* image, int width, int height, int brightness) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image[y * width + x].r = clamp(image[y * width + x].r + brightness);
            image[y * width + x].g = clamp(image[y * width + x].g + brightness);
            image[y * width + x].b = clamp(image[y * width + x].b + brightness);
        }
    }
}

void adjust_contrast(pixel* image, int width, int height, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image[y * width + x].r = clamp(factor * (image[y * width + x].r - 128) + 128);
            image[y * width + x].g = clamp(factor * (image[y * width + x].g - 128) + 128);
            image[y * width + x].b = clamp(factor * (image[y * width + x].b - 128) + 128);
        }
    }
}

int main() {
    // Load the image
    FILE* file = fopen("image.bmp", "rb");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    
    // Read the header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    // Get the image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Read the image data
    pixel* image = malloc(width * height * sizeof(pixel));
    fread(image, sizeof(pixel), width * height, file);
    fclose(file);

    // Flip the image horizontally
    flip_horizontal(image, width, height);

    // Flip the image vertically
    flip_vertical(image, width, height);

    // Adjust the brightness
    adjust_brightness(image, width, height, 50);

    // Adjust the contrast
    adjust_contrast(image, width, height, 1.5);

    // Save the image
    file = fopen("new_image.bmp", "wb");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    fwrite(header, sizeof(unsigned char), 54, file);
    fwrite(image, sizeof(pixel), width * height, file);
    fclose(file);

    // Free the image data
    free(image);

    return 0;
}