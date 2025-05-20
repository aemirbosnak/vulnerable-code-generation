//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_FILENAME 256
#define IMAGE_WIDTH 256
#define IMAGE_HEIGHT 256

typedef struct {
    uint8_t r, g, b; // RGB Color
} Pixel;

typedef struct {
    Pixel pixels[IMAGE_HEIGHT][IMAGE_WIDTH];
} Image;

void readImage(const char *filename, Image *img) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Can't open image file");
        exit(EXIT_FAILURE);
    }
    fread(img, sizeof(Image), 1, file);
    fclose(file);
}

void writeImage(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Can't write image file");
        exit(EXIT_FAILURE);
    }
    fwrite(img, sizeof(Image), 1, file);
    fclose(file);
}

void embedWatermark(Image *img, const char *watermark) {
    size_t w_len = strlen(watermark);
    int index = 0;

    for (int y = 0; y < IMAGE_HEIGHT && index < w_len; y++) {
        for (int x = 0; x < IMAGE_WIDTH && index < w_len; x++) {
            uint8_t bit = (watermark[index] >> (7 - (x % 8))) & 1; // Extract bit from watermark
            img->pixels[y][x].r = (img->pixels[y][x].r & 0xFE) | bit; // Embed bit into the least significant bit
            if (x % 8 == 7) index++; // Move to the next character
        }
    }
}

void extractWatermark(const Image *img, char *watermark) {
    int index = 0;

    for (int y = 0; y < IMAGE_HEIGHT && index < 32; y++) { // Assuming 32 bits for watermark max size
        for (int x = 0; x < IMAGE_WIDTH && index < 32; x++) {
            if (x % 8 == 0) watermark[index] = 0; // new byte
            watermark[index] |= ((img->pixels[y][x].r & 1) << (7 - (x % 8))); // Extract bit
            if (x % 8 == 7) index++; // Move to the next character
        }
    }
    watermark[32] = '\0'; // Null-terminate
}

int main() {
    Image img;
    char watermark[33] = "Watermark!";
    char extractedWatermark[33];

    // Read image
    char inputFile[MAX_FILENAME], outputFile[MAX_FILENAME];
    printf("Enter input image filename: ");
    scanf("%s", inputFile);
    readImage(inputFile, &img);

    // Embed watermark
    embedWatermark(&img, watermark);

    // Write image with watermark
    printf("Enter output image filename: ");
    scanf("%s", outputFile);
    writeImage(outputFile, &img);

    // Extract watermark for verification
    extractWatermark(&img, extractedWatermark);
    printf("Extracted Watermark: %s\n", extractedWatermark);

    return 0;
}