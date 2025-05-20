//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROWS 200
#define COLS 200
#define MAX_VALUE 255

int main() {
    int i, j;
    int **image;
    int **new_image;
    double brightness, contrast;

    image = (int **)malloc(ROWS * sizeof(int *));
    for (i = 0; i < ROWS; i++) {
        image[i] = (int *)malloc(COLS * sizeof(int));
    }

    printf("Enter the image:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    printf("Enter the brightness (0-100): ");
    scanf("%d", &brightness);
    printf("Enter the contrast (0-100): ");
    scanf("%d", &contrast);

    new_image = (int **)malloc(ROWS * sizeof(int *));
    for (i = 0; i < ROWS; i++) {
        new_image[i] = (int *)malloc(COLS * sizeof(int));
    }

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int value = (int)((double)image[i][j] * brightness / 100 + (double)contrast * (double)MAX_VALUE / 100);
            if (value < 0) {
                value = 0;
            } else if (value > MAX_VALUE) {
                value = MAX_VALUE;
            }
            new_image[i][j] = value;
        }
    }

    printf("Flipped image:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", new_image[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < ROWS; i++) {
        free(image[i]);
    }
    free(image);

    for (i = 0; i < ROWS; i++) {
        free(new_image[i]);
    }
    free(new_image);

    return 0;
}