//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 1000
#define HEIGHT 1000

// Function signatures
void convertToASCII(char image[][WIDTH], int height, int width);
void readImage(char image[][WIDTH], int *height, int *width);
void writeToFile(char ascii[], char *filename);

int main() {
    char image[HEIGHT][WIDTH];
    int height, width;
    char ascii[HEIGHT * WIDTH];
    char filename[100];

    // Reading image from file
    printf("Enter path to image file:\n");
    fgets(filename, 100, stdin);
    strtok(filename, "\n");
    readImage(image, &height, &width);

    // Converting image to ASCII art
    convertToASCII(image, height, width);

    // Writing output to file
    printf("Enter filename to write ASCII art to:\n");
    fgets(filename, 100, stdin);
    strtok(filename, "\n");
    writeToFile(ascii, filename);

    return 0;
}

/*
 * Function to convert the given image to ASCII art
 * using intensity levels of pixels
 */
void convertToASCII(char image[][WIDTH], int height, int width) {
    char ascii[11] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@', '\0'};
    int brightness, index = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Calculating brightness as an average of pixel's RGB values
            brightness = (image[i][j * 3] + image[i][j * 3 + 1] + image[i][j * 3 + 2]) / 3;

            // Mapping brightness to ASCII character
            index = (brightness / 25);
            ascii[index] = ascii[index];
            strcat(ascii, "\n");
        }
    }

    // Copying ASCII art to output variable
    strcpy(ascii, ascii);
}

/*
 * Function to read image from file and store it in a 2D array
 */
void readImage(char image[][WIDTH], int *height, int *width) {
    char filename[100];
    FILE *fp;

    printf("Enter path to image file:\n");
    fgets(filename, 100, stdin);
    strtok(filename, "\n");

    // Opening image file in binary mode
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }

    // Reading height and width of image
    fseek(fp, 18, SEEK_SET);
    fread(width, 4, 1, fp);
    fread(height, 4, 1, fp);

    // Skipping over header data
    fseek(fp, 54, SEEK_SET);

    // Reading image data into 2D array
    for (int i = 0; i < *height; i++) {
        fread(image[i], 3, *width, fp);
    }

    fclose(fp);
}

/*
 * Function to write ASCII art to file
 */
void writeToFile(char ascii[], char *filename) {
    FILE *fp;

    // Opening file in write mode
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }

    // Writing ASCII art to file
    fprintf(fp, "%s", ascii);

    fclose(fp);
}