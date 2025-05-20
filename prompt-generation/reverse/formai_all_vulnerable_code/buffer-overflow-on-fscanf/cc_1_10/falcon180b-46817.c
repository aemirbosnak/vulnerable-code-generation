//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    float price;
    int quantity;
} Stock;

int main() {
    int num_stocks = 0;
    Stock stocks[MAX_STOCKS];

    FILE *fp = fopen("stocks.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (num_stocks < MAX_STOCKS && fscanf(fp, "%s %s %f %d", stocks[num_stocks].name, stocks[num_stocks].symbol, &stocks[num_stocks].price, &stocks[num_stocks].quantity) == 4) {
        num_stocks++;
    }

    fclose(fp);

    char input[MAX_SYMBOL_LEN];
    while (1) {
        printf("Enter a stock symbol to track (or type 'quit' to exit): ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        int i;
        for (i = 0; i < num_stocks; i++) {
            if (strcmp(stocks[i].symbol, input) == 0) {
                printf("Current price for %s: $%.2f\n", stocks[i].name, stocks[i].price);
                printf("Quantity owned: %d\n", stocks[i].quantity);
                break;
            }
        }

        if (i == num_stocks) {
            printf("Stock not found.\n");
        }
    }

    return 0;
}