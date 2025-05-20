//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME 20
#define MAX_PRICE 10

typedef struct {
    char name[MAX_NAME];
    char symbol[MAX_NAME];
    float price;
} Stock;

int compare_stocks(const void *a, const void *b) {
    const Stock *stock_a = a;
    const Stock *stock_b = b;

    return strcmp(stock_a->symbol, stock_b->symbol);
}

void print_stock(const Stock *stock) {
    printf("Name: %s\n", stock->name);
    printf("Symbol: %s\n", stock->symbol);
    printf("Price: $%.2f\n\n", stock->price);
}

int main() {
    int num_stocks;
    Stock stocks[MAX_STOCKS];

    printf("Welcome to the Happy Stock Market Tracker!\n\n");
    printf("How many stocks do you want to track? ");
    scanf("%d", &num_stocks);

    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the name of stock #%d: ", i + 1);
        scanf("%s", stocks[i].name);

        printf("Enter the symbol of stock #%d: ", i + 1);
        scanf("%s", stocks[i].symbol);

        printf("Enter the price of stock #%d: ", i + 1);
        scanf("%f", &stocks[i].price);
    }

    qsort(stocks, num_stocks, sizeof(Stock), compare_stocks);

    printf("\nYour portfolio:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(&stocks[i]);
    }

    return 0;
}