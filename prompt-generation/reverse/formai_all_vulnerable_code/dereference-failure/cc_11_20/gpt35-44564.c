//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int width = 0, height = 0;      // width and height of the image
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);

    int **image = (int **)malloc(height * sizeof(int *));    // dynamic allocation of memory for the image array
    for(int i = 0; i < height; i++)
        image[i] = (int *)malloc(width * sizeof(int));

    printf("Enter the pixel values of the image: \n");
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
            scanf("%d", &image[i][j]);
    }

    printf("\nThe ASCII art representation of the image is: \n");
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(image[i][j] <= 25)
                printf("@");        // use '@' for darkest pixel values
            else if(image[i][j] <= 50)
                printf("#");
            else if(image[i][j] <= 75)
                printf("&");
            else if(image[i][j] <= 100)
                printf("8");
            else if(image[i][j] <= 125)
                printf("o");
            else if(image[i][j] <= 150)
                printf(":");
            else if(image[i][j] <= 175)
                printf("*");
            else if(image[i][j] <= 200)
                printf(".");
            else if(image[i][j] <= 225)
                printf(" ");
            else
                printf(" ");        // use space for lightest pixel values
        }
        printf("\n");
    }

    for(int i = 0; i < height; i++)     // deallocating memory
        free(image[i]);
    free(image);
    return 0;
}