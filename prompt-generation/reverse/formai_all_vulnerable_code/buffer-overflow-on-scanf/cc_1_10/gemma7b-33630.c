//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, f, b, a[1000], freq[1000], h[1000], g[1000], p[1000];
    char ch, str[1000];

    printf("Enter the number of symbols: ");
    scanf("%d", &n);

    printf("Enter the symbols: ");
    scanf("%s", str);

    for (i = 0; i < n; i++)
    {
        a[i] = str[i];
        freq[i] = 1;
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                freq[i]++;
            }
        }
    }

    h[0] = 0;
    for (i = 1; i < n; i++)
    {
        h[i] = h[i - 1] + freq[i - 1] * 2;
    }

    g[0] = 0;
    for (i = 1; i < n; i++)
    {
        g[i] = h[i - 1] - freq[i - 1] * 2;
    }

    p[0] = 0;
    for (i = 1; i < n; i++)
    {
        p[i] = g[i] / 2;
    }

    printf("Huffman Code:\n");
    for (i = 0; i < n; i++)
    {
        printf("%c: %d\n", a[i], p[i]);
    }

    return 0;
}