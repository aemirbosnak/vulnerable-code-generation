//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Global variables
int width, height, max_value;

// Function to flip the image horizontally
void flipHorizontal(unsigned char image[][width]) {
    // Iterate through each row of the image
    for(int i=0; i<height; i++) {
        // Swap elements of the row from start and end
        for(int j=0; j<width/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
}

// Function to change brightness of the image
void changeBrightness(unsigned char image[][width], int adjustment) {
    // Iterate through each pixel of the image
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            // Add the adjustment value to the pixel value
            int new_value = image[i][j] + adjustment;
            // Ensure that the pixel value stays within 0 to max_value
            if(new_value < 0)
                new_value = 0;
            if(new_value > max_value)
                new_value = max_value;
            image[i][j] = new_value;
        }
    }
}

// Function to change contrast of the image
void changeContrast(unsigned char image[][width], float adjustment) {
    float factor = (259.0 * (adjustment + 255.0)) / (255.0 * (259.0 - adjustment));
    // Iterate through each pixel of the image
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int new_value = factor * (image[i][j] - 128) + 128;
            // Ensure that the pixel value stays within 0 to max_value
            if(new_value < 0)
                new_value = 0;
            if(new_value > max_value)
                new_value = max_value;
            image[i][j] = new_value;
        }
    }
}

int main() {
    // Read in the image file
    FILE *fp = fopen("image.pgm", "rb");
    if(fp == NULL) {
        printf("Error: Unable to read file\n");
        return 1;
    }
    char magic_number[3];
    fscanf(fp, "%s", magic_number);
    if(magic_number[0] != 'P' || magic_number[1] != '5') {
        printf("Error: Invalid file format\n");
        return 1;
    }
    fscanf(fp, "%d %d %d\n", &width, &height, &max_value);
    unsigned char image[height][width];
    fread(image, sizeof(char), width*height, fp);
    fclose(fp);
    
    // Flip image horizontally
    flipHorizontal(image);
    
    // Change brightness
    changeBrightness(image, 50);
    
    // Change contrast
    changeContrast(image, 30.0);
    
    // Write out the processed image to a new file
    fp = fopen("processed_image.pgm", "wb");
    if(fp == NULL) {
        printf("Error: Unable to write file\n");
        return 1;
    }
    fprintf(fp, "P5\n%d %d\n%d\n", width, height, max_value);
    fwrite(image, sizeof(char), width*height, fp);
    fclose(fp);
    
    printf("Image processing completed!\n");
    return 0;
}