//FormAI DATASET v1.0 Category: Image Editor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for RGB pixel
typedef struct pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

// Structure for image
typedef struct image {
    int width;
    int height;
    Pixel *pixels;
} Image;

// Function to read image from file
Image *readImage(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        return NULL;
    }

    char format[3];
    int width, height, maxval;
    fscanf(file, "%s %d %d %d", format, &width, &height, &maxval);
    if (strcmp(format, "P6") != 0) {
        printf("Error: invalid file format\n");
        fclose(file);
        return NULL;
    }

    Pixel *pixels = (Pixel*) malloc(width * height * sizeof(Pixel));
    fread(pixels, sizeof(Pixel), width * height, file);

    Image *image = (Image*) malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = pixels;

    fclose(file);

    return image;
}

// Function to write image to file
void writeImage(char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    fprintf(file, "P6\n");
    fprintf(file, "%d %d\n", image->width, image->height);
    fprintf(file, "255\n");

    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);

    fclose(file);
}

// Function to flip image horizontally
void flipHorizontal(Image *image) {
    Pixel *temp = (Pixel*) malloc(sizeof(Pixel));
    int halfWidth = image->width / 2;
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < halfWidth; x++) {
            *temp = image->pixels[y * image->width + x];
            image->pixels[y * image->width + x] = image->pixels[(y + 1) * image->width - x - 1];
            image->pixels[(y + 1) * image->width - x - 1] = *temp;
        }
    }
    free(temp);
}

// Function to grayscale image
void grayscale(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        int gray = (int) (0.299 * image->pixels[i].red + 0.587 * image->pixels[i].green + 0.114 * image->pixels[i].blue);
        image->pixels[i].red = gray;
        image->pixels[i].green = gray;
        image->pixels[i].blue = gray;
    }
}

int main() {
    // Read image from file
    Image *image = readImage("input.ppm");
    if (!image) {
        return 1;
    }

    // Flip image horizontally
    flipHorizontal(image);

    // Grayscale image
    grayscale(image);

    // Write image to file
    writeImage("output.ppm", image);

    // Free memory
    free(image->pixels);
    free(image);

    // Exit program
    printf("Image edited successfully!");
    return 0;
}