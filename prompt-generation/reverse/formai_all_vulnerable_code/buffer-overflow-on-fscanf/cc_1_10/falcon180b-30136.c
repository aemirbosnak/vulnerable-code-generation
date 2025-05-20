//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10
#define MAX_PRICE_LENGTH 20
#define MAX_VOLUME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    char price[MAX_PRICE_LENGTH];
    char volume[MAX_VOLUME_LENGTH];
} stock_t;

int main() {
    int num_stocks = 0;
    stock_t stocks[MAX_STOCKS];

    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open stocks.txt\n");
        return 1;
    }

    while (fscanf(fp, "%s %s %s %s", stocks[num_stocks].name, stocks[num_stocks].symbol, stocks[num_stocks].price, stocks[num_stocks].volume)!= EOF) {
        num_stocks++;
    }

    fclose(fp);

    printf("Stock Market Tracker\n");
    printf("--------------------\n");

    while (1) {
        system("clear");
        printf("Enter stock symbol to search: ");
        char symbol[MAX_SYMBOL_LENGTH];
        fgets(symbol, MAX_SYMBOL_LENGTH, stdin);
        symbol[strcspn(symbol, "\n")] = '\0';

        int found = 0;
        for (int i = 0; i < num_stocks; i++) {
            if (strcmp(stocks[i].symbol, symbol) == 0) {
                printf("Stock found:\n");
                printf("Name: %s\n", stocks[i].name);
                printf("Symbol: %s\n", stocks[i].symbol);
                printf("Price: %s\n", stocks[i].price);
                printf("Volume: %s\n", stocks[i].volume);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Stock not found.\n");
        }

        printf("Press any key to continue...\n");
        getchar();
    }

    return 0;
}