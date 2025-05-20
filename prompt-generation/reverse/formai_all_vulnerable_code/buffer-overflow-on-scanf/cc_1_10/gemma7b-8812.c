//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int width, height;
    printf("Enter image width: ");
    scanf("%d", &width);
    printf("Enter image height: ");
    scanf("%d", &height);

    char **image = (char **)malloc(height * sizeof(char *) + 1);
    for (int r = 0; r < height; r++)
    {
        image[r] = (char *)malloc(width * sizeof(char) + 1);
    }

    printf("Enter image data (separated by spaces): ");
    char data[1000];
    scanf("%[^\n]%*c", data);

    int i = 0;
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            image[r][c] = data[i];
            i++;
        }
    }

    printf("Image in ASCII art:\n");
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            switch (image[r][c])
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("·");
                    break;
                case 2:
                    printf("○");
                    break;
                case 3:
                    printf("█");
                    break;
                default:
                    printf("Error");
            }
        }
        printf("\n");
    }

    free(image);
    return 0;
}