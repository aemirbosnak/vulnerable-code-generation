//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void image_to_ascii(char **img, int w, int h)
{
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            int pixel_value = img[y][x];
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
                case 4:
                    printf(".... ");
                    break;
                default:
                    printf("Error!");
            }
        }
        printf("\n");
    }
}

int main()
{
    char **img = NULL;
    int w = 0;
    int h = 0;

    // Allocate memory for the image
    img = (char **)malloc(h * w * sizeof(char *));
    for (int i = 0; i < h; i++)
    {
        img[i] = (char *)malloc(w * sizeof(char));
    }

    // Get the image dimensions
    printf("Enter the width of the image: ");
    scanf("%d", &w);

    printf("Enter the height of the image: ");
    scanf("%d", &h);

    // Get the image pixels
    printf("Enter the pixels of the image (separated by commas): ");
    char pixel_str[1024];
    scanf("%s", pixel_str);

    // Convert the pixel string into an array
    int pixels[h * w];
    char *p = pixel_str;
    for (int i = 0; i < h * w; i++)
    {
        pixels[i] = atoi(p);
        p += 1;
    }

    // Fill the image with pixels
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            img[y][x] = pixels[y * w + x];
        }
    }

    // Convert the image to ASCII art
    image_to_ascii(img, w, h);

    // Free the memory
    for (int i = 0; i < h; i++)
    {
        free(img[i]);
    }
    free(img);

    return 0;
}