//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1024

void watermark(unsigned char *img, int w, int h, int k)
{
    int i, j, r, g, b, d;
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            r = img[3 * (i * w + j)] & 0xFF;
            g = img[3 * (i * w + j) + 1] & 0xFF;
            b = img[3 * (i * w + j) + 2] & 0xFF;
            d = (int) (r * k) / MAX + (int) (g * k) / MAX + (int) (b * k) / MAX;
            img[3 * (i * w + j)] = (r & 0xFF) | ((d & 0xFF) << 8);
            img[3 * (i * w + j) + 1] = (g & 0xFF) | ((d & 0xFF) << 8);
            img[3 * (i * w + j) + 2] = (b & 0xFF) | ((d & 0xFF) << 8);
        }
    }
}

int main()
{
    unsigned char *img = (unsigned char *) malloc(MAX * 3);
    int w, h, k;

    printf("Enter image width: ");
    scanf("%d", &w);

    printf("Enter image height: ");
    scanf("%d", &h);

    printf("Enter watermark key: ");
    scanf("%d", &k);

    printf("Enter watermark data: ");
    scanf("%s", img);

    watermark(img, w, h, k);

    printf("Watermarked image:\n");
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf("%c ", img[3 * (i * w + j)] & 0xFF);
        }
        printf("\n");
    }

    free(img);

    return 0;
}