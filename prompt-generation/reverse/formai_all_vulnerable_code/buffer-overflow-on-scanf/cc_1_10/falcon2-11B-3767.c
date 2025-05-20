//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to embed watermark into the image
void embedWatermark(unsigned char *image, unsigned char *watermark, int width, int height) {
    int i, j, k;
    unsigned char *pImage, *pWatermark;
    pImage = image;
    pWatermark = watermark;
    
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            for (k = 0; k < 3; k++) {
                pImage[i * 3 + k] += pWatermark[i * 3 + k] * 0.5;
            }
            pImage += 3;
        }
        pImage += width * 3;
    }
}

// Function to extract watermark from the image
void extractWatermark(unsigned char *image, unsigned char *watermark, int width, int height) {
    int i, j, k;
    unsigned char *pImage, *pWatermark;
    pImage = image;
    pWatermark = watermark;
    
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            for (k = 0; k < 3; k++) {
                pWatermark[i * 3 + k] += pImage[i * 3 + k] * 0.5;
            }
            pImage += 3;
        }
        pImage += width * 3;
    }
}

// Function to compare extracted watermark with original watermark
int compareWatermarks(unsigned char *image, unsigned char *watermark, int width, int height) {
    int i, j, k;
    unsigned char *pImage, *pWatermark;
    pImage = image;
    pWatermark = watermark;
    
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            for (k = 0; k < 3; k++) {
                if (pImage[i * 3 + k]!= pWatermark[i * 3 + k]) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main() {
    unsigned char image[100][100] = {0};
    unsigned char watermark[100][100] = {0};
    int width = 100;
    int height = 100;
    
    // Load image
    printf("Enter image data (100x100):\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%u", &image[i][j]);
        }
    }
    
    // Load watermark
    printf("Enter watermark data (100x100):\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%u", &watermark[i][j]);
        }
    }
    
    // Embed watermark into image
    embedWatermark(image, watermark, width, height);
    
    // Extract watermark from image
    extractWatermark(image, watermark, width, height);
    
    // Compare extracted watermark with original watermark
    if (compareWatermarks(image, watermark, width, height) == 1) {
        printf("Watermark extraction successful!\n");
    } else {
        printf("Watermark extraction failed!\n");
    }
    
    return 0;
}