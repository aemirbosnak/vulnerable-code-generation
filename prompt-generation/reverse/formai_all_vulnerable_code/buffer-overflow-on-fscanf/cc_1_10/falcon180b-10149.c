//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Ken Thompson
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
} stock_t;

int main() {
    int num_stocks = 0;
    stock_t stocks[MAX_STOCKS];

    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open stocks file.\n");
        return 1;
    }

    while (fscanf(fp, "%s %s %s\n", stocks[num_stocks].name, stocks[num_stocks].symbol, stocks[num_stocks].price) == 3) {
        num_stocks++;
        if (num_stocks >= MAX_STOCKS) {
            printf("Error: too many stocks in file.\n");
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    char input[MAX_NAME_LEN];
    while (1) {
        printf("Enter a stock name to search for: ");
        fgets(input, MAX_NAME_LEN, stdin);
        input[strcspn(input, "\n")] = '\0';

        int found = 0;
        for (int i = 0; i < num_stocks; i++) {
            if (strcmp(stocks[i].name, input) == 0) {
                printf("Stock found:\n");
                printf("Name: %s\n", stocks[i].name);
                printf("Symbol: %s\n", stocks[i].symbol);
                printf("Price: %s\n", stocks[i].price);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Stock not found.\n");
        }
    }

    return 0;
}