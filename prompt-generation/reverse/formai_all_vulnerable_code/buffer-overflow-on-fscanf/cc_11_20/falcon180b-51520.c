//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 20
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_NAME_LEN];
    double price;
} stock_t;

int main() {
    stock_t stocks[MAX_STOCKS];
    int num_stocks = 0;
    char input[MAX_NAME_LEN];
    double price;

    printf("Welcome to the stock market tracker!\n");

    // Load stocks from file
    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open stocks file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s %lf\n", input, stocks[num_stocks].symbol, &price) == 3) {
        strncpy(stocks[num_stocks].name, input, MAX_NAME_LEN);
        stocks[num_stocks].price = price;
        num_stocks++;
    }

    fclose(fp);

    if (num_stocks == 0) {
        printf("Error: no stocks found in file.\n");
        exit(1);
    }

    while (1) {
        printf("\nCurrent stock prices:\n");
        for (int i = 0; i < num_stocks; i++) {
            printf("%-20s %-10s $%.2lf\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
        }

        printf("\nEnter the symbol of the stock you want to track: ");
        scanf("%s", input);

        for (int i = 0; i < num_stocks; i++) {
            if (strcmp(input, stocks[i].symbol) == 0) {
                printf("\nTracking %s (%s):\n", stocks[i].name, stocks[i].symbol);
                break;
            }
        }

        while (1) {
            printf("\nEnter 'q' to quit tracking or any other key to continue:\n");
            scanf(" %c", &input);

            if (input == 'q' || input == 'Q') {
                break;
            }
        }
    }

    return 0;
}