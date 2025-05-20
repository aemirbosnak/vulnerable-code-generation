//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: calm
#include <stdio.h>
#include <string.h>

int main()
{
    char image[1024];
    int width, height;

    printf("Enter the image file path: ");
    scanf("%s", image);

    FILE *file = fopen(image, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(file, "Dimensions: %dx%d", &width, &height);

    printf("Image dimensions: %dx%d\n", width, height);

    fscanf(file, "%[^\n]%*c", image);

    fclose(file);

    char asciiImage[height][width];

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            asciiImage[row][col] = image[row * width + col];
        }
    }

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            switch (asciiImage[row][col])
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf("$");
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

    return 0;
}