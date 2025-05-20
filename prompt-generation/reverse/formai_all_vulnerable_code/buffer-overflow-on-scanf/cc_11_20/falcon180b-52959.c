//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 512
#define WATERMARK_SIZE 64
#define ALPHA 0.5

int main() {
    char image[SIZE][SIZE];
    char watermark[WATERMARK_SIZE][SIZE];
    char result[SIZE][SIZE];
    int i, j, k;
    int w, h;

    printf("Enter the width of the image: ");
    scanf("%d", &w);
    printf("Enter the height of the image: ");
    scanf("%d", &h);

    printf("Enter the image:\n");
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            scanf("%c", &image[i][j]);
        }
    }

    printf("Enter the watermark:\n");
    for (i = 0; i < h; i++) {
        for (j = 0; j < WATERMARK_SIZE; j++) {
            scanf("%c", &watermark[i][j]);
        }
    }

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if (i < h - WATERMARK_SIZE && j < w - WATERMARK_SIZE) {
                result[i][j] = image[i][j] + ALPHA * watermark[i][j];
            } else {
                result[i][j] = image[i][j];
            }
        }
    }

    printf("The watermarked image is:\n");
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            printf("%c", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}