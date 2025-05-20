//MISTRAL-7B DATASET v1.0 Category: Stock market tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMPANIES 100
#define MAX_SYMBOL_LENGTH 10
#define MAX_NUM_DAYS 30

struct stock {
    char symbol[MAX_SYMBOL_LENGTH + 1];
    int price[MAX_NUM_DAYS];
};

typedef struct stock Stock;

void initStocks(Stock *stocks, int numStocks);
void loadPrices(Stock *stocks, int numStocks);
void printReport(const Stock *stocks, int numStocks);

int main() {
    Stock myStocks[MAX_COMPANIES];
    int numStocks = 0;

    initStocks(myStocks, MAX_COMPANIES);
    loadPrices(myStocks, MAX_COMPANIES);
    printReport(myStocks, MAX_COMPANIES);

    return 0;
}

void initStocks(Stock *stocks, int numStocks) {
    for (int i = 0; i < numStocks; i++) {
        scanf("%s", stocks[i].symbol);
        for (int j = 0; j < MAX_NUM_DAYS; j++) {
            stocks[i].price[j] = 0;
        }
    }
}

void loadPrices(Stock *stocks, int numStocks) {
    FILE *fp;
    char filename[MAX_SYMBOL_LENGTH + 5];

    for (int i = 0; i < numStocks; i++) {
        sprintf(filename, "%s_prices.txt", stocks[i].symbol);
        fp = fopen(filename, "r");
        for (int j = 0; j < MAX_NUM_DAYS; j++) {
            fscanf(fp, "%d", &stocks[i].price[j]);
        }
        fclose(fp);
    }
}

void printReport(const Stock *stocks, int numStocks) {
    printf("\n----- STOCK REPORT -----\n");

    for (int i = 0; i < numStocks; i++) {
        printf("\n%s: \n", stocks[i].symbol);
        for (int j = MAX_NUM_DAYS - 1; j >= 0; j--) {
            printf("%d ", stocks[i].price[j]);
        }
    }

    printf("\n-----------------------\n");
}