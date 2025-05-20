//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Ken Thompson
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

int compare_stocks(const void *a, const void *b) {
    const Stock *stock1 = a;
    const Stock *stock2 = b;

    if (stock1->price > stock2->price) {
        return -1;
    } else if (stock1->price < stock2->price) {
        return 1;
    } else {
        return 0;
    }
}

void print_stock(const Stock *stock) {
    printf("%-20s %-10s $%.2f %d\n", stock->name, stock->symbol, stock->price, stock->quantity);
}

int main() {
    int num_stocks;
    Stock stocks[MAX_STOCKS];

    printf("Enter the number of stocks to track (up to %d): ", MAX_STOCKS);
    scanf("%d", &num_stocks);

    for (int i = 0; i < num_stocks; i++) {
        printf("Enter stock %d information:\n", i + 1);
        printf("Name: ");
        scanf("%s", stocks[i].name);
        printf("Symbol: ");
        scanf("%s", stocks[i].symbol);
        printf("Price: $");
        scanf("%lf", &stocks[i].price);
        printf("Quantity: ");
        scanf("%d", &stocks[i].quantity);
    }

    qsort(stocks, num_stocks, sizeof(Stock), compare_stocks);

    printf("\nStock Market Tracker\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(&stocks[i]);
    }

    return 0;
}