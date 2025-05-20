//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} Stock;

void print_header(void) {
    printf("Name\tSymbol\tPrice\tQuantity\n");
}

void print_stock(Stock stock) {
    printf("%-50s\t%-10s\t$%.2f\t%d\n", stock.name, stock.symbol, stock.price, stock.quantity);
}

int compare_stocks(const void *a, const void *b) {
    const Stock *stockA = a;
    const Stock *stockB = b;

    if (stockA->price > stockB->price) {
        return -1;
    } else if (stockA->price < stockB->price) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    printf("Enter the number of stocks to track:\n");
    scanf("%d", &num_stocks);

    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the name of stock %d:\n", i + 1);
        scanf("%s", stocks[i].name);

        printf("Enter the symbol of stock %d:\n", i + 1);
        scanf("%s", stocks[i].symbol);

        printf("Enter the price of stock %d:\n", i + 1);
        scanf("%lf", &stocks[i].price);

        printf("Enter the quantity of stock %d:\n", i + 1);
        scanf("%d", &stocks[i].quantity);
    }

    print_header();

    qsort(stocks, num_stocks, sizeof(Stock), compare_stocks);

    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}