//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int img_width, img_height;
    printf("Enter the width of the image: ");
    scanf("%d", &img_width);

    printf("Enter the height of the image: ");
    scanf("%d", &img_height);

    unsigned char **img_data = (unsigned char **)malloc(img_height * sizeof(unsigned char *) + 1);
    for (int h = 0; h < img_height; h++)
    {
        img_data[h] = (unsigned char *)malloc(img_width * sizeof(unsigned char) + 1);
    }

    printf("Enter the image data (separated by commas): ");
    char image_data[1000];
    scanf("%s", image_data);

    // Convert image data to binary
    int index = 0;
    for (int h = 0; h < img_height; h++)
    {
        for (int w = 0; w < img_width; w++)
        {
            img_data[h][w] = image_data[index] & 0xFF;
            index++;
        }
    }

    // Convert binary to ASCII art
    for (int h = 0; h < img_height; h++)
    {
        for (int w = 0; w < img_width; w++)
        {
            switch (img_data[h][w])
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("·");
                    break;
                case 2:
                    printf("§");
                    break;
                case 3:
                    printf("$");
                    break;
                default:
                    printf("!");
                    break;
            }
        }
        printf("\n");
    }

    // Free memory
    for (int h = 0; h < img_height; h++)
    {
        free(img_data[h]);
    }
    free(img_data);

    return 0;
}