//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Function to get grayscale value of a pixel
int getGrayScale(int R, int G, int B) {
    int gray = 0.2126*R + 0.7152*G + 0.0722*B;
    return gray;
}

// Recursive function to convert image to ASCII art
void convertToAscii(char *asciiChars, int asciiCount, int width, int height, int x, int y, int grayVals[height][width]) {
    // Base case: if we have reached the end of the row
    if (x >= width) {
        printf("\n");
        y++;
        x = 0;
    }

    // Base case: if we have reached the end of the image
    if (y >= height) return;

    // Get the grayscale value for this pixel
    int gray = grayVals[y][x];

    // Determine the character for this pixel based on grayscale value
    int charIndex = (int) round(gray / (255.0 / (asciiCount-1)));

    // Print the character for this pixel
    printf("%c", asciiChars[charIndex]);

    // Recursive call for next pixel
    convertToAscii(asciiChars, asciiCount, width, height, x+1, y, grayVals);
}

int main() {
    // Get input image filename from user
    char filename[100];
    printf("Enter input image filename: ");
    scanf("%s", filename);

    // Open the input file
    FILE *inputFile = fopen(filename, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Check the file header to make sure it's a BMP
    char header[54];
    size_t bytesRead = fread(header, sizeof(char), 54, inputFile);
    if (bytesRead != 54 || header[0] != 'B' || header[1] != 'M') {
        printf("Error: Input file is not a BMP\n");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    // Get image width and height from header
    int width = *(int*) &header[18];
    int height = *(int*) &header[22];

    // Allocate memory for pixel array
    unsigned char *pixelArray = (unsigned char*) malloc(width*height*3*sizeof(unsigned char));
    if (pixelArray == NULL) {
        printf("Error: Could not allocate memory for pixel array\n");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    // Read the pixel array from the input file
    fseek(inputFile, *(int*) &header[10], SEEK_SET);
    bytesRead = fread(pixelArray, sizeof(unsigned char), width*height*3, inputFile);
    if (bytesRead != width*height*3) {
        printf("Error: Failed to read pixel data from input file\n");
        fclose(inputFile);
        free(pixelArray);
        exit(EXIT_FAILURE);
    }

    // Close the input file
    fclose(inputFile);

    // Allocate memory for 2D grayscale value array
    int **grayVals = (int**) malloc(height*sizeof(int*));
    for (int i = 0; i < height; i++) {
        grayVals[i] = (int*) malloc(width*sizeof(int));
        if (grayVals[i] == NULL) {
            printf("Error: Could not allocate memory for grayVals[%d]\n", i);
            for (int j = 0; j < i; j++) {
                free(grayVals[j]);
            }
            free(grayVals);
            free(pixelArray);
            exit(EXIT_FAILURE);
        }
    }

    // Convert the pixel array to grayscale values
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int R = (int) pixelArray[(y*width+x)*3];
            int G = (int) pixelArray[(y*width+x)*3+1];
            int B = (int) pixelArray[(y*width+x)*3+2];
            grayVals[y][x] = getGrayScale(R, G, B);
        }
    }

    // Define the ASCII characters to use
    char asciiChars[] = " .:-=+*#%@";
    int asciiCount = strlen(asciiChars);

    // Start the recursive conversion process
    convertToAscii(asciiChars, asciiCount, width, height, 0, 0, grayVals);

    // Free memory allocated for arrays
    for (int i = 0; i < height; i++) {
        free(grayVals[i]);
    }
    free(grayVals);
    free(pixelArray);

    return EXIT_SUCCESS;
}