//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

// Define constant ASCII characters used in the conversion
#define ASCII_CHARS "@B%8WM#*oahkbdpwmZO0QCJYXzcvnxrjft\/|()1{}[]?-_+~i!lI;:,\"^`'. "

/* Function to calculate the luminance of a pixel */
int calculateLuminance(int red, int green, int blue) {
    return (int)(0.2126 * red + 0.7152 * green + 0.0722 * blue);
}

/* Main function for the image to ASCII conversion program */
int main(int argc, char *argv[]) {

    // Read in the argument for the image file path
    char *filepath = argv[1];
    FILE *file;
    int width, height, maxColor, currentLuminance;
    unsigned char pixel[3];

    // Attempt to open the image file
    if ((file = fopen(filepath, "rb")) == NULL) {
        printf("Could not open file");
        exit(1);
    }

    // Read the image header information
    fscanf(file, "P6\n%d %d\n%d\n", &width, &height, &maxColor);

    // Output the ASCII art image to the console
    printf("\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Read the pixel data for each pixel in the image
            fread(pixel, sizeof(unsigned char), 3, file);
            // Calculate the luminance of the current pixel
            currentLuminance = calculateLuminance(pixel[0], pixel[1], pixel[2]);
            // Determine the corresponding ASCII character for the current pixel's luminance
            int index = (int)((currentLuminance * (sizeof(ASCII_CHARS) / sizeof(char))) / 255.0);
            printf("%c", ASCII_CHARS[index]);
        }
        printf("\n");
    }

    // Close the image file
    fclose(file);

    return 0;
}