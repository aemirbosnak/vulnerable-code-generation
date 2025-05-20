//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

/* Function to flip an image horizontally */
void flipHorizontally(int width, int height, int image[height][width]) {
    int i, j, temp;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

/* Function to change the brightness of an image */
void changeBrightness(int width, int height, int image[height][width], int brightness) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            image[i][j] += brightness;
            if (image[i][j] < 0) {
                image[i][j] = 0;
            }
            else if (image[i][j] > 255) {
                image[i][j] = 255;
            }
        }
    }
}

/* Function to change the contrast of an image */
void changeContrast(int width, int height, int image[height][width], float contrast) {
    int i, j;
    float factor, adjustment;
    factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            adjustment = factor * (image[i][j] - 128) + 128;
            if (adjustment < 0) {
                adjustment = 0;
            }
            else if (adjustment > 255) {
                adjustment = 255;
            }
            image[i][j] = (int)adjustment;
        }
    }
}

int main() {
    int i, j, width, height, brightness, choice;
    float contrast;
    printf("Enter the width and height of the image: ");
    scanf("%d %d", &width, &height);
    int image[height][width];
    printf("Enter the pixel values of the image:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            scanf("%d", &image[i][j]);
        }
    }
    printf("Choose the image processing task:\n");
    printf("1. Flip horizontally\n");
    printf("2. Change brightness\n");
    printf("3. Change contrast\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            flipHorizontally(width, height, image);
            break;
        case 2:
            printf("Enter the brightness value (-255 to 255): ");
            scanf("%d", &brightness);
            changeBrightness(width, height, image, brightness);
            break;
        case 3:
            printf("Enter the contrast value (0.0 to 10.0): ");
            scanf("%f", &contrast);
            changeContrast(width, height, image, contrast);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    printf("Modified image:\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    return 0;
}