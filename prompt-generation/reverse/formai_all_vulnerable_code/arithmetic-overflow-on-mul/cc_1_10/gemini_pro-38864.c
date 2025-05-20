//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: Ada Lovelace
// Ada Lovelace-inspired C Image Classification System

// Includes necessary headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Defines data structure for an image
typedef struct Image {
    int width, height;
    char *pixels;
} Image;

// Prototypes for functions
Image* loadImage(char *filename);
void freeImage(Image *image);
int classifyImage(Image *image);

// Main function
int main(int argc, char *argv[]) {
    // Checks if the user provided an image file
    if (argc != 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    // Loads the image from the file
    Image *image = loadImage(argv[1]);
    if (image == NULL) {
        printf("Error loading image.\n");
        return 1;
    }

    // Classifies the image
    int class = classifyImage(image);

    // Prints the classification result
    switch (class) {
        case 0: printf("Image is of a cat.\n"); break;
        case 1: printf("Image is of a dog.\n"); break;
        case 2: printf("Image is of a bird.\n"); break;
        default: printf("Image is of an unknown object.\n");
    }

    // Frees the memory allocated for the image
    freeImage(image);

    return 0;
}

// Function to load an image from a file
Image* loadImage(char *filename) {
    // Opens the file for reading
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    // Reads the image header
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    // Allocates memory for the image
    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fclose(file);
        return NULL;
    }

    // Reads the image pixels
    int size = width * height;
    char *pixels = malloc(size * sizeof(char));
    if (pixels == NULL) {
        fclose(file);
        free(image);
        return NULL;
    }

    fread(pixels, sizeof(char), size, file);

    // Closes the file
    fclose(file);

    // Initializes the image structure
    image->width = width;
    image->height = height;
    image->pixels = pixels;

    return image;
}

// Function to free the memory allocated for an image
void freeImage(Image *image) {
    if (image != NULL) {
        free(image->pixels);
        free(image);
    }
}

// Function to classify an image
int classifyImage(Image *image) {
    // Extracts features from the image
    double mean = 0.0;
    double std_dev = 0.0;

    for (int i = 0; i < image->width * image->height; i++) {
        double pixel_value = image->pixels[i];
        mean += pixel_value;
    }
    mean /= image->width * image->height;

    for (int i = 0; i < image->width * image->height; i++) {
        double pixel_value = image->pixels[i];
        std_dev += pow(pixel_value - mean, 2);
    }
    std_dev = sqrt(std_dev / (image->width * image->height));

    // Classifies the image based on the extracted features
    int class;
    if (mean > 128 && std_dev < 50) {
        class = 0; // Cat
    } else if (mean < 128 && std_dev < 50) {
        class = 1; // Dog
    } else {
        class = 2; // Bird
    }

    return class;
}