//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMPANIES 100
#define MAX_STOCK_NAME_LEN 20
#define MAX_SHARES 1000000

typedef struct {
    char stockName[MAX_STOCK_NAME_LEN];
    double stockPrice;
    int shares;
} Stock;

void initializeStock(Stock *stock, char *name, double price, int shares) {
    strcpy(stock->stockName, name);
    stock->stockPrice = price;
    stock->shares = shares;
}

void printStock(Stock stock) {
    printf("%-20s $%.2f %d shares\n", stock.stockName, stock.stockPrice, stock.shares);
}

int main() {
    Stock stocks[MAX_COMPANIES];
    int numStocks = 0;
    char input[100];

    while (1) {
        printf("\nEnter a stock command (buy, sell, list, quit): ");
        fgets(input, 100, stdin);
        if (strcmp(input, "quit") == 0) {
            break;
        } else if (strcmp(input, "list") == 0) {
            for (int i = 0; i < numStocks; i++) {
                printStock(stocks[i]);
            }
        } else if (strcmp(input, "buy") == 0) {
            printf("Enter stock name: ");
            fgets(input, 100, stdin);
            printf("Enter stock price: ");
            scanf("%lf", &stocks[numStocks].stockPrice);
            printf("Enter number of shares: ");
            scanf("%d", &stocks[numStocks].shares);
            strcpy(stocks[numStocks].stockName, input);
            numStocks++;
        } else if (strcmp(input, "sell") == 0) {
            printf("Enter stock name: ");
            fgets(input, 100, stdin);
            for (int i = 0; i < numStocks; i++) {
                if (strcmp(stocks[i].stockName, input) == 0) {
                    printf("Sold %d shares of %s at $%.2f\n", stocks[i].shares, stocks[i].stockName, stocks[i].stockPrice);
                    stocks[i].shares = 0;
                }
            }
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}