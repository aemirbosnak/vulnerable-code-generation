//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to generate watermark
void generateWatermark(int *watermark, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        watermark[i] = rand() % 256;
    }
}

// Function to embed watermark
void embedWatermark(int *image, int *watermark, int size) {
    for (int i = 0; i < size; i++) {
        image[i] = (image[i] + watermark[i]) % 256;
    }
}

// Function to extract watermark
void extractWatermark(int *image, int *watermark, int size) {
    for (int i = 0; i < size; i++) {
        watermark[i] = (image[i] - watermark[i]) % 256;
    }
}

// Function to display image
void displayImage(int *image, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", image[i]);
    }
    printf("\n");
}

int main() {
    // Get image size from user
    int size;
    printf("Enter image size: ");
    scanf("%d", &size);

    // Generate watermark
    int watermark[size];
    generateWatermark(watermark, size);

    // Display original image
    int image[size];
    for (int i = 0; i < size; i++) {
        image[i] = i;
    }
    printf("Original image:\n");
    displayImage(image, size);

    // Embed watermark in image
    embedWatermark(image, watermark, size);
    printf("Watermarked image:\n");
    displayImage(image, size);

    // Extract watermark from image
    int extractedWatermark[size];
    extractWatermark(image, extractedWatermark, size);
    printf("Extracted watermark:\n");
    displayImage(extractedWatermark, size);

    return 0;
}