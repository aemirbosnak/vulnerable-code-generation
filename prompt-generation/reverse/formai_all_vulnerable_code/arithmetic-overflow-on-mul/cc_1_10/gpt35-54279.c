//FormAI DATASET v1.0 Category: Image Classification system ; Style: authentic
// This is a program for Image Classification in C

#include <stdio.h>
#include <stdlib.h>

// Function to read image data from a file
void read_image_data(FILE* image_file, int** image_data, int height, int width) {
    // Allocate memory for image data
    *image_data = (int*)malloc(height * width * sizeof(int));

    // Read image data from file
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(image_file, "%d", &(*image_data)[i * width + j]);
        }
    }
}

// Function to classify the image
int classify_image(int* image_data, int height, int width) {
    int sum = 0;

    // Compute the sum of pixel values in the image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            sum += image_data[i * width + j];
        }
    }

    // If the sum is less than 100, classify the image as "dark"
    // Otherwise, classify the image as "bright"
    if (sum < 100) {
        return 0; // dark image
    } else {
        return 1; // bright image
    }
}

int main() {
    FILE* image_file;
    int* image_data;
    int height, width, classification;

    // Open image file
    image_file = fopen("image_data.txt", "r");
    if (image_file == NULL) {
        printf("Error: Failed to open image file.");
        return 1;
    }

    // Read image dimensions from file
    fscanf(image_file, "%d %d", &height, &width);

    // Read image data from file
    read_image_data(image_file, &image_data, height, width);

    // Close image file
    fclose(image_file);

    // Classify the image
    classification = classify_image(image_data, height, width);

    // Print the classification result
    if (classification == 0) {
        printf("Dark image.");
    } else {
        printf("Bright image.");
    }

    // Free image data memory
    free(image_data);

    return 0;
}