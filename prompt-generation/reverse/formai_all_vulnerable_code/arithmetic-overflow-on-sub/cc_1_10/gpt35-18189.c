//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Donald Knuth
/* 
 * Basic Image Processing Program 
 * to Flip an Image, Change Brightness and Contrast
 * in C language
 * 
 * Written by [Your Name and Date]
 * 
 * Inspired by Donald Knuth's literate programming style
 * 
 * This program takes an image file, flips it horizontally or vertically, 
 * and then adjusts the brightness and contrast of the flipped image.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255

/* Function to swap two integers */
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to flip an image horizontally */
void flipHorizontally(unsigned char *imageData, int width, int height, int bytesPerPixel)
{
    int i, j, k;
    unsigned char temp;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width / 2; j++)
        {
            for (k = 0; k < bytesPerPixel; k++)
            {
                temp = imageData[i * width * bytesPerPixel + j * bytesPerPixel + k];
                imageData[i * width * bytesPerPixel + j * bytesPerPixel + k] = imageData[(i + 1) * width * bytesPerPixel - (j + 1) * bytesPerPixel + k];
                imageData[(i + 1) * width * bytesPerPixel - (j + 1) * bytesPerPixel + k] = temp;
            }
        }
    }
}

/* Function to flip an image vertically */
void flipVertically(unsigned char *imageData, int width, int height, int bytesPerPixel)
{
    int i, j, k;
    unsigned char temp;

    for (i = 0; i < height / 2; i++)
    {
        for (j = 0; j < width; j++)
        {
            for (k = 0; k < bytesPerPixel; k++)
            {
                temp = imageData[i * width * bytesPerPixel + j * bytesPerPixel + k];
                imageData[i * width * bytesPerPixel + j * bytesPerPixel + k] = imageData[(height - i - 1) * width * bytesPerPixel + j * bytesPerPixel + k];
                imageData[(height - i - 1) * width * bytesPerPixel + j * bytesPerPixel + k] = temp;
            }
        }
    }
}

/* Function to change the brightness of an image */
void changeBrightness(unsigned char *imageData, int width, int height, int bytesPerPixel, int brightness)
{
    int i, j, k;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            for (k = 0; k < bytesPerPixel; k++)
            {
                int currentValue = imageData[i * width * bytesPerPixel + j * bytesPerPixel + k];
                int newValue = currentValue + brightness;

                if (newValue < 0)
                {
                    newValue = 0;
                }
                else if (newValue > MAX_PIXEL_VALUE)
                {
                    newValue = MAX_PIXEL_VALUE;
                }

                imageData[i * width * bytesPerPixel + j * bytesPerPixel + k] = newValue;
            }
        }
    }
}

/* Function to change the contrast of an image */
void changeContrast(unsigned char *imageData, int width, int height, int bytesPerPixel, float contrast)
{
    int i, j, k;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            for (k = 0; k < bytesPerPixel; k++)
            {
                int currentValue = imageData[i * width * bytesPerPixel + j * bytesPerPixel + k];
                float newValue = contrast * (currentValue - MAX_PIXEL_VALUE / 2.0) + MAX_PIXEL_VALUE / 2.0;

                if (newValue < 0)
                {
                    newValue = 0;
                }
                else if (newValue > MAX_PIXEL_VALUE)
                {
                    newValue = MAX_PIXEL_VALUE;
                }

                imageData[i * width * bytesPerPixel + j * bytesPerPixel + k] = (unsigned char)newValue;
            }
        }
    }
}

/* Main function */
int main(void)
{
    FILE *fp;
    char filename[] = "image.bmp";
    unsigned char *imageData;
    int width, height, bitDepth, bytesPerPixel, i, j;
    int brightness = 50;
    float contrast = 1.5;

    /* Open the input file */
    fp = fopen(filename, "rb");

    /* Read the BMP file header */
    fseek(fp, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    fseek(fp, 2, SEEK_CUR);
    fread(&bitDepth, sizeof(short), 1, fp);
    bytesPerPixel = bitDepth / 8;

    /* Allocate memory for the image data array */
    imageData = (unsigned char *)malloc(width * height * bytesPerPixel);

    /* Read the BMP image data */
    fseek(fp, 54, SEEK_SET);
    fread(imageData, width * height * bytesPerPixel, 1, fp);

    /* Close the input file */
    fclose(fp);

    /* Flip the image horizontally */
    flipHorizontally(imageData, width, height, bytesPerPixel);

    /* Flip the image vertically */
    flipVertically(imageData, width, height, bytesPerPixel);

    /* Change the brightness of the image */
    changeBrightness(imageData, width, height, bytesPerPixel, brightness);

    /* Change the contrast of the image */
    changeContrast(imageData, width, height, bytesPerPixel, contrast);

    /* Open the output file */
    fp = fopen("output.bmp", "wb");

    /* Write the BMP file header */
    fwrite("BM", sizeof(char), 2, fp);
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);
    fwrite("\0\0\0\0", sizeof(char), 4, fp);
    fwrite("\x36\0\0\0", sizeof(char), 4, fp);
    fwrite("\x28\0\0\0", sizeof(char), 4, fp);
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);
    fwrite("\x01\0", sizeof(short), 1, fp);
    fwrite(&bitDepth, sizeof(short), 1, fp);
    fwrite("\0\0\0\0", sizeof(char), 4, fp);
    fwrite("\0\0\0\0", sizeof(char), 4, fp);
    fwrite("\0\0\0\0", sizeof(char), 4, fp);
    fwrite("\0\0\0\0", sizeof(char), 4, fp);

    /* Write the BMP image data */
    fwrite(imageData, width * height * bytesPerPixel, 1, fp);

    /* Close the output file */
    fclose(fp);

    /* Free the memory allocated for the image data array */
    free(imageData);

    /* Exit program */
    return 0;
}