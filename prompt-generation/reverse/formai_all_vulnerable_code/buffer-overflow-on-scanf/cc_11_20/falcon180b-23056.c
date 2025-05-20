//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 100
#define COLS 100

int main() {
    int image[ROWS][COLS];
    int flipped_image[ROWS][COLS];
    int brightness_image[ROWS][COLS];
    int contrast_image[ROWS][COLS];

    printf("Enter image data:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            flipped_image[i][j] = image[i][COLS - j - 1];
        }
    }

    double brightness = 0.5;
    double contrast = 1.5;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            brightness_image[i][j] = (int) (brightness * image[i][j]);
            contrast_image[i][j] = (int) (contrast * (brightness_image[i][j] - 127.5));
        }
    }

    printf("Original Image:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    printf("\nFlipped Image:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", flipped_image[i][j]);
        }
        printf("\n");
    }

    printf("\nBrightness Image:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", brightness_image[i][j]);
        }
        printf("\n");
    }

    printf("\nContrast Image:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", contrast_image[i][j]);
        }
        printf("\n");
    }

    return 0;
}