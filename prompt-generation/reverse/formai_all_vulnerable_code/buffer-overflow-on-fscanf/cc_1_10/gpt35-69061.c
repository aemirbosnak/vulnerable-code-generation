//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// function to convert a single pixel in an image to an ASCII character
char convertPixelToChar(int pixelValue) {
    char asciiChar;
    if (pixelValue < 50) {
        asciiChar = '@';
    } else if (pixelValue >= 50 && pixelValue < 100) {
        asciiChar = '#';
    } else if (pixelValue >= 100 && pixelValue < 150) {
        asciiChar = '&';
    } else if (pixelValue >= 150 && pixelValue < 200) {
        asciiChar = '$';
    } else if (pixelValue >= 200 && pixelValue < 250) {
        asciiChar = '*';
    } else {
        asciiChar = ' ';
    }
    return asciiChar;
}

// function to load an image from a file
int** loadImageFromFile(char* filename, int* width, int* height) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fscanf(file, "P2 %d %d 255\n", width, height);

    int** image = malloc(*height * sizeof(int*));
    for (int i = 0; i < *height; i++) {
        image[i] = malloc(*width * sizeof(int));
        for (int j = 0; j < *width; j++) {
            fscanf(file, "%d", &image[i][j]);
        }
    }

    fclose(file);
    return image;
}

// function to convert an image to ASCII art and print it to the console
void convertImageToAsciiArt(int** image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char asciiChar = convertPixelToChar(image[i][j]);
            printf("%c", asciiChar);
        }
        printf("\n");
    }
}

int main() {
    char filename[100];
    int width, height;
    int** image;

    // prompt user for filename and load image from file
    printf("Enter filename of image to convert: ");
    fgets(filename, 100, stdin);
    if (strlen(filename) > 0 && filename[strlen(filename)-1] == '\n') {
        filename[strlen(filename)-1] = '\0';
    }
    image = loadImageFromFile(filename, &width, &height);

    // convert image to ASCII art and print to console
    convertImageToAsciiArt(image, width, height);

    // free memory allocated for image
    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}