//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Claude Shannon
// Basic Image Processing in C: A Claude Shannon Adventure

#include <stdio.h>
#include <stdlib.h>

// Pixel struct (Red, Green, Blue)
typedef struct Pixel {
    unsigned char r, g, b;
} Pixel;

// Image struct (Width, Height, Pixel Array)
typedef struct Image {
    int width, height;
    Pixel *pixels;
} Image;

// Function to load an image from file
Image *load_image(char *filename) {
    // Open file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Read header
    int width, height;
    fscanf(fp, "P6\n%d %d\n255\n", &width, &height);

    // Allocate memory for image
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(Pixel));

    // Read pixel data
    fread(image->pixels, sizeof(Pixel), width * height, fp);

    // Close file
    fclose(fp);

    return image;
}

// Function to save an image to file
void save_image(Image *image, char *filename) {
    // Open file
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Write header
    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);

    // Write pixel data
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, fp);

    // Close file
    fclose(fp);
}

// Function to flip an image horizontally
void flip_horizontal(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            // Swap pixels
            Pixel temp = image->pixels[y * image->width + x];
            image->pixels[y * image->width + x] = image->pixels[y * image->width + image->width - x - 1];
            image->pixels[y * image->width + image->width - x - 1] = temp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(Image *image, int delta) {
    for (int i = 0; i < image->width * image->height; i++) {
        // Clamp brightness to 0-255
        image->pixels[i].r = image->pixels[i].r + delta;
        if (image->pixels[i].r > 255) image->pixels[i].r = 255;
        if (image->pixels[i].r < 0) image->pixels[i].r = 0;

        image->pixels[i].g = image->pixels[i].g + delta;
        if (image->pixels[i].g > 255) image->pixels[i].g = 255;
        if (image->pixels[i].g < 0) image->pixels[i].g = 0;

        image->pixels[i].b = image->pixels[i].b + delta;
        if (image->pixels[i].b > 255) image->pixels[i].b = 255;
        if (image->pixels[i].b < 0) image->pixels[i].b = 0;
    }
}

// Function to change the contrast of an image
void change_contrast(Image *image, float factor) {
    for (int i = 0; i < image->width * image->height; i++) {
        // Adjust contrast
        image->pixels[i].r = (image->pixels[i].r - 128) * factor + 128;
        image->pixels[i].g = (image->pixels[i].g - 128) * factor + 128;
        image->pixels[i].b = (image->pixels[i].b - 128) * factor + 128;

        // Clamp to 0-255
        if (image->pixels[i].r > 255) image->pixels[i].r = 255;
        if (image->pixels[i].r < 0) image->pixels[i].r = 0;

        if (image->pixels[i].g > 255) image->pixels[i].g = 255;
        if (image->pixels[i].g < 0) image->pixels[i].g = 0;

        if (image->pixels[i].b > 255) image->pixels[i].b = 255;
        if (image->pixels[i].b < 0) image->pixels[i].b = 0;
    }
}

// Function to free the memory allocated for an image
void free_image(Image *image) {
    free(image->pixels);
    free(image);
}

// Main function
int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <input> <output> <operation> <argument 1> <argument 2>\n", argv[0]);
        return 1;
    }

    // Load image
    Image *image = load_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    // Perform operation
    if (strcmp(argv[3], "flip_horizontal") == 0) {
        flip_horizontal(image);
    } else if (strcmp(argv[3], "change_brightness") == 0) {
        change_brightness(image, atoi(argv[4]));
    } else if (strcmp(argv[3], "change_contrast") == 0) {
        change_contrast(image, atof(argv[4]));
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[3]);
        free_image(image);
        return 1;
    }

    // Save image
    save_image(image, argv[2]);

    // Free memory
    free_image(image);

    return 0;
}