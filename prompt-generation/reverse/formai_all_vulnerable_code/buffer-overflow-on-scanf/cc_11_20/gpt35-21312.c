//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXELS 512

int main()
{
    int image[MAX_PIXELS][MAX_PIXELS];
    int rows,cols;
    int i,j, temp, brightness, contrast;
    char choice;

    printf("Enter the number of rows of the image: ");
    scanf("%d",&rows);
    printf("Enter the number of columns of the image: ");
    scanf("%d",&cols);

    printf("Enter the pixel values of the image(A value between 0-255):\n");

    for (i=0;i<rows;i++)
        for (j=0;j<cols;j++)
            scanf("%d",&image[i][j]);

    printf("Do you want to flip the image (y/n)? ");
    scanf(" %c",&choice);

    if (choice == 'y')
    {
        for (i=0;i<rows;i++)
            for (j=0;j<cols/2;j++)
            {
                temp = image[i][j];
                image[i][j] = image[i][cols-j-1];
                image[i][cols-j-1] = temp;
            }
    }

    printf("Enter the brightness value (0-255): ");
    scanf("%d",&brightness);

    printf("Enter the contrast value (0-255): ");
    scanf("%d",&contrast);

    for (i=0;i<rows;i++)
        for (j=0;j<cols;j++)
        {
            image[i][j] += brightness;
            if (image[i][j]<0) image[i][j] = 0;
            else if (image[i][j]>255) image[i][j] = 255;
            image[i][j] = (int) (image[i][j]*(contrast/255.0-0.5)+128);
            if (image[i][j]<0) image[i][j] = 0;
            else if (image[i][j]>255) image[i][j] = 255;
        }

    printf("The processed image is:\n");

    for (i=0;i<rows;i++)
    {
        for (j=0;j<cols;j++)
            printf("%d ",image[i][j]);
        printf("\n");
    }

    return 0;
}