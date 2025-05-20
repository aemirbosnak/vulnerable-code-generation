//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80

// Define ASCII characters for different brightness levels
const char *ASCII_CHARS = "@%#*+=-:. "; // Dark to light

typedef struct {
    unsigned char r, g, b; // RGB values
} Pixel;

typedef struct {
    int width, height;
    Pixel *data; // Dynamic array of pixels
} Image;

// Function to read a PPM image file
Image* readPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    char format[3];
    int width, height, maxColor;
    fscanf(file, "%s\n%d %d\n%d\n", format, &width, &height, &maxColor);
    if(strcmp(format, "P6") != 0 || maxColor != 255) {
        fprintf(stderr, "Invalid PPM file format.\n");
        fclose(file);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(Pixel));

    fread(img->data, sizeof(Pixel), width * height, file);
    fclose(file);
    return img;
}

// Function to convert a pixel to brightness value
int pixelToBrightness(Pixel pixel) {
    return (int)(0.21 * pixel.r + 0.72 * pixel.g + 0.07 * pixel.b);
}

// Function to convert image to ASCII art
void imageToASCII(Image *img) {
    int asciiWidth = MAX_WIDTH;
    int asciiHeight = MAX_HEIGHT;
    int stepX = img->width / asciiWidth;
    int stepY = img->height / asciiHeight;

    for (int y = 0; y < asciiHeight; y++) {
        for (int x = 0; x < asciiWidth; x++) {
            int pixelX = x * stepX;
            int pixelY = y * stepY;
            if (pixelX >= img->width || pixelY >= img->height) continue;

            Pixel pixel = img->data[pixelY * img->width + pixelX];
            int brightness = pixelToBrightness(pixel);
            int asciiIndex = (brightness * (strlen(ASCII_CHARS) - 1)) / 255;

            putchar(ASCII_CHARS[asciiIndex]);
        }
        putchar('\n');
    }
}

// Free memory allocated for the image
void freeImage(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

// Main function to control the flow
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = readPPM(argv[1]);
    if (img == NULL) {
        return EXIT_FAILURE;
    }

    imageToASCII(img);
    freeImage(img);
    return EXIT_SUCCESS;
}