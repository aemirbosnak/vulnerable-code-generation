//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j, height, width, channels;
    unsigned char *image_data;
    unsigned char *image_data_flip;

    printf("Enter the dimensions of the image (width x height): ");
    scanf("%d %d", &width, &height);

    printf("Enter the number of color channels in the image: ");
    scanf("%d", &channels);

    image_data = (unsigned char *) malloc(width * height * channels);
    image_data_flip = (unsigned char *) malloc(width * height * channels);

    printf("Enter the RGB values for each pixel in the image:\n");
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            scanf("%d %d %d", &image_data[i * width * channels + j * channels], &image_data[i * width * channels + j * channels + 1], &image_data[i * width * channels + j * channels + 2]);
        }
    }

    // Flip the image horizontally
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width / 2; j++)
        {
            unsigned char temp = image_data[i * width * channels + j * channels];
            image_data[i * width * channels + j * channels] = image_data[i * width * channels + width / 2 + (j * channels + width / 2)];
            image_data[i * width * channels + width / 2 + (j * channels + width / 2)] = temp;

            temp = image_data[i * width * channels + j * channels + 1];
            image_data[i * width * channels + j * channels + 1] = image_data[i * width * channels + width / 2 + (j * channels + width / 2) + 1];
            image_data[i * width * channels + width / 2 + (j * channels + width / 2) + 1] = temp;

            temp = image_data[i * width * channels + j * channels + 2];
            image_data[i * width * channels + j * channels + 2] = image_data[i * width * channels + width / 2 + (j * channels + width / 2) + 2];
            image_data[i * width * channels + width / 2 + (j * channels + width / 2) + 2] = temp;
        }
    }

    // Increase brightness
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            unsigned char temp = image_data[i * width * channels + j * channels];
            image_data[i * width * channels + j * channels] += 50;
            if (image_data[i * width * channels + j * channels] > 255)
            {
                image_data[i * width * channels + j * channels] = 255;
            }
            else if (image_data[i * width * channels + j * channels] < 0)
            {
                image_data[i * width * channels + j * channels] = 0;
            }

            temp = image_data[i * width * channels + j * channels + 1];
            image_data[i * width * channels + j * channels + 1] += 50;
            if (image_data[i * width * channels + j * channels + 1] > 255)
            {
                image_data[i * width * channels + j * channels + 1] = 255;
            }
            else if (image_data[i * width * channels + j * channels + 1] < 0)
            {
                image_data[i * width * channels + j * channels + 1] = 0;
            }

            temp = image_data[i * width * channels + j * channels + 2];
            image_data[i * width * channels + j * channels + 2] += 50;
            if (image_data[i * width * channels + j * channels + 2] > 255)
            {
                image_data[i * width * channels + j * channels + 2] = 255;
            }
            else if (image_data[i * width * channels + j * channels + 2] < 0)
            {
                image_data[i * width * channels + j * channels + 2] = 0;
            }
        }
    }

    // Decrease contrast
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            unsigned char temp = image_data[i * width * channels + j * channels];
            image_data[i * width * channels + j * channels] -= 50;
            if (image_data[i * width * channels + j * channels] < 0)
            {
                image_data[i * width * channels + j * channels] = 0;
            }
            else if (image_data[i * width * channels + j * channels] > 255)
            {
                image_data[i * width * channels + j * channels] = 255;
            }

            temp = image_data[i * width * channels + j * channels + 1];
            image_data[i * width * channels + j * channels + 1] -= 50;
            if (image_data[i * width * channels + j * channels + 1] < 0)
            {
                image_data[i * width * channels + j * channels + 1] = 0;
            }
            else if (image_data[i * width * channels + j * channels + 1] > 255)
            {
                image_data[i * width * channels + j * channels + 1] = 255;
            }

            temp = image_data[i * width * channels + j * channels + 2];
            image_data[i * width * channels + j * channels + 2] -= 50;
            if (image_data[i * width * channels + j * channels + 2] < 0)
            {
                image_data[i * width * channels + j * channels + 2] = 0;
            }
            else if (image_data[i * width * channels + j * channels + 2] > 255)
            {
                image_data[i * width * channels + j * channels + 2] = 255;
            }
        }
    }

    // Display the modified image
    printf("Modified Image:\n");
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            printf("%d %d %d\n", image_data[i * width * channels + j * channels], image_data[i * width * channels + j * channels + 1], image_data[i * width * channels + j * channels + 2]);
        }
    }

    free(image_data);
    free(image_data_flip);

    return 0;
}