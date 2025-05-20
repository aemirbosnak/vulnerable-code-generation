//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255

// Structure to hold the image data
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Function to load a PGM image
Image *loadPGM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P5") != 0) {
        fclose(file);
        return NULL;
    }
    
    Image *img = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int maxVal;
    fscanf(file, "%d", &maxVal);
    fgetc(file); // Skip the newline after the max pixel value

    img->data = (unsigned char *)malloc(img->width * img->height);
    fread(img->data, sizeof(unsigned char), img->width * img->height, file);
    fclose(file);

    return img;
}

// Function to save a PGM image
void savePGM(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) return;

    fprintf(file, "P5\n%d %d\n%d\n", img->width, img->height, MAX_PIXEL_VALUE);
    fwrite(img->data, sizeof(unsigned char), img->width * img->height, file);
    fclose(file);
}

// Function to flip the image vertically
void flipImage(Image *img) {
    unsigned char *flippedData = (unsigned char *)malloc(img->width * img->height);
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            flippedData[y * img->width + x] = img->data[(img->height - 1 - y) * img->width + x];
        }
    }
    free(img->data);
    img->data = flippedData;
}

// Function to change brightness
void changeBrightness(Image *img, int adjustment) {
    for (int i = 0; i < img->width * img->height; i++) {
        int newValue = img->data[i] + adjustment;
        img->data[i] = (newValue > MAX_PIXEL_VALUE) ? MAX_PIXEL_VALUE : (newValue < 0) ? 0 : newValue;
    }
}

// Function to adjust contrast
void adjustContrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        int newValue = (int)((img->data[i] - 128) * factor + 128);
        img->data[i] = (newValue > MAX_PIXEL_VALUE) ? MAX_PIXEL_VALUE : (newValue < 0) ? 0 : newValue;
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <input.pgm> <output.pgm> <brightness> <contrast_factor>\n", argv[0]);
        return 1;
    }

    Image *img = loadPGM(argv[1]);
    if (!img) {
        printf("Error loading image.\n");
        return 1;
    }

    // Show loaded image properties
    printf("Loaded image: %d x %d\n", img->width, img->height);

    // Perform flipping
    flipImage(img);
    printf("Flipped the image vertically.\n");

    // Change brightness
    int brightnessAdjustment = atoi(argv[3]);
    changeBrightness(img, brightnessAdjustment);
    printf("Changed brightness by %d.\n", brightnessAdjustment);

    // Adjust contrast
    float contrastFactor = atof(argv[4]);
    adjustContrast(img, contrastFactor);
    printf("Adjusted contrast with factor %.2f.\n", contrastFactor);

    // Save the modified image
    savePGM(argv[2], img);
    printf("Saved the modified image as %s.\n", argv[2]);

    // Freeing allocated memory
    free(img->data);
    free(img);
    
    return 0;
}