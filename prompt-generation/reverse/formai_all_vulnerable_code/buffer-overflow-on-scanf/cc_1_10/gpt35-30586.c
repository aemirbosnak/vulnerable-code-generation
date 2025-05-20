//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 60
#define MAX_PIXEL_VALUE 255

// Function to convert image to ASCII art
void convertImageToASCII(char *imageFileName) {
    FILE *inputFile;
    FILE *outputFile;
    char outputFileName[100];
    char *line;
    int i, j, k, count, width, height, maxPixelValue, pixelValue;
    double scaleFactor;
    
    // Open input file
    inputFile = fopen(imageFileName, "r");
    if(inputFile == NULL) {
        printf("Failed to open file.\n");
        return;
    }
    
    // Read image information from input file
    fscanf(inputFile, "P2\n%d %d\n%d\n", &width, &height, &maxPixelValue);
    
    // Create output file name
    strcpy(outputFileName, imageFileName);
    strcat(outputFileName, ".txt");
    
    // Open output file
    outputFile = fopen(outputFileName, "w");
    if(outputFile == NULL) {
        printf("Failed to create output file.\n");
        return;
    }
    
    // Allocate memory for line buffer
    line = (char*)malloc(sizeof(char) * (width + 1));
    
    // Calculate scale factor for pixel to ASCII conversion
    scaleFactor = (double)MAX_PIXEL_VALUE / (double)(strlen("#WMBND8%$@"));
    
    // Loop through each pixel and convert to ASCII character
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            fscanf(inputFile, "%d", &pixelValue);
            
            // Normalize pixel value and convert to ASCII char
            count = (int)(pixelValue / scaleFactor);
            if(count >= strlen("#WMBND8%$@")) {
                count = strlen("#WMBND8%$@") - 1;
            }
            fprintf(outputFile, "%c", "#WMBND8%$@"[count]);
        }
        fprintf(outputFile, "\n");
    }
    
    // Free memory and close files
    free(line);
    fclose(inputFile);
    fclose(outputFile);
    
    printf("Image converted successfully!\n");
}

int main() {
    char file[100];
    printf("Enter the image file name (with extension): ");
    scanf("%s", file);
    
    convertImageToASCII(file);
    
    return 0;
}