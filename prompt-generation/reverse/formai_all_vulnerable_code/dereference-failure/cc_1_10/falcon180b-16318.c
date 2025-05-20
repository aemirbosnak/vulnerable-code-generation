//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
} Stock;

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;
    char input[100];
    char *name, *symbol, *endptr;
    double price;

    printf("Enter stock information in the following format:\n");
    printf("Name Symbol Price\n");
    printf("---- ------ -----\n");

    while (fgets(input, sizeof(input), stdin)) {
        if (numStocks >= MAX_STOCKS) {
            printf("Error: Maximum number of stocks reached.\n");
            break;
        }

        name = strtok(input, " ");
        symbol = strtok(NULL, " ");
        if (name == NULL || symbol == NULL) {
            printf("Error: Invalid input format.\n");
            continue;
        }

        price = strtod(strtok(NULL, " "), &endptr);
        if (endptr == NULL || *endptr!= '\0') {
            printf("Error: Invalid price format.\n");
            continue;
        }

        strcpy(stocks[numStocks].name, name);
        strcpy(stocks[numStocks].symbol, symbol);
        stocks[numStocks].price = price;
        numStocks++;
    }

    printf("Stock Market Tracker\n");
    printf("--------------------\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%-20s %s %10.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }

    return 0;
}