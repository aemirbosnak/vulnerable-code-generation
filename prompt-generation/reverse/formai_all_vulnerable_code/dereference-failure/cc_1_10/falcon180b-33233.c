//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define WATERMARK_SIZE 64
#define IMAGE_SIZE 512
#define PIXEL_SIZE 8
#define WATERMARK_TYPE "Watermark"
#define WATERMARK_VALUE "My Digital Watermark"

typedef struct {
    unsigned char* data;
    int width;
    int height;
} Image;

void generateWatermark(Image* watermark) {
    int i, j, k;
    for (i = 0; i < watermark->height; i++) {
        for (j = 0; j < watermark->width; j++) {
            k = i * watermark->width + j;
            if (k % 2 == 0) {
                watermark->data[k] = 0;
            } else {
                watermark->data[k] = 255;
            }
        }
    }
}

void applyWatermark(Image* image, Image* watermark) {
    int i, j, k;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            k = i * image->width + j;
            if (k % 2 == 0) {
                image->data[k] = (image->data[k] + watermark->data[k]) / 2;
            } else {
                image->data[k] = (image->data[k] + watermark->data[k]) / 2;
            }
        }
    }
}

void saveImage(Image* image, char* filename) {
    FILE* fp;
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Cannot create file.\n");
        exit(1);
    }
    fwrite(image->data, 1, image->width * image->height, fp);
    fclose(fp);
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    Image watermark, image;
    watermark.width = WATERMARK_SIZE;
    watermark.height = WATERMARK_SIZE;
    watermark.data = (unsigned char*)malloc(watermark.width * watermark.height * PIXEL_SIZE);
    generateWatermark(&watermark);
    watermark.data[0] = 0;
    watermark.data[1] = 0;
    watermark.data[2] = 0;
    watermark.data[3] = 0;
    image.width = IMAGE_SIZE;
    image.height = IMAGE_SIZE;
    image.data = (unsigned char*)malloc(image.width * image.height * PIXEL_SIZE);
    for (int i = 0; i < image.width * image.height; i++) {
        image.data[i] = rand() % 256;
    }
    applyWatermark(&image, &watermark);
    saveImage(&image, "watermark.bmp");
    printf("Watermark applied successfully.\n");
    return 0;
}