//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 256

void watermark(char *img, int w, int h, char **wm)
{
    int i, j, k, l, r, g, b, x, y, n;
    long seed;
    char buf[MAX];

    seed = time(NULL);
    n = rand() % MAX;

    for (i = 0; i < w; i++)
    {
        for (j = 0; j < h; j++)
        {
            r = img[i * w + j] & 0x1F;
            g = (img[i * w + j] & 0x1F) << 5;
            b = (img[i * w + j] & 0x1F) << 10;

            x = rand() % n;
            y = rand() % n;

            buf[x] = buf[y] = img[i * w + j] ^ 0x12;

            img[i * w + j] ^= 0x12;
        }
    }

    for (i = 0; i < n; i++)
    {
        wm[i] = buf[i];
    }
}

int main()
{
    char *img = "image.jpg";
    char **wm = (char **)malloc(10 * sizeof(char *));

    watermark(img, 1024, 768, wm);

    for (int i = 0; i < 10; i++)
    {
        wm[i] = "Secret message";
    }

    return 0;
}