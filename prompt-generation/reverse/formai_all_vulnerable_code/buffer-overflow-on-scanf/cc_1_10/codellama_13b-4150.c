//Code Llama-13B DATASET v1.0 Category: Stock market tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100

typedef struct {
    char name[30];
    double price;
    double previous_price;
    double change;
} Stock;

void print_stock(Stock *stock) {
    printf("%-30s %7.2f %7.2f %7.2f\n", stock->name, stock->price, stock->previous_price, stock->change);
}

void update_stock(Stock *stock, double price) {
    stock->previous_price = stock->price;
    stock->price = price;
    stock->change = price - stock->previous_price;
}

void sort_stocks(Stock *stocks, int num_stocks) {
    int i, j;
    Stock temp;

    for (i = 0; i < num_stocks - 1; i++) {
        for (j = i + 1; j < num_stocks; j++) {
            if (stocks[i].price < stocks[j].price) {
                temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }
}

int main() {
    int i, num_stocks;
    Stock stocks[MAX_STOCKS];

    printf("Enter the number of stocks: ");
    scanf("%d", &num_stocks);

    for (i = 0; i < num_stocks; i++) {
        printf("Enter the name of stock %d: ", i + 1);
        scanf("%s", stocks[i].name);
        printf("Enter the price of stock %s: ", stocks[i].name);
        scanf("%lf", &stocks[i].price);
        stocks[i].previous_price = stocks[i].price;
        stocks[i].change = 0;
    }

    printf("Stock Market Tracker\n");
    printf("%-30s %7s %7s %7s\n", "Name", "Price", "Previous Price", "Change");
    for (i = 0; i < num_stocks; i++) {
        print_stock(&stocks[i]);
    }

    sort_stocks(stocks, num_stocks);

    printf("\n\nSorted by Price\n");
    printf("%-30s %7s %7s %7s\n", "Name", "Price", "Previous Price", "Change");
    for (i = 0; i < num_stocks; i++) {
        print_stock(&stocks[i]);
    }

    return 0;
}