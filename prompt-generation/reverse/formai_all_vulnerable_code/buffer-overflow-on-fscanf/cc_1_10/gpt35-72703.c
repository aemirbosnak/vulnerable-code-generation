//FormAI DATASET v1.0 Category: Image compression ; Style: enthusiastic
/* Welcome to my awesome image compression program! */
/* This program reads in a PPM file and compresses it into a smaller size while preserving the important visual information. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum dimensions for the image */
#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

/* Define the image struct */
typedef struct
{
    int width;
    int height;
    int pixels[MAX_WIDTH][MAX_HEIGHT][3];
} image;

/* Compress the image by dividing the RGB values by 2 */
void compressImage(image *img)
{
    int i, j, k;
    for (i = 0; i < img->width; i++)
    {
        for (j = 0; j < img->height; j++)
        {
            for (k = 0; k < 3; k++)
            {
                img->pixels[i][j][k] /= 2;
            }
        }
    }
}

/* Read in the image from a PPM file */
int readImage(char *filename, image *img)
{
    char magicNum[3];
    int i, j;

    FILE *fin;

    /* Open the file for reading */
    fin = fopen(filename, "r");

    /* Read in the magic number */
    fscanf(fin, "%s", magicNum);

    /* Make sure it's a PPM file */
    if (strcmp(magicNum, "P3"))
    {
        printf("Error: Not a PPM file\n");
        return 0;
    }

    /* Read in the image dimensions */
    fscanf(fin, "%d %d", &(img->width), &(img->height));

    /* Make sure the dimensions aren't too large */
    if (img->width > MAX_WIDTH || img->height > MAX_HEIGHT)
    {
        printf("Error: Image dimensions too large\n");
        return 0;
    }

    /* Read in the maximum pixel value */
    int maxValue;
    fscanf(fin, "%d", &maxValue);

    /* Read in the pixel values */
    for (i = 0; i < img->width; i++)
    {
        for (j = 0; j < img->height; j++)
        {
            fscanf(fin, "%d %d %d", &(img->pixels[i][j][0]), &(img->pixels[i][j][1]), &(img->pixels[i][j][2]));
        }
    }

    /* Close the file */
    fclose(fin);

    return 1;
}

/* Write out the compressed image to a PPM file */
int writeImage(char *filename, image *img)
{
    int i, j;

    FILE *fout;

    /* Open the file for writing */
    fout = fopen(filename, "w");

    /* Write out the magic number */
    fprintf(fout, "P3\n");

    /* Write out the dimensions */
    fprintf(fout, "%d %d\n", img->width, img->height);

    /* Write out the maximum pixel value */
    fprintf(fout, "255\n");

    /* Write out the pixel values (compressed) */
    for (i = 0; i < img->width; i++)
    {
        for (j = 0; j < img->height; j++)
        {
            fprintf(fout, "%d %d %d ", img->pixels[i][j][0], img->pixels[i][j][1], img->pixels[i][j][2]);
        }
        fprintf(fout, "\n");
    }

    /* Close the file */
    fclose(fout);

    return 1;
}

/* Main function */
int main()
{
    /* Declare variables */
    image myImage;
    char *inputFilename = "input.ppm";
    char *outputFilename = "output.ppm";

    /* Read in the image */
    if (!readImage(inputFilename, &myImage))
    {
        return 1;
    }

    /* Compress the image */
    compressImage(&myImage);

    /* Write out the compressed image */
    if (!writeImage(outputFilename, &myImage))
    {
        return 1;
    }

    /* Success */
    printf("Image compression and saving complete! Check out the new smaller image in %s\n", outputFilename);
    return 0;
}