//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 512  // Maximum size of the image

// Function to read the image from file
void read_image(char *filename, int image[][MAX], int *row, int *col) {

    FILE *fp = fopen(filename, "rb");  // Open the file in read binary mode

    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Read the row and column of the image
    fscanf(fp, "%d %d", row, col);

    // Read the data from the file
    for(int i=0; i<*row; i++) {
        for(int j=0; j<*col; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }

    fclose(fp);  // Close the file
}

// Function to write the image to file
void write_image(char *filename, int image[][MAX], int row, int col) {

    FILE *fp = fopen(filename, "wb");  // Open the file in write binary mode

    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Write the row and column of the image
    fprintf(fp, "%d %d\n", row, col);

    // Write the data to the file
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            fprintf(fp, "%d ", image[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);  // Close the file
}

// Function to flip the image horizontally
void flip_horizontal(int image[][MAX], int row, int col) {

    for(int i=0; i<row; i++) {
        for(int j=0; j<col/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][col-j-1];
            image[i][col-j-1] = temp;
        }
    }
}

// Function to change the brightness of the image
void change_brightness(int image[][MAX], int row, int col, int brightness) {

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            int pixel = image[i][j] + brightness;
            if(pixel > 255) {
                pixel = 255;  // Cap the pixel value at 255
            } else if(pixel < 0) {
                pixel = 0;  // Cap the pixel value at 0
            }
            image[i][j] = pixel;
        }
    }
}

// Function to change the contrast of the image
void change_contrast(int image[][MAX], int row, int col, int contrast) {

    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            int pixel = image[i][j];
            pixel = (int)(factor * (pixel - 128) + 128);  // Apply the contrast
            if(pixel > 255) {
                pixel = 255;  // Cap the pixel value at 255
            } else if(pixel < 0) {
                pixel = 0;  // Cap the pixel value at 0
            }
            image[i][j] = pixel;
        }
    }
}

int main() {

    int image[MAX][MAX], row, col;

    // Read the image from file
    read_image("input.txt", image, &row, &col);

    // Flip the image horizontally
    flip_horizontal(image, row, col);

    // Change the brightness of the image
    change_brightness(image, row, col, 50);

    // Change the contrast of the image
    change_contrast(image, row, col, 50);

    // Write the image to file
    write_image("output.txt", image, row, col);

    return 0;
}