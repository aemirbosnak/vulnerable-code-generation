//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

void encode(char **img, int w, int h, char **msg)
{
    int i, j, k = 0;
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            (*img)[i * w + j] = (*img)[i * w + j] & 0xFC | (*msg)[k] << 2;
            k++;
        }
    }
}

void decode(char **img, int w, int h, char **msg)
{
    int i, j, k = 0;
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            (*msg)[k] = ((*img)[i * w + j] & 0x03) >> 2;
            k++;
        }
    }
}

int main()
{
    char img[MAX], msg[MAX];
    int w, h;

    printf("Enter image width: ");
    scanf("%d", &w);

    printf("Enter image height: ");
    scanf("%d", &h);

    printf("Enter message: ");
    scanf("%s", msg);

    encode(&img, w, h, &msg);

    printf("Encoded message: ");
    printf("%s", msg);

    decode(&img, w, h, &msg);

    printf("Decoded message: ");
    printf("%s", msg);

    return 0;
}