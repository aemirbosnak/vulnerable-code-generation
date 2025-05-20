//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
} Stock;

void read_stocks(Stock stocks[], int num_stocks) {
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open stocks file.\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %s %s\n", stocks[i].name, stocks[i].symbol, stocks[i].price) == 3) {
        i++;
        if (i == num_stocks) {
            break;
        }
    }

    fclose(fp);
}

void display_stocks(Stock stocks[], int num_stocks) {
    printf("Name\tSymbol\tPrice\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s %-10s %s\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    read_stocks(stocks, MAX_STOCKS);
    num_stocks = MAX_STOCKS;

    while (1) {
        display_stocks(stocks, num_stocks);
        printf("Enter stock symbol to search for: ");
        scanf("%s", stocks[num_stocks-1].symbol);
        if (strcasecmp(stocks[num_stocks-1].symbol, "quit") == 0) {
            break;
        }

        int index = 0;
        for (int i = 0; i < num_stocks-1; i++) {
            if (strcasecmp(stocks[i].symbol, stocks[num_stocks-1].symbol) == 0) {
                index = i;
                break;
            }
        }

        if (index == 0) {
            printf("Stock not found.\n");
        } else {
            printf("Stock found at position %d:\n", index+1);
            display_stocks(stocks, num_stocks-1);
        }
    }

    return 0;
}