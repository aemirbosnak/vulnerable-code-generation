//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main()
{
    int i, n, m, price[MAX], low[MAX], high[MAX], volume[MAX];
    char symbol[MAX];
    time_t t;

    printf("Enter the number of stocks: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the symbol of the stock: ");
        scanf("%s", symbol);

        printf("Enter the initial price of the stock: ");
        scanf("%d", &price[i]);

        printf("Enter the low price of the stock: ");
        scanf("%d", &low[i]);

        printf("Enter the high price of the stock: ");
        scanf("%d", &high[i]);

        printf("Enter the volume of the stock: ");
        scanf("%d", &volume[i]);
    }

    t = time(NULL);

    printf("\nTime: %s",ctime(&t));

    for (i = 0; i < n; i++)
    {
        printf("%s: ", symbol[i]);

        printf("Price: %.2f, ", (price[i] - low[i]) / high[i] * 100.0);

        printf("Volume: %d", volume[i]);

        printf("\n");
    }

    return 0;
}