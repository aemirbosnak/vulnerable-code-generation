//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Function to flip the image horizontally
void flipHorizontal(int rows, int cols, unsigned char image[rows][cols]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols/2; j++) {
            unsigned char temp = image[i][j];
            image[i][j] = image[i][cols-1-j];
            image[i][cols-1-j] = temp;
        }
    }
}

// Function to adjust the brightness of the image
void adjustBrightness(int rows, int cols, unsigned char image[rows][cols], int brightness) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int pixel = (int)image[i][j] + brightness;
            if(pixel < 0) {
                image[i][j] = 0;
            } else if (pixel > 255) {
                image[i][j] = 255;
            } else {
                image[i][j] = (unsigned char)pixel;
            }
        }
    }
}

// Function to adjust the contrast of the image
void adjustContrast(int rows, int cols, unsigned char image[rows][cols], float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int pixel = (int) (factor * (image[i][j] - 128) + 128);
            if(pixel < 0) {
                image[i][j] = 0;
            } else if (pixel > 255) {
                image[i][j] = 255;
            } else {
                image[i][j] = (unsigned char)pixel;
            }
        }
    }
}

int main() {
    FILE *file;
    char inputFileName[] = "input_image.pgm";
    char outputFileName[] = "output_image.pgm";
    char magicNumber[3];
    int imageWidth, imageHeight, maxValue;
    int brightness, contrast; // adjust the brightness and contrast

    file = fopen(inputFileName, "r");
    if(file == NULL) {
        printf("Error: Unable to open the file!\n");
        exit(1);
    }

    fscanf(file, "%s %d %d %d", magicNumber, &imageWidth, &imageHeight, &maxValue);

    unsigned char image[imageHeight][imageWidth];

    for(int i = 0; i < imageHeight; i++) {
        for(int j = 0; j < imageWidth; j++) {
            fscanf(file, "%hhu", &image[i][j]);
        }
    }

    fclose(file);

    // Flip the image horizontally
    flipHorizontal(imageHeight, imageWidth, image);

    // Adjust the brightness of the image
    brightness = -50;
    adjustBrightness(imageHeight, imageWidth, image, brightness);

    // Adjust the contrast of the image
    contrast = 50;
    adjustContrast(imageHeight, imageWidth, image, contrast);

    // Write the output image to a file
    file = fopen(outputFileName, "w");
    if(file == NULL) {
        printf("Error: Unable to open the file!\n");
        exit(1);
    }

    fprintf(file, "%s\n%d %d\n%d\n", magicNumber, imageWidth, imageHeight, maxValue);

    for(int i = 0; i < imageHeight; i++) {
        for(int j = 0; j < imageWidth; j++) {
            fprintf(file, "%hhu ", image[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    
    return 0;
}