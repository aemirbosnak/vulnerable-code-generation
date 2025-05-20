//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_VOLUME_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
    char volume[MAX_VOLUME_LEN];
} stock_t;

void read_stocks(stock_t stocks[], int num_stocks) {
    FILE *fp;
    char line[256];
    int i = 0;

    fp = fopen("stocks.txt", "r");

    if (fp == NULL) {
        printf("Error: Unable to open stocks file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= num_stocks) {
            printf("Warning: Maximum number of stocks reached.\n");
            break;
        }

        char *token = strtok(line, ",");
        strcpy(stocks[i].name, token);

        token = strtok(NULL, ",");
        strcpy(stocks[i].symbol, token);

        token = strtok(NULL, ",");
        strcpy(stocks[i].price, token);

        token = strtok(NULL, ",");
        strcpy(stocks[i].volume, token);

        i++;
    }

    fclose(fp);
}

void print_stocks(stock_t stocks[], int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        printf("%-20s %-10s %-10s %-10s\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].volume);
    }
}

int main() {
    stock_t stocks[MAX_STOCKS];
    int num_stocks = 0;

    read_stocks(stocks, MAX_STOCKS);
    num_stocks = MAX_STOCKS;

    print_stocks(stocks, num_stocks);

    return 0;
}