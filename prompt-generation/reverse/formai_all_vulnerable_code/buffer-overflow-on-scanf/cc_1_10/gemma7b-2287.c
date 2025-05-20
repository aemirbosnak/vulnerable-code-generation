//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int main()
{
    int i, j, k, n, m, b, a[MAX], price[MAX], vol[MAX], time[MAX];
    char symbol[MAX];

    printf("Enter the number of stocks: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the symbol of the stock: ");
        scanf("%s", symbol[i]);

        printf("Enter the current price of the stock: ");
        scanf("%d", &price[i]);

        printf("Enter the volatility of the stock: ");
        scanf("%d", &vol[i]);

        printf("Enter the time of the transaction: ");
        scanf("%d", &time[i]);
    }

    m = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (price[i] > price[j])
            {
                b = price[i] - price[j];
                a[m] = b;
                m++;
            }
        }
    }

    printf("The following are the differences in price between pairs of stocks: \n");
    for (i = 0; i < m; i++)
    {
        printf("%d. %s and %s, the difference is: %d\n", time[i], symbol[i], symbol[i - 1], a[i]);
    }

    return 0;
}