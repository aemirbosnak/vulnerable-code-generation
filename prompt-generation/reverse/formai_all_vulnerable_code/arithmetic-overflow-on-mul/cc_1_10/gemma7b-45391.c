//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1024

void watermark(char **img, int w, int h)
{
    int i, j, k;
    for (i = 0; i < w; i++)
    {
        for (j = 0; j < h; j++)
        {
            k = (i + j) % MAX_SIZE;
            img[i][j] ^= (k & 0x1) << 2;
        }
    }
}

int main()
{
    char **img = NULL;
    int w, h;

    printf("Enter the width of the image: ");
    scanf("%d", &w);

    printf("Enter the height of the image: ");
    scanf("%d", &h);

    img = (char **)malloc(w * h * sizeof(char));

    printf("Enter the watermark: ");
    char watermark_str[MAX_SIZE] = "";
    scanf("%s", watermark_str);

    watermark(img, w, h);

    printf("Watermarked image:\n");
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            printf("%c ", img[j][i]);
        }
        printf("\n");
    }

    free(img);

    return 0;
}