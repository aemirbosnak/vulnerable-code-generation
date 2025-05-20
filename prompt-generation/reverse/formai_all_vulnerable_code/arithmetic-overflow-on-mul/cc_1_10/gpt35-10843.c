//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_PIXEL 255
#define MIN_PIXEL 0

// Function declarations
void flipVertical(int numRows, int numCols, unsigned char *image);
void flipHorizontal(int numRows, int numCols, unsigned char *image);
void changeBrightness(int numRows, int numCols, unsigned char *image, int brightnessLevel);
void changeContrast(int numRows, int numCols, unsigned char *image, float contrastLevel);

int main(int argc, char **argv)
{
    // Make sure the user provided the correct number of arguments
    if (argc < 3)
    {
        printf("Error! Please provide an input file and an output file.\n");
        return 0;
    }

    // Open the input and output files
    FILE *fileIn = fopen(argv[1], "rb");
    FILE *fileOut = fopen(argv[2], "wb");
    if (fileIn == NULL || fileOut == NULL)
    {
        printf("Error! Could not open the files.\n");
        return 0;
    }

    // Read the header information
    int numRows, numCols, maxPixel;
    fscanf(fileIn, "P5\n%d %d\n%d\n", &numCols, &numRows, &maxPixel);
    if (maxPixel != MAX_PIXEL || numRows <= 0 || numCols <= 0)
    {
        printf("Error! Invalid header information.\n");
        return 0;
    }

    // Allocate memory for the image
    unsigned char *image = (unsigned char *)malloc(numRows * numCols * sizeof(unsigned char));
    if (image == NULL)
    {
        printf("Error! Could not allocate memory.\n");
        return 0;
    }

    // Read the image data
    int bytesRead = fread(image, 1, numRows * numCols, fileIn);
    if (bytesRead != numRows * numCols)
    {
        printf("Error! Could not read the image data.\n");
        free(image);
        return 0;
    }

    // Flip the image vertically
    flipVertical(numRows, numCols, image);

    // Flip the image horizontally
    flipHorizontal(numRows, numCols, image);

    // Change the brightness of the image
    int brightnessLevel = 50;
    changeBrightness(numRows, numCols, image, brightnessLevel);

    // Change the contrast of the image
    float contrastLevel = 0.5;
    changeContrast(numRows, numCols, image, contrastLevel);

    // Write the image data to the output file
    fprintf(fileOut, "P5\n%d %d\n%d\n", numCols, numRows, MAX_PIXEL);
    fwrite(image, 1, numRows * numCols, fileOut);

    // Clean up
    free(image);
    fclose(fileIn);
    fclose(fileOut);

    return 0;
}

void flipVertical(int numRows, int numCols, unsigned char *image)
{
    unsigned char temp;

    for (int col = 0; col < numCols; col++)
    {
        for (int row = 0; row < numRows / 2; row++)
        {
            temp = image[row * numCols + col];
            image[row * numCols + col] = image[(numRows - row - 1) * numCols + col];
            image[(numRows - row - 1) * numCols + col] = temp;
        }
    }
}

void flipHorizontal(int numRows, int numCols, unsigned char *image)
{
    unsigned char temp;

    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols / 2; col++)
        {
            temp = image[row * numCols + col];
            image[row * numCols + col] = image[row * numCols + (numCols - col - 1)];
            image[row * numCols + (numCols - col - 1)] = temp;
        }
    }
}

void changeBrightness(int numRows, int numCols, unsigned char *image, int brightnessLevel)
{
    int pixel;
    int delta = brightnessLevel - 50;

    for (int i = 0; i < numRows * numCols; i++)
    {
        pixel = (int)image[i] + delta;

        if (pixel < MIN_PIXEL)
        {
            image[i] = MIN_PIXEL;
        }
        else if (pixel > MAX_PIXEL)
        {
            image[i] = MAX_PIXEL;
        }
        else
        {
            image[i] = (unsigned char)pixel;
        }
    }
}

void changeContrast(int numRows, int numCols, unsigned char *image, float contrastLevel)
{
    float pixel;
    float factor = (259.0 * (contrastLevel + 255.0)) / (255.0 * (259.0 - contrastLevel));

    for (int i = 0; i < numRows * numCols; i++)
    {
        pixel = factor * ((float)image[i] - 128.0) + 128.0;

        if (pixel < MIN_PIXEL)
        {
            image[i] = MIN_PIXEL;
        }
        else if (pixel > MAX_PIXEL)
        {
            image[i] = MAX_PIXEL;
        }
        else
        {
            image[i] = (unsigned char)pixel;
        }
    }
}