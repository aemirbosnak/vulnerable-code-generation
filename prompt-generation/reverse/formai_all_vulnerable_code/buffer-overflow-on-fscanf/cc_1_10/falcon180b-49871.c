//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Donald Knuth
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
} stock_t;

void read_stocks(stock_t stocks[]) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open stocks file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s %lf %d\n", stocks[count].name, stocks[count].symbol, &stocks[count].price, &stocks[count].quantity) == 4 && count < MAX_STOCKS) {
        count++;
    }

    fclose(fp);
}

void print_stocks(stock_t stocks[]) {
    printf("Name\tSymbol\tPrice\tQuantity\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].name[0]!= '\0') {
            printf("%-20s\t%-10s\t$%.2f\t%d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
        }
    }
}

void sort_stocks(stock_t stocks[]) {
    for (int i = 0; i < MAX_STOCKS - 1; i++) {
        for (int j = i + 1; j < MAX_STOCKS; j++) {
            if (stocks[j].price < stocks[i].price) {
                stock_t temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }
}

int main() {
    stock_t stocks[MAX_STOCKS];

    read_stocks(stocks);
    printf("Initial stocks:\n");
    print_stocks(stocks);

    sort_stocks(stocks);
    printf("\nSorted by price:\n");
    print_stocks(stocks);

    return 0;
}