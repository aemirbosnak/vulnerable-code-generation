//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} Stock;

void print_stock(Stock s) {
    printf("Name: %s\n", s.name);
    printf("Symbol: %s\n", s.symbol);
    printf("Price: $%.2f\n", s.price);
    printf("Quantity: %d\n\n", s.quantity);
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

void sort_stocks(Stock stocks[], int n) {
    qsort(stocks, n, sizeof(Stock), compare_stocks);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int n_stocks = 0;

    while (n_stocks < MAX_STOCKS) {
        printf("Enter the name of the stock (or type 'done' to finish): ");
        scanf("%s", stocks[n_stocks].name);

        if (strcmp(stocks[n_stocks].name, "done") == 0) {
            break;
        }

        printf("Enter the symbol of the stock: ");
        scanf("%s", stocks[n_stocks].symbol);

        printf("Enter the price of the stock: $");
        scanf("%lf", &stocks[n_stocks].price);

        printf("Enter the quantity of the stock: ");
        scanf("%d", &stocks[n_stocks].quantity);

        n_stocks++;
    }

    printf("Unsorted stocks:\n");
    for (int i = 0; i < n_stocks; i++) {
        print_stock(stocks[i]);
    }

    sort_stocks(stocks, n_stocks);

    printf("\nSorted by price (highest to lowest):\n");
    for (int i = 0; i < n_stocks; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}