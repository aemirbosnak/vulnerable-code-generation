//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

int main()
{
    char img[MAX], msg[MAX], key[MAX];
    int i, j, k, l, n, hidden, msg_len, img_len;

    printf("Enter the image file name: ");
    scanf("%s", img);

    printf("Enter the secret message: ");
    scanf("%s", msg);

    printf("Enter the key: ");
    scanf("%s", key);

    img_len = readImage(img, img);
    msg_len = strlen(msg);
    hidden = hideMessage(img, msg, key, img_len, msg_len);

    if (hidden)
    {
        printf("Message hidden successfully!\n");
    }
    else
    {
        printf("Error hiding message.\n");
    }

    return 0;
}

int readImage(char *img_file, char *img)
{
    FILE *fp;
    int i, img_len = 0;

    fp = fopen(img_file, "rb");
    if (fp == NULL)
    {
        return -1;
    }

    while (!feof(fp))
    {
        img[img_len++] = fgetc(fp);
    }

    fclose(fp);

    return img_len;
}

int hideMessage(char *img, char *msg, char *key, int img_len, int msg_len)
{
    int i, j, k, l, n, hidden = 0;
    char *p, *q;

    n = strlen(key);
    p = img;
    q = msg;

    for (i = 0; i < msg_len; i++)
    {
        for (j = 0; j < n; j++)
        {
            k = (p[j] ^ key[j]) & MAX;
            l = (q[i] & MAX) >> 2;
            p[j] ^= l;
        }
    }

    hidden = 1;

    return hidden;
}