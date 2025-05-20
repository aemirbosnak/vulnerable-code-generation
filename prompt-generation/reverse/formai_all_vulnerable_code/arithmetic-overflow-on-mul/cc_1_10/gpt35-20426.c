//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: puzzling
#include <stdio.h>
#include <string.h>

#define MAX_WIDTH 80 // maximum width of ascii art

// Converts a pixel from RGB to grayscale
unsigned char RGBToGrayScale(unsigned char red, unsigned char green, unsigned char blue) {
    return 0.2989 * red + 0.5870 * green + 0.1140 * blue;
}

// Maps the pixel grayscale value to an ASCII character
char MapToCharacter(unsigned char pixelValue) {
    // Characters from darkest to brightest
    char characters[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    int numChars = sizeof(characters) / sizeof(char);
    
    // Map the value to the corresponding character
    int charIndex = (int) (pixelValue / 25.5);
    return characters[charIndex < numChars ? charIndex : numChars - 1];
}

// Converts an image to ASCII art and prints it to the console
void ConvertImageToASCII(char* filename) {
    FILE *fileptr;
    unsigned char buffer[54], width[4], height[4];
    unsigned char red, green, blue;
    int i, j, padding, heightInt, widthInt, index;
    char character;
    
    // Open the file
    fileptr = fopen(filename, "rb");
    if (fileptr == NULL) {
        printf("Error: Unable to open file '%s'\n", filename);
        return;
    }
    
    // Read the header and get the image dimensions
    fread(buffer, 1, 54, fileptr);
    widthInt = *(int*)&buffer[18];
    heightInt = *(int*)&buffer[22];
    
    // Calculate the padding for each line
    padding = (4 - (widthInt * 3) % 4) % 4;
    
    // Only display the maximum width of ascii art characters
    int asciiWidth = widthInt > MAX_WIDTH ? MAX_WIDTH : widthInt;
    
    // Loop through each pixel in the image
    for (i = 0; i < heightInt; i++) {
        for (j = 0; j < widthInt; j++) {
            // Read the RGB values of the pixel
            fread(&blue, 1, 1, fileptr);
            fread(&green, 1, 1, fileptr);
            fread(&red, 1, 1, fileptr);
            
            // Calculate the grayscale value of the pixel and map it to an ASCII character
            character = MapToCharacter(RGBToGrayScale(red, green, blue));
            
            // Print the ASCII character to the console
            if (j < asciiWidth) {
                printf("%c", character);
            }
        }
        
        // Skip any padding at the end of the line
        fseek(fileptr, padding, SEEK_CUR);
        
        // Print a newline character to move to the next line
        printf("\n");
    }
    
    // Close the file
    fclose(fileptr);
}

int main() {
    ConvertImageToASCII("test_image.bmp");
    
    return 0;
}