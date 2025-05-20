//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_COMPANIES 100
#define MAX_STOCK_NAME_LENGTH 50
#define MAX_STOCK_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_STOCK_NAME_LENGTH];
    char symbol[MAX_STOCK_SYMBOL_LENGTH];
    double price;
    int change;
    int changePercent;
} Stock;

int compareStocks(const void *a, const void *b) {
    const Stock *stockA = (const Stock *)a;
    const Stock *stockB = (const Stock *)b;

    if (stockA->changePercent > stockB->changePercent) {
        return -1;
    } else if (stockA->changePercent < stockB->changePercent) {
        return 1;
    } else {
        return 0;
    }
}

void printStock(const Stock *stock) {
    printf("%-50s %-10s $%.2f %+d (%.2f%%)\n", stock->name, stock->symbol, stock->price, stock->change, stock->changePercent);
}

int main() {
    int numCompanies;
    scanf("%d", &numCompanies);

    Stock companies[MAX_COMPANIES];
    for (int i = 0; i < numCompanies; i++) {
        scanf("%s %s $%lf %d", companies[i].name, companies[i].symbol, &companies[i].price, &companies[i].change);
    }

    qsort(companies, numCompanies, sizeof(Stock), compareStocks);

    for (int i = 0; i < numCompanies; i++) {
        printStock(&companies[i]);
    }

    return 0;
}