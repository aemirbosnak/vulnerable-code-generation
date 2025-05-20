//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

// Function to flip an image horizontally
void flip_horizontally(int rows, int columns, int image[rows][columns]) {
    int temp;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns/2; j++) {
            // Swap the values
            temp = image[i][j];
            image[i][j] = image[i][columns-j-1];
            image[i][columns-j-1] = temp;
        }
    }
}

// Function to change the brightness of an image
void brightness(int rows, int columns, int image[rows][columns], int val) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            // Add the brightness value to each pixel
            image[i][j] += val;
            // Ensure that the pixel values are between 0 and 255
            if(image[i][j] < 0) image[i][j] = 0;
            else if(image[i][j] > 255) image[i][j] = 255;
        }
    }
}

// Function to change the contrast of an image
void contrast(int rows, int columns, int image[rows][columns], float val) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            // Multiply the pixel values with the contrast value
            image[i][j] = (int)((image[i][j] - 128) * val + 128);
            // Ensure that the pixel values are between 0 and 255
            if(image[i][j] < 0) image[i][j] = 0;
            else if(image[i][j] > 255) image[i][j] = 255;
        }
    }
}

int main() {
    int rows, columns, choice, val;
    float contrast_val;
    printf("Enter the number of rows and columns of the image: ");
    scanf("%d %d", &rows, &columns);
    int image[rows][columns];
    printf("Enter the values of the image:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            scanf("%d", &image[i][j]);
        }
    }
    printf("\n");
    printf("Choose a task to perform:\n");
    printf("1. Flip the image horizontally\n");
    printf("2. Change the brightness of the image\n");
    printf("3. Change the contrast of the image\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    switch(choice) {
        case 1: flip_horizontally(rows, columns, image);
                printf("The flipped image is:\n");
                for(int i=0; i<rows; i++) {
                    for(int j=0; j<columns; j++) {
                        printf("%d ", image[i][j]);
                    }
                    printf("\n");
                }
                break;
        case 2: printf("Enter the brightness value: ");
                scanf("%d", &val);
                brightness(rows, columns, image, val);
                printf("The image with adjusted brightness is:\n");
                for(int i=0; i<rows; i++) {
                    for(int j=0; j<columns; j++) {
                        printf("%d ", image[i][j]);
                    }
                    printf("\n");
                }
                break;
        case 3: printf("Enter the contrast value: ");
                scanf("%f", &contrast_val);
                contrast(rows, columns, image, contrast_val);
                printf("The image with adjusted contrast is:\n");
                for(int i=0; i<rows; i++) {
                    for(int j=0; j<columns; j++) {
                        printf("%d ", image[i][j]);
                    }
                    printf("\n");
                }
                break;
        default: printf("Invalid choice\n");
    }
    return 0;
}