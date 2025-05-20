//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Stock {
    char name[20];
    double price;
    double previousPrice;
    double change;
} Stock;

void updateStock(Stock *stock) {
    printf("Enter the name of the stock: ");
    scanf("%s", stock->name);

    printf("Enter the current price of the stock: ");
    scanf("%lf", &stock->price);

    stock->previousPrice = stock->price;

    if (stock->price > stock->previousPrice) {
        stock->change = (stock->price - stock->previousPrice) / stock->previousPrice * 100;
        printf("The stock has increased by %.2f%.\n", stock->change);
    } else if (stock->price < stock->previousPrice) {
        stock->change = (stock->previousPrice - stock->price) / stock->previousPrice * 100;
        printf("The stock has decreased by %.2f%.\n", stock->change);
    } else {
        printf("The stock has remained unchanged.\n");
    }
}

int main() {
    Stock stocks[MAX];

    for (int i = 0; i < MAX; i++) {
        stocks[i].name[0] = '\0';
        stocks[i].price = 0.0;
        stocks[i].previousPrice = 0.0;
        stocks[i].change = 0.0;
    }

    int numStocks = 0;

    while (1) {
        updateStock(&stocks[numStocks]);

        numStocks++;

        if (numStocks == MAX - 1) {
            break;
        }
    }

    return 0;
}