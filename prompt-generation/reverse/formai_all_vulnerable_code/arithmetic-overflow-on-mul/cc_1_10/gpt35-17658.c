//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>

//Function declarations
void pixelToChar(int pixelValue);

//Program begins
int main()
{
    //Open the image
    FILE *image = fopen("example_image.png", "rb");

    //Check if the image was opened successfully
    if (image == NULL)
    {
        printf("Error opening image.\n");
        return 1;
    }

    //Read image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image);

    //Get image width and height
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    //Calculate image size
    int imageSize = width * height * 3;

    //Allocate memory for image pixels
    unsigned char *pixels = (unsigned char*)malloc(sizeof(unsigned char) * imageSize);

    //Read image pixels into memory
    fread(pixels, sizeof(unsigned char), imageSize, image);

    //Close the image
    fclose(image);

    //Loop through the image pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Calculate index of current pixel (in 1D array)
            int index = (i * width + j) * 3;

            //Convert pixel to ASCII character
            pixelToChar(pixels[index]);
            pixelToChar(pixels[index+1]);
            pixelToChar(pixels[index+2]);
        }
        //Print new line after each row
        printf("\n");
    }

    //Free memory allocated for image pixels
    free(pixels);

    return 0;
}

//Function to convert pixel to ASCII character
void pixelToChar(int pixelValue)
{
    //Map pixel value to ASCII character
    if (pixelValue >= 0 && pixelValue <= 63)
    {
        printf(".");
    }
    else if (pixelValue >= 64 && pixelValue <= 127)
    {
        printf(":");
    }
    else if (pixelValue >= 128 && pixelValue <= 191)
    {
        printf("*");
    }
    else if (pixelValue >= 192 && pixelValue <= 255)
    {
        printf("#");
    }
}