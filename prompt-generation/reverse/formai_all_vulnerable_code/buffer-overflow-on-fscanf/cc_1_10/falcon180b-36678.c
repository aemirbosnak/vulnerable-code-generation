//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 100
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 20
#define MAX_VOLUME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    char price[MAX_PRICE_LEN];
    char volume[MAX_VOLUME_LEN];
} stock_t;

int main() {
    int num_stocks = 0;
    stock_t stocks[MAX_STOCKS];

    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open stocks.txt\n");
        return 1;
    }

    while (fscanf(fp, "%s %s %s %s\n", stocks[num_stocks].name, stocks[num_stocks].symbol, stocks[num_stocks].price, stocks[num_stocks].volume)!= EOF) {
        num_stocks++;
    }

    fclose(fp);

    // Display initial stock prices
    printf("Initial Stock Prices:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s %s $%.2f %s\n", stocks[i].name, stocks[i].symbol, atof(stocks[i].price), stocks[i].volume);
    }

    // Simulate stock market changes
    for (int i = 0; i < num_stocks; i++) {
        stocks[i].price[strlen(stocks[i].price) - 1] = '\0';
        stocks[i].price[strlen(stocks[i].price) - 2] = '\0';
        stocks[i].price[strlen(stocks[i].price) - 3] = '\0';
        float price_change = (rand() % 101) / 100.0;
        float new_price = atof(stocks[i].price) + price_change;
        sprintf(stocks[i].price, "%.2f", new_price);
    }

    // Display updated stock prices
    printf("\nUpdated Stock Prices:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s %s $%.2f %s\n", stocks[i].name, stocks[i].symbol, atof(stocks[i].price), stocks[i].volume);
    }

    return 0;
}