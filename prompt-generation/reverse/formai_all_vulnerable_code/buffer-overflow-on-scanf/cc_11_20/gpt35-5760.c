//FormAI DATASET v1.0 Category: Image Editor ; Style: post-apocalyptic
#include <stdio.h>

int main()
{
    char img[500][500];
    int width, height;

    // take user input for image width and height
    printf("Enter image width: ");
    scanf("%d", &width);
    printf("Enter image height: ");
    scanf("%d", &height);

    // initialize image to all white pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            img[i][j] = 'W';
        }
    }

    // add some post-apocalyptic effects to the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i % 2 == 0 && j % 2 == 0)
            {
                img[i][j] = 'B'; // add some black and white stripes
            }

            if (i % 3 == 0 && j % 3 == 0)
            {
                img[i][j] = 'R'; // add some red dots
            }

            if (i >= height/2 && j >= width/2)
            {
                img[i][j] = 'G'; // darken the bottom right corner
            }
        }
    }

    // print the image to the console
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c ", img[i][j]);
        }
        printf("\n");
    }

    return 0;
}