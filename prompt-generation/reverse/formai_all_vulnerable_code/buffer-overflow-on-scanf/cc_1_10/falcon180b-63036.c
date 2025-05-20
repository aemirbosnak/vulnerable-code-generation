//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 100
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
    int quantity;
} Stock;

int main() {
    int numStocks;
    Stock *stocks = NULL;

    printf("Enter the number of stocks to track: ");
    scanf("%d", &numStocks);

    if (numStocks <= 0 || numStocks > MAX_STOCKS) {
        printf("Invalid number of stocks.\n");
        return 1;
    }

    stocks = malloc(numStocks * sizeof(Stock));

    for (int i = 0; i < numStocks; i++) {
        printf("Enter the name of stock %d: ", i + 1);
        scanf("%s", stocks[i].name);

        printf("Enter the symbol of stock %d: ", i + 1);
        scanf("%s", stocks[i].symbol);

        printf("Enter the price of stock %d: ", i + 1);
        scanf("%lf", &stocks[i].price);

        printf("Enter the quantity of stock %d: ", i + 1);
        scanf("%d", &stocks[i].quantity);
    }

    printf("\nStock Name\tSymbol\tPrice\tQuantity\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s\t%s\t%.2f\t%d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }

    free(stocks);
    return 0;
}