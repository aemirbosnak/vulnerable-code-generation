//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Function to embed watermark */
void embedWatermark(int *image, int rows, int cols, int watermark) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if ((i + j) % 2 == 0) {
                /* Add watermark to even positions */
                image[i * cols + j] += watermark;
            }
        }
    }
}

/* Function to extract watermark */
int extractWatermark(int *image, int rows, int cols) {
    int i, j, sum = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if ((i + j) % 2 == 0) {
                /* Extract watermark from even positions */
                sum += image[i * cols + j];
            }
        }
    }
    return sum;
}

int main() {
    int rows, cols, watermark, i, j;
    printf("Enter the number of rows and columns in the image: ");
    scanf("%d %d", &rows, &cols);
    int *image = (int *) malloc(rows * cols * sizeof(int));

    /* Read image data from user */
    printf("Enter the image data:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &image[i * cols + j]);
        }
    }

    /* Embed watermark */
    printf("Enter the watermark to embed: ");
    scanf("%d", &watermark);
    embedWatermark(image, rows, cols, watermark);

    /* Print watermarked image */
    printf("Watermarked image:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", image[i * cols + j]);
        }
        printf("\n");
    }

    /* Extract watermark */
    int extractedWatermark = extractWatermark(image, rows, cols);
    printf("Extracted watermark: %d\n", extractedWatermark);

    free(image);
    return 0;
}