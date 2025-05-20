//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXELS 1000000
#define MAX_BRIGHTNESS 255
#define MIN_BRIGHTNESS 0

// Reverse the order of the pixels in the image horizontally
void flipImageHorizontally(unsigned char* image, int width, int height) {
    int i, j;
    unsigned char temp;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            temp = image[i * width + j];
            image[i * width + j] = image[i * width + (width - j - 1)];
            image[i * width + (width - j - 1)] = temp;
        }
    }
}

// Adjust the brightness of the image by a certain amount
void adjustBrightness(unsigned char* image, int width, int height, int brightness) {
    int i, j;
    int pixel;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            pixel = image[i * width + j] + brightness;
            if (pixel > MAX_BRIGHTNESS) {
                image[i * width + j] = MAX_BRIGHTNESS;
            } else if (pixel < MIN_BRIGHTNESS) {
                image[i * width + j] = MIN_BRIGHTNESS;
            } else {
                image[i * width + j] = (unsigned char) pixel;
            }
        }
    }
}

// Adjust the contrast of the image by a certain amount
void adjustContrast(unsigned char* image, int width, int height, float contrast) {
    int i, j;
    int pixel;
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            pixel = (int) (factor * (image[i * width + j] - 128) + 128);
            if (pixel > MAX_BRIGHTNESS) {
                image[i * width + j] = MAX_BRIGHTNESS;
            } else if (pixel < MIN_BRIGHTNESS) {
                image[i * width + j] = MIN_BRIGHTNESS;
            } else {
                image[i * width + j] = (unsigned char) pixel;
            }
        }
    }
}

int main(int argc, char** argv) {
    unsigned char* image;
    FILE* fp;
    char* filename;
    int width, height, maxVal;
    int brightness;
    float contrast;

    if (argc < 2) {
        printf("Usage: %s [filename.pgm]\n", argv[0]);
        return -1;
    }

    filename = argv[1];

    // Open the image file
    fp = fopen(filename, "rb");
    if (!fp) {
        printf("Could not open file: %s\n", filename);
        return -1;
    }

    // Read the header of the image file
    char magicNumber[3];
    fscanf(fp, "%2s", magicNumber);
    if (strcmp(magicNumber, "P5") != 0) {
        printf("Error: file is not a PGM file.\n");
        fclose(fp);
        return -1;
    }
    fscanf(fp, "%d %d %d\n", &width, &height, &maxVal);
    if (maxVal > MAX_BRIGHTNESS) {
        printf("Error: file has an invalid maximum value.\n");
        fclose(fp);
        return -1;
    }

    image = (unsigned char*) malloc(sizeof(unsigned char) * width * height);

    // Read the image data from the file
    fread(image, width, height, fp);

    // Close the file
    fclose(fp);

    // Flip the image horizontally
    flipImageHorizontally(image, width, height);

    // Increase the brightness of the image by 50
    brightness = 50;
    adjustBrightness(image, width, height, brightness);

    // Decrease the contrast of the image by 30%
    contrast = 0.7;
    adjustContrast(image, width, height, contrast);

    // Write the modified image data to a new file
    char* newFilename = (char*) malloc(sizeof(char) * strlen(filename) + 10);
    strcpy(newFilename, "modified_");
    strcat(newFilename, filename);
    fp = fopen(newFilename, "wb");
    fprintf(fp, "P5\n%d %d\n%d\n", width, height, maxVal);
    fwrite(image, width, height, fp);
    fclose(fp);
    free(newFilename);

    // Free the allocated memory
    free(image);

    return 0;
}