//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Variables
    char image[1024];
    int width, height;
    int i, j;

    // Get image data from user
    printf("Enter the image data (separated by spaces): ");
    scanf("%s", image);

    // Calculate image dimensions
    width = (int)strlen(image) / 3;
    height = 1;
    for (i = 0; image[i] != '\0'; i++)
    {
        if (image[i] == ',')
            height++;
    }

    // Convert image to ASCII art
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            switch (image[j * 3 + i])
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(". ");
                    break;
                case 2:
                    printf("* ");
                    break;
                case 3:
                    printf("o ");
                    break;
                case 4:
                    printf("# ");
                    break;
            }
        }
        printf("\n");
    }

    return 0;
}