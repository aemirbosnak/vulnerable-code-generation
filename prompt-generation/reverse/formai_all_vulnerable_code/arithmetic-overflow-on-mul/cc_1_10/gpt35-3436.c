//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to convert image to ASCII art */
void imageToAscii(char *filename, int width, int height)
{
    /* Open image file */
    FILE *imageFile;
    imageFile = fopen(filename, "rb");
    if (imageFile == NULL)
    {
        printf("Error opening the file.\n");
        exit(1);
    }

    /* Read image data */
    unsigned char imageData[width][height];
    fread(imageData, sizeof(unsigned char), width * height, imageFile);

    /* Close image file */
    fclose(imageFile);

    /* ASCII table */
    char asciiTable[11] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@', ' '};

    /* Convert image data to ASCII art */
    int i, j;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            unsigned char pixel = imageData[j][i];
            int index = pixel / 25;
            printf("%c", asciiTable[index]);
        }
        printf("\n");
    }
}

int main()
{
    /* Input image filename */
    char filename[50];
    printf("Enter the filename of the image to convert: ");
    scanf("%s", filename);

    /* Input image width */
    int width;
    printf("Enter the width of the image in pixels: ");
    scanf("%d", &width);

    /* Input image height */
    int height;
    printf("Enter the height of the image in pixels: ");
    scanf("%d", &height);

    /* Convert image to ASCII art */
    imageToAscii(filename, width, height);

    return 0;
}