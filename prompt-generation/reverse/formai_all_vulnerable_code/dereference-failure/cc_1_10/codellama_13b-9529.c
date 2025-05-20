//Code Llama-13B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Cyberpunk
// Simple Image Processing in C

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Image structure
typedef struct {
    int width;
    int height;
    int** pixels;
} Image;

// Flip image horizontally
void flip_horizontal(Image* image) {
    int width = image->width;
    int height = image->height;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            int temp = image->pixels[y][x];
            image->pixels[y][x] = image->pixels[y][width - x - 1];
            image->pixels[y][width - x - 1] = temp;
        }
    }
}

// Change brightness and contrast
void change_brightness_contrast(Image* image, int brightness, int contrast) {
    int width = image->width;
    int height = image->height;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel = image->pixels[y][x];
            pixel = (pixel + brightness) * contrast / 255;
            pixel = pixel < 0 ? 0 : pixel > 255 ? 255 : pixel;
            image->pixels[y][x] = pixel;
        }
    }
}

int main() {
    // Create an image
    Image* image = malloc(sizeof(Image));
    image->width = 512;
    image->height = 512;
    image->pixels = malloc(image->height * sizeof(int*));
    for (int y = 0; y < image->height; y++) {
        image->pixels[y] = malloc(image->width * sizeof(int));
        for (int x = 0; x < image->width; x++) {
            image->pixels[y][x] = rand() % 256;
        }
    }

    // Flip the image horizontally
    flip_horizontal(image);

    // Change brightness and contrast
    change_brightness_contrast(image, 50, 200);

    // Save the image
    FILE* fp = fopen("image.ppm", "wb");
    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            fprintf(fp, "%c%c%c", image->pixels[y][x], image->pixels[y][x], image->pixels[y][x]);
        }
    }
    fclose(fp);

    // Free memory
    for (int y = 0; y < image->height; y++) {
        free(image->pixels[y]);
    }
    free(image->pixels);
    free(image);

    return 0;
}