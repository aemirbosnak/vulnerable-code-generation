//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_IMAGE_SIZE 1000 //maximum size of the image

//function to read image from file
void readImage(char filename[], int image[][MAX_IMAGE_SIZE], int *height, int *width) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error in opening file\n");
        exit(1);
    }
    fscanf(fp, "%d%d", height, width); //read height and width of image
    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            fscanf(fp, "%d", &image[i][j]); //read pixel values
        }
    }
    fclose(fp);
}

//function to write image to file
void writeImage(char filename[], int image[][MAX_IMAGE_SIZE], int height, int width) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error in opening file\n");
        exit(1);
    }
    fprintf(fp, "%d %d\n", height, width); //write height and width of image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(fp, "%d ", image[i][j]); //write pixel values
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

//function to flip image horizontally
void flipHorizontally(int image[][MAX_IMAGE_SIZE], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

//function to adjust brightness of image
void adjustBrightness(int image[][MAX_IMAGE_SIZE], int height, int width, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] += brightness;
            if (image[i][j] < 0) image[i][j] = 0;
            if (image[i][j] > 255) image[i][j] = 255;
        }
    }
}

//function to adjust contrast of image
void adjustContrast(int image[][MAX_IMAGE_SIZE], int height, int width, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = factor * (image[i][j] - 128) + 128;
            if (image[i][j] < 0) image[i][j] = 0;
            if (image[i][j] > 255) image[i][j] = 255;
        }
    }
}

int main() {
    int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
    int height, width;
    readImage("image.txt", image, &height, &width);

    //flip image horizontally
    flipHorizontally(image, height, width);

    //adjust brightness of image
    adjustBrightness(image, height, width, 50);

    //adjust contrast of image
    adjustContrast(image, height, width, 50);

    writeImage("processed_image.txt", image, height, width);

    return 0;
}