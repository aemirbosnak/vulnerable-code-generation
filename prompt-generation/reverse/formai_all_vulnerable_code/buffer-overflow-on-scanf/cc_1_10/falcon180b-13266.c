//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
    int quantity;
} Stock;

void print_header() {
    printf("+-------------------+-----------------+---------------+---------------+\n");
    printf("| Name              | Symbol           | Current Price  | Quantity       |\n");
    printf("+-------------------+-----------------+---------------+---------------+\n");
}

void print_stock(Stock stock) {
    printf("| %-20s | %-5s | $%.2f | %d |\n", stock.name, stock.symbol, stock.price, stock.quantity);
}

void print_stocks(Stock stocks[], int n) {
    print_header();
    for (int i = 0; i < n; i++) {
        print_stock(stocks[i]);
    }
    printf("+-------------------+-----------------+---------------+---------------+\n");
}

int compare_stocks(const void *a, const void *b) {
    Stock stock1 = *(Stock *)a;
    Stock stock2 = *(Stock *)b;

    if (stock1.price > stock2.price) {
        return -1;
    } else if (stock1.price < stock2.price) {
        return 1;
    } else {
        return 0;
    }
}

void sort_stocks(Stock stocks[], int n) {
    qsort(stocks, n, sizeof(Stock), compare_stocks);
}

int main() {
    srand(time(NULL));

    Stock stocks[MAX_STOCKS];
    int n = 0;

    while (n < MAX_STOCKS) {
        char name[MAX_NAME_LENGTH];
        char symbol[MAX_SYMBOL_LENGTH];

        printf("Enter the name of the stock (max %d characters): ", MAX_NAME_LENGTH - 1);
        scanf("%s", name);

        printf("Enter the symbol of the stock (max %d characters): ", MAX_SYMBOL_LENGTH - 1);
        scanf("%s", symbol);

        double price = rand() % 100;
        int quantity = rand() % 100;

        strncpy(stocks[n].name, name, MAX_NAME_LENGTH);
        strncpy(stocks[n].symbol, symbol, MAX_SYMBOL_LENGTH);
        stocks[n].price = price;
        stocks[n].quantity = quantity;

        n++;
    }

    print_stocks(stocks, n);

    return 0;
}