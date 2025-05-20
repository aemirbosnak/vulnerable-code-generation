//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VALUE 255

// Function to flip an image horizontally
void flipImage(int **image, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols/2; j++) {
            int temp = (*(image+i*cols+j));
            (*(image+i*cols+j)) = (*(image+i*cols+cols-j-1));
            (*(image+i*cols+cols-j-1)) = temp;
        }
    }
}

// Function to change brightness/contrast of an image
void changeBrightnessContrast(int **image, int rows, int cols, float brightness, float contrast) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            int pixelValue = (*(image+i*cols+j));
            int newValue = (int) ((pixelValue * contrast) + brightness);
            if(newValue > MAX_VALUE)
                newValue = MAX_VALUE;
            else if(newValue < 0)
                newValue = 0;
            (*(image+i*cols+j)) = newValue;
        }
    }
}

// Function to save an image to a file
void saveImage(int **image, int rows, int cols, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if(fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    fwrite(image, sizeof(int), rows*cols, fp);
    fclose(fp);
}

int main() {
    int **image;
    int rows, cols;

    // Read image from file
    FILE *fp = fopen("input.bmp", "rb");
    if(fp == NULL) {
        printf("Error: Could not open file input.bmp\n");
        exit(1);
    }
    fseek(fp, 18, SEEK_SET);
    fread(&rows, sizeof(int), 1, fp);
    fread(&cols, sizeof(int), 1, fp);
    image = (int **) malloc(rows * sizeof(int *));
    for(int i=0; i<rows; i++) {
        image[i] = (int *) malloc(cols * sizeof(int));
    }
    fread(image[0], sizeof(int), cols, fp);
    for(int i=1; i<rows; i++) {
        fread(image[i], sizeof(int), cols, fp);
    }
    fclose(fp);

    // Flip image
    flipImage(image, rows, cols);

    // Change brightness/contrast of image
    float brightness = 1.5;
    float contrast = 2.0;
    changeBrightnessContrast(image, rows, cols, brightness, contrast);

    // Save modified image to file
    char *outputFilename = "output.bmp";
    saveImage(image, rows, cols, outputFilename);

    printf("Image processing completed successfully!\n");

    return 0;
}