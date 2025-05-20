//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 255 // Maximum pixel value

// Function to read the PGM image file
void readPGM(char* filename, unsigned char* image, int* width, int* height)
{
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    char magic[3];
    fscanf(fp, "%s\n", magic);
    if (strcmp(magic, "P5") != 0) {
        printf("Invalid PGM file format!\n");
        exit(1);
    }

    fscanf(fp, "%d %d\n", width, height);
    int maxval;
    fscanf(fp, "%d\n", &maxval);
    if (maxval != MAX) {
        printf("Invalid PGM file format (maximum pixel value should be %d)!\n", MAX);
        exit(1);
    }

    fread(image, *width, *height, fp);
    fclose(fp);
}

// Function to write the PGM image file
void writePGM(char* filename, unsigned char* image, int width, int height)
{
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(fp, "P5\n");
    fprintf(fp, "%d %d\n", width, height);
    fprintf(fp, "%d\n", MAX);
    fwrite(image, width, height, fp);
    fclose(fp);
}

// Function to flip the image horizontally
void flipHorizontal(unsigned char* image, int width, int height)
{
    unsigned char temp;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            temp = image[i * width + j];
            image[i * width + j] = image[i * width + (width - 1 - j)];
            image[i * width + (width - 1 - j)] = temp;
        }
    }
}

// Function to change the brightness of the image
void changeBrightness(unsigned char* image, int width, int height, int brightness)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int val = image[i * width + j] + brightness;
            if (val < 0) val = 0;
            else if (val > MAX) val = MAX;
            image[i * width + j] = (unsigned char)val;
        }
    }
}

// Function to change the contrast of the image
void changeContrast(unsigned char* image, int width, int height, float contrast)
{
    float factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int val = (int)(factor * (image[i * width + j] - 128.0f) + 128.0f);
            if (val < 0) val = 0;
            else if (val > MAX) val = MAX;
            image[i * width + j] = (unsigned char)val;
        }
    }
}

int main()
{
    unsigned char* image;
    int width, height;

    // Read the input image
    readPGM("input.pgm", image, &width, &height);

    // Flip the image horizontally
    flipHorizontal(image, width, height);

    // Change the brightness of the image
    changeBrightness(image, width, height, 50);

    // Change the contrast of the image
    changeContrast(image, width, height, 50.0f);

    // Write the output image
    writePGM("output.pgm", image, width, height);

    // Free the memory allocated for the image
    free(image);

    return 0;
}