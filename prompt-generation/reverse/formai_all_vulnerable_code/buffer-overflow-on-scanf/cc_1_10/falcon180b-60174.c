//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 20
#define MAX_SYMBOL_LEN 10
#define MAX_PRICE_LEN 10
#define MAX_QUANTITY_LEN 10
#define MAX_DATE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
    char date[MAX_DATE_LEN];
} Stock;

int main() {
    int numStocks = 0;
    char input[MAX_NAME_LEN];
    Stock stocks[MAX_STOCKS];

    // Read in stocks
    while (numStocks < MAX_STOCKS) {
        printf("Enter stock name: ");
        fgets(input, MAX_NAME_LEN, stdin);
        strtok(input, "\n");
        strcpy(stocks[numStocks].name, input);

        printf("Enter stock symbol: ");
        fgets(input, MAX_SYMBOL_LEN, stdin);
        strtok(input, "\n");
        strcpy(stocks[numStocks].symbol, input);

        printf("Enter stock price: ");
        scanf("%lf", &stocks[numStocks].price);

        printf("Enter stock quantity: ");
        scanf("%d", &stocks[numStocks].quantity);

        printf("Enter stock purchase date (YYYY-MM-DD): ");
        fgets(stocks[numStocks].date, MAX_DATE_LEN, stdin);
        strtok(stocks[numStocks].date, "\n");
        strcpy(stocks[numStocks].date, toupper(stocks[numStocks].date));
        numStocks++;
    }

    // Print out stocks
    printf("Stocks:\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s (%s) - $%.2f - %d shares - Purchased on %s\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity, stocks[i].date);
    }

    return 0;
}