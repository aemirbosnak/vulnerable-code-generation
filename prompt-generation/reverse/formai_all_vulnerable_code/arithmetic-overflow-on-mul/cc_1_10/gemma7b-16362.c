//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

typedef struct Pixel
{
    int r, g, b, a;
} Pixel;

Pixel pixels[MAX];

void hide(char *msg)
{
    int i = 0;
    while (pixels[i].a != 0)
    {
        int n = msg[i] & 0x0F;
        pixels[i].r += n;
        pixels[i].g += n;
        pixels[i].b += n;
        i++;
    }
}

int main()
{
    FILE *fp = fopen("image.jpg", "rb");
    int w, h;
    fscanf(fp, "%d %d", &w, &h);

    for (int i = 0; i < w * h; i++)
    {
        fscanf(fp, "%d %d %d %d", &pixels[i].r, &pixels[i].g, &pixels[i].b, &pixels[i].a);
    }

    char msg[] = "Hello, world!";
    hide(msg);

    FILE *fp2 = fopen("image_stego.jpg", "wb");
    fprintf(fp2, "%d %d\n", w, h);

    for (int i = 0; i < w * h; i++)
    {
        fprintf(fp2, "%d %d %d %d\n", pixels[i].r, pixels[i].g, pixels[i].b, pixels[i].a);
    }

    fclose(fp);
    fclose(fp2);

    return 0;
}