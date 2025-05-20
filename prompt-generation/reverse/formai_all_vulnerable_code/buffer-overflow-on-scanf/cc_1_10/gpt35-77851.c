//FormAI DATASET v1.0 Category: Image compression ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compress an image
void compressImage(int image[100][100], int width, int height)
{
    // Step 1 - Find the average of each 2x2 block
    int compressedImage[50][50];
    for(int i = 0; i < height; i += 2)
    {
        for(int j = 0; j < width; j += 2)
        {
            int avg = (image[i][j] + image[i][j+1] + image[i+1][j] + image[i+1][j+1]) / 4;
            compressedImage[i/2][j/2] = avg;
        }
    }

    // Step 2 - Perform logarithmic compression on the image
    for(int i = 0; i < height/2; i++)
    {
        for(int j = 0; j < width/2; j++)
        {
            compressedImage[i][j] = log(compressedImage[i][j] + 1);
        }
    }

    // Step 3 - Print the compressed image
    for(int i = 0; i < height/2; i++)
    {
        for(int j = 0; j < width/2; j++)
        {
            printf("%d ", compressedImage[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int image[100][100];
    int width, height;

    printf("Enter the width and height of the image: ");
    scanf("%d %d", &width, &height);

    // Accept the image values from user
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            scanf("%d", &image[i][j]);
        }
    }

    // Compress the image and print the compressed image
    compressImage(image, width, height);
    return 0;
}