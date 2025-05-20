//FormAI DATASET v1.0 Category: Image Classification system ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Shape Shifting Image Classifier!\n");
    printf("Please enter the dimensions of your image in pixels.\n");
    int width, height;
    scanf("%d %d", &width, &height);
    
    // Allocate memory for the image data
    int** image = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        image[i] = (int*)malloc(width * sizeof(int));
    }
    
    // Populate the image with pixel values
    printf("Please enter the pixel values for your image.\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%d", &image[i][j]);
        }
    }
    
    // Shape shifting begins!
    printf("What shape would you like to shift your image to?\n");
    printf("1. Square\n2. Circle\n3. Triangle\n");
    int shapeOption;
    scanf("%d", &shapeOption);
    
    switch (shapeOption) {
        case 1: // Square
            printf("Transforming the image into a square...\n");
            int squareSide = (width > height) ? width : height;
            int** squareImage = (int**)malloc(squareSide * sizeof(int*));
            for (int i = 0; i < squareSide; i++) {
                squareImage[i] = (int*)malloc(squareSide * sizeof(int));
            }
            for (int i = 0; i < squareSide; i++) {
                for (int j = 0; j < squareSide; j++) {
                    if (i < height && j < width) {
                        squareImage[i][j] = image[i][j];
                    } else {
                        squareImage[i][j] = 0;
                    }
                }
            }
            printf("The image has been transformed into a square.\n");
            // TODO: Perform image classification on squareImage
            break;
        case 2: // Circle
            printf("Transforming the image into a circle...\n");
            int centerX = width / 2;
            int centerY = height / 2;
            int radius = (width > height) ? height / 2 : width / 2;
            int** circleImage = (int**)malloc(height * sizeof(int*));
            for (int i = 0; i < height; i++) {
                circleImage[i] = (int*)malloc(width * sizeof(int));
            }
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    int dx = centerX - j;
                    int dy = centerY - i;
                    if (dx*dx + dy*dy <= radius*radius) {
                        circleImage[i][j] = image[i][j];
                    } else {
                        circleImage[i][j] = 0;
                    }
                }
            }
            printf("The image has been transformed into a circle.\n");
            // TODO: Perform image classification on circleImage
            break;
        case 3: // Triangle
            printf("Transforming the image into a triangle...\n");
            int** triangleImage = (int**)malloc(height * sizeof(int*));
            for (int i = 0; i < height; i++) {
                triangleImage[i] = (int*)malloc(width * sizeof(int));
            }
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (i <= j) {
                        triangleImage[i][j] = image[i][j];
                    } else {
                        triangleImage[i][j] = 0;
                    }
                }
            }
            printf("The image has been transformed into a triangle.\n");
            // TODO: Perform image classification on triangleImage
            break;
        default:
            printf("Invalid shape option.\n");
    }
    
    // Free memory allocated for the images
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);
    
    return 0;
}