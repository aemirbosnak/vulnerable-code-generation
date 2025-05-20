//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

int main() {
    srand(time(NULL));
    int width, height;
    printf("Enter the width and height of the image: ");
    scanf("%d %d", &width, &height);

    if (width <= 0 || height <= 0 || width > MAX_SIZE || height > MAX_SIZE) {
        printf("Invalid image size.\n");
        return 1;
    }

    int image[height][width];
    printf("Enter the image values:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    int flipped_image[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            flipped_image[i][j] = image[height - 1 - i][width - 1 - j];
        }
    }

    printf("Flipped image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", flipped_image[i][j]);
        }
        printf("\n");
    }

    int brightened_image[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            brightened_image[i][j] = image[i][j] + rand() % 50;
        }
    }

    printf("\nBrightened image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", brightened_image[i][j]);
        }
        printf("\n");
    }

    int contrasted_image[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            contrasted_image[i][j] = (int) ((double) image[i][j] / (double) 255 * 100) + rand() % 50;
        }
    }

    printf("\nContrasted image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", contrasted_image[i][j]);
        }
        printf("\n");
    }

    return 0;
}