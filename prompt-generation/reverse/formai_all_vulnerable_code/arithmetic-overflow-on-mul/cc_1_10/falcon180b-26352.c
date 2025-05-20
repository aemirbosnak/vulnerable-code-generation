//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

#define WATERMARK_SIZE 10
#define WATERMARK_VALUE 42

// Function to embed watermark
void embed_watermark(int *image, int rows, int cols, int watermark) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i % WATERMARK_SIZE == 0 && j % WATERMARK_SIZE == 0) {
                // Check if the pixel is part of the watermark
                if (image[i*cols+j]!= watermark) {
                    image[i*cols+j] = watermark;
                }
            }
        }
    }
}

// Function to extract watermark
int extract_watermark(int *image, int rows, int cols) {
    int i, j;
    int watermark = -1;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i % WATERMARK_SIZE == 0 && j % WATERMARK_SIZE == 0) {
                // Check if the pixel is part of the watermark
                if (image[i*cols+j] == WATERMARK_VALUE) {
                    // If found, return the watermark value
                    return WATERMARK_VALUE;
                }
            }
        }
    }
    // If watermark not found, return -1
    return -1;
}

int main() {
    int rows, cols, watermark;
    printf("Enter the number of rows and columns in the image: ");
    scanf("%d %d", &rows, &cols);
    int *image = (int*)malloc(rows*cols*sizeof(int));
    printf("Enter the image values: ");
    for (int i = 0; i < rows*cols; i++) {
        scanf("%d", &image[i]);
    }
    printf("Enter the watermark value: ");
    scanf("%d", &watermark);
    // Embed the watermark
    embed_watermark(image, rows, cols, watermark);
    // Extract the watermark
    int extracted_watermark = extract_watermark(image, rows, cols);
    if (extracted_watermark == -1) {
        printf("Watermark not found.\n");
    } else {
        printf("Watermark extracted successfully.\n");
    }
    free(image);
    return 0;
}