//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the width and height of the ASCII art
#define WIDTH 80
#define HEIGHT 60

void convertToAscii(char *filename) {
    // Open the specified file
    FILE *file = fopen(filename, "rb");

    // Check if the file exists
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Allocate memory for the image buffer
    unsigned char *image = (unsigned char*) malloc(WIDTH * HEIGHT);

    // Check if memory allocation was successful
    if (image == NULL) {
        printf("Error allocating memory for image.\n");
        return;
    }

    // Read in the image data
    fread(image, sizeof(unsigned char), WIDTH * HEIGHT, file);

    // Close the file
    fclose(file);

    // Print out the ASCII art
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // Determine the character to print
            char c;
            int pixel_value = image[i * WIDTH + j];
            if (pixel_value < 32) {
                c = ' ';
            } else if (pixel_value < 64) {
                c = '.';
            } else if (pixel_value < 96) {
                c = '*';
            } else if (pixel_value < 128) {
                c = ':';
            } else if (pixel_value < 160) {
                c = 'o';
            } else if (pixel_value < 192) {
                c = '&';
            } else if (pixel_value < 224) {
                c = '8';
            } else {
                c = '@';
            }

            // Print the character
            printf("%c", c);
        }
        printf("\n");
    }

    // Free the image buffer
    free(image);
}

int main() {
    // Get the filename from the user
    char filename[80];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    // Convert the image to ASCII art
    convertToAscii(filename);

    return 0;
}