//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 256
#define HEIGHT 100
#define WIDTH 100

int main(int argc, char *argv[])
{
    FILE *fp;
    int i, j, x, y, n, max, min, sum, avg, bright, cont;
    unsigned char *img, *ptr;
    char filename[50];

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    n = ftell(fp);
    rewind(fp);
    img = (unsigned char *)malloc(n);
    fread(img, n, 1, fp);
    fclose(fp);

    printf("Enter the brightness (0-255): ");
    scanf("%d", &bright);

    printf("Enter the contrast (0-100): ");
    scanf("%d", &cont);

    max = bright + (MAX - bright) * cont / 100;
    min = bright - (MAX - bright) * cont / 100;

    ptr = img;
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            sum = 0;
            avg = 0;
            for (x = -1; x <= 1; x++)
            {
                for (y = -1; y <= 1; y++)
                {
                    sum += *(ptr + (i + x) * WIDTH + j + y);
                }
            }
            avg = sum / 9;

            if (avg < min)
                *(ptr + i * WIDTH + j) = min;
            else if (avg > max)
                *(ptr + i * WIDTH + j) = max;
        }
        ptr += WIDTH;
    }

    fp = fopen("output.bmp", "wb");
    if (fp == NULL)
    {
        printf("Error creating file.\n");
        exit(1);
    }

    fwrite(img, n, 1, fp);
    fclose(fp);

    printf("Image processed successfully.\n");

    return 0;
}