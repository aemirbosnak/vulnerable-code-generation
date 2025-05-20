//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024

void image_to_ascii(char **image, int width, int height)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int pixel_value = image[y][x];
            switch (pixel_value)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("!");
                    break;
                case 2:
                    printf("$");
                    break;
                case 3:
                    printf("%");
                    break;
                case 4:
                    printf("#");
                    break;
                default:
                    printf("?");
            }
        }
        printf("\n");
    }
}

int main()
{
    char **image = NULL;
    int width, height;

    printf("Enter image width: ");
    scanf("%d", &width);

    printf("Enter image height: ");
    scanf("%d", &height);

    image = (char **)malloc(height * sizeof(char *) + 1);
    for (int i = 0; i < height; i++)
    {
        image[i] = (char *)malloc(width * sizeof(char) + 1);
    }

    printf("Enter image data (separate pixels with spaces): ");
    scanf("%s", image[0]);

    image_to_ascii(image, width, height);

    for (int i = 0; i < height; i++)
    {
        free(image[i]);
    }
    free(image);

    return 0;
}