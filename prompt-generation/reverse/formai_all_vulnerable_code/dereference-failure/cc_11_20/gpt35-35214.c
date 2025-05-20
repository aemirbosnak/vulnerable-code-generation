//FormAI DATASET v1.0 Category: Image compression ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define IMAGE_SIZE 512
#define COMPRESSION_RATIO 2

int main() {
    // Allocate memory for uncompressed image
    int **uncompressed_image = (int **)malloc(sizeof(int *) * IMAGE_SIZE);
    for (int i = 0; i < IMAGE_SIZE; i++) {
        uncompressed_image[i] = (int *)malloc(sizeof(int) * IMAGE_SIZE);
    }
    
    // Fill uncompressed image with random pixel values (0-255)
    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            uncompressed_image[i][j] = rand() % 256;
        }
    }
    
    // Allocate memory for compressed image
    int **compressed_image = (int **)malloc(sizeof(int *) * (IMAGE_SIZE / COMPRESSION_RATIO));
    for (int i = 0; i < IMAGE_SIZE / COMPRESSION_RATIO; i++) {
        compressed_image[i] = (int *)malloc(sizeof(int) * (IMAGE_SIZE / COMPRESSION_RATIO));
    }
    
    // Compress image
    for (int i = 0; i < IMAGE_SIZE; i += COMPRESSION_RATIO) {
        for (int j = 0; j < IMAGE_SIZE; j += COMPRESSION_RATIO) {
            int sum = 0;
            for (int x = i; x < i + COMPRESSION_RATIO; x++) {
                for (int y = j; y < j + COMPRESSION_RATIO; y++) {
                    sum += uncompressed_image[x][y];
                }
            }
            compressed_image[i / COMPRESSION_RATIO][j / COMPRESSION_RATIO] = sum / (COMPRESSION_RATIO * COMPRESSION_RATIO);
        }
    }
    
    // Free memory for uncompressed image
    for (int i = 0; i < IMAGE_SIZE; i++) {
        free(uncompressed_image[i]);
    }
    free(uncompressed_image);
    
    // Print compressed image
    for (int i = 0; i < IMAGE_SIZE / COMPRESSION_RATIO; i++) {
        for (int j = 0; j < IMAGE_SIZE / COMPRESSION_RATIO; j++) {
            printf("%d ", compressed_image[i][j]);
        }
        printf("\n");
    }
    
    // Free memory for compressed image
    for (int i = 0; i < IMAGE_SIZE / COMPRESSION_RATIO; i++) {
        free(compressed_image[i]);
    }
    free(compressed_image);

    return 0;
}