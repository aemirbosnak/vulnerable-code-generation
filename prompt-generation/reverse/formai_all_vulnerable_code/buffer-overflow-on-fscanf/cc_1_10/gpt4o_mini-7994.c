//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Define the structure for a PPM image
typedef struct {
    int width;
    int height;
    uint8_t *data;
} Image;

// Function to read a PPM image from a file
Image *readPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return NULL;
    }

    char format[3];
    fscanf(file, "%2s", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported image format: %s\n", format);
        fclose(file);
        return NULL;
    }

    Image *img = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file); // read the newline

    img->data = (uint8_t *)malloc(img->width * img->height * 3);
    fread(img->data, 3, img->width * img->height, file);
    fclose(file);

    return img;
}

// Function to write a PPM image to a file
void writePPM(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, 3, img->width * img->height, file);
    fclose(file);
}

// Function to flip the image horizontally
void flipHorizontally(Image *img) {
    int rowSize = img->width * 3;
    uint8_t *flipped = (uint8_t *)malloc(rowSize * img->height);

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int srcIndex = (y * img->width + x) * 3;
            int destIndex = (y * img->width + (img->width - 1 - x)) * 3;
            memcpy(flipped + destIndex, img->data + srcIndex, 3);
        }
    }

    free(img->data);
    img->data = flipped;
}

// Function to change brightness of the image
void changeBrightness(Image *img, int value) {
    for (int i = 0; i < img->width * img->height * 3; i++) {
        int newValue = img->data[i] + value;
        img->data[i] = newValue < 0 ? 0 : (newValue > 255 ? 255 : newValue);
    }
}

// Function to change contrast of the image
void changeContrast(Image *img, double factor) {
    for (int i = 0; i < img->width * img->height * 3; i++) {
        int newValue = (int)((img->data[i] - 128) * factor + 128);
        img->data[i] = newValue < 0 ? 0 : (newValue > 255 ? 255 : newValue);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <input.ppm> <output.ppm> <flip|brightness|contrast> <value>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = readPPM(argv[1]);
    if (!img) {
        return EXIT_FAILURE; 
    }

    char *operation = argv[3];
    int value = atoi(argv[4]);

    if (strcmp(operation, "flip") == 0) {
        flipHorizontally(img);
    } else if (strcmp(operation, "brightness") == 0) {
        changeBrightness(img, value);
    } else if (strcmp(operation, "contrast") == 0) {
        changeContrast(img, (double)value);
    } else {
        fprintf(stderr, "Unknown operation: %s\n", operation);
        free(img->data);
        free(img);
        return EXIT_FAILURE;
    }

    writePPM(argv[2], img);
    free(img->data);
    free(img);

    return EXIT_SUCCESS;
}