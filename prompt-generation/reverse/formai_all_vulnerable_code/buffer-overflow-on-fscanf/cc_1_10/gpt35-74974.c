//FormAI DATASET v1.0 Category: Image Editor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void readImage(FILE *fp, int image[][500], int width, int height);
void writeImage(FILE *fp, int image[][500], int width, int height);
void invertColors(int image[][500], int width, int height);
void mirrorImage(int image[][500], int width, int height);
void flipImage(int image[][500], int width, int height);

// main function
int main()
{
    FILE *fp;
    int image[500][500];
    int width, height, choice;

    // read image file
    fp = fopen("input_image.txt", "r");
    if (fp == NULL) 
    {
        printf("Failed to open input file.\n");
        exit(EXIT_FAILURE);
    }

    // get image dimensions
    fscanf(fp, "%d %d", &width, &height);

    // read image data
    readImage(fp, image, width, height);

    // close file
    fclose(fp);

    // display menu
    printf("MENU\n");
    printf("1. Invert colors\n");
    printf("2. Mirror image\n");
    printf("3. Flip image\n");

    // get user choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // perform selected operation
    switch (choice)
    {
        case 1:
            invertColors(image, width, height);
            break;
        case 2:
            mirrorImage(image, width, height);
            break;
        case 3:
            flipImage(image, width, height);
            break;
        default:
            printf("Invalid choice\n");
    }

    // write modified image to output file
    fp = fopen("output_image.txt", "w");
    if (fp == NULL) 
    {
        printf("Failed to open output file.\n");
        exit(EXIT_FAILURE);
    }

    writeImage(fp, image, width, height);

    // close file
    fclose(fp);

    return 0;
}

// function to read image file
void readImage(FILE *fp, int image[][500], int width, int height)
{
    int i, j;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            fscanf(fp, "%d", &image[i][j]);
        }
    }
}

// function to write image file
void writeImage(FILE *fp, int image[][500], int width, int height)
{
    int i, j;

    fprintf(fp, "%d %d\n", width, height);

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            fprintf(fp, "%d ", image[i][j]);
        }
        fprintf(fp, "\n");
    }
}

// function to invert colors of image
void invertColors(int image[][500], int width, int height)
{
    int i, j;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            image[i][j] = 255 - image[i][j];
        }
    }
}

// function to mirror image horizontally
void mirrorImage(int image[][500], int width, int height)
{
    int i, j;
    int temp;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width/2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
}

// function to flip image vertically
void flipImage(int image[][500], int width, int height)
{
    int i, j;
    int temp;

    for (j = 0; j < width; j++)
    {
        for (i = 0; i < height/2; i++)
        {
            temp = image[i][j];
            image[i][j] = image[height-i-1][j];
            image[height-i-1][j] = temp;
        }
    }
}