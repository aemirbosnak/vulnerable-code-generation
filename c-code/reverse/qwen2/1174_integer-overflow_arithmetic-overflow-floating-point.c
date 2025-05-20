#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255

void adjustBrightnessContrast(char* inputFileName, char* outputFileName, int brightness, int contrast) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Error opening input file");
        return;
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return;
    }

    unsigned char header[1024];
    fread(header, 1, sizeof(header), inputFile);

    fwrite(header, 1, sizeof(header), outputFile);

    int width, height, maxVal;
    sscanf((char*)header + 3, "%d %d\n%d", &width, &height, &maxVal);

    unsigned char* pixels = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    if (!pixels) {
        perror("Memory allocation failed");
        fclose(inputFile);
        fclose(outputFile);
        return;
    }

    fread(pixels, 1, width * height, inputFile);

    for (int i = 0; i < width * height; i++) {
        int adjustedValue = ((int)pixels[i] * contrast / 128) + brightness;
        if (adjustedValue > MAX_PIXEL_VALUE) {
            adjustedValue = MAX_PIXEL_VALUE;
        } else if (adjustedValue < 0) {
            adjustedValue = 0;
        }
        pixels[i] = (unsigned char)adjustedValue;
    }

    fwrite(pixels, 1, width * height, outputFile);

    free(pixels);
    fclose(inputFile);
    fclose(outputFile);
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input.pgm> <output.pgm> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    adjustBrightnessContrast(argv[1], argv[2], atoi(argv[3]), atoi(argv[4]));

    return 0;
}
