//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int img_width = 512;
    int img_height = 512;
    unsigned char *img_data = (unsigned char *)malloc(img_width * img_height * 3);

    // Image data initialization
    for (int i = 0; i < img_width * img_height; i++)
    {
        img_data[i] = 0;
    }

    // Gaussian blur
    int radius = 3;
    for (int y = 0; y < img_height; y++)
    {
        for (int x = 0; x < img_width; x++)
        {
            int sum = 0;
            for (int dy = -radius; dy <= radius; dy++)
            {
                for (int dx = -radius; dx <= radius; dx++)
                {
                    int x_prime = x + dx;
                    int y_prime = y + dy;
                    if (x_prime >= 0 && x_prime < img_width && y_prime >= 0 && y_prime < img_height)
                    {
                        sum += img_data[x_prime * img_height + y_prime] * 2;
                    }
                }
            }
            img_data[x * img_height + y] = (sum / (2 * radius * radius)) + 128;
        }
    }

    // Display the image
    printf("Image:\n");
    for (int i = 0; i < img_height; i++)
    {
        for (int j = 0; j < img_width; j++)
        {
            printf("%c ", img_data[j * img_height + i]);
        }
        printf("\n");
    }

    free(img_data);
    return 0;
}