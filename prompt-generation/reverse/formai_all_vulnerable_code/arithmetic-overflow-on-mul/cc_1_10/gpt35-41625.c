//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL 255

// function prototypes
void flipImage(unsigned char *imageData, int imageWidth, int imageHeight);
void changeBrightness(unsigned char *imageData, int imageWidth, int imageHeight, int brightness);
void changeContrast(unsigned char *imageData, int imageWidth, int imageHeight, float contrast);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Please provide a valid filename as argument.\n");
        return 1;
    }

    // read image file
    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error reading file.\n");
        return 1;
    }

    // read header
    char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    // read image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // read image data
    int imageSize = width * height * 3;
    unsigned char *imageData = (unsigned char*) malloc(imageSize * sizeof(unsigned char));
    fread(imageData, sizeof(unsigned char), imageSize, file);
    fclose(file);

    // perform image operations
    flipImage(imageData, width, height);
    changeBrightness(imageData, width, height, 50);
    changeContrast(imageData, width, height, 1.5);

    // write new image data to file
    char newFilename[50];
    strcpy(newFilename, "edited_");
    strcat(newFilename, argv[1]);
    FILE *newFile = fopen(newFilename, "wb");
    fwrite(header, sizeof(unsigned char), 54, newFile);
    fwrite(imageData, sizeof(unsigned char), imageSize, newFile);
    fclose(newFile);

    // free memory
    free(imageData);

    return 0;
}

// function to flip image horizontally
void flipImage(unsigned char *imageData, int imageWidth, int imageHeight) {
    int rowSize = imageWidth * 3;
    for (int y = 0; y < imageHeight; y++) {
        for (int x = 0; x < rowSize / 2; x += 3) {
            int leftIndex = y * rowSize + x;
            int rightIndex = leftIndex + rowSize - x - 6;
            for (int c = 0; c < 3; c++) {
                unsigned char temp = imageData[leftIndex + c];
                imageData[leftIndex + c] = imageData[rightIndex + c];
                imageData[rightIndex + c] = temp;
            }
        }
    }
}

// function to change brightness of image
void changeBrightness(unsigned char *imageData, int imageWidth, int imageHeight, int brightness) {
    for (int i = 0; i < imageWidth * imageHeight * 3; i++) {
        int value = imageData[i] + brightness;
        imageData[i] = value > MAX_PIXEL ? MAX_PIXEL : (unsigned char) value;
    }
}

// function to change contrast of image
void changeContrast(unsigned char *imageData, int imageWidth, int imageHeight, float contrast) {
    // compute transformation function
    unsigned char transformationTable[MAX_PIXEL + 1];
    for (int i = 0; i <= MAX_PIXEL; i++) {
        float newIntensity = (i - MAX_PIXEL/2.0) * contrast + MAX_PIXEL/2.0;
        if (newIntensity > MAX_PIXEL) {
            newIntensity = MAX_PIXEL;
        } else if (newIntensity < 0) {
            newIntensity = 0;
        }
        transformationTable[i] = (unsigned char) newIntensity;
    }

    // apply transformation function to image data
    for (int i = 0; i < imageWidth * imageHeight * 3; i++) {
        imageData[i] = transformationTable[imageData[i]];
    }
}