//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void readImage(char *filename, int **image, int *rows, int *columns);
void writeImage(char *filename, int **image, int rows, int columns);
void flipHorizontal(int **image, int rows, int columns);
void flipVertical(int **image, int rows, int columns);
void adjustBrightness(int **image, int rows, int columns, int adjustment);
void adjustContrast(int **image, int rows, int columns, float adjustment);

int main()
{
    char filename[100];
    int rows, columns, adjustment;
    float fadjustment;
    int **image;

    printf("Enter the filename of the image you would like to process: ");
    scanf("%s", filename);

    readImage(filename, &image, &rows, &columns);

    // Flip the image horizontally
    flipHorizontal(image, rows, columns);
    writeImage("horizontal_flip.pgm", image, rows, columns);

    // Flip the image vertically
    flipVertical(image, rows, columns);
    writeImage("vertical_flip.pgm", image, rows, columns);

    printf("Enter the desired brightness adjustment as an integer: ");
    scanf("%d", &adjustment);

    // Adjust the brightness of the image
    adjustBrightness(image, rows, columns, adjustment);
    writeImage("brightness_adjusted.pgm", image, rows, columns);

    printf("Enter the desired contrast adjustment as a decimal value: ");
    scanf("%f", &fadjustment);

    // Adjust the contrast of the image
    adjustContrast(image, rows, columns, fadjustment);
    writeImage("contrast_adjusted.pgm", image, rows, columns);

    free(image[0]);
    free(image);

    return 0;
}

void readImage(char *filename, int **image, int *rows, int *columns)
{
    FILE *fp;
    char magicNumber[3];
    int maxIntensity;

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file %s", filename);
        exit(1);
    }

    // Read the magic number (P2)
    fscanf(fp, "%s", magicNumber);
    if (magicNumber[0] != 'P' || magicNumber[1] != '2')
    {
        fprintf(stderr, "Error: Invalid file format. Expected P2");
        exit(1);
    }

    // Read the image dimensions
    fscanf(fp, "%d %d", columns, rows);

    // Read the maximum intensity value
    fscanf(fp, "%d", &maxIntensity);

    *image = (int *)malloc((*rows) * (*columns) * sizeof(int));

    // Read pixel values
    for (int i = 0; i < (*rows) * (*columns); i++)
    {
        fscanf(fp, "%d", *image + i);
    }

    fclose(fp);
}

void writeImage(char *filename, int **image, int rows, int columns)
{
    FILE *fp;

    fp = fopen(filename, "w");

    if (fp == NULL)
    {
        fprintf(stderr, "Error creating file %s", filename);
        exit(1);
    }

    // Write the magic number and image dimensions
    fprintf(fp, "P2\n%d %d\n255\n", columns, rows);

    // Write pixel values
    for (int i = 0; i < rows * columns; i++)
    {
        fprintf(fp, "%d ", *(*image + i));
        if ((i + 1) % columns == 0)
            fprintf(fp, "\n");
    }

    fclose(fp);
}

void flipHorizontal(int **image, int rows, int columns)
{
    int temp;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns / 2; j++)
        {
            // Swap pixels across the y-axis
            temp = *(*image + i * columns + j);
            *(*image + i * columns + j) = *(*image + i * columns + columns - j - 1);
            *(*image + i * columns + columns - j - 1) = temp;
        }
    }
}

void flipVertical(int **image, int rows, int columns)
{
    int temp;

    for (int i = 0; i < rows / 2; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // Swap pixels across the x-axis
            temp = *(*image + i * columns + j);
            *(*image + i * columns + j) = *(*image + (rows - i - 1) * columns + j);
            *(*image + (rows - i - 1) * columns + j) = temp;
        }
    }
}

void adjustBrightness(int **image, int rows, int columns, int adjustment)
{
    for (int i = 0; i < rows * columns; i++)
    {
        *(*image + i) += adjustment;
        if (*(*image + i) > 255)
            *(*image + i) = 255;
        else if (*(*image + i) < 0)
            *(*image + i) = 0;
    }
}

void adjustContrast(int **image, int rows, int columns, float adjustment)
{
    float factor = (259 * (adjustment + 255)) / (255 * (259 - adjustment));

    for (int i = 0; i < rows * columns; i++)
    {
        *(*image + i) = (int)(factor * (*(*image + i) - 128) + 128);
        if (*(*image + i) > 255)
            *(*image + i) = 255;
        else if (*(*image + i) < 0)
            *(*image + i) = 0;
    }
}