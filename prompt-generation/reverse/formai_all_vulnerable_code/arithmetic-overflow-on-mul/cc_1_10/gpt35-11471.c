//FormAI DATASET v1.0 Category: Image compression ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PIXEL 255
#define BRIGHTNESS_THRESHOLD 100

// This function takes in the path of the input image file and returns an array of pixels
int *readImage(char *filename, int *width, int *height)
{
    FILE *imageFile = fopen(filename, "rb");
    if (imageFile == NULL)
    {
        printf("Unable to open file!");
        exit(1);
    }

    // Get the dimensions of the image
    int header[4];
    fread(header, sizeof(int), 4, imageFile);
    *width = header[0];
    *height = header[1];

    int *image = (int*)malloc((*height * *width) * sizeof(int));

    // Read the pixel values into the array
    for (int i = 0; i < *height * *width; i++)
    {
        fread(&image[i], sizeof(int), 1, imageFile);
    }
    fclose(imageFile);
    return image;
}

// This function takes in an array of pixels and writes them to a new image file at the specified path
void writeImage(char *filename, int *image, int width, int height)
{
    FILE *imageFile = fopen(filename, "wb");
    if (imageFile == NULL)
    {
        printf("Unable to open file!");
        exit(1);
    }

    // Write the header to the new image file
    int header[4];
    header[0] = width;
    header[1] = height;
    header[2] = MAX_PIXEL;
    header[3] = 0;
    fwrite(header, sizeof(int), 4, imageFile);

    // Write the pixel values to the new image file
    for (int i = 0; i < height * width; i++)
    {
        fwrite(&image[i], sizeof(int), 1, imageFile);
    }
    fclose(imageFile);
}

// This function takes in an array of pixels and performs image compression using a brightness threshold
int *compressImage(int *image, int width, int height)
{
    int *compressedImage = (int*)malloc((height * width) * sizeof(int));
    for (int i = 0; i < height * width; i++)
    {
        if (image[i] < BRIGHTNESS_THRESHOLD)
        {
            compressedImage[i] = 0;
        }
        else
        {
            compressedImage[i] = MAX_PIXEL;
        }
    }
    return compressedImage;
}

// This is the main function of the program
int main()
{
    char *inputPath = "input_image.bin";
    char *outputPath = "compressed_image.bin";
    int width, height;
    int *image = readImage(inputPath, &width, &height);
    int *compressedImage = compressImage(image, width, height);
    writeImage(outputPath, compressedImage, width, height);
    free(image);
    free(compressedImage);
    return 0;
}