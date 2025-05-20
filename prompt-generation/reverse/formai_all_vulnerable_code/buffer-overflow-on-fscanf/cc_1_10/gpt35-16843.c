//FormAI DATASET v1.0 Category: Image Editor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PIXEL_VALUE 255

/* Struct to hold pixel data */
typedef struct {
    int red;
    int green;
    int blue;
} Pixel;

/* Struct to hold image data */
typedef struct {
    int width;
    int height;
    Pixel **pixels; // 2D array of pixels
} Image;

/* Function to allocate memory for an image */
Image *createImage(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(Pixel*) * height);
    for(int i = 0; i < height; i++) {
        image->pixels[i] = malloc(sizeof(Pixel) * width);
    }
    return image;
}

/* Function to read an image from a file */
Image *readImage(char *filename) {
    FILE *file = fopen(filename, "rb");
    if(!file) {
        printf("Error opening file\n");
        exit(1);
    }
    // Read magic number
    char magic[2];
    fread(magic, sizeof(char), 2, file);
    // Read image dimensions
    int width, height;
    fscanf(file, "%d %d", &width, &height);
    Image *image = createImage(width, height);
    // Read maximum pixel value
    int maxPixelValue;
    fscanf(file, "%d", &maxPixelValue);
    // Read pixel data
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            Pixel pixel;
            fread(&pixel, sizeof(Pixel), 1, file);
            image->pixels[i][j] = pixel;
        }
    }
    fclose(file);
    return image;
}

/* Function to write an image to a file */
void writeImage(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if(!file) {
        printf("Error opening file\n");
        exit(1);
    }
    // Write magic number
    char magic[2] = {'P', '6'};
    fwrite(magic, sizeof(char), 2, file);
    // Write image dimensions
    fprintf(file, "\n%d %d\n", image->width, image->height);
    // Write maximum pixel value
    fprintf(file, "%d\n", MAX_PIXEL_VALUE);
    // Write pixel data
    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            fwrite(&(image->pixels[i][j]), sizeof(Pixel), 1, file);
        }
    }
    fclose(file);
}

/* Function to invert colors of an image */
void invert(Image *image) {
    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            Pixel pixel = image->pixels[i][j];
            pixel.red = MAX_PIXEL_VALUE - pixel.red;
            pixel.green = MAX_PIXEL_VALUE - pixel.green;
            pixel.blue = MAX_PIXEL_VALUE - pixel.blue;
            image->pixels[i][j] = pixel;
        }
    }
}

/* Function to apply grayscale filter to an image */
void grayscale(Image *image) {
    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            Pixel pixel = image->pixels[i][j];
            int grayValue = (pixel.red + pixel.green + pixel.blue) / 3;
            pixel.red = grayValue;
            pixel.green = grayValue;
            pixel.blue = grayValue;
            image->pixels[i][j] = pixel;
        }
    }
}

/* Function to apply sepia filter to an image */
void sepia(Image *image) {
    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            Pixel pixel = image->pixels[i][j];
            int sepiaRed = round(pixel.red * 0.393 + pixel.green * 0.769 + pixel.blue * 0.189);
            int sepiaGreen = round(pixel.red * 0.349 + pixel.green * 0.686 + pixel.blue * 0.168);
            int sepiaBlue = round(pixel.red * 0.272 + pixel.green * 0.534 + pixel.blue * 0.131);
            pixel.red = sepiaRed > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : sepiaRed;
            pixel.green = sepiaGreen > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : sepiaGreen;
            pixel.blue = sepiaBlue > MAX_PIXEL_VALUE ? MAX_PIXEL_VALUE : sepiaBlue;
            image->pixels[i][j] = pixel;
        }
    }
}

/* Function to apply blur filter to an image */
void blur(Image *image) {
    for(int i = 1; i < image->height - 1; i++) {
        for(int j = 1; j < image->width - 1; j++) {
            int redSum = 0;
            int greenSum = 0;
            int blueSum = 0;
            for(int ii = -1; ii <= 1; ii++) {
                for(int jj = -1; jj <= 1; jj++) {
                    Pixel pixel = image->pixels[i + ii][j + jj];
                    redSum += pixel.red;
                    greenSum += pixel.green;
                    blueSum += pixel.blue;
                }
            }
            Pixel pixel = image->pixels[i][j];
            pixel.red = round(redSum / 9.0);
            pixel.green = round(greenSum / 9.0);
            pixel.blue = round(blueSum / 9.0);
            image->pixels[i][j] = pixel;
        }
    }
}

int main() {
    Image *image = readImage("sample.ppm");
    // Invert colors
    invert(image);
    writeImage(image, "inverted.ppm");
    // Grayscale
    grayscale(image);
    writeImage(image, "grayscale.ppm");
    // Sepia
    sepia(image);
    writeImage(image, "sepia.ppm");
    // Blur
    blur(image);
    writeImage(image, "blurred.ppm");
    return 0;
}