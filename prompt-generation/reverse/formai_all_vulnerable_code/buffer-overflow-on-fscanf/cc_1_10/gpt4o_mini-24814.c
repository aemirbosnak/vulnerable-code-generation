//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIM 1024
#define MAX_COLOR 255

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel pixels[MAX_DIM][MAX_DIM];
} Image;

// Function prototypes
Image* loadImage(const char* filename);
void saveImage(const char* filename, Image* img);
void flipImageHorizontally(Image* img);
void adjustBrightness(Image* img, int adjustment);
void adjustContrast(Image* img, float factor);
void freeImage(Image* img);
void printImageData(Image* img);

// Function to load an image from a PPM file
Image* loadImage(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Cannot open file %s\n", filename);
        return NULL;
    }

    Image* img = (Image*)malloc(sizeof(Image));
    if (!img) {
        fclose(file);
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported file format: %s\n", format);
        fclose(file);
        free(img);
        return NULL;
    }

    fscanf(file, "%d %d", &img->width, &img->height);
    int maxColorValue;
    fscanf(file, "%d", &maxColorValue);
    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

// Function to save an image to a PPM file
void saveImage(const char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Cannot open file %s\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n%d\n", img->width, img->height, MAX_COLOR);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

// Function to flip the image horizontally
void flipImageHorizontally(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            Pixel temp = img->pixels[y][x];
            img->pixels[y][x] = img->pixels[y][img->width - 1 - x];
            img->pixels[y][img->width - 1 - x] = temp;
        }
    }
}

// Function to adjust the brightness of the image
void adjustBrightness(Image* img, int adjustment) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            img->pixels[y][x].r = (unsigned char) fmin(fmax(img->pixels[y][x].r + adjustment, 0), MAX_COLOR);
            img->pixels[y][x].g = (unsigned char) fmin(fmax(img->pixels[y][x].g + adjustment, 0), MAX_COLOR);
            img->pixels[y][x].b = (unsigned char) fmin(fmax(img->pixels[y][x].b + adjustment, 0), MAX_COLOR);
        }
    }
}

// Function to adjust the contrast of the image
void adjustContrast(Image* img, float factor) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            img->pixels[y][x].r = (unsigned char) fmin(fmax(((img->pixels[y][x].r - 128) * factor) + 128, 0), MAX_COLOR);
            img->pixels[y][x].g = (unsigned char) fmin(fmax(((img->pixels[y][x].g - 128) * factor) + 128, 0), MAX_COLOR);
            img->pixels[y][x].b = (unsigned char) fmin(fmax(((img->pixels[y][x].b - 128) * factor) + 128, 0), MAX_COLOR);
        }
    }
}

// Function to free the image memory
void freeImage(Image* img) {
    free(img);
}

// Function to print image data (for debugging)
void printImageData(Image* img) {
    printf("Image Width: %d, Height: %d\n", img->width, img->height);
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            printf("(%d, %d, %d) ", img->pixels[y][x].r, img->pixels[y][x].g, img->pixels[y][x].b);
        }
        printf("\n");
    }
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <brightness adjustment> <contrast factor>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image* img = loadImage(argv[1]);
    if (!img) return EXIT_FAILURE;

    int brightnessAdjustment = atoi(argv[3]);
    float contrastFactor = atof(argv[4]);

    printf("Original Image:\n");
    printImageData(img);

    adjustBrightness(img, brightnessAdjustment);
    adjustContrast(img, contrastFactor);
    flipImageHorizontally(img);

    printf("Processed Image:\n");
    printImageData(img);

    saveImage(argv[2], img);
    freeImage(img);

    return EXIT_SUCCESS;
}