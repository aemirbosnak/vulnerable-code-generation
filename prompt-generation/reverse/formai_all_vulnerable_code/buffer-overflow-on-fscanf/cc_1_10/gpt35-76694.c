//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: protected
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Open the input and output files
    FILE *inFile = fopen("input_image.pgm", "rb");
    FILE *outFile = fopen("output_image.pgm", "wb");

    // Check if the files were opened successfully
    if (inFile == NULL)
    {
        printf("Error opening input file\n");
        return 1;
    }
    if (outFile == NULL)
    {
        printf("Error opening output file\n");
        return 1;
    }

    // Read the header information from the input file
    char magicNumber[3];
    int width, height, maxVal;
    fscanf(inFile, "%s %d %d %d\n", magicNumber, &width, &height, &maxVal);

    // Write the header information to the output file
    fprintf(outFile, "%s\n%d %d\n%d\n", magicNumber, width, height, maxVal);

    // Allocate memory for the image data
    unsigned char *imageData = (unsigned char *)malloc(width * height * sizeof(unsigned char));

    // Read the image data from the input file
    fread(imageData, sizeof(unsigned char), width * height, inFile);

    // Flip the image horizontally
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width / 2; x++)
        {
            unsigned char temp = imageData[y * width + x];
            imageData[y * width + x] = imageData[y * width + (width - 1 - x)];
            imageData[y * width + (width - 1 - x)] = temp;
        }
    }

    // Increase the brightness of the image by 50
    for (int i = 0; i < width * height; i++)
    {
        if (imageData[i] + 50 > maxVal)
        {
            imageData[i] = maxVal;
        }
        else
        {
            imageData[i] += 50;
        }
    }

    // Decrease the contrast of the image by 25%
    float scaleFactor = 0.75;
    unsigned char midpoint = maxVal / 2;
    for (int i = 0; i < width * height; i++)
    {
        unsigned char newValue = (unsigned char)((imageData[i] - midpoint) * scaleFactor + midpoint);
        if (newValue > maxVal)
        {
            imageData[i] = maxVal;
        }
        else
        {
            imageData[i] = newValue;
        }
    }

    // Write the modified image data to the output file
    fwrite(imageData, sizeof(unsigned char), width * height, outFile);

    // Free the allocated memory and close the files
    free(imageData);
    fclose(inFile);
    fclose(outFile);

    return 0;
}