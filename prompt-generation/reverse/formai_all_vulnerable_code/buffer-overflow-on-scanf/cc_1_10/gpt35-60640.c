//FormAI DATASET v1.0 Category: Stock market tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int numOfStocks = 0;
    double currentPrice;
    double previousPrice;
    double difference;
    char name[50];

    printf("How many stocks would you like to track? ");
    scanf("%d", &numOfStocks);

    struct stock
    {
        char name[50];
        double price;
    };

    struct stock stocks[numOfStocks];

    for (int i = 0; i < numOfStocks; i++)
    {
        printf("Enter the name of stock %d: ", i+1);
        scanf("%s", &stocks[i].name);
        printf("Enter the current price of stock %d: ", i+1);
        scanf("%lf", &stocks[i].price);
    }

    while (1)
    {
        system("clear");
        printf("Stocks\n");
        printf("------\n\n");

        for (int i = 0; i < numOfStocks; i++)
        {
            printf("%s - $%.2lf\n", stocks[i].name, stocks[i].price);
        }

        printf("\nEnter the name of the stock you want to update (or 'exit' to quit): ");
        scanf("%s", name);

        if (strcmp(name, "exit") == 0)
        {
            break;
        }

        for (int i = 0; i < numOfStocks; i++)
        {
            if (strcmp(name, stocks[i].name) == 0)
            {
                printf("Enter the new price for %s: ", name);
                scanf("%lf", &currentPrice);
                previousPrice = stocks[i].price;
                stocks[i].price = currentPrice;
                difference = currentPrice - previousPrice;
                printf("%s's price was updated from $%.2lf to $%.2lf (%.2lf%%)\n", name, previousPrice, currentPrice, (difference/previousPrice)*100);
                break;
            }

            if (i == numOfStocks - 1)
            {
                printf("Stock not found\n");
            }
        }

        printf("\nPress any key to continue...");
        getchar();
        getchar();
    }

    return 0;
}