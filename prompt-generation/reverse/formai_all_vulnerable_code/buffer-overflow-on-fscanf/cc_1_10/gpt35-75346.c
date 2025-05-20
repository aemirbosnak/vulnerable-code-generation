//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255
#define MIN_PIXEL_VALUE 0

typedef struct {
    unsigned char red, green, blue;
} Pixel;

// Function to flip the image horizontally
void flipImageHorizontally(Pixel *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            Pixel temp = image[i * width + j];
            image[i * width + j] = image[i * width + (width - j - 1)];
            image[i * width + (width - j - 1)] = temp;
        }
    }
}

// Function to change the brightness of the image
void changeBrightness(Pixel *image, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i * width + j].red += brightness;
            image[i * width + j].green += brightness;
            image[i * width + j].blue += brightness;
            if (image[i * width + j].red > MAX_PIXEL_VALUE) {
                image[i * width + j].red = MAX_PIXEL_VALUE;
            }
            if (image[i * width + j].green > MAX_PIXEL_VALUE) {
                image[i * width + j].green = MAX_PIXEL_VALUE;
            }
            if (image[i * width + j].blue > MAX_PIXEL_VALUE) {
                image[i * width + j].blue = MAX_PIXEL_VALUE;
            }
            if (image[i * width + j].red < MIN_PIXEL_VALUE) {
                image[i * width + j].red = MIN_PIXEL_VALUE;
            }
            if (image[i * width + j].green < MIN_PIXEL_VALUE) {
                image[i * width + j].green = MIN_PIXEL_VALUE;
            }
            if (image[i * width + j].blue < MIN_PIXEL_VALUE) {
                image[i * width + j].blue = MIN_PIXEL_VALUE;
            }
        }
    }
}

// Function to change the contrast of the image
void changeContrast(Pixel *image, int width, int height, float contrast) {
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i * width + j].red = (unsigned char) ((factor * (image[i * width + j].red - 128)) + 128);
            image[i * width + j].green = (unsigned char) ((factor * (image[i * width + j].green - 128)) + 128);
            image[i * width + j].blue = (unsigned char) ((factor * (image[i * width + j].blue - 128)) + 128);
            if (image[i * width + j].red > MAX_PIXEL_VALUE) {
                image[i * width + j].red = MAX_PIXEL_VALUE;
            }
            if (image[i * width + j].green > MAX_PIXEL_VALUE) {
                image[i * width + j].green = MAX_PIXEL_VALUE;
            }
            if (image[i * width + j].blue > MAX_PIXEL_VALUE) {
                image[i * width + j].blue = MAX_PIXEL_VALUE;
            }
            if (image[i * width + j].red < MIN_PIXEL_VALUE) {
                image[i * width + j].red = MIN_PIXEL_VALUE;
            }
            if (image[i * width + j].green < MIN_PIXEL_VALUE) {
                image[i * width + j].green = MIN_PIXEL_VALUE;
            }
            if (image[i * width + j].blue < MIN_PIXEL_VALUE) {
                image[i * width + j].blue = MIN_PIXEL_VALUE;
            }
        }
    }
}

int main() {
    FILE *inputFile = fopen("sample_image.ppm", "rb");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    // Reading header data
    char fileType[3];
    fscanf(inputFile, "%s\n", fileType);
    if (fileType[0] != 'P' || fileType[1] != '6') {
        printf("Invalid file type\n");
        fclose(inputFile);
        return 1;
    }
    int width, height, maxPixelValue;
    fscanf(inputFile, "%d %d\n%d\n", &width, &height, &maxPixelValue);
    if (maxPixelValue != MAX_PIXEL_VALUE) {
        printf("Invalid max pixel value\n");
        fclose(inputFile);
        return 1;
    }

    // Reading pixel data
    Pixel *image = (Pixel *) malloc(width * height * sizeof(Pixel));
    fread(image, sizeof(Pixel), width * height, inputFile);
    fclose(inputFile);

    // Flipping the image
    flipImageHorizontally(image, width, height);

    // Changing brightness of the image
    changeBrightness(image, width, height, 50);

    // Changing contrast of the image
    changeContrast(image, width, height, 100.0);

    // Writing output image
    FILE *outputFile = fopen("processed_image.ppm", "wb");
    if (outputFile == NULL) {
        printf("Error opening output file\n");
        free(image);
        return 1;
    }
    fprintf(outputFile, "P6\n%d %d\n%d\n", width, height, MAX_PIXEL_VALUE);
    fwrite(image, sizeof(Pixel), width * height, outputFile);
    fclose(outputFile);

    free(image);
    return 0;
}