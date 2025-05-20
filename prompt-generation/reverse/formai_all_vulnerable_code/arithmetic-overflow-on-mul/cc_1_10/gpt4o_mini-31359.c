//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEIGHT 512
#define MAX_WIDTH 512

typedef struct {
    int width;
    int height;
    unsigned char pixels[MAX_HEIGHT][MAX_WIDTH];
} Image;

void readImage(const char *filename, Image *img) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("Failed to open file");
        exit(1);
    }

    fscanf(f, "P5\n%d %d\n255\n", &img->width, &img->height);
    fread(img->pixels, sizeof(unsigned char), img->width * img->height, f);
    fclose(f);
}

void writeImage(const char *filename, Image *img) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        perror("Failed to open file");
        exit(1);
    }

    fprintf(f, "P5\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(unsigned char), img->width * img->height, f);
    fclose(f);
}

void embedWatermark(Image *img, const unsigned char watermark, int x_offset, int y_offset) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            if (x == x_offset && y == y_offset) {
                img->pixels[y][x] = watermark;
            }
        }
    }
}

unsigned char extractWatermark(Image *img, int x_offset, int y_offset) {
    return img->pixels[y_offset][x_offset];
}

void printImageData(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            printf("%d ", img->pixels[y][x]);
        }
        printf("\n");
    }
}

int main() {
    Image img;
    const char *inputFile = "input.pgm";
    const char *outputFile = "output.pgm";
    unsigned char watermark = 200; // Example watermark value (a pixel intensity)
    int x_offset = 10;
    int y_offset = 10;

    readImage(inputFile, &img);
    
    printf("Original Image Data:\n");
    printImageData(&img);

    embedWatermark(&img, watermark, x_offset, y_offset);
    
    printf("Image Data After Embedding Watermark:\n");
    printImageData(&img);
    
    writeImage(outputFile, &img);
    
    unsigned char extractedWatermark = extractWatermark(&img, x_offset, y_offset);
    printf("Extracted Watermark from Position (%d, %d): %d\n", x_offset, y_offset, extractedWatermark);

    return 0;
}