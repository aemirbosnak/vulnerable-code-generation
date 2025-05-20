//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define IMAGE_SIZE WIDTH * HEIGHT
#define WATERMARK_SIZE 64
#define THRESHOLD 128

typedef struct {
    int value;
    int position;
} Pixel;

typedef struct {
    int width;
    int height;
    int **data;
} Image;

void readImage(char *filename, Image *image) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    rewind(fp);

    image->width = WIDTH;
    image->height = HEIGHT;
    image->data = malloc(IMAGE_SIZE * sizeof(int));

    for (int i = 0; i < IMAGE_SIZE; i++) {
        fread(&image->data[i], sizeof(int), 1, fp);
    }

    fclose(fp);
}

void writeImage(char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < IMAGE_SIZE; i++) {
        fwrite(&image->data[i], sizeof(int), 1, fp);
    }

    fclose(fp);
}

void applyWatermark(Image *image, char *watermark) {
    int watermarkValue = 0;
    for (int i = 0; i < strlen(watermark); i++) {
        watermarkValue += watermark[i];
    }

    int watermarkPosition = 0;
    int watermarkStep = WIDTH / strlen(watermark);

    for (int i = 0; i < IMAGE_SIZE; i++) {
        if (image->data[i] > THRESHOLD) {
            image->data[i] += watermarkValue;
        }
    }
}

void saveWatermarkedImage(char *filename, Image *image) {
    writeImage(filename, image);
}

int main() {
    Image image;
    readImage("image.bmp", &image);

    char watermark[] = "Genius";
    applyWatermark(&image, watermark);

    saveWatermarkedImage("watermarked_image.bmp", &image);

    return 0;
}