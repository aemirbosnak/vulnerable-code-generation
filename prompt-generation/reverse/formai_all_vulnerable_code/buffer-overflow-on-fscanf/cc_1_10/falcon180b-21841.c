//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10
#define MAX_PRICE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
} stock;

int compare_names(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int compare_symbols(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int compare_prices(const void *a, const void *b) {
    return (*(double *)a - *(double *)b);
}

void print_stock(stock s) {
    printf("%-20s %-10s $%.2f\n", s.name, s.symbol, s.price);
}

int main() {
    int num_stocks = 0;
    stock stocks[MAX_STOCKS];

    FILE *input_file = fopen("stocks.txt", "r");

    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    while (fscanf(input_file, "%s %s %lf", stocks[num_stocks].name, stocks[num_stocks].symbol, &stocks[num_stocks].price)!= EOF) {
        num_stocks++;
    }

    fclose(input_file);

    qsort(stocks, num_stocks, sizeof(stock), compare_names);

    printf("Sorted by Name:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    qsort(stocks, num_stocks, sizeof(stock), compare_symbols);

    printf("\nSorted by Symbol:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    qsort(stocks, num_stocks, sizeof(stock), compare_prices);

    printf("\nSorted by Price:\n");
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }

    return 0;
}