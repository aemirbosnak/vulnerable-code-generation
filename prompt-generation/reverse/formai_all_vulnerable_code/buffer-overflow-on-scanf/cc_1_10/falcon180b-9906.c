//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
} Stock;

void initializeStock(Stock *stock) {
    strcpy(stock->name, "");
    strcpy(stock->symbol, "");
    stock->price = 0;
}

void printStock(Stock stock) {
    printf("Name: %s\n", stock.name);
    printf("Symbol: %s\n", stock.symbol);
    printf("Price: $%.2f\n\n", stock.price);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;

    printf("Welcome to the Stock Market Tracker!\n\n");

    while (numStocks < MAX_STOCKS) {
        printf("Enter the name of the stock: ");
        scanf("%s", stocks[numStocks].name);

        printf("Enter the symbol of the stock: ");
        scanf("%s", stocks[numStocks].symbol);

        printf("Enter the current price of the stock: ");
        scanf("%lf", &stocks[numStocks].price);

        numStocks++;
    }

    printf("\nHere are the stocks you are tracking:\n");

    for (int i = 0; i < numStocks; i++) {
        printStock(stocks[i]);
    }

    return 0;
}