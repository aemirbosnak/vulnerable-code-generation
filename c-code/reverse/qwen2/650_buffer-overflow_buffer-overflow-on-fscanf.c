#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

void flipVertically(unsigned char *image, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        unsigned char *top = &image[i * width];
        unsigned char *bottom = &image[(height - i - 1) * width];
        for (int j = 0; j < width; j++) {
            unsigned char temp = top[j];
            top[j] = bottom[j];
            bottom[j] = temp;
        }
    }
}

void modifyBrightnessContrast(unsigned char *image, int width, int height, int brightness, int contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i * width + j] = ((image[i * width + j] * contrast / 128) + brightness);
        }
    }
}

int main() {
    FILE *inputFile, *outputFile;
    char filename[256], header[32];
    int width, height, maxVal;

    inputFile = fopen("input.pgm", "r");
    fscanf(inputFile, "%s %d %d %d", header, &width, &height, &maxVal);

    unsigned char image[MAX_HEIGHT * MAX_WIDTH];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(inputFile, "%hhu", &image[i * width + j]);
        }
    }

    fclose(inputFile);

    modifyBrightnessContrast(image, width, height, 32, 128);
    flipVertically(image, width, height);

    outputFile = fopen("output.pgm", "w");
    fprintf(outputFile, "%s\n%d %d\n%d\n", header, width, height, maxVal);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(outputFile, "%hhu ", image[i * width + j]);
        }
        fprintf(outputFile, "\n");
    }

    fclose(outputFile);

    return 0;
}
