//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: irregular
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
    double price;
} Stock;

int main() {
    int num_stocks = 0;
    Stock stocks[MAX_STOCKS];

    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open stocks file.\n");
        return 1;
    }

    while (fscanf(fp, "%s %s %lf\n", stocks[num_stocks].name, stocks[num_stocks].symbol, &stocks[num_stocks].price)!= EOF) {
        num_stocks++;
    }

    fclose(fp);

    printf("Enter symbol to track: ");
    char symbol[MAX_SYMBOL_LEN];
    fgets(symbol, MAX_SYMBOL_LEN, stdin);
    symbol[strcspn(symbol, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < num_stocks; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            printf("Stock found:\n");
            printf("Name: %s\n", stocks[i].name);
            printf("Symbol: %s\n", stocks[i].symbol);
            printf("Price: $%.2f\n", stocks[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Stock not found.\n");
    }

    return 0;
}