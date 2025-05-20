//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store RGB pixel data
typedef struct {
    unsigned char r, g, b;
} Pixel;

// Function to read a PPM image
Pixel **readPPM(const char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    char header[3];
    fscanf(file, "%s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported PPM format. Use binary P6 format.\n");
        fclose(file);
        return NULL;
    }

    fscanf(file, "%d %d", width, height);
    int maxVal;
    fscanf(file, "%d", &maxVal);
    fgetc(file);  // Read the newline after maxVal

    Pixel **image = malloc(*height * sizeof(Pixel *));
    for (int i = 0; i < *height; ++i) {
        image[i] = malloc(*width * sizeof(Pixel));
        fread(image[i], sizeof(Pixel), *width, file);
    }
    fclose(file);
    return image;
}

// Function to write a PPM image
void writePPM(const char *filename, Pixel **image, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", width, height);
    for (int i = 0; i < height; ++i) {
        fwrite(image[i], sizeof(Pixel), width, file);
    }
    fclose(file);
}

// Function to embed a watermark into the image
void embedWatermark(Pixel **image, Pixel **watermark, int width, int height, int wmWidth, int wmHeight) {
    for (int i = 0; i < wmHeight; ++i) {
        for (int j = 0; j < wmWidth; ++j) {
            if (i < height && j < width) {
                image[i][j].r = (image[i][j].r & 0xFE) | ((watermark[i][j].r > 128) ? 1 : 0);
                image[i][j].g = (image[i][j].g & 0xFE) | ((watermark[i][j].g > 128) ? 1 : 0);
                image[i][j].b = (image[i][j].b & 0xFE) | ((watermark[i][j].b > 128) ? 1 : 0);
            }
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image.ppm> <watermark_image.ppm> <output_image.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int imageWidth, imageHeight;
    Pixel **image = readPPM(argv[1], &imageWidth, &imageHeight);
    if (!image) return EXIT_FAILURE;

    int wmWidth, wmHeight;
    Pixel **watermark = readPPM(argv[2], &wmWidth, &wmHeight);
    if (!watermark) {
        for (int i = 0; i < imageHeight; ++i) free(image[i]);
        free(image);
        return EXIT_FAILURE;
    }

    embedWatermark(image, watermark, imageWidth, imageHeight, wmWidth, wmHeight);
    writePPM(argv[3], image, imageWidth, imageHeight);

    // Clean up
    for (int i = 0; i < imageHeight; ++i) free(image[i]);
    free(image);
    for (int i = 0; i < wmHeight; ++i) free(watermark[i]);
    free(watermark);

    printf("Watermark embedded successfully!\n");
    return EXIT_SUCCESS;
}