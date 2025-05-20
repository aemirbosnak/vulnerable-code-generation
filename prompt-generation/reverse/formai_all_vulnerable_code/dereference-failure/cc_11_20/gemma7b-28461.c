//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

int main()
{
    // Allocate memory for image data
    int **image = (int **)malloc(MAX_HEIGHT * sizeof(int *));
    for (int h = 0; h < MAX_HEIGHT; h++)
    {
        image[h] = (int *)malloc(MAX_WIDTH * sizeof(int));
    }

    // Get image data from user
    printf("Enter the number of rows: ");
    int height = atoi(stdin);

    printf("Enter the number of columns: ");
    int width = atoi(stdin);

    printf("Enter the pixel values: ");
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w] = atoi(stdin);
        }
    }

    // Convert image data to ASCII art
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int pixelValue = image[h][w];

            switch (pixelValue)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf("*");
                    break;
                case 3:
                    printf("#");
                    break;
                default:
                    printf("!");
                    break;
            }
        }

        printf("\n");
    }

    // Free memory
    for (int h = 0; h < MAX_HEIGHT; h++)
    {
        free(image[h]);
    }
    free(image);

    return 0;
}