//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uint8;

// Structure to hold image information
typedef struct {
    int width;
    int height;
    uint8 *data; // Pixel data
} Image;

// Function to load a PPM image
Image* loadPPM(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Cannot open file: %s\n", filename);
        return NULL;
    }

    char header[3];
    fscanf(file, "%s", header);
    if (strcmp(header, "P6") != 0) {
        printf("Unsupported file format\n");
        fclose(file);
        return NULL;
    }

    int width, height, maxval;
    fscanf(file, "%d %d %d", &width, &height, &maxval);
    fgetc(file); // Consume the newline character

    Image* img = (Image*)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = (uint8*)malloc(width * height * 3);
    fread(img->data, 3, width * height, file);
    fclose(file);
    return img;
}

// Function to save a PPM image
void savePPM(const char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Cannot save file: %s\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, 3, img->width * img->height, file);
    fclose(file);
}

// Function to flip an image horizontally
void flipImageHorizontal(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            for (int color = 0; color < 3; color++) { // RGB
                uint8 temp = img->data[(y * img->width + x) * 3 + color];
                img->data[(y * img->width + x) * 3 + color] = img->data[(y * img->width + (img->width - 1 - x)) * 3 + color];
                img->data[(y * img->width + (img->width - 1 - x)) * 3 + color] = temp;
            }
        }
    }
}

// Function to adjust brightness
void adjustBrightness(Image* img, int value) {
    for (int i = 0; i < img->width * img->height * 3; i++) {
        int newValue = img->data[i] + value;
        img->data[i] = newValue < 0 ? 0 : (newValue > 255 ? 255 : newValue);
    }
}

// Function to adjust contrast
void adjustContrast(Image* img, float factor) {
    for (int i = 0; i < img->width * img->height * 3; i++) {
        int newValue = (int)((img->data[i] - 128) * factor + 128);
        img->data[i] = newValue < 0 ? 0 : (newValue > 255 ? 255 : newValue);
    }
}

// Main function to test image processing
int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input.ppm> <output.ppm> <brightness adjustment> <contrast factor>\n", argv[0]);
        return 1;
    }

    Image* img = loadPPM(argv[1]);
    if (!img) return 1;

    printf("Loaded image: %dx%d\n", img->width, img->height);

    // Flip the image horizontally
    flipImageHorizontal(img);
    printf("Image flipped horizontally.\n");

    // Adjust brightness
    int brightnessAdjustment = atoi(argv[3]);
    adjustBrightness(img, brightnessAdjustment);
    printf("Brightness adjusted by %d.\n", brightnessAdjustment);

    // Adjust contrast
    float contrastFactor = atof(argv[4]);
    adjustContrast(img, contrastFactor);
    printf("Contrast adjusted with factor %.2f.\n", contrastFactor);

    // Save the processed image
    savePPM(argv[2], img);
    printf("Processed image saved to %s\n", argv[2]);

    // Cleanup
    free(img->data);
    free(img);
    return 0;
}