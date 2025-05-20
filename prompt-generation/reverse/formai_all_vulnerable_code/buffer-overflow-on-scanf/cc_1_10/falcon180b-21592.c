//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_DECIMALS 2

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    double change;
    double percentage_change;
} Stock;

void print_stock(Stock stock) {
    printf("%-50s %-10s $%.2f ($%.2f) %.2f%%\n", stock.name, stock.symbol, stock.price, stock.change, stock.percentage_change);
}

int compare_stocks(const void* a, const void* b) {
    const Stock* stock_a = (const Stock*) a;
    const Stock* stock_b = (const Stock*) b;

    if (stock_a->price > stock_b->price) {
        return -1;
    } else if (stock_a->price < stock_b->price) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num_stocks;
    scanf("%d", &num_stocks);

    Stock stocks[MAX_STOCKS];
    for (int i = 0; i < num_stocks; i++) {
        scanf("%s %s $%lf", stocks[i].name, stocks[i].symbol, &stocks[i].price);
    }

    qsort(stocks, num_stocks, sizeof(Stock), compare_stocks);

    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}