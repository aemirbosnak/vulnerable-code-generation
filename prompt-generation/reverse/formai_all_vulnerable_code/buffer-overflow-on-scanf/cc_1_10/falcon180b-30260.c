//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
} Stock;

int main() {
    int numStocks;
    printf("Enter the number of stocks to track: ");
    scanf("%d", &numStocks);

    Stock stocks[numStocks];

    for (int i = 0; i < numStocks; i++) {
        printf("Enter stock %d name: ", i+1);
        scanf("%s", stocks[i].name);
        printf("Enter stock %d symbol: ", i+1);
        scanf("%s", stocks[i].symbol);
        stocks[i].price = 0;
    }

    while (1) {
        system("clear");
        printf("\n");
        for (int i = 0; i < numStocks; i++) {
            printf("%s (%s) - $%.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
        }
        printf("\n");
        printf("Enter a stock symbol to update its price: ");
        char symbol[MAX_SYMBOL_LEN];
        scanf("%s", symbol);

        for (int i = 0; i < numStocks; i++) {
            if (strcmp(stocks[i].symbol, symbol) == 0) {
                printf("Enter the new price for %s: ", stocks[i].name);
                scanf("%lf", &stocks[i].price);
                printf("%s (%s) price updated to $%.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
                break;
            }
        }
    }

    return 0;
}