//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to flip an image horizontally
void flipImage(int *image, int width, int height) {
    int temp;

    // Loop over each pixel in the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Store the current pixel value
            temp = image[i * width + j];

            // Swap the pixel values
            image[i * width + j] = image[(height - 1 - i) * width + j];
            image[(height - 1 - i) * width + j] = temp;
        }
    }
}

// Function to display an image
void displayImage(int *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[i * width + j]);
        }
        printf("\n");
    }
}

// Function to read an image file
void readImage(char *filename, int *image, int width, int height) {
    FILE *fp;
    char line[80];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file '%s'\n", filename);
        exit(1);
    }

    fgets(line, 80, fp);
    sscanf(line, "%d %d", &width, &height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(fp, "%d", &image[i * width + j]);
        }
    }

    fclose(fp);
}

// Main function
int main() {
    int width, height, i, j;
    int *image;
    char filename[80];

    // Get the dimensions of the image
    printf("Enter the width and height of the image: ");
    scanf("%d %d", &width, &height);

    // Allocate memory for the image
    image = (int *)malloc(width * height * sizeof(int));

    // Read the image file
    printf("Enter the name of the image file: ");
    scanf("%s", filename);
    readImage(filename, image, width, height);

    // Flip the image horizontally
    flipImage(image, width, height);

    // Display the image
    printf("\nOriginal Image:\n");
    displayImage(image, width, height);

    printf("\nFlipped Image:\n");
    displayImage(image, width, height);

    // Free the memory
    free(image);

    return 0;
}