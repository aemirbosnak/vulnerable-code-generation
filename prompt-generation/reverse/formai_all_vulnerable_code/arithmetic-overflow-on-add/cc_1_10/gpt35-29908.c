//FormAI DATASET v1.0 Category: Image Editor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Define size of image
#define WIDTH 10
#define HEIGHT 10

// Function to generate random RGB value
int rand_color() {
    return rand() % 256;
}

// Function to print preview of image
void preview(int image[WIDTH][HEIGHT]) {
    printf("\n");
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf(" (%d,%d,%d)", image[i][j], image[i][j], image[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to select an area of the image and apply effects
void select_area(int image[WIDTH][HEIGHT]) {
    int start_row, start_column, end_row, end_column;
    printf("\nEnter start row: ");
    scanf("%d", &start_row);
    printf("Enter start column: ");
    scanf("%d", &start_column);
    printf("Enter end row: ");
    scanf("%d", &end_row);
    printf("Enter end column: ");
    scanf("%d", &end_column);

    // Apply effects to selected area
    for (int i = start_row; i <= end_row; i++) {
        for (int j = start_column; j <= end_column; j++) {
            // Invert RGB values
            image[i][j] = 255 - image[i][j];
        }
    }
}

int main() {
    int image[WIDTH][HEIGHT];

    // Generate random RGB values for each pixel in image
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            image[i][j] = rand_color();
        }
    }

    // Preview original image
    printf("Original Image:\n");
    preview(image);

    // Ask user to select area and apply effects
    printf("Select Area to Edit:\n");
    select_area(image);

    // Preview edited image
    printf("Edited Image:\n");
    preview(image);

    return 0;
}