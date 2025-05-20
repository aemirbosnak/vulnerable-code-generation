//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char msg[1024];
    char img[512];
    int i, j, k, l, n, m, size = 0;

    printf("Enter a secret message: ");
    scanf("%s", msg);

    printf("Enter the image file name: ");
    scanf("%s", img);

    FILE *fp = fopen(img, "rb");
    if (fp == NULL)
    {
        printf("Error opening image file.\n");
        return 1;
    }

    n = fread(img, 1, 512, fp);
    fclose(fp);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 4; j++)
        {
            k = (img[i] & 0xf0) >> 4;
            l = img[i] & 0x0f;
            m = (k + l) % 2;
            img[i] ^= m;
        }
    }

    size = strlen(msg) + 1;
    for (i = 0; i < size; i++)
    {
        img[i] ^= msg[i];
    }

    fp = fopen(img, "wb");
    if (fp == NULL)
    {
        printf("Error writing image file.\n");
        return 1;
    }

    fwrite(img, 1, n, fp);
    fclose(fp);

    printf("Secret message hidden. Image file saved.\n");

    return 0;
}