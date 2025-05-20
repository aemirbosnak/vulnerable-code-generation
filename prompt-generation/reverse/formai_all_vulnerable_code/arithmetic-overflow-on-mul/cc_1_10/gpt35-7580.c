//FormAI DATASET v1.0 Category: Image Editor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_LENGTH 20

// Struct to store image information
typedef struct {
    int width;
    int height;
    char *pixels;
} Image;

// Function to allocate memory to store image pixels
void allocateImagePixels(Image *img) {
    img->pixels = (char *)malloc(sizeof(char) * img->width * img->height);
    if (img->pixels == NULL) {
        printf("Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }
}

// Function to free memory allocated to store image pixels
void freeImagePixels(Image *img) {
    free(img->pixels);
}

// Function to read PGM image file
void readPGMImage(char *fileName, Image *img) {
    FILE *fp;
    char MagicNum[2];
    int maxValue;

    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error in opening file!\n");
        exit(EXIT_FAILURE);
    }

    // read image format                        
    fscanf(fp, "%s", MagicNum);

    // check if image format is P5 or not         
    if (MagicNum[0] != 'P' || MagicNum[1] != '5') {
        printf("Image format is not PGM P5 format!\n");
        exit(EXIT_FAILURE);
    }

    // read image dimensions
    fscanf(fp, "%d %d", &img->width, &img->height);

    // read image max value
    fscanf(fp, "%d", &maxValue);

    // check if max value is 255 or not
    if (maxValue != 255) {
        printf("Image max value is not 255!\n");
        exit(EXIT_FAILURE);
    }

    // allocate memory to store image pixels
    allocateImagePixels(img);

    // read image pixels
    fread(img->pixels, sizeof(char), img->width * img->height, fp);

    fclose(fp);
}

// Function to write PGM image file
void writePGMImage(char *fileName, Image *img) {
    FILE *fp;
    int pixelIndex;

    fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("Error in opening file!\n");
        exit(EXIT_FAILURE);
    }

    // write image format, dimensions and max value
    fprintf(fp, "P5\n%d %d\n%d\n", img->width, img->height, 255);

    // write image pixels
    for (pixelIndex = 0; pixelIndex < img->width * img->height; pixelIndex++) {
        fwrite(&img->pixels[pixelIndex], sizeof(char), 1, fp);
    }

    fclose(fp);
}

// Function to apply horizontal flip to image
void horizontalFlip(Image *img) {
    int rowIndex, colIndex;
    char tempPixel;

    for (rowIndex = 0; rowIndex < img->height; rowIndex++) {
        for (colIndex = 0; colIndex < img->width / 2; colIndex++) {
            tempPixel = img->pixels[rowIndex * img->width + colIndex];
            img->pixels[rowIndex * img->width + colIndex] =
            img->pixels[rowIndex * img->width + img->width - 1 - colIndex];
            img->pixels[rowIndex * img->width + img->width - 1 - colIndex] = tempPixel;
        }
    }
}

int main() {
    char inputFileName[FILE_NAME_LENGTH];
    char outputFileName[FILE_NAME_LENGTH];
    Image img;

    // read input image file
    printf("Enter input image file name (*.pgm) : ");
    scanf("%s", inputFileName);
    readPGMImage(inputFileName, &img);

    // apply horizontal flip to image
    horizontalFlip(&img);

    // write output image file
    printf("Enter output image file name (*.pgm) : ");
    scanf("%s", outputFileName);
    writePGMImage(outputFileName, &img);

    // free memory allocated to store image pixels
    freeImagePixels(&img);

    printf("Horizontal flip applied successfully!\n");

    return 0;
}