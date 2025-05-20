//Gemma-7B DATASET v1.0 Category: QR code reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0, p = 0, q = 0, r = 0, s = 0;
    char a[100], b[100], c[100], d[100], e[100], f[100], g[100], h[100], i_s[100];
    long int x = 0, y = 0, z = 0, w = 0, h_w = 0;
    FILE *fp;

    fp = fopen("qrcode.txt", "r");
    fscanf(fp, "%s", i_s);

    for (i = 0; i_s[i] != '\0'; i++)
    {
        a[i] = i_s[i];
    }

    for (j = 0; a[j] != '\0'; j++)
    {
        if (a[j] >= 'a' && a[j] <= 'z')
        {
            b[k] = a[j] - 32;
            k++;
        }
    }

    for (l = 0; b[l] != '\0'; l++)
    {
        c[m] = (b[l] - 'A') * 4 + 1;
        m++;
    }

    for (n = 0; c[n] != '\0'; n++)
    {
        d[o] = (c[n] - 1) / 4 + 'A';
        o++;
    }

    for (p = 0; d[p] != '\0'; p++)
    {
        e[q] = d[p] - 'A' + 32;
        q++;
    }

    for (r = 0; e[r] != '\0'; r++)
    {
        printf("%c", e[r]);
    }

    fclose(fp);
}