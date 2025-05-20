//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 40

/*
Function to convert an image to ASCII art
Takes input as an array of integers where each integer represents a pixel's intensity value
Returns a string of ASCII characters representing the image
*/
char* convertToAsciiArt(int* pixels, int width, int height) {
    char* asciiArt = malloc(MAX_WIDTH * MAX_HEIGHT * sizeof(char));  // allocate memory for ASCII art string
    int asciiArtIndex = 0;  // keep track of index in ASCII art string
    double intensityRange = 255.0 / 70;  // calculate range of pixel values for each ASCII character
    
    // loop through each pixel in the image, convert to ASCII character and append to ASCII art string
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int intensity = pixels[i * width + j];
            char asciiChar;
            if (intensity < intensityRange) {
                asciiChar = ' ';
            } else if (intensity < intensityRange * 2) {
                asciiChar = '.';
            } else if (intensity < intensityRange * 3) {
                asciiChar = ':';
            } else if (intensity < intensityRange * 4) {
                asciiChar = '-';
            } else if (intensity < intensityRange * 5) {
                asciiChar = '=';
            } else if (intensity < intensityRange * 6) {
                asciiChar = '+';
            } else if (intensity < intensityRange * 7) {
                asciiChar = '*';
            } else if (intensity < intensityRange * 8) {
                asciiChar = '#';
            } else {
                asciiChar = '@';
            }
            asciiArt[asciiArtIndex++] = asciiChar;
        }
        asciiArt[asciiArtIndex++] = '\n';  // append newline character at end of row
    }
    asciiArt[asciiArtIndex] = '\0';  // append null character at end of string
    return asciiArt;
}

int main() {
    // code to read image file and store pixel values in an array
    FILE* imageFile = fopen("image.txt", "r");  // assume image is stored in a text file
    int width, height;
    fscanf(imageFile, "%d %d", &width, &height);
    int* pixels = malloc(width * height * sizeof(int));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int intensity;
            fscanf(imageFile, "%d", &intensity);
            pixels[i * width + j] = intensity;
        }
    }
    
    // convert image to ASCII art
    char* asciiArt = convertToAsciiArt(pixels, width, height);
    printf("%s\n", asciiArt);
    
    // free memory allocated for arrays
    free(pixels);
    free(asciiArt);
    return 0;
}