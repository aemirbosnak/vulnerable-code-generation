//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: inquisitive
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

int main() {
    stock_t stocks[MAX_STOCKS];
    int num_stocks = 0;

    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error opening stocks file.\n");
        return 1;
    }

    char line[1000];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_stocks >= MAX_STOCKS) {
            printf("Error: Too many stocks in file.\n");
            fclose(fp);
            return 1;
        }

        char *token = strtok(line, ",");
        strcpy(stocks[num_stocks].name, token);
        token = strtok(NULL, ",");
        strcpy(stocks[num_stocks].symbol, token);
        token = strtok(NULL, ",");
        strcpy(stocks[num_stocks].price, token);
        token = strtok(NULL, ",");
        strcpy(stocks[num_stocks].volume, token);

        num_stocks++;
    }

    fclose(fp);

    printf("Stock Market Tracker\n");
    printf("--------------------\n");

    for (int i = 0; i < num_stocks; i++) {
        printf("%s (%s): $%.2f (%s)\n", stocks[i].name, stocks[i].symbol, atof(stocks[i].price), stocks[i].volume);
    }

    return 0;
}