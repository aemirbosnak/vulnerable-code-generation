//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define WATERMARK_SIZE 8
#define IMAGE_SIZE 512

typedef struct {
    int watermark[WATERMARK_SIZE][WATERMARK_SIZE];
    int image[IMAGE_SIZE][IMAGE_SIZE];
} WatermarkedImage;

void generateWatermark(WatermarkedImage *watermarkedImage) {
    int i, j;
    for (i = 0; i < WATERMARK_SIZE; i++) {
        for (j = 0; j < WATERMARK_SIZE; j++) {
            watermarkedImage->watermark[i][j] = rand() % 256;
        }
    }
}

void embedWatermark(WatermarkedImage *watermarkedImage) {
    int i, j, k;
    for (i = 0; i < IMAGE_SIZE; i++) {
        for (j = 0; j < IMAGE_SIZE; j++) {
            int watermarkValue = watermarkedImage->watermark[i % WATERMARK_SIZE][j % WATERMARK_SIZE];
            int imageValue = watermarkedImage->image[i][j];
            int newValue = (imageValue + watermarkValue) % 256;
            watermarkedImage->image[i][j] = newValue;
        }
    }
}

void printWatermarkedImage(WatermarkedImage *watermarkedImage) {
    int i, j;
    for (i = 0; i < IMAGE_SIZE; i++) {
        for (j = 0; j < IMAGE_SIZE; j++) {
            printf("%d ", watermarkedImage->image[i][j]);
        }
        printf("\n");
    }
}

int main() {
    WatermarkedImage watermarkedImage;
    generateWatermark(&watermarkedImage);
    embedWatermark(&watermarkedImage);
    printWatermarkedImage(&watermarkedImage);
    return 0;
}