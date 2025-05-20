//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
} Stock;

void print_stock(Stock *s) {
    printf("Name: %s\n", s->name);
    printf("Symbol: %s\n", s->symbol);
    printf("Price: $%.2f\n\n", s->price);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    printf("Welcome to the Stock Market Tracker!\n");

    while (num_stocks < MAX_STOCKS) {
        printf("Enter the name of a stock (or type 'done' to finish): ");
        scanf("%s", stocks[num_stocks].name);

        if (strcmp(stocks[num_stocks].name, "done") == 0) {
            break;
        }

        printf("Enter the symbol of the stock: ");
        scanf("%s", stocks[num_stocks].symbol);

        printf("Enter the current price of the stock: $");
        scanf("%lf", &stocks[num_stocks].price);

        num_stocks++;
    }

    printf("\nStocks being tracked:\n");

    for (int i = 0; i < num_stocks; i++) {
        print_stock(&stocks[i]);
    }

    return 0;
}