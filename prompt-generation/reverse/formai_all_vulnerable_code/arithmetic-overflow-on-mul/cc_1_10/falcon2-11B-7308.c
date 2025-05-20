//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char buffer[1000];
    int width, height, size, i, j, k;
    int *image = NULL;

    fp = fopen("input.bmp", "rb");
    if (fp == NULL)
    {
        printf("Could not open file input.bmp\n");
        return 1;
    }

    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    fread(&size, sizeof(int), 1, fp);

    image = (int *)malloc(width * height * sizeof(int));
    if (image == NULL)
    {
        printf("Could not allocate memory for image\n");
        fclose(fp);
        return 1;
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            fread(&image[i * width + j], sizeof(int), 1, fp);
        }
    }
    fclose(fp);

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            image[i * width + j] = (i + height - 1) * width + j;
        }
    }

    fp = fopen("output.bmp", "wb");
    if (fp == NULL)
    {
        printf("Could not open file output.bmp\n");
        return 1;
    }

    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);
    fwrite(&size, sizeof(int), 1, fp);

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            fwrite(&image[i * width + j], sizeof(int), 1, fp);
        }
    }

    fclose(fp);

    return 0;
}