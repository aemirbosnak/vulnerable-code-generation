//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int width, height;
    printf("Enter image width: ");
    scanf("%d", &width);
    printf("Enter image height: ");
    scanf("%d", &height);

    int **image = (int **)malloc(height * sizeof(int *));
    for (int h = 0; h < height; h++)
    {
        image[h] = (int *)malloc(width * sizeof(int));
    }

    printf("Enter image pixel values (separated by commas): ");
    char input[256];
    scanf("%s", input);

    // Convert input string to int array
    int pixels = 0;
    int pixel_array[height * width];
    char *p = input;
    while (p && pixels < height * width)
    {
        pixel_array[pixels++] = atoi(p);
        p += 2;
    }

    // Convert pixel array to ASCII art
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int pixel_value = pixel_array[h * width + w];
            switch (pixel_value)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(". ");
                    break;
                case 2:
                    printf(".. ");
                    break;
                case 3:
                    printf("... ");
                    break;
                default:
                    printf("Error ");
                    break;
            }
        }
        printf("\n");
    }

    // Free memory
    for (int h = 0; h < height; h++)
    {
        free(image[h]);
    }
    free(image);

    return 0;
}