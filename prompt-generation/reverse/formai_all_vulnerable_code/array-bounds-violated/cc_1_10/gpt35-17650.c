//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024
#define MAX_LINE_LENGTH 80

char asciiChars[] = {'@','%','#','*','+', '=', '-', ':', '.', ' '};
// Array of characters to represent the image.

int getGrayScaleValue(int r, int g, int b) {
    return (r + g + b) / 3; // returns the grayscale value of an RGB color.
}

int getAsciiCharacter(int grayValue) {
    int range = 255 / (sizeof(asciiChars)/sizeof(asciiChars[0]));
    // Determine the range of grayValues per ascii character.

    return asciiChars[grayValue/range];
    // return the ascii character based on the gray scale value.
}

int main(int argc, char *argv[]) {
    FILE *imageFile = NULL;
    char line[MAX_LINE_LENGTH];
    char asciiImage[MAX_IMAGE_SIZE][MAX_LINE_LENGTH];
    int rowCount = 0;
    // Declare necessary variables.

    if(argc != 2) {
        printf("Please provide the image file path.\n");
        return 1;
    }
    // Check if the correct number of arguments is provided.

    imageFile = fopen(argv[1],"r");
    if(imageFile == NULL) {
        printf("Unable to open the image file.\n");
        return 1;
    }
    // Try to open the image file.

    while(fgets(line,MAX_LINE_LENGTH,imageFile)) {
        for(int i=0;i<(int)strlen(line);i+=3) {
            int r = (unsigned char)line[i];
            int g = (unsigned char)line[i+1];
            int b = (unsigned char)line[i+2];
            // Get RGB values of a pixel.

            int grayValue = getGrayScaleValue(r, g, b);
            asciiImage[rowCount][i/3] = getAsciiCharacter(grayValue);
            // Convert the pixel to ascii char and store in the asciiImage array.
        }
        rowCount++;
        // Process the next row of pixels.
    }

    printf("\nThe resulting ASCII art:\n");
    for(int i=0;i<rowCount;i++) {
        printf("%s\n", asciiImage[i]);
    }
    // Print the resulted ASCII art.

    fclose(imageFile);
    return 0;
}