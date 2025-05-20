//Code Llama-13B DATASET v1.0 Category: Pixel Art Generator ; Style: detailed
// Pixel Art Generator Example Program

#include <stdio.h>
#include <stdlib.h>

// Struct to hold the dimensions and pixels of the image
struct Image {
    int width;
    int height;
    char** pixels;
};

// Function to allocate memory for the image
void allocate_image(struct Image* image) {
    image->pixels = (char**)malloc(image->height * sizeof(char*));
    for (int i = 0; i < image->height; i++) {
        image->pixels[i] = (char*)malloc(image->width * sizeof(char));
    }
}

// Function to set the pixel at (x, y) to the given color
void set_pixel(struct Image* image, int x, int y, char color) {
    image->pixels[y][x] = color;
}

// Function to print the image to the console
void print_image(struct Image* image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            printf("%c", image->pixels[i][j]);
        }
        printf("\n");
    }
}

// Function to free the memory used by the image
void free_image(struct Image* image) {
    for (int i = 0; i < image->height; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
}

// Main function
int main() {
    // Create a new image with dimensions 10x10
    struct Image image;
    image.width = 10;
    image.height = 10;
    allocate_image(&image);

    // Set the pixel at (5, 5) to the color 'X'
    set_pixel(&image, 5, 5, 'X');

    // Print the image to the console
    print_image(&image);

    // Free the memory used by the image
    free_image(&image);

    return 0;
}