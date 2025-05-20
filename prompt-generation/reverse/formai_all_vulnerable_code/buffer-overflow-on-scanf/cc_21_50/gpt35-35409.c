//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int width = 0, height = 0;
    printf("Enter the width and height of the image: ");
    scanf("%d %d", &width, &height);

    int image[height][width];

    // Fill the image with random values
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = rand() % 256;
        }
    }

    // Print the original image
    printf("Original Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Flip the image vertically
    for (int i = 0; i < height/2; i++) {
        for (int j = 0; j < width; j++) {
            int temp = image[i][j];
            image[i][j] = image[height-i-1][j];
            image[height-i-1][j] = temp;
        }
    }

    // Print the vertically flipped image
    printf("\nVertically Flipped Image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Change the brightness of the image
    int brightness = 50;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = image[i][j] + brightness;
            if (image[i][j] > 255) {
                image[i][j] = 255;
            } else if (image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }

    // Print the image with changed brightness
    printf("\nImage with Changed Brightness:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Change the contrast of the image
    float contrast = 1.5;
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = factor * (image[i][j] - 128) + 128;
            if (image[i][j] > 255) {
                image[i][j] = 255;
            } else if (image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }

    // Print the image with changed contrast
    printf("\nImage with Changed Contrast:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}