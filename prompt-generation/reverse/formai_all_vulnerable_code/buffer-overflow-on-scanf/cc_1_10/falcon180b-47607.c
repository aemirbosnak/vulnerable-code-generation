//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to embed watermark in image
void embedWatermark(int* image, int* watermark, int n, int m, int threshold) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (image[i * m + j] > threshold) {
                image[i * m + j] += watermark[i * m + j];
            } else {
                image[i * m + j] -= watermark[i * m + j];
            }
        }
    }
}

// Function to extract watermark from image
int* extractWatermark(int* image, int* watermark, int n, int m) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            watermark[i * m + j] = image[i * m + j] - watermark[i * m + j];
        }
    }
    return watermark;
}

int main() {
    int n, m, threshold;
    printf("Enter the size of the image (n x m): ");
    scanf("%d %d", &n, &m);
    int* image = (int*) malloc(n * m * sizeof(int));
    int* watermark = (int*) malloc(n * m * sizeof(int));

    // Initialize image with random values
    for (int i = 0; i < n * m; i++) {
        image[i] = rand() % 256;
    }

    // Initialize watermark with random values
    for (int i = 0; i < n * m; i++) {
        watermark[i] = rand() % 16;
    }

    // Embed watermark in image
    embedWatermark(image, watermark, n, m, 128);

    // Extract watermark from image
    int* extractedWatermark = extractWatermark(image, watermark, n, m);

    // Print extracted watermark
    printf("Extracted watermark:\n");
    for (int i = 0; i < n * m; i++) {
        printf("%d ", extractedWatermark[i]);
    }
    printf("\n");

    return 0;
}