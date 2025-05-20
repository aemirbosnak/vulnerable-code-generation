//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_QUANTITY 1000
#define MAX_PRICE 100000

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    int quantity;
    double price;
} Stock;

Stock stocks[MAX_STOCKS];
int num_stocks;

void print_stock(Stock* stock) {
    printf("Name: %s\n", stock->name);
    printf("Symbol: %s\n", stock->symbol);
    printf("Quantity: %d\n", stock->quantity);
    printf("Price: $%.2f\n\n", stock->price);
}

void print_stocks() {
    printf("Stocks:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(&stocks[i]);
    }
}

int compare_stocks(const void* a, const void* b) {
    const Stock* stock1 = (const Stock*)a;
    const Stock* stock2 = (const Stock*)b;

    if (stock1->price > stock2->price) {
        return -1;
    } else if (stock1->price < stock2->price) {
        return 1;
    } else {
        return 0;
    }
}

void sort_stocks() {
    qsort(stocks, num_stocks, sizeof(Stock), compare_stocks);
}

int main() {
    num_stocks = 0;

    while (num_stocks < MAX_STOCKS) {
        printf("Enter stock information (name, symbol, quantity, price):\n");
        scanf("%s %s %d $%lf", stocks[num_stocks].name, stocks[num_stocks].symbol, &stocks[num_stocks].quantity, &stocks[num_stocks].price);
        num_stocks++;
    }

    sort_stocks();
    print_stocks();

    return 0;
}