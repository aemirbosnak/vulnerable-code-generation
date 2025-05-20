//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 1000
#define PI 3.14159

// Function to flip the image
void flip(int image[MAX][MAX], int rows, int cols) {
    int temp;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols/2; j++) {
            temp = image[i][j];
            image[i][j] = image[i][cols-j-1];
            image[i][cols-j-1] = temp;
        }
    }
}

// Function to change brightness/contrast of the image
void change_brightness_contrast(int image[MAX][MAX], int rows, int cols, float brightness, float contrast) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            float new_pixel_value = (image[i][j] * contrast) + brightness;
            if(new_pixel_value > 255) {
                new_pixel_value = 255;
            } else if(new_pixel_value < 0) {
                new_pixel_value = 0;
            }
            image[i][j] = (int)new_pixel_value;
        }
    }
}

// Function to display the image
void display_image(int image[MAX][MAX], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int image[MAX][MAX], rows, cols;
    FILE *fp;

    // Read the image from a file
    fp = fopen("image.txt", "r");
    if(fp == NULL) {
        printf("Error reading image file\n");
        exit(1);
    }
    fscanf(fp, "%d %d", &rows, &cols);
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }
    fclose(fp);

    // Flip the image
    flip(image, rows, cols);

    // Change the brightness/contrast of the image
    float brightness = 1.5;
    float contrast = 1.2;
    change_brightness_contrast(image, rows, cols, brightness, contrast);

    // Display the modified image
    printf("Modified Image:\n");
    display_image(image, rows, cols);

    return 0;
}