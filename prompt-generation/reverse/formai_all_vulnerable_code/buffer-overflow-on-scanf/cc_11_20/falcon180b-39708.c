//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 45

int main()
{
    FILE *fp;
    char filename[100];
    int i, j, x, y;
    int count = 0;
    char pixel;

    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    // Open the image file
    fp = fopen(filename, "rb");

    // Check if the file was opened successfully
    if (fp == NULL)
    {
        printf("Error: File not found.\n");
        exit(1);
    }

    // Read the image data
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            fread(&pixel, 1, 1, fp);

            if (pixel == 0)
            {
                printf("  ");
            }
            else if (pixel == 1)
            {
                printf(" *");
            }
            else if (pixel == 2)
            {
                printf(" o");
            }
            else if (pixel == 3)
            {
                printf(" O");
            }
            else if (pixel == 4)
            {
                printf(" @");
            }
            else if (pixel == 5)
            {
                printf(" #");
            }
            else if (pixel == 6)
            {
                printf(" $");
            }
            else if (pixel == 7)
            {
                printf(" %");
            }
            else
            {
                printf("?");
            }

            count++;
        }

        printf("\n");
    }

    // Close the image file
    fclose(fp);

    printf("\n%d pixels converted to ASCII art.\n", count);

    return 0;
}