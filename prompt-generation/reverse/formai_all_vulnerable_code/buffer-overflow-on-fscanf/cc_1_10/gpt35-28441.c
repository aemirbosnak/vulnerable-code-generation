//FormAI DATASET v1.0 Category: Image Classification system ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for the number of input images and classes
#define NUM_IMAGES 100
#define NUM_CLASSES 10

// Define a structure for an image
typedef struct Image {
    int id;
    char name[50];
    int class;
    double pixels[32*32];
} Image;

// Define a function to read images from a file
int read_images(char* filename, Image* images) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open %s\n", filename);
        return -1;
    }
    int count = 0;
    while (!feof(file) && count < NUM_IMAGES) {
        Image image;
        fscanf(file, "%d %s %d", &image.id, image.name, &image.class);
        for (int i=0; i<32*32; i++) {
            fscanf(file, "%lf", &image.pixels[i]);
        }
        images[count++] = image;
    }
    fclose(file);
    return count;
}

// Define a function to classify an image
int classify_image(Image* image, double** weights) {
    double scores[NUM_CLASSES];
    for (int i=0; i<NUM_CLASSES; i++) {
        scores[i] = 0.0;
        for (int j=0; j<32*32; j++) {
            scores[i] += image->pixels[j] * weights[i][j];
        }
    }
    int max_idx = 0;
    double max_score = scores[0];
    for (int i=1; i<NUM_CLASSES; i++) {
        if (scores[i] > max_score) {
            max_idx = i;
            max_score = scores[i];
        }
    }
    return max_idx;
}

int main() {

    // Allocate memory for the images
    Image* images = (Image*)malloc(sizeof(Image)*NUM_IMAGES);
    if (!images) {
        printf("Failed to allocate memory for images\n");
        return -1;
    }

    // Read the images from file
    int num_images = read_images("images.txt", images);
    if (num_images < 0) {
        printf("Failed to read images from file\n");
        return -1;
    }

    // Allocate memory for the weights
    double** weights = (double**)malloc(sizeof(double*)*NUM_CLASSES);
    if (!weights) {
        printf("Failed to allocate memory for weights\n");
        return -1;
    }
    for (int i=0; i<NUM_CLASSES; i++) {
        weights[i] = (double*)malloc(sizeof(double)*32*32);
        if (!weights[i]) {
            printf("Failed to allocate memory for weights[%d]\n", i);
            return -1;
        }
    }

    // Initialize weights randomly
    for (int i=0; i<NUM_CLASSES; i++) {
        for (int j=0; j<32*32; j++) {
            weights[i][j] = (double)rand() / RAND_MAX;
        }
    }

    // Test the classifier on the first image
    int class = classify_image(&images[0], weights);
    printf("Image: %s\nActual class: %d\nPredicted class: %d\n", 
           images[0].name, images[0].class, class);

    // Free memory
    for (int i=0; i<NUM_CLASSES; i++) {
        free(weights[i]);
    }
    free(weights);
    free(images);

    return 0;
}