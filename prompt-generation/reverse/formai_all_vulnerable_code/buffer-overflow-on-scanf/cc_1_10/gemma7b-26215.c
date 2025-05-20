//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char image[1024];
    printf("Enter the image path: ");
    scanf("%s", image);

    FILE *fp = fopen(image, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    char buffer[1024];
    int i = 0;
    while (fgets(buffer, 1024, fp) != NULL)
    {
        image[i++] = buffer[0];
    }

    fclose(fp);

    image[i] = '\0';

    char ascii_image[1024];
    int j = 0;
    for (i = 0; image[i] != '\0'; i++)
    {
        switch (image[i])
        {
            case 0:
                ascii_image[j++] = ' ';
                break;
            case 1:
                ascii_image[j++] = '.';
                break;
            case 2:
                ascii_image[j++] = '_';
                break;
            case 3:
                ascii_image[j++] = '=';
                break;
            case 4:
                ascii_image[j++] = '*';
                break;
            case 5:
                ascii_image[j++] = '#';
                break;
            default:
                ascii_image[j++] = ' ';
                break;
        }
    }

    ascii_image[j] = '\0';

    printf("ASCII image:\n");
    printf("%s\n", ascii_image);

    return 0;
}