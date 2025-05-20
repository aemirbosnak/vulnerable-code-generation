//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480
#define PIXEL_DEPTH 24

int main()
{
    unsigned char *image;
    unsigned char *oldImage;
    int i, j;

    image = (unsigned char*)malloc(WIDTH * HEIGHT * PIXEL_DEPTH);
    oldImage = (unsigned char*)malloc(WIDTH * HEIGHT * PIXEL_DEPTH);

    // Initialize image
    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            image[i * HEIGHT + j] = rand() % 256;
        }
    }

    // Print the original image
    printf("Original image:\n");
    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            printf("%3u ", image[i * HEIGHT + j]);
        }
        printf("\n");
    }

    printf("---------------------\n");

    // Edit the image
    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            if (i < 300 && j < 300)
            {
                image[i * HEIGHT + j] = 0;
            }
            else
            {
                image[i * HEIGHT + j] = 255;
            }
        }
    }

    // Print the edited image
    printf("Edited image:\n");
    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            printf("%3u ", image[i * HEIGHT + j]);
        }
        printf("\n");
    }

    return 0;
}