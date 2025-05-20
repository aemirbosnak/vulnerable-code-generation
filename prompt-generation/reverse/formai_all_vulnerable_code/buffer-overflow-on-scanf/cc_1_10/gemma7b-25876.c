//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **image_to_ascii(char **image, int w, int h)
{
    int i, j, k;
    char **ascii_image = NULL;

    ascii_image = malloc(h * sizeof(char *));
    for (i = 0; i < h; i++)
    {
        ascii_image[i] = malloc(w * sizeof(char));
    }

    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            int pixel_value = image[i][j];
            switch (pixel_value)
            {
                case 0:
                    ascii_image[i][j] = ' ';
                    break;
                case 255:
                    ascii_image[i][j] = '#';
                    break;
                default:
                    ascii_image[i][j] = '.';
                    break;
            }
        }
    }

    return ascii_image;
}

int main()
{
    char **image = NULL;
    int w, h;

    // Read image dimensions
    scanf("Enter width: ", &w);
    scanf("Enter height: ", &h);

    // Allocate memory for the image
    image = malloc(h * sizeof(char *));
    for (int i = 0; i < h; i++)
    {
        image[i] = malloc(w * sizeof(char));
    }

    // Read pixel values
    printf("Enter pixel values (separated by spaces): ");
    char pixel_values[1024];
    scanf("%s", pixel_values);

    // Convert pixel values to ASCII art
    image_to_ascii(image, w, h);

    // Print ASCII art
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf("%c", image[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < h; i++)
    {
        free(image[i]);
    }
    free(image);

    return 0;
}