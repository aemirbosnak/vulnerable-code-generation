//FormAI DATASET v1.0 Category: Image Editor ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Global variables
int width  = 0;
int height = 0;
int MAX_COLOR_VAL = 255;
int** image;   // This is a 2D-array to hold our image

// Function to allocate memory for the image
void allocateImage() {
    image = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        image[i] = (int*)malloc(width * sizeof(int));
    }
}

// Function to read input from user
void readInput() {
    printf("Enter width of image: ");
    scanf("%d", &width);
    printf("Enter height of image: ");
    scanf("%d", &height);

    // Allocate memory for the image
    allocateImage();

    // Read image data from user
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("Enter value for (%d,%d): ", i, j);
            scanf("%d", &image[i][j]);
            if (image[i][j] > MAX_COLOR_VAL) {
                image[i][j] = MAX_COLOR_VAL;  // Cap color values at 255
            } else if (image[i][j] < 0) {
                image[i][j] = 0;  // Set negative color values to 0
            }
        }
    }
}

// Function to output the image
void output() {
    printf("P2\n");   // Mandatory header for PGM file format
    printf("%d %d\n", width, height);   // Width and height of the image
    printf("%d\n", MAX_COLOR_VAL);   // Maximum color value
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i][j]);   // Output each pixel value
        }
        printf("\n");
    }
}

// Function to invert the image
void invert() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = MAX_COLOR_VAL - image[i][j];   // Invert pixel value
        }
    }
}

// Function to flip the image horizontally
void flipHorizontally() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width/2; j++) {
            // Swap pixel values on either side of the center line
            int temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
}

// Function to flip the image vertically
void flipVertically() {
    for (int i = 0; i < height/2; i++) {
        for (int j = 0; j < width; j++) {
            // Swap pixel values on either side of the center line
            int temp = image[i][j];
            image[i][j] = image[height-i-1][j];
            image[height-i-1][j] = temp;
        }
    }
}

// Main function to run the image editor program
int main() {
    // Prompt user for input and read image data
    readInput();

    // Display image to user
    printf("Original image:\n");
    output();

    // Menu for user to select various image editing options
    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Invert image\n");
        printf("2. Flip image horizontally\n");
        printf("3. Flip image vertically\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                invert();
                printf("Inverted image:\n");
                output();
                break;
            case 2:
                flipHorizontally();
                printf("Horizontally flipped image:\n");
                output();
                break;
            case 3:
                flipVertically();
                printf("Vertically flipped image:\n");
                output();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    // Free up memory allocated for image
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}