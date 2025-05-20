//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL 255

// Function to flip an image horizontally
void flipImageHorizontally (int rows, int cols, int image[][cols]) {
    int temp;
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols/2; j++) {
            temp = image[i][j];
            image[i][j] = image[i][cols-1-j];
            image[i][cols-1-j] = temp;
        }
    }
}

// Function to apply brightness on an image
void applyBrightness (int rows, int cols, int image[][cols], int brightness) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            image[i][j] += brightness;
            if (image[i][j] > MAX_PIXEL) {
                image[i][j] = MAX_PIXEL;
            }
            else if (image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }
}

// Function to apply contrast on an image
void applyContrast (int rows, int cols, int image[][cols], float contrast) {
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            image[i][j] = factor * (image[i][j] - 128) + 128;
            if (image[i][j] > MAX_PIXEL) {
                image[i][j] = MAX_PIXEL;
            }
            else if (image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }
}

// Function to print an image
void printImage (int rows, int cols, int image[][cols]) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("%d\t", image[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols, brightness, choice;
    float contrast;
    printf("Enter the number of rows and columns of the image: ");
    scanf("%d %d", &rows, &cols);

    int image[rows][cols];
    printf("Enter the pixel values of the image: ");
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    printf("1. Flip image horizontally\n2. Change brightness\n3. Change contrast\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            flipImageHorizontally(rows, cols, image);
            printf("\nImage after horizontal flip:\n");
            printImage(rows, cols, image);
            break;
        case 2:
            printf("Enter the brightness value (between -255 and 255): ");
            scanf("%d", &brightness);
            applyBrightness(rows, cols, image, brightness);
            printf("\nImage after brightness change:\n");
            printImage(rows, cols, image);
            break;
        case 3:
            printf("Enter the contrast value (between -255 and 255): ");
            scanf("%f", &contrast);
            applyContrast(rows, cols, image, contrast);
            printf("\nImage after contrast change:\n");
            printImage(rows, cols, image);
            break;
        default:
            printf("\nInvalid choice!\n");
            break;
    }
    return 0;
}