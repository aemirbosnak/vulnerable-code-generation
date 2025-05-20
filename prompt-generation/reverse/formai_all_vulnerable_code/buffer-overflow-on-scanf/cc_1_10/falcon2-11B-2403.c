//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void flipImage(int* image, int width, int height) {
    int temp = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            temp = image[i * width + j];
            image[i * width + j] = image[height - i - 1 * width + j];
            image[height - i - 1 * width + j] = temp;
        }
    }
}

void adjustBrightness(int* image, int width, int height) {
    float factor = 1.1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i * width + j] = (int) (image[i * width + j] * factor);
        }
    }
}

void adjustContrast(int* image, int width, int height) {
    float factor = 1.1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i * width + j] = (int) (image[i * width + j] * factor);
        }
    }
}

int main() {
    int width, height, i, j;
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);

    int* image = (int*) malloc(width * height * sizeof(int));

    printf("Enter the pixel values of the image:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            scanf("%d", &image[i * width + j]);
        }
    }

    flipImage(image, width, height);
    printf("Flipped image:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", image[i * width + j]);
        }
        printf("\n");
    }

    adjustBrightness(image, width, height);
    printf("Brightness adjusted image:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", image[i * width + j]);
        }
        printf("\n");
    }

    adjustContrast(image, width, height);
    printf("Contrast adjusted image:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", image[i * width + j]);
        }
        printf("\n");
    }

    free(image);
    return 0;
}