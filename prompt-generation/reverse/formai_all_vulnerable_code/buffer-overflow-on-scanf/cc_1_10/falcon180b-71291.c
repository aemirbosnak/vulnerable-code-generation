//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} Stock;

void print_stock(Stock s) {
    printf("%-20s %-10s $%.2f %d\n", s.name, s.symbol, s.price, s.quantity);
}

int compare_stocks(const void *a, const void *b) {
    const Stock *s1 = a;
    const Stock *s2 = b;

    if (s1->price > s2->price) {
        return -1;
    } else if (s1->price < s2->price) {
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
        scanf("%s %s $%.2f %d", stocks[i].name, stocks[i].symbol, &stocks[i].price, &stocks[i].quantity);
    }

    qsort(stocks, num_stocks, sizeof(Stock), compare_stocks);

    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}