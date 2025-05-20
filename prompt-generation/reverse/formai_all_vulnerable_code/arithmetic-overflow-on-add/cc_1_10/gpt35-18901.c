//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: expert-level
// C program to convert an image to ASCII art

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to determine the intensity of the pixel
char intensity(int r, int g, int b) {
    int avg = (r + g + b) / 3;
    if (avg >= 230) {
        return ' ';
    }
    else if (avg >= 200) {
        return '.';
    }
    else if (avg >= 180) {
        return '*';
    }
    else if (avg >= 160) {
        return ':';
    }
    else if (avg >= 130) {
        return 'o';
    }
    else if (avg >= 100) {
        return '&';
    }
    else if (avg >= 70) {
        return '8';
    }
    else {
        return '@';
    }
}

// Function to convert image to ASCII art
void convertToASCII(char* inputFile, char* outputFile) {
    FILE* in = fopen(inputFile, "rb");
    FILE* out = fopen(outputFile, "w");

    char header[54];
    fread(header, sizeof(char), 54, in);

    // Get the image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Calculate the row padding
    int padding = 4 - (width * sizeof(int)) % 4;

    // Allocate memory for the pixel data
    unsigned char* pixelData = (unsigned char*)malloc(width * height * sizeof(int));

    // Read the pixel data
    fread(pixelData, sizeof(char), width * height * sizeof(int), in);

    // Print the ASCII art representation
    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;
            char i = intensity(pixelData[index], pixelData[index + 1], pixelData[index + 2]);
            fputc(i, out);
        }
        fputc('\n', out);

        // Add padding to the row
        for (int p = 0; p < padding; p++) {
            fputc('\0', out);
        }
    }

    // Free the memory and close the files
    free(pixelData);
    fclose(in);
    fclose(out);
}

// Main function
int main() {
    char inputFile[] = "myimage.bmp";
    char outputFile[] = "asciiart.txt";
    convertToASCII(inputFile, outputFile);
    printf("Image converted to ASCII art!\n");
    return 0;
}