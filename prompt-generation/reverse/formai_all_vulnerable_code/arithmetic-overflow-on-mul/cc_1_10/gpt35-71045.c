//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480

// Define image struct
typedef struct
{
    int width;
    int height;
    unsigned char *data;
} Image;

// Allocate memory for image
void allocateImage(Image *img)
{
    img->data = (unsigned char *)malloc(img->width * img->height * sizeof(unsigned char));
}

// Read image from file
void readImage(Image *img, char *filename)
{
    FILE *fp = fopen(filename, "rb");

    if (fp == NULL)
    {
        printf("Error opening file %s", filename);
        exit(1);
    }

    // Read header data
    char buffer[54];
    fread(buffer, sizeof(char), 54, fp);

    // Set image dimensions
    img->width = *(int *)&buffer[18];
    img->height = *(int *)&buffer[22];

    // Allocate memory for image
    allocateImage(img);

    // Read image data
    fread(img->data, sizeof(unsigned char), img->width * img->height, fp);
    fclose(fp);
}

// Write image to file
void writeImage(Image *img, char *filename)
{
    FILE *fp = fopen(filename, "wb");

    // Write header data
    char header[54] = {
        'B', 'M',         // Signature
        0x36, 0xf3, 0x0, 0x0, // Size of file
        0x0,  0x0,        // Reserved
        0x0,  0x0,        // Reserved
        0x36, 0x0, 0x0, 0x0, // Offset to pixel data
        0x28, 0x0, 0x0, 0x0, // Size of DIB header
        0x0,  0x2, 0x0, 0x0, // Width of image (little-endian)
        0x20, 0x1, 0x0, 0x0, // Height of image (little-endian)
        0x1,  0x0,        // Number of color planes
        0x8,  0x0,        // Bits per pixel
        0x0,  0x0, 0x0, 0x0, // Compression method (none)
        0x0,  0xf3, 0x0, 0x0, // Size of pixel data
        0x0,  0x0, 0x0, 0x0, // Horizontal resolution (px/m)
        0x0,  0x0, 0x0, 0x0, // Vertical resolution (px/m)
        0x0,  0x0, 0x0, 0x0, // Number of colors in palette (default)
        0x0,  0x0, 0x0, 0x0, // Number of important colors (all)
    };

    *(int *)&header[18] = img->width;  // Set image width
    *(int *)&header[22] = img->height; // Set image height
    fwrite(header, sizeof(char), 54, fp);

    // Write pixel data
    fwrite(img->data, sizeof(unsigned char), img->width * img->height, fp);
    fclose(fp);
}

// Flip image horizontally
void flipHorizontally(Image *img)
{
    unsigned char *temp = (unsigned char *)malloc(img->width * sizeof(unsigned char));

    for (int y = 0; y < img->height; y++)
    {
        for (int x = 0; x < img->width / 2; x++)
        {
            int indexA = y * img->width + x;
            int indexB = y * img->width + img->width - 1 - x;
            temp[x] = img->data[indexA];
            img->data[indexA] = img->data[indexB];
            img->data[indexB] = temp[x];
        }
    }
}

// Change image brightness and contrast
void changeBrightnessContrast(Image *img, int brightness, float contrast)
{
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    float pixelValue;

    for (int y = 0; y < img->height; y++)
    {
        for (int x = 0; x < img->width; x++)
        {
            int index = y * img->width + x;
            pixelValue = (float)img->data[index];
            pixelValue = factor * (pixelValue - 128.0) + 128.0 + brightness;

            if (pixelValue < 0.0)
            {
                pixelValue = 0.0;
            }

            if (pixelValue > 255.0)
            {
                pixelValue = 255.0;
            }

            img->data[index] = (unsigned char)pixelValue;
        }
    }
}

int main()
{
    // Read input image
    Image inputImg;
    readImage(&inputImg, "input.bmp");

    // Flip image horizontally
    flipHorizontally(&inputImg);

    // Change brightness and contrast
    int brightness = 50;
    float contrast = 50.0;
    changeBrightnessContrast(&inputImg, brightness, contrast);

    // Write output image
    writeImage(&inputImg, "output.bmp");

    // De-allocate memory
    free(inputImg.data);

    return 0;
}