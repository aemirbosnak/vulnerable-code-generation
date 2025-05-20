//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 300
#define MAX_HEIGHT 300
#define ASCII_ART_SCALE_FACTOR 4
#define ASCII_ART_CHARACTERS "@#S%?*+;:,. "

// Function to convert an image to ASCII art
void convertImageToASCII(char *imageFilename)
{
    // Open the image file in binary mode
    FILE *imageFile = fopen(imageFilename, "rb");
    
    // Check if the file could be opened
    if (!imageFile)
    {
        printf("Error: Could not open image file \"%s\"\n", imageFilename);
        return;
    }
    
    // Get the image dimensions by reading the header information
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, imageFile);
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int bitDepth = *(int *)&header[28];
    
    // Check if the image format is valid
    if (memcmp(&header[0], "BM", 2) || bitDepth != 24)
    {
        printf("Error: Invalid image format for \"%s\"\n", imageFilename);
        fclose(imageFile);
        return;
    }
    
    // Calculate the scaled dimensions
    int scaledWidth = width / ASCII_ART_SCALE_FACTOR;
    int scaledHeight = height / ASCII_ART_SCALE_FACTOR;
    
    // Read the pixel data
    unsigned char pixelData[height * width * 3];
    fread(pixelData, sizeof(unsigned char), height * width * 3, imageFile);
    fclose(imageFile);
    
    // Allocate memory for the scaled pixel data
    unsigned char scaledPixelData[scaledHeight][scaledWidth];
    
    // Loop through each pixel and calculate the scaled value
    for (int y = 0; y < height; y += ASCII_ART_SCALE_FACTOR)
    {
        for (int x = 0; x < width; x += ASCII_ART_SCALE_FACTOR)
        {
            // Calculate the index of the current pixel in the pixel data array
            int pixelIndex = (y * width + x) * 3;
            
            // Calculate the scaled index based on the current pixel index
            int scaledIndex = ((y / ASCII_ART_SCALE_FACTOR) * scaledWidth) + (x / ASCII_ART_SCALE_FACTOR);
            
            // Get the RGB values of the current pixel
            unsigned char red = pixelData[pixelIndex + 2];
            unsigned char green = pixelData[pixelIndex + 1];
            unsigned char blue = pixelData[pixelIndex];
            
            // Calculate the grayscale value of the current pixel using luminosity method
            int grayscaleValue = (int)(0.21 * red + 0.72 * green + 0.07 * blue);
            
            // Scale the grayscale value to fit into the range of characters
            int scaledGrayscaleValue = grayscaleValue / 26;
            
            // Store the scaled grayscale value in the scaled pixel data array
            scaledPixelData[y / ASCII_ART_SCALE_FACTOR][x / ASCII_ART_SCALE_FACTOR] = scaledGrayscaleValue;
        }
    }
    
    // Open a new file to write the ASCII art
    char asciiFilename[100];
    sprintf(asciiFilename, "%s.txt", imageFilename);
    FILE *asciiFile = fopen(asciiFilename, "w");
    
    // Check if the file could be created
    if (!asciiFile)
    {
        printf("Error: Could not create ASCII file for \"%s\"\n", imageFilename);
        return;
    }
    
    // Loop through each row of the scaled pixel data
    for (int y = 0; y < scaledHeight; y++)
    {
        // Loop through each column of the scaled pixel data
        for (int x = 0; x < scaledWidth; x++)
        {
            // Get the scaled grayscale value of the current pixel
            int scaledGrayscaleValue = scaledPixelData[y][x];
            
            // Write the corresponding character to the ASCII file
            fputc(ASCII_ART_CHARACTERS[scaledGrayscaleValue], asciiFile);
        }
        
        // Move to the next line in the ASCII file
        fputc('\n', asciiFile);
    }
    
    // Close the ASCII file
    fclose(asciiFile);
    
    printf("ASCII art file \"%s\" created for \"%s\"\n", asciiFilename, imageFilename);
}

int main()
{
    // Convert the sample image to ASCII art
    convertImageToASCII("sample_image.bmp");
    
    return 0;
}