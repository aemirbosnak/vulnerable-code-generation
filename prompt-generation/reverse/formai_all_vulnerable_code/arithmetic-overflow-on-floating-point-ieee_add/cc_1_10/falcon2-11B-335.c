//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10

typedef struct {
    char name[50];
    double price;
} Stock;

int main() {
    Stock stocks[MAX_STOCKS];

    int numStocks = 0;
    int numTrades = 0;
    double totalTradedValue = 0.0;

    printf("Enter the number of stocks: ");
    scanf("%d", &numStocks);

    for (int i = 0; i < numStocks; i++) {
        printf("Enter the name of stock %d: ", i+1);
        scanf("%s", stocks[i].name);

        printf("Enter the price of stock %d: ", i+1);
        scanf("%lf", &stocks[i].price);
    }

    printf("Enter the number of trades: ");
    scanf("%d", &numTrades);

    for (int i = 0; i < numTrades; i++) {
        int tradeType;
        double tradeValue;

        printf("Enter the trade type (1 for buy, 2 for sell): ");
        scanf("%d", &tradeType);

        if (tradeType == 1) {
            printf("Enter the stock name: ");
            scanf("%s", stocks[tradeType-1].name);

            printf("Enter the trade value: ");
            scanf("%lf", &tradeValue);

            stocks[tradeType-1].price += tradeValue;
            totalTradedValue += tradeValue;
        } else if (tradeType == 2) {
            printf("Enter the stock name: ");
            scanf("%s", stocks[tradeType-1].name);

            printf("Enter the trade value: ");
            scanf("%lf", &tradeValue);

            stocks[tradeType-1].price -= tradeValue;
            totalTradedValue -= tradeValue;
        }
    }

    printf("\nStock Tracker\n");
    printf("-------------------------\n");
    printf("Name\t\tPrice\t\tTraded Value\n");
    printf("-------------------------\n");

    for (int i = 0; i < numStocks; i++) {
        printf("%s\t\t%lf\t\t%.2lf\n", stocks[i].name, stocks[i].price, totalTradedValue);
    }

    return 0;
}