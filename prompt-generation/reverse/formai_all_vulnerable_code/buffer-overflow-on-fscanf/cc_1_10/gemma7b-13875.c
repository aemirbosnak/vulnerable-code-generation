//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char image[1024] = "IMG_001.jpg";
    FILE *fp;
    unsigned char pixel;
    int x, y;

    fp = fopen(image, "rb");
    if (fp == NULL)
    {
        return -1;
    }

    fscanf(fp, "%d %d", &x, &y);

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            pixel = fgetc(fp);
            switch (pixel)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("·");
                    break;
                case 2:
                    printf(":");
                    break;
                case 3:
                    printf("!");
                    break;
                case 4:
                    printf("#");
                    break;
                default:
                    printf("!");
                    break;
            }
        }
        printf("\n");
    }

    fclose(fp);

    return 0;
}