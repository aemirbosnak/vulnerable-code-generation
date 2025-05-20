//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to flip an image vertically
void flip_vertical(int img[][MAX_SIZE], int rows, int cols) {
    int temp;
    for (int i = 0; i < rows/2; i++) {
        for (int j = 0; j < cols; j++) {
            temp = img[i][j];
            img[i][j] = img[rows-i-1][j];
            img[rows-i-1][j] = temp;
        }
    }
}

// Function to flip an image horizontally
void flip_horizontal(int img[][MAX_SIZE], int rows, int cols) {
    int temp;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols/2; j++) {
            temp = img[i][j];
            img[i][j] = img[i][cols-j-1];
            img[i][cols-j-1] = temp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(int img[][MAX_SIZE], int rows, int cols, int brightness) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            img[i][j] += brightness;
            if (img[i][j] > 255) img[i][j] = 255;
            if (img[i][j] < 0) img[i][j] = 0;
        }
    }
}

// Function to change the contrast of an image
void change_contrast(int img[][MAX_SIZE], int rows, int cols, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            img[i][j] = (int)(factor * (img[i][j] - 128) + 128);
            if (img[i][j] > 255) img[i][j] = 255;
            if (img[i][j] < 0) img[i][j] = 0;
        }
    }
}

int main() {
    // Read input image from file
    FILE* fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    int rows, cols, img[MAX_SIZE][MAX_SIZE];
    fscanf(fp, "%d %d", &rows, &cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(fp, "%d", &img[i][j]);
        }
    }
    fclose(fp);

    // Flip image vertically and save to file
    flip_vertical(img, rows, cols);
    fp = fopen("output_vertical.txt", "w");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    fprintf(fp, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(fp, "%d ", img[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    // Flip image horizontally and save to file
    flip_horizontal(img, rows, cols);
    fp = fopen("output_horizontal.txt", "w");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    fprintf(fp, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(fp, "%d ", img[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    // Change brightness by 50 and save to file
    change_brightness(img, rows, cols, 50);
    fp = fopen("output_brightness.txt", "w");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    fprintf(fp, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(fp, "%d ", img[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    // Change contrast by a factor of 1.5 and save to file
    change_contrast(img, rows, cols, 1.5);
    fp = fopen("output_contrast.txt", "w");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    fprintf(fp, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(fp, "%d ", img[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    return 0;
}