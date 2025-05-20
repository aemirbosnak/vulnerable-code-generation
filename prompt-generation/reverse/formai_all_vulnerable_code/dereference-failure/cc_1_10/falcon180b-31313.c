//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STOCKS 50
#define MAX_NAME_LEN 50
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
} Stock;

void read_stocks_from_file(Stock stocks[], int *num_stocks) {
    FILE *fp;
    char line[MAX_NAME_LEN + MAX_SYMBOL_LEN + MAX_PRICE_LEN + 2];
    int i = 0;

    fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open stocks.txt\n");
        exit(1);
    }

    *num_stocks = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= MAX_STOCKS) {
            printf("Error: too many stocks in stocks.txt\n");
            exit(1);
        }

        char *token = strtok(line, ",");
        if (token == NULL) {
            printf("Error: invalid line in stocks.txt\n");
            exit(1);
        }

        strcpy(stocks[i].name, token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Error: invalid line in stocks.txt\n");
            exit(1);
        }

        strcpy(stocks[i].symbol, token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Error: invalid line in stocks.txt\n");
            exit(1);
        }

        stocks[i].price = atof(token);
        i++;
    }

    fclose(fp);
    *num_stocks = i;
}

void print_stock(Stock stock) {
    printf("Name: %s\n", stock.name);
    printf("Symbol: %s\n", stock.symbol);
    printf("Price: $%.2f\n", stock.price);
    printf("\n");
}

void print_stocks(Stock stocks[], int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        print_stock(stocks[i]);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks;

    read_stocks_from_file(stocks, &num_stocks);
    printf("Number of stocks: %d\n", num_stocks);

    print_stocks(stocks, num_stocks);

    return 0;
}