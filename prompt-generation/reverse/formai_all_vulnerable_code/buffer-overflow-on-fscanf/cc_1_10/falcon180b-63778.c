//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[10];
    double price;
} Stock;

void print_stock(Stock s) {
    printf("%-20s %-10s $%9.2f\n", s.name, s.symbol, s.price);
}

int compare_stocks(const void *a, const void *b) {
    Stock *stock_a = (Stock *)a;
    Stock *stock_b = (Stock *)b;

    if (stock_a->price > stock_b->price) {
        return -1;
    } else if (stock_a->price < stock_b->price) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    FILE *file = fopen("stocks.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open stocks file.\n");
        return 1;
    }

    while (fscanf(file, "%s %s %lf\n", stocks[num_stocks].name, stocks[num_stocks].symbol, &stocks[num_stocks].price)!= EOF) {
        num_stocks++;
    }

    fclose(file);

    qsort(stocks, num_stocks, sizeof(Stock), compare_stocks);

    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}