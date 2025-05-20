//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Function to get the ASCII character for a given intensity
char intensityToAscii(char intensity) {
    const char asciiChars[] = " .,:;ox%#@";
    int numChars = strlen(asciiChars);
    int index = ((intensity * 1.0) / 255) * (numChars - 1);
    return asciiChars[index];
}

// Function to read in an image file and convert to ASCII art
void convertImageToAscii(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // Read in the header information
    char header[3];
    fscanf(file, "%s\n", header);
    if (strcmp(header, "P3") != 0) {
        printf("Invalid image format.\n");
        return;
    }

    // Read in the width and height
    int width, height;
    fscanf(file, "%d %d\n", &width, &height);
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Image too large.\n");
        return;
    }

    // Read in the maximum intensity value
    int maxIntensity;
    fscanf(file, "%d\n", &maxIntensity);

    // Create a buffer to store the pixel intensities
    int pixels[height][width][3];

    // Read in the pixel intensities
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(file, "%d %d %d ", &pixels[i][j][0], &pixels[i][j][1], &pixels[i][j][2]);
        }
    }

    // Close the image file
    fclose(file);

    // Convert the pixel intensities to ASCII characters
    char asciiArt[MAX_HEIGHT][MAX_WIDTH];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char rIntensity = pixels[i][j][0];
            char gIntensity = pixels[i][j][1];
            char bIntensity = pixels[i][j][2];
            char intensity = (rIntensity + gIntensity + bIntensity) / 3;
            asciiArt[i][j] = intensityToAscii(intensity);
        }
    }

    // Print out the ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", asciiArt[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the Romeo and Juliet Image to ASCII Art converter!\n");
    printf("Please enter the filename of the image you would like to convert: ");
    char filename[100];
    scanf("%s", filename);

    convertImageToAscii(filename);

    printf("\n");
    printf("Romeo: O, she doth teach the torches to burn bright!\n");
    printf("Juliet: It seems she hangs upon the cheek of night\n");
    printf("        As a rich jewel in an Ethiope’s ear—\n");
    printf("        Beauty too rich for use, for earth too dear.\n");
    printf("Romeo: Did my heart love till now? Forswear it, sight,\n");
    printf("        For I ne’er saw true beauty till this night.\n");

    return 0;
}