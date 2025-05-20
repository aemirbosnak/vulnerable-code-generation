//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to flip an image
void flipImage(int **image, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][cols-j-1];
            image[i][cols-j-1] = temp;
        }
    }
}

// Function to change brightness and contrast
void changeBrightnessContrast(int **image, int rows, int cols, float brightness, float contrast) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            int value = image[i][j];
            value = (int) ((value * brightness) + 128);
            value = (int) ((value * contrast) / 255);
            image[i][j] = value;
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns of the image: ");
    scanf("%d %d", &rows, &cols);

    int **image = (int **) malloc(rows * sizeof(int *));
    for(int i=0; i<rows; i++) {
        image[i] = (int *) malloc(cols * sizeof(int));
    }

    printf("Enter the image values:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    flipImage(image, rows, cols);
    changeBrightnessContrast(image, rows, cols, 1.5, 1.5);

    printf("The modified image is:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<rows; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}