//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, r, g, b, a;
    char img[1000];

    printf("Enter image file name: ");
    scanf("%s", img);

    FILE *fp = fopen(img, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(fp, "%d %d", &x, &y);
    r = g = b = a = 0;

    for (int i = 0; i < x * y; i++)
    {
        fscanf(fp, "%d %d %d %d", &r, &g, &b, &a);
        img[i] = (r << 24) | (g << 16) | (b << 8) | a;
    }

    fclose(fp);

    printf("Enter the number of pixels to edit: ");
    scanf("%d", &r);

    for (int i = 0; i < r; i++)
    {
        printf("Enter the pixel coordinates (x, y): ");
        scanf("%d %d", &x, &y);

        printf("Enter the new RGB values (r, g, b): ");
        scanf("%d %d %d", &r, &g, &b);

        img[x * y] = (r << 24) | (g << 16) | (b << 8) | a;
    }

    FILE *fp2 = fopen("edited.jpg", "w");
    if (fp2 == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(fp2, "%d %d\n", x, y);
    for (int i = 0; i < x * y; i++)
    {
        fprintf(fp2, "%d %d %d %d\n", img[i] >> 24, (img[i] & 0xff00) >> 16, (img[i] & 0x0ff0) >> 8, img[i] & 0xff);
    }

    fclose(fp2);

    printf("Image edited successfully.\n");

    return 0;
}