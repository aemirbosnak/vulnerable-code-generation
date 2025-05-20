//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate watermark
void generate_watermark(int *watermark, int size) {
    int i;
    for (i = 0; i < size; i++) {
        watermark[i] = rand() % 256;
    }
}

// Function to embed watermark
void embed_watermark(int *image, int *watermark, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            image[i * size + j] = (image[i * size + j] + watermark[i * size + j]) % 256;
        }
    }
}

// Function to extract watermark
void extract_watermark(int *image, int *watermark, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            watermark[i * size + j] = image[i * size + j] - (image[i * size + j] % 256);
        }
    }
}

int main() {
    int size = 256;
    int *image = (int *)malloc(size * size * sizeof(int));
    int *watermark = (int *)malloc(size * size * sizeof(int));

    generate_watermark(watermark, size);
    embed_watermark(image, watermark, size);

    printf("Watermarked image:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", image[i * size + j]);
        }
        printf("\n");
    }

    extract_watermark(image, watermark, size);

    printf("Extracted watermark:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", watermark[i * size + j]);
        }
        printf("\n");
    }

    free(image);
    free(watermark);

    return 0;
}