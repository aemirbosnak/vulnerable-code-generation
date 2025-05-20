//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
} Stock;

int main() {
    int numStocks = 0;
    Stock stocks[MAX_STOCKS];

    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open stocks file.\n");
        return 1;
    }

    while (fscanf(fp, "%s %s %s\n", stocks[numStocks].name, stocks[numStocks].symbol, stocks[numStocks].price)!= EOF) {
        numStocks++;
    }

    fclose(fp);

    printf("Number of stocks: %d\n", numStocks);

    char searchSymbol[MAX_SYMBOL_LEN];
    printf("Enter a stock symbol to search: ");
    scanf("%s", searchSymbol);

    int found = 0;
    for (int i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].symbol, searchSymbol) == 0) {
            printf("Found %s (%s)\n", stocks[i].name, stocks[i].symbol);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Stock not found.\n");
    }

    return 0;
}