//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

// Function to convert an RGB color value to grayscale
int getGrayScale(int r, int g, int b)
{
    float gray = (0.2989 * r) + (0.5870 * g) + (0.1140 * b); //Formula for calculating grayscale value
    return (int)round(gray);
}

//Function to map a GrayScale value to a character
char mapChar(int grayValue)
{
    char asciiChars[] = {' ', '.', '*', ':', 'o', '&', '8', '#', '@'}; //Array of ASCII characters ordered by increasing darkness
    int numChars = 9; //Total number of characters in the array
    int charIndex = (int)round((grayValue * (numChars - 1)) / 255.0); //Map the grayscale value to an ASCII index
    return asciiChars[charIndex]; //Return the corresponding ASCII character
}

int main()
{
    FILE *imageFile = fopen("image.bmp", "rb"); //Open the image to be converted in binary mode
    if(imageFile == NULL)
    {
        printf("Error: Cannot open input file.\n");
        return -1; //Exit program if input file cannot be opened
    }

    unsigned char header[54]; //BMP header is 54 bytes
    fread(header, sizeof(unsigned char), 54, imageFile); //Read the header

    //Extract image dimensions and other important information from the header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bitDepth = *(int*)&header[28];

    //If the image is not 24-bit, exit the program
    if(bitDepth != 24)
    {
        printf("Error: Input image must be 24-bit.\n");
        fclose(imageFile);
        return -1;
    }

    int padding = (4 - (width * 3) % 4) % 4; //Calculate padding bytes at end of each row
    int i, j;
    unsigned char pixel[3];
    char charPixel;

    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            fread(pixel, sizeof(unsigned char), 3, imageFile); //Read RGB values of pixel
            int grayValue = getGrayScale((int)pixel[2], (int)pixel[1], (int)pixel[0]); //Convert RGB to Grayscale
            charPixel = mapChar(grayValue); //Map Grayscale value to ASCII character
            printf("%c", charPixel); //Print the ASCII character
        }
        fseek(imageFile, padding, SEEK_CUR); //Skip the padding bytes at the end of each row
        printf("\n"); //Start a new line after each row
    }

    fclose(imageFile); //Close the input file
    return 0; //Exit the program with success status
}