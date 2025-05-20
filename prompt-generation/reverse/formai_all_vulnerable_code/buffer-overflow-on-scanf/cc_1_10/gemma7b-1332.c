//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char stock_name[20];
    int i, j, k, total_stocks = 0, current_price = 0, previous_price = 0, change = 0;

    system("cls");
    printf("Enter the name of the stock you want to track: ");
    scanf("%s", stock_name);

    FILE *fp = fopen("stock_prices.txt", "r");
    if (fp == NULL)
    {
        fp = fopen("stock_prices.txt", "w");
        fprintf(fp, "%s\n", stock_name);
        fclose(fp);
        current_price = 100;
    }
    else
    {
        fscanf(fp, "%d", &current_price);
        fclose(fp);
    }

    printf("Current price of %s: $%d\n", stock_name, current_price);

    printf("Enter the previous price of the stock: ");
    scanf("%d", &previous_price);

    change = current_price - previous_price;

    printf("Change in price: $%d\n", change);

    if (change > 0)
    {
        printf("The stock is up!**\n");
    }
    else if (change < 0)
    {
        printf("The stock is down!**\n");
    }
    else
    {
        printf("The stock is unchanged.**\n");
    }

    return 0;
}