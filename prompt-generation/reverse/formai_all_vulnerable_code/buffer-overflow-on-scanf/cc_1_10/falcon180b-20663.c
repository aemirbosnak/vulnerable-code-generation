//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    double price;
} Stock;

int main() {
    int numStocks;
    Stock stocks[MAX_STOCKS];
    char input[1000];
    char delimiter = ',';

    printf("Enter the number of stocks to track: ");
    scanf("%d", &numStocks);

    printf("Enter the stocks (name, symbol, price):\n");
    fgets(input, 1000, stdin);
    stocks[0].name[0] = '\0';
    stocks[0].symbol[0] = '\0';
    stocks[0].price = 0;
    char *token = strtok(input, ",");
    int i = 0;
    while (token!= NULL) {
        if (i >= MAX_STOCKS) {
            printf("Error: Maximum number of stocks reached.\n");
            return 1;
        }
        strcpy(stocks[i].name, token);
        token = strtok(NULL, ",");
        strcpy(stocks[i].symbol, token);
        token = strtok(NULL, ",");
        stocks[i].price = atof(token);
        i++;
        token = strtok(NULL, ",");
    }

    printf("\nStock Market Tracker\n");
    printf("---------------------\n");
    for (i = 0; i < numStocks; i++) {
        printf("%-20s %-10s $%.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }

    return 0;
}