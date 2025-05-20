//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80 // Maximum width of ASCII art
#define MAX_HEIGHT 80 // Maximum height of ASCII art
#define MAX_PIXEL_VALUE 255 // Maximum value of pixel in image

char asciiChars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'}; // ASCII characters for the converter

// Function to convert image to ASCII art
void convertToAscii(char* fileName) {
    FILE* fp;
    char pixel[MAX_WIDTH][MAX_HEIGHT]; // 2D array to store pixel values
    int width, height, pixelLength;
    
    fp = fopen(fileName, "rb"); // Read the image file in binary mode
    
    // Check if file is successfully opened or not
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }
    
    // Read the height, width and pixel length of the image
    fscanf(fp, "P5\n%d %d\n%d\n", &width, &height, &pixelLength);
    
    // Check if the image is supported by the program
    if (width > MAX_WIDTH || height > MAX_HEIGHT || pixelLength > MAX_PIXEL_VALUE) {
        printf("Unsupported image file!\n");
        return;
    }
    
    // Store the pixel values
    fread(pixel, sizeof(char), width * height, fp);
    
    fclose(fp); // Close the file
    
    printf("Converted ASCII art:\n\n");
    
    // Convert each pixel value to corresponding ASCII character
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", asciiChars[(int)(pixel[i][j] / ((float)MAX_PIXEL_VALUE / 10))]);
        }
        printf("\n");
    }
}

int main() {
    char fileName[100];
    
    printf("Enter the name of the image file: ");
    scanf("%s", fileName);
    
    convertToAscii(fileName); // Convert the image to ASCII art
    
    return 0;
}