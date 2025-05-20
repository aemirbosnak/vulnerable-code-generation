//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, l, n, m, flag = 0;
    char a[1024], b[1024], c[1024];

    printf("Enter the number of characters you want to embed: ");
    scanf("%d", &n);

    printf("Enter the secret message: ");
    scanf("%s", a);

    printf("Enter the image file name: ");
    scanf("%s", b);

    FILE *fp = fopen(b, "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    k = fread(c, 1, 1024, fp);
    fclose(fp);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            l = c[j] & 0x1F;
            m = a[i] & 0x1F;
            c[j] ^= (l ^ m) & 0x1F;
        }
    }

    fp = fopen(b, "w");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    fwrite(c, 1, k, fp);
    fclose(fp);

    printf("Secret message embedded.\n");
    return 0;
}