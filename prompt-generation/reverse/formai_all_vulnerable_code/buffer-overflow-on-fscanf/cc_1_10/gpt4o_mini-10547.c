//GPT-4o-mini DATASET v1.0 Category: Image Classification system ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_SIZE 16   // 4x4 image for simplicity
#define NUM_CLASSES 3   // Three classes for classification
#define NUM_TRAIN_IMAGES 6 // 6 training images
#define NUM_TEST_IMAGES 2   // 2 testing images

// Structure to hold image data
typedef struct {
    int pixels[IMAGE_SIZE];
    int label; // 0: Class A, 1: Class B, 2: Class C
} Image;

// Forward declaration
void loadImages(Image* images, const char* directory, int numImages);
int classifyImage(int* pixels);
void printClass(int classIndex);

int main() {
    Image trainImages[NUM_TRAIN_IMAGES];
    Image testImages[NUM_TEST_IMAGES];

    // Load training and testing images
    loadImages(trainImages, "train_images/", NUM_TRAIN_IMAGES);
    loadImages(testImages, "test_images/", NUM_TEST_IMAGES);

    // Classify test images
    for (int i = 0; i < NUM_TEST_IMAGES; i++) {
        printf("Classifying Test Image %d:\n", i + 1);
        int predictedClass = classifyImage(testImages[i].pixels);
        printClass(predictedClass);
        printf("\n");
    }

    return 0;
}

// Load images from the specified directory into the images array
void loadImages(Image* images, const char* directory, int numImages) {
    char filepath[100];
    
    for (int i = 0; i < numImages; i++) {
        snprintf(filepath, sizeof(filepath), "%simage%d.txt", directory, i + 1);
        FILE* file = fopen(filepath, "r");
        if (file == NULL) {
            fprintf(stderr, "Could not open image file: %s\n", filepath);
            exit(1);
        }

        // Read the pixel data
        for (int j = 0; j < IMAGE_SIZE; j++) {
            fscanf(file, "%d", &images[i].pixels[j]);
        }
        fclose(file);

        // Assign class based on the index (for demonstration purposes)
        images[i].label = i % NUM_CLASSES;
    }
}

// A simple classification function based on the pixel data
int classifyImage(int* pixels) {
    // Simple logic based on sum of pixel intensities
    int sum = 0;
    for (int i = 0; i < IMAGE_SIZE; i++) {
        sum += pixels[i];
    }

    // Basic decision boundary for classification
    if (sum < 40) {
        return 0; // Class A
    } else if (sum < 80) {
        return 1; // Class B
    } else {
        return 2; // Class C
    }
}

// Print class label based on index
void printClass(int classIndex) {
    switch (classIndex) {
        case 0:
            printf("Predicted Class: A");
            break;
        case 1:
            printf("Predicted Class: B");
            break;
        case 2:
            printf("Predicted Class: C");
            break;
        default:
            printf("Unknown Class");
            break;
    }
}