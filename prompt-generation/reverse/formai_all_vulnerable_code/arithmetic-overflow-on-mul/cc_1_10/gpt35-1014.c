//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80       // Width of ASCII art
#define HEIGHT 60      // Height of ASCII art
#define MAX_PIXEL 255  // Maximum pixel value

// Function to load image from file
int *load_image(char *filename, int *w, int *h){
    FILE *f = fopen(filename, "rb");
    if(f == NULL){
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    // Read image header
    char header[64];
    fgets(header, 64, f);

    // Read image dimensions
    fscanf(f, "%d %d\n", w, h);

    // Allocate memory for image
    int *image = (int *)malloc((*w) * (*h) * sizeof(int));

    // Read pixel values
    int i;
    for(i=0; i<(*w) * (*h); i++){
        int pixel;
        fscanf(f, "%d", &pixel);
        image[i] = pixel;
    }

    // Close file and return image
    fclose(f);
    return image;
}

// Function to convert image to ASCII art
void convert_to_ascii(int *image, int w, int h){
    int i, j, index;
    float scale_factor = (float)MAX_PIXEL / (float)WIDTH;

    // Loop through each row of the image
    for(i=0; i<h; i++){
        // Loop through each column of the image
        for(j=0; j<w; j++){
            // Calculate index of current pixel
            index = i * w + j;

            // Calculate ASCII character based on pixel value
            int value = image[index] / scale_factor;
            char character = ' ' + (value * 12 / WIDTH);

            // Print ASCII character to console
            printf("%c", character);
        }

        // Print newline character to console
        printf("\n");
    }
}

// Main function
int main(int argc, char **argv){
    char *filename;
    int *image, w, h;

    // Check that filename was provided
    if(argc < 2){
        printf("Error: No filename specified\n");
        exit(1);
    }

    // Load image from file
    filename = argv[1];
    image = load_image(filename, &w, &h);

    // Convert image to ASCII art and print to console
    convert_to_ascii(image, w, h);

    // Free memory allocated for image
    free(image);
    return 0;
}