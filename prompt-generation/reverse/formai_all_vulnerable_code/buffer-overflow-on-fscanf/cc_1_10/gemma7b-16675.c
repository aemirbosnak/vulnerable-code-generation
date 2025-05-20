//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main()
{
    int i, j, k, n, m;
    char **a = (char **)malloc(MAX * sizeof(char *));
    char **b = (char **)malloc(MAX * sizeof(char *));
    char **c = (char **)malloc(MAX * sizeof(char *));
    FILE *fp;

    fp = fopen("stock_prices.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    n = 0;
    while (!feof(fp))
    {
        a[n] = (char *)malloc(20 * sizeof(char));
        b[n] = (char *)malloc(20 * sizeof(char));
        c[n] = (char *)malloc(20 * sizeof(char));
        fscanf(fp, "%s %s %s\n", a[n], b[n], c[n]);
        n++;
    }

    fclose(fp);

    for (i = 0; i < n; i++)
    {
        printf("Company: %s\n", a[i]);
        printf("Price: %s\n", b[i]);
        printf("Change: %s\n", c[i]);
        printf("\n");
    }

    for (i = 0; i < n; i++)
    {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }

    free(a);
    free(b);
    free(c);

    return 0;
}