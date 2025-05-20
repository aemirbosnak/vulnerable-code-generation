//GEMINI-pro DATASET v1.0 Category: Image Classification system ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our curious image classifier!
typedef struct {
    char *name;
    int num_pixels;
    int *pixels;
} Image;

// Load an image from a file.
Image *load_image(const char *filename) {
    Image *image = malloc(sizeof(Image));
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error loading image: %s\n", filename);
        return NULL;
    }
    fscanf(file, "%s %d\n", image->name, &image->num_pixels);
    image->pixels = malloc(sizeof(int) * image->num_pixels);
    for (int i = 0; i < image->num_pixels; i++) {
        fscanf(file, "%d ", &image->pixels[i]);
    }
    fclose(file);
    return image;
}

// Free the memory allocated for an image.
void free_image(Image *image) {
    free(image->name);
    free(image->pixels);
    free(image);
}

// Classify an image.
int classify_image(Image *image) {
    // Here's where the magic happens!
    int class = 0;
    for (int i = 0; i < image->num_pixels; i++) {
        class += image->pixels[i];
    }
    class %= 10;
    return class;
}

// Print the classification results.
void print_results(Image *image, int class) {
    printf("Image: %s\n", image->name);
    printf("Class: %d\n", class);
}

// The main function.
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    // Load the image.
    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Classify the image.
    int class = classify_image(image);

    // Print the classification results.
    print_results(image, class);

    // Free the memory allocated for the image.
    free_image(image);

    return 0;
}