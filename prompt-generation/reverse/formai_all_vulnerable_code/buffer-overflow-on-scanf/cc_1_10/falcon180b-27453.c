//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} Stock;

int main() {
    int numStocks;
    printf("Enter the number of stocks to track: ");
    scanf("%d", &numStocks);

    if (numStocks > MAX_STOCKS || numStocks < 1) {
        printf("Invalid number of stocks.\n");
        return 1;
    }

    Stock stocks[numStocks];

    for (int i = 0; i < numStocks; i++) {
        printf("Enter the name of stock #%d: ", i+1);
        scanf("%s", stocks[i].name);

        printf("Enter the symbol of stock #%d: ", i+1);
        scanf("%s", stocks[i].symbol);

        printf("Enter the price of stock #%d: ", i+1);
        scanf("%lf", &stocks[i].price);

        printf("Enter the quantity of stock #%d: ", i+1);
        scanf("%d", &stocks[i].quantity);
    }

    printf("\nStock Tracker\n");
    printf("--------------------\n");

    for (int i = 0; i < numStocks; i++) {
        printf("%-20s %-10s $%.2f %d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }

    return 0;
}