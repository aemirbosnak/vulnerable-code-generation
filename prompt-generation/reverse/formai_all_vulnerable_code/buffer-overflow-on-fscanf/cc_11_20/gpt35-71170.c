//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

/* Simple image processing using C language */

int main()
{
    int width, height, maxcolor;
    char img_type[20];
    unsigned char **img, **out;
    int flip;
    double bright, contrast;

    /* Opening the image file */
    FILE *fp = fopen("image.pgm", "rb");
    if (fp == NULL)
    {
        printf("Error: Could not open the image file\n");
        return 1;
    }

    /* Reading image properties */
    fscanf(fp, "%s\n", img_type);
    fscanf(fp, "%d %d\n", &width, &height);
    fscanf(fp, "%d\n", &maxcolor);

    /* Allocating memory for the image */
    img = (unsigned char **)malloc(height * sizeof(unsigned char *));
    for (int i = 0; i < height; i++)
    {
        img[i] = (unsigned char *)malloc(width * sizeof(unsigned char));
    }

    /* Reading image data */
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fscanf(fp, "%c", &img[i][j]);
        }
    }

    /* Closing the image file */
    fclose(fp);

    /* Flipping the image */
    printf("Do you want to flip the image horizontally? (0/1): ");
    scanf("%d", &flip);
    if (flip)
    {
        out = (unsigned char **)malloc(height * sizeof(unsigned char *));
        for (int i = 0; i < height; i++)
        {
            out[i] = (unsigned char *)malloc(width * sizeof(unsigned char));
        }
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                out[i][j] = img[i][width - j - 1];
            }
        }
        for (int i = 0; i < height; i++)
        {
            free(img[i]);
        }
        free(img);
        img = out;
        out = NULL;
    }

    /* Changing brightness and contrast */
    printf("Enter the brightness factor (e.g. 0.5 for darker, 1 for original, 1.5 for brighter, etc.): ");
    scanf("%lf", &bright);
    printf("Enter the contrast factor (e.g. 0.5 for less contrast, 1 for original, 1.5 for more contrast, etc.): ");
    scanf("%lf", &contrast);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            img[i][j] = (unsigned char)((double)maxcolor / 2.0 + (double)(img[i][j] - (double)maxcolor / 2.0) * contrast + bright * (double)(img[i][j] - (double)maxcolor / 2.0));
        }
    }

    /* Saving the processed image */
    fp = fopen("processed_image.pgm", "wb");
    fprintf(fp, "P5\n%d %d\n%d\n", width, height, maxcolor);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fprintf(fp, "%c", img[i][j]);
        }
    }
    fclose(fp);

    /* Freeing the memory */
    for (int i = 0; i < height; i++)
    {
        free(img[i]);
    }
    free(img);

    return 0;
}