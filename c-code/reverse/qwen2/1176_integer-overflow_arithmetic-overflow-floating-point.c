#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 255

void adjustBrightnessContrast(char *inputFile, char *outputFile, float brightnessFactor, float contrastFactor) {
    FILE *in = fopen(inputFile, "rb");
    if (!in) {
        perror("Error opening input file");
        return;
    }

    char header[18];
    fread(header, 1, 18, in);
    int width = ((header[18] << 8) | header[19]);
    int height = ((header[20] << 8) | header[21]);

    unsigned char *image = (unsigned char *)malloc(width * height * sizeof(unsigned char));
    if (!image) {
        fclose(in);
        perror("Memory allocation failed");
        return;
    }

    fread(image, 1, width * height, in);
    fclose(in);

    for (int i = 0; i < width * height; i++) {
        int pixel = image[i];
        int adjustedPixel = (int)((pixel - 128) * contrastFactor + 128 + brightnessFactor * 255);
        if (adjustedPixel > MAX_VALUE) {
            image[i] = MAX_VALUE;
        } else if (adjustedPixel < 0) {
            image[i] = 0;
        } else {
            image[i] = (unsigned char)adjustedPixel;
        }
    }

    FILE *out = fopen(outputFile, "wb");
    if (!out) {
        free(image);
        perror("Error opening output file");
        return;
    }

    fwrite(header, 1, 18, out);
    fwrite(image, 1, width * height, out);
    fclose(out);
    free(image);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input.pgm> <output.pgm> <brightness_factor> <contrast_factor>\n", argv[0]);
        return 1;
    }

    char *inputFile = argv[1];
    char *outputFile = argv[2];
    float brightnessFactor = atof(argv[3]);
    float contrastFactor = atof(argv[4]);

    adjustBrightnessContrast(inputFile, outputFile, brightnessFactor, contrastFactor);

    return 0;
}
