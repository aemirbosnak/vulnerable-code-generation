//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define constants for dataset size
#define NUM_CLASSES 3
#define MAX_IMAGES 100
#define IMAGE_SIZE 256

// Structure to hold image data
typedef struct {
    int label; // Class label
    unsigned char pixels[IMAGE_SIZE][IMAGE_SIZE]; // Image pixels
} Image;

// Function prototypes
void load_images(Image images[], const char* filepath, int* count);
double calculate_distance(unsigned char img1[IMAGE_SIZE][IMAGE_SIZE], unsigned char img2[IMAGE_SIZE][IMAGE_SIZE]);
int classify_image(Image images[], int count, unsigned char query_image[IMAGE_SIZE][IMAGE_SIZE]);

int main() {
    Image images[MAX_IMAGES];
    int image_count = 0;
    
    // Load images from file
    load_images(images, "image_dataset.txt", &image_count);
    
    // Placeholder for loading a query image
    unsigned char query_image[IMAGE_SIZE][IMAGE_SIZE] = {0}; // Assume this is filled with data
    
    int predicted_class = classify_image(images, image_count, query_image);
    printf("Predicted Class: %d\n", predicted_class);
    
    return 0;
}

// Load images from a file
void load_images(Image images[], const char* filepath, int* count) {
    FILE* file = fopen(filepath, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filepath);
        return;
    }

    while (*count < MAX_IMAGES && fscanf(file, "%d", &images[*count].label) == 1) {
        for (int i = 0; i < IMAGE_SIZE; i++) {
            for (int j = 0; j < IMAGE_SIZE; j++) {
                // Load pixel value (for simplicity, we just use random values)
                images[*count].pixels[i][j] = rand() % 256; // Simulated pixel data
            }
        }
        (*count)++;
    }

    fclose(file);
}

// Calculate the Euclidean distance between two images
double calculate_distance(unsigned char img1[IMAGE_SIZE][IMAGE_SIZE], unsigned char img2[IMAGE_SIZE][IMAGE_SIZE]) {
    double sum = 0.0;
    for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            sum += (img1[i][j] - img2[i][j]) * (img1[i][j] - img2[i][j]);
        }
    }
    return sqrt(sum);
}

// Classify an image using the nearest neighbor algorithm
int classify_image(Image images[], int count, unsigned char query_image[IMAGE_SIZE][IMAGE_SIZE]) {
    int nearest_label = -1;
    double min_distance = INFINITY;

    for (int i = 0; i < count; i++) {
        double distance = calculate_distance(images[i].pixels, query_image);
        if (distance < min_distance) {
            min_distance = distance;
            nearest_label = images[i].label;
        }
    }

    return nearest_label;
}