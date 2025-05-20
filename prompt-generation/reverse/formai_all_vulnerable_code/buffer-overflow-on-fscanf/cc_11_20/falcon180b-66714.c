//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HEIGHT 100
#define WIDTH 100

int main()
{
    int i, j;
    int image[HEIGHT][WIDTH];

    // Read image from file
    FILE *fp = fopen("image.txt", "r");
    if (fp == NULL)
    {
        printf("Error: Cannot open image file\n");
        exit(1);
    }

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            fscanf(fp, "%d", &image[i][j]);
        }
    }
    fclose(fp);

    // Flip image horizontally
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH/2; j++)
        {
            int temp = image[i][j];
            image[i][j] = image[i][WIDTH-j-1];
            image[i][WIDTH-j-1] = temp;
        }
    }

    // Change brightness/contrast
    int brightness = 50;
    int contrast = 100;

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            int gray = (image[i][j] * brightness) / 255;
            gray += contrast;

            if (gray > 255)
                gray = 255;
            else if (gray < 0)
                gray = 0;

            image[i][j] = gray;
        }
    }

    // Save modified image to file
    FILE *fp_out = fopen("modified_image.txt", "w");
    if (fp_out == NULL)
    {
        printf("Error: Cannot create output file\n");
        exit(1);
    }

    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            fprintf(fp_out, "%d ", image[i][j]);
        }
        fprintf(fp_out, "\n");
    }

    fclose(fp_out);
    return 0;
}