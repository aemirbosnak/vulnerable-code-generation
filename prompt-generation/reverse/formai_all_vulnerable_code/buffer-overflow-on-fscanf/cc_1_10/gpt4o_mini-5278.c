//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

// Function to read a PPM image
Image *readPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    char format[3];
    fscanf(file, "%s\n", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported image format\n");
        fclose(file);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    fscanf(file, "%d %d\n255\n", &img->width, &img->height);
    img->data = malloc(img->width * img->height * sizeof(Pixel));

    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

// Function to write a PPM image
void writePPM(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

// Function to flip the image
void flipImage(Image *img) {
    int rowSize = img->width * sizeof(Pixel);
    Pixel *tempRow = malloc(rowSize);
    for (int y = 0; y < img->height / 2; y++) {
        Pixel *topRow = img->data + y * img->width;
        Pixel *bottomRow = img->data + (img->height - y - 1) * img->width;
        memcpy(tempRow, topRow, rowSize);
        memcpy(topRow, bottomRow, rowSize);
        memcpy(bottomRow, tempRow, rowSize);
    }
    free(tempRow);
}

// Function to adjust brightness
void adjustBrightness(Image *img, int value) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (img->data[i].r + value > 255) ? 255 : (img->data[i].r + value < 0) ? 0 : (img->data[i].r + value);
        img->data[i].g = (img->data[i].g + value > 255) ? 255 : (img->data[i].g + value < 0) ? 0 : (img->data[i].g + value);
        img->data[i].b = (img->data[i].b + value > 255) ? 255 : (img->data[i].b + value < 0) ? 0 : (img->data[i].b + value);
    }
}

// Function to adjust contrast
void adjustContrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (int) (factor * (img->data[i].r - 128) + 128);
        img->data[i].g = (int) (factor * (img->data[i].g - 128) + 128);
        img->data[i].b = (int) (factor * (img->data[i].b - 128) + 128);

        // Clamping to the [0, 255] range
        img->data[i].r = (img->data[i].r > 255) ? 255 : (img->data[i].r < 0) ? 0 : img->data[i].r;
        img->data[i].g = (img->data[i].g > 255) ? 255 : (img->data[i].g < 0) ? 0 : img->data[i].g;
        img->data[i].b = (img->data[i].b > 255) ? 255 : (img->data[i].b < 0) ? 0 : img->data[i].b;
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <brightness> <contrast>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = readPPM(argv[1]);
    if (!img) {
        return EXIT_FAILURE;
    }

    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);

    flipImage(img);
    adjustBrightness(img, brightness);
    adjustContrast(img, contrast);

    writePPM(argv[2], img);

    free(img->data);
    free(img);
    return EXIT_SUCCESS;
}