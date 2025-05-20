//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

char matrix[MAX_HEIGHT][MAX_WIDTH];

// Function to convert a pixel value to a character
char pixelToChar(int value)
{
    char chars[] = " .:-=+*#%@";
    int numChars = sizeof(chars) - 1;
    int index = (int)(((float)value / 255.0) * numChars);
    return chars[index];
}

// Function to print the ascii art
void printASCII(int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to read in the image and convert it to ascii art
void imageToASCII(char *filename)
{
    // Open the image file
    FILE *file;
    file = fopen(filename, "rb");

    // Get the file header
    char header[54];
    fread(header, sizeof(char), 54, file);

    // Get the image size
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Calculate the padding
    int padding = 4 - (width * 3) % 4;

    // Create a buffer to hold the image data
    unsigned char data[height][width][3];

    // Read in the image data
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fread(data[i][j], sizeof(unsigned char), 3, file);
        }
        fseek(file, padding, SEEK_CUR);
    }

    // Convert the image to ascii art
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            char c = pixelToChar((int)data[i][j][0]);
            matrix[i][j] = c;
        }
    }

    // Print the ascii art
    printASCII(width, height);

    // Close the file
    fclose(file);
}

// Main function
int main()
{
    char filename[100];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);
    imageToASCII(filename);
    return 0;
}