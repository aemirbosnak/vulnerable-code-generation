//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define WATERMARK_SIZE 100
#define IMAGE_SIZE 512
#define MAX_VALUE 255

typedef struct {
    int x, y;
} Point;

typedef struct {
    int *data;
    int size;
} Image;

Image createImage() {
    Image img;
    img.data = (int *)malloc(IMAGE_SIZE * IMAGE_SIZE * sizeof(int));
    img.size = IMAGE_SIZE * IMAGE_SIZE;
    for (int i = 0; i < img.size; i++) {
        img.data[i] = rand() % MAX_VALUE;
    }
    return img;
}

void drawWatermark(Image *img, Image *watermark) {
    for (int i = 0; i < watermark->size; i++) {
        for (int j = 0; j < watermark->size; j++) {
            int x = i + rand() % (IMAGE_SIZE - watermark->size);
            int y = j + rand() % (IMAGE_SIZE - watermark->size);
            if (img->data[y * IMAGE_SIZE + x] < MAX_VALUE - watermark->data[i * watermark->size + j]) {
                img->data[y * IMAGE_SIZE + x] += watermark->data[i * watermark->size + j];
            }
        }
    }
}

void saveImage(Image img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    fwrite(img.data, sizeof(int), img.size, fp);
    fclose(fp);
}

int main() {
    srand(time(NULL));
    Image img = createImage();
    Image watermark = createImage();
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        for (int j = 0; j < WATERMARK_SIZE; j++) {
            watermark.data[i * watermark.size + j] = rand() % MAX_VALUE;
        }
    }
    drawWatermark(&img, &watermark);
    saveImage(img, "watermarked.bmp");
    return 0;
}