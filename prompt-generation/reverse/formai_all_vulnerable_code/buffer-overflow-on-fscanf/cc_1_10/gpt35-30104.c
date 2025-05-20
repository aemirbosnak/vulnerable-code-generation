//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BRIGHTNESS 255
#define MIN_BRIGHTNESS 0
#define MAX_CONTRAST 100
#define MIN_CONTRAST 0

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

void flipImage(Pixel **image, int width, int height) {
    Pixel *temp;
    int i, j, k;
    
    temp = (Pixel *)malloc(sizeof(Pixel) * width);
    
    for (i = 0; i < height/2; i++) {
        for (j = 0; j < width; j++) {
            temp[j] = image[i][j];
            image[i][j] = image[height - 1 - i][j];
            image[height - 1 - i][j] = temp[j];
        }
    }
    
    free(temp);
}

void adjustBrightness(Pixel **image, int width, int height, int brightness) {
    int i, j;
    double brightnessFactor;
    
    brightnessFactor = ((double)brightness - 50) / 50.0;
    
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            image[i][j].red = (unsigned char)fmin(MAX_BRIGHTNESS, fmax(MIN_BRIGHTNESS, round(image[i][j].red + brightnessFactor * 50)));
            image[i][j].green = (unsigned char)fmin(MAX_BRIGHTNESS, fmax(MIN_BRIGHTNESS, round(image[i][j].green + brightnessFactor * 50)));
            image[i][j].blue = (unsigned char)fmin(MAX_BRIGHTNESS, fmax(MIN_BRIGHTNESS, round(image[i][j].blue + brightnessFactor * 50)));
        }
    }
}

void adjustContrast(Pixel **image, int width, int height, int contrast) {
    double contrastFactor, factorA, factorB, grayValue;
    int i, j;
    
    contrastFactor = ((double)contrast - 50) / 50.0;
    
    factorA = 259.0 * (contrastFactor + 1.0) / (255.0 * (1.0 - contrastFactor));
    factorB = 128.0 * (1.0 - factorA);
    
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            grayValue = 0.2989 * image[i][j].red + 0.587 * image[i][j].green + 0.114 * image[i][j].blue;
            image[i][j].red = (unsigned char)fmin(MAX_BRIGHTNESS, fmax(MIN_BRIGHTNESS, round(factorA * (image[i][j].red - 128) + 128 + factorB)));
            image[i][j].green = (unsigned char)fmin(MAX_BRIGHTNESS, fmax(MIN_BRIGHTNESS, round(factorA * (image[i][j].green - 128) + 128 + factorB)));
            image[i][j].blue = (unsigned char)fmin(MAX_BRIGHTNESS, fmax(MIN_BRIGHTNESS, round(factorA * (image[i][j].blue - 128) + 128 + factorB)));
        }
    }
}

void printImage(Pixel **image, int width, int height) {
    int i, j;
    
    printf("P6\n");
    printf("%d %d\n", width, height);
    printf("255\n");
    
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            putchar(image[i][j].red);
            putchar(image[i][j].green);
            putchar(image[i][j].blue);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *inputFile, *outputFile;
    Pixel **image;
    char magicNumber[3];
    int width, height, maxBrightness, brightness, contrast, i, j;
    
    if (argc != 6) {
        fprintf(stderr, "USAGE: %s <input_file> <output_file> <flip|brightness|contrast> <brightness/contrast_value> <image_file>\n", argv[0]);
        return -1;
    }
    
    inputFile = fopen(argv[1], "r");
    outputFile = fopen(argv[2], "w");
    
    sscanf(argv[4], "%d", &brightness);
    sscanf(argv[4], "%d", &contrast);
    
    if (inputFile == NULL) {
        fprintf(stderr, "Unable to open input file: %s\n", argv[1]);
        return -1;
    }
    
    if (outputFile == NULL) {
        fprintf(stderr, "Unable to open output file: %s\n", argv[2]);
        return -1;
    }
    
    fscanf(inputFile, "%s\n", magicNumber);
    fscanf(inputFile, "%d %d\n", &width, &height);
    fscanf(inputFile, "%d\n", &maxBrightness);
    
    image = (Pixel **)malloc(sizeof(Pixel *) * height);
    
    for (i = 0; i < height; i++) {
        image[i] = (Pixel *)malloc(sizeof(Pixel) * width);
        fread(image[i], sizeof(Pixel), width, inputFile);
    }
    
    fclose(inputFile);
    
    if (strcmp(argv[3], "flip") == 0) {
        flipImage(image, width, height);
    } else if (strcmp(argv[3], "brightness") == 0) {
        adjustBrightness(image, width, height, brightness);
    } else if (strcmp(argv[3], "contrast") == 0) {
        adjustContrast(image, width, height, contrast);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[3]);
        return -1;
    }
    
    printImage(image, width, height);
    
    for (i = 0; i < height; i++) {
        free(image[i]);
    }
    
    free(image);
    
    fclose(outputFile);
    
    return 0;
}