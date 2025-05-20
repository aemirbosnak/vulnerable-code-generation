//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WATERMARK_SIZE 32
#define IMAGE_SIZE 512

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point topLeft;
    Point bottomRight;
} Rect;

typedef struct {
    int width;
    int height;
    int *data;
} Image;

void readImage(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    image->data = (int *)malloc(filesize);
    fread(image->data, sizeof(int), filesize / sizeof(int), fp);
    fclose(fp);
    image->width = IMAGE_SIZE;
    image->height = IMAGE_SIZE;
}

void writeImage(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    fwrite(image->data, sizeof(int), image->width * image->height, fp);
    fclose(fp);
}

void addWatermark(Image *image, int watermark) {
    int alpha = 127;
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            int index = j * image->width + i;
            int value = image->data[index];
            value = (value + alpha * watermark) % 256;
            image->data[index] = value;
        }
    }
}

void detectWatermark(Image *image, int *watermark) {
    int sum = 0;
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        sum += image->data[i];
    }
    *watermark = sum % 256;
}

int main() {
    Image image1, image2;
    readImage("image1.bmp", &image1);
    readImage("image2.bmp", &image2);
    int watermark = rand() % 256;
    addWatermark(&image1, watermark);
    writeImage("watermarked_image1.bmp", &image1);
    int detectedWatermark;
    detectWatermark(&image1, &detectedWatermark);
    printf("Detected watermark: %d\n", detectedWatermark);
    return 0;
}