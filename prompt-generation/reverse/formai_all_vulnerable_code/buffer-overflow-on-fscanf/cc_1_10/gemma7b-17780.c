//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char image[1024];
    int width, height;

    printf("Enter image file name: ");
    scanf("%s", image);

    FILE *fp = fopen(image, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    fscanf(fp, "%d %d", &width, &height);

    printf("Image dimensions: %dx%d\n", width, height);

    fread(image, 1, width * height, fp);

    fclose(fp);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int pixel = image[x + y * width];

            switch (pixel)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf("#");
                    break;
                default:
                    printf("!");
                    break;
            }
        }

        printf("\n");
    }

    return 0;
}