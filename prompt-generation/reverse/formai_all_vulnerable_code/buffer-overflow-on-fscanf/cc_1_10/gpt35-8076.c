//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define width and height of image
#define WIDTH 50
#define HEIGHT 25

// Declare function prototypes
void loadImage(char* filename, char image[][WIDTH]);
void printASCII(char image[][WIDTH]);

int main(int argc, char** argv) {

    // Check for correct number of arguments
    if (argc != 2) {
        printf("Please provide a filename as an argument.\n");
        return 1;
    }

    // Define 2D array to hold image
    char image[HEIGHT][WIDTH];

    // Load image
    loadImage(argv[1], image);

    // Convert image to ASCII art and print to console
    printASCII(image);

    return 0;
}

void loadImage(char* filename, char image[][WIDTH]) {

    // Open file for reading
    FILE* file = fopen(filename, "r");

    // Check if file was opened successfully
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Read image into 2D array
    for (int i = 0; i < HEIGHT; i++) {
        fscanf(file, "%s", image[i]);
    }

    // Close file
    fclose(file);
}

void printASCII(char image[][WIDTH]) {

    // Define ASCII characters to represent pixels
    char asciiChars[] = {' ', '.', '-', '+', '*', 'X', '@'};

    // Determine the range of pixel values
    int min = 255;
    int max = 0;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int pixel = (int)image[i][j];
            if (pixel < min) {
                min = pixel;
            }
            if (pixel > max) {
                max = pixel;
            }
        }
    }

    // Map pixel values to ASCII characters and print to console
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int pixel = (int)image[i][j];
            int index = (int)(((double)pixel - (double)min) / ((double)max - (double)min) * 6.0);
            printf("%c", asciiChars[index]);
        }
        printf("\n");
    }
}