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

    FILE *out = fopen(outputFile, "wb");
    if (!out) {
        perror("Error opening output file");
        fclose(in);
        return;
    }

    unsigned char header[3];
    fread(header, 1, 3, in);
    fwrite(header, 1, 3, out);

    int width, height, maxVal;
    fscanf(in, "%d %d", &width, &height);
    fprintf(out, "%d %d\n", width, height);

    fscanf(in, "%d", &maxVal);
    fprintf(out, "%d\n", maxVal);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            unsigned char pixel;
            fread(&pixel, 1, 1, in);

            int adjustedPixel = (int)((brightnessFactor + contrastFactor / 255.0) * pixel - contrastFactor / 2);
            if (adjustedPixel > MAX_VALUE) {
                adjustedPixel = MAX_VALUE;
            } else if (adjustedPixel < 0) {
                adjustedPixel = 0;
            }

            fwrite((unsigned char*)&adjustedPixel, 1, 1, out);
        }
    }

    fclose(in);
    fclose(out);
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        printf("Usage: %s <input.pgm> <output.pgm> <brightness_factor> <contrast_factor>\n", argv[0]);
        return 1;
    }

    char *inputFile = argv[1];
    char *outputFile = argv[2];
    float brightnessFactor = atof(argv[3]);
    float contrastFactor = atof(argv[4]);

    adjustBrightnessContrast(inputFile, outputFile, brightnessFactor, contrastFactor);

    return 0;
}
