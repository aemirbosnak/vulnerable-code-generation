//FormAI DATASET v1.0 Category: Image Editor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printMenu(); // Function to print the main menu
void loadImage(int **, int *, int *); // Function to load an image from file
void saveImage(int **, int, int); // Function to save the image to file
void invertColors(int **, int, int); // Function to invert the colors of the image
void flipImage(int **, int, int); // Function to flip the image horizontally


int main() {

    int **image = NULL; // Declare a 2D array to store the image pixel values
    int numRows = 0, numCols = 0; // Declare variables to store the number of rows and columns of the image
    int choice = 0;
    bool running = true;

    while (running) {
        printMenu();

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Load the image from file
                loadImage(image, &numRows, &numCols);
                break;

            case 2:
                // Save the image to file
                saveImage(image, numRows, numCols);
                break;

            case 3:
                // Invert the colors of the image
                invertColors(image, numRows, numCols);
                break;

            case 4:
                // Flip the image horizontally
                flipImage(image, numRows, numCols);
                break;

            case 0:
                // Exit the program
                running = false;
                break;

            default:
                printf("Invalid option\n");
                break;
        }
    }

    // Free the memory allocated for the image
    for (int i = 0; i < numRows; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}

void printMenu() {
    printf("\nC Image Editor\n");
    printf("---------------\n");
    printf("1. Load image from file\n");
    printf("2. Save image to file\n");
    printf("3. Invert colors\n");
    printf("4. Flip horizontally\n");
    printf("0. Exit program\n");
    printf("---------------\n");
    printf("Enter your choice: ");
}

void loadImage(int **image, int *numRows, int *numCols) {
    FILE *imageFile = NULL;
    char filename[100];
    int **newImage = NULL;
    int tempPixel = 0;

    // Ask user to enter the filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open the image file
    imageFile = fopen(filename, "r");

    if (imageFile == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Read the number of rows and columns of the image
    fscanf(imageFile, "%d %d", numRows, numCols);

    // Allocate memory for the new image
    newImage = (int **) malloc(sizeof(int *) * (*numRows));
    for (int i = 0; i < *numRows; i++) {
        newImage[i] = (int *) malloc(sizeof(int) * (*numCols));
    }

    // Read the pixel values from the file and store them in the new image
    for (int i = 0; i < *numRows; i++) {
        for (int j = 0; j < *numCols; j++) {
            fscanf(imageFile, "%d", &tempPixel);
            newImage[i][j] = tempPixel;
        }
    }

    // Close the image file
    fclose(imageFile);

    // Free the memory allocated for the old image
    for (int i = 0; i < *numRows; i++) {
        free(image[i]);
    }
    free(image);

    // Update the image pointer to point to the new image
    image = newImage;

    printf("Image loaded successfully\n");
}

void saveImage(int **image, int numRows, int numCols) {
    FILE *imageFile = NULL;
    char filename[100];

    // Ask user to enter the filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open the image file
    imageFile = fopen(filename, "w");

    if (imageFile == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Write the number of rows and columns of the image to the file
    fprintf(imageFile, "%d %d\n", numRows, numCols);

    // Write the pixel values to the file
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            fprintf(imageFile, "%d ", image[i][j]);
        }
        fprintf(imageFile, "\n");
    }

    // Close the image file
    fclose(imageFile);

    printf("Image saved successfully\n");
}

void invertColors(int **image, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            // Invert the color of each pixel
            image[i][j] = 255 - image[i][j];
        }
    }

    printf("Colors inverted successfully\n");
}

void flipImage(int **image, int numRows, int numCols) {
    int tempPixel = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols/2; j++) {
            // Swap the pixels horizontally
            tempPixel = image[i][j];
            image[i][j] = image[i][numCols-1-j];
            image[i][numCols-1-j] = tempPixel;
        }
    }

    printf("Image flipped horizontally successfully\n");
}