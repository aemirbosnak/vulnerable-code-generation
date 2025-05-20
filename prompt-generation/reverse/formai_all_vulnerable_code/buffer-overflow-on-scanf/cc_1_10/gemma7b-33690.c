//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int main()
{
    int i, j, k, l, n, m, a[MAX], b[MAX], c[MAX];

    system("CLS");

    printf("The Stock Market Tracker is SHOCKED!!!\n\n");

    printf("Enter the number of stocks you want to track: ");
    scanf("%d", &n);

    printf("Enter the ticker symbols of the stocks: ");
    for (i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
    }

    printf("Enter the initial prices of the stocks: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", b[i]);
    }

    printf("Enter the daily price changes of the stocks: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", c[i]);
    }

    printf("\n");

    printf("The following are the stock prices for the day: \n");
    for (i = 0; i < n; i++)
    {
        l = b[i] + c[i];
        printf("%s: $%d\n", a[i], l);
    }

    printf("\n");

    printf("The SHOCKED Stock Market Tracker is FINISHED!!!\n");

    return 0;
}