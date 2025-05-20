//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Function to read the image data from file
void readImageData(FILE *fptr, char *hdr, int *w, int *h, int *max, char **buffer)
{
    int i, numPixels;

    // Read the image header
    fscanf(fptr, "%s %d %d %d", hdr, w, h, max);

    // Calculate the number of pixels in the image
    numPixels = (*w) * (*h);

    // Allocate memory for the image buffer
    *buffer = (char *) malloc(sizeof(char) * numPixels);

    // Read the image data into the buffer
    for(i = 0; i < numPixels; i++)
        fscanf(fptr, "%c", (*buffer) + i);
}

// Function to write the image data to file
void writeImageData(FILE *fptr, char *hdr, int w, int h, int max, char *buffer)
{
    int i;

    // Write the image header
    fprintf(fptr, "%s\n%d %d\n%d\n", hdr, w, h, max);

    // Write the image data to file
    for(i = 0; i < w*h; i++)
        fprintf(fptr, "%c", buffer[i]);
}

// Function to flip the image vertically
void flipVertically(char *buffer, int w, int h)
{
    int i, j;
    char temp;

    // Swap the values along the vertical axis
    for(i = 0; i < h/2; i++)
    {
        for(j = 0; j < w; j++)
        {
            temp = buffer[i*w+j];
            buffer[i*w+j] = buffer[(h-i-1)*w+j];
            buffer[(h-i-1)*w+j] = temp;
        }
    }
}

// Function to adjust the brightness of the image
void adjustBrightness(char *buffer, int w, int h, int adjustment)
{
    int i, brightness;

    // Adjust the brightness of each pixel
    for(i = 0; i < w*h; i++)
    {
        brightness = buffer[i] + adjustment;

        // Ensure that the brightness stays within the valid range
        if(brightness < 0)
            brightness = 0;
        else if(brightness > 255)
            brightness = 255;

        buffer[i] = (char) brightness;
    }
}

// Function to adjust the contrast of the image
void adjustContrast(char *buffer, int w, int h, float factor)
{
    int i, brightness;
    float contrast;

    // Adjust the contrast of each pixel
    for(i = 0; i < w*h; i++)
    {
        brightness = buffer[i];

        // Adjust the brightness based on the contrast factor
        contrast = (brightness - 128.0f) * factor + 128.0f;

        // Ensure that the contrast stays within the valid range
        if(contrast < 0.0f)
            contrast = 0.0f;
        else if(contrast > 255.0f)
            contrast = 255.0f;

        buffer[i] = (char) contrast;
    }
}

int main()
{
    char header[3];
    int width, height, maxVal;

    // Open the input file in read mode
    FILE *fpIn = fopen("input.pgm", "r");
    if(fpIn == NULL)
    {
        printf("Error: Unable to open input file!\n");
        return -1;
    }

    // Open the output file in write mode
    FILE *fpOut = fopen("output.pgm", "w+");
    if(fpOut == NULL)
    {
        printf("Error: Unable to create output file!\n");
        return -1;
    }

    // Read the image data from the input file
    char *buffer;
    readImageData(fpIn, header, &width, &height, &maxVal, &buffer);

    // Flip the image vertically
    flipVertically(buffer, width, height);

    // Adjust the brightness of the image
    adjustBrightness(buffer, width, height, 50);

    // Adjust the contrast of the image
    adjustContrast(buffer, width, height, 1.5f);

    // Write the modified image data to the output file
    writeImageData(fpOut, header, width, height, maxVal, buffer);

    // Free the memory used by the image buffer
    free(buffer);

    // Close the input and output files
    fclose(fpIn);
    fclose(fpOut);

    return 0;
}