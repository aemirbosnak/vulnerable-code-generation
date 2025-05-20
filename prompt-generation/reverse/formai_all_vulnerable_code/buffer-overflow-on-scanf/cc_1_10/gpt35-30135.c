//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// function to flip the image
void flipImage(int** image, int rows, int cols) {
    int temp;
    for(int i=0; i < rows; i++) {
        for(int j=0; j < cols/2; j++) {
            temp = image[i][j];
            image[i][j] = image[i][cols-j-1];
            image[i][cols-j-1] = temp;
        }
    }
}

// function to change brightness/contrast of the image
void adjustImage(int** image, int rows, int cols, float brightness, float contrast) {
    float factor = (259*(contrast + 255)) / (255*(259-contrast));
    for(int i=0; i < rows; i++) {
        for(int j=0; j < cols; j++) {
            image[i][j] = factor * (image[i][j] - 128) + 128 + brightness;
            if(image[i][j] > 255) image[i][j] = 255;
            if(image[i][j] < 0) image[i][j] = 0;
        }
    }
}

int main() {
    int rows, cols;
    float brightness, contrast;
    printf("Enter number of rows and columns of image: ");
    scanf("%d %d", &rows, &cols);
    // allocate memory for 2D array to hold image
    int** image = (int**)malloc(rows * sizeof(int*));
    for(int i=0; i < rows; i++) {
        image[i] = (int*)malloc(cols * sizeof(int));
    }
    // get input image
    printf("Enter image values:\n");
    for(int i=0; i < rows; i++) {
        for(int j=0; j < cols; j++) {
            scanf("%d", &image[i][j]);
        }
    }
    // get user input for brightness and contrast
    printf("Enter brightness value (0 to 255): ");
    scanf("%f", &brightness);
    printf("Enter contrast value (0 to 255): ");
    scanf("%f", &contrast);
    // flip the image and adjust brightness/contrast
    flipImage(image, rows, cols);
    adjustImage(image, rows, cols, brightness, contrast);
    // print the modified image
    printf("Modified image:\n");
    for(int i=0; i < rows; i++) {
        for(int j=0; j < cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    // free memory allocated for image
    for(int i=0; i < rows; i++) {
        free(image[i]);
    }
    free(image);
    return 0;
}