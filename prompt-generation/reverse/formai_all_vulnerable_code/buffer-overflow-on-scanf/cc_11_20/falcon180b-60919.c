//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_SIZE 20
#define MAX_PRICE_SIZE 10

typedef struct {
    char name[MAX_NAME_SIZE];
    float price;
    int quantity;
} stock;

int main() {
    int numStocks;
    stock stocks[MAX_STOCKS];
    char input[100];
    int i, j;
    float totalValue = 0.0;

    printf("Welcome to the Stock Market Tracker!\n");
    printf("How many stocks would you like to track? (Max %d): ", MAX_STOCKS);
    scanf("%d", &numStocks);

    for (i = 0; i < numStocks; i++) {
        printf("Enter the name of stock #%d: ", i+1);
        scanf("%s", stocks[i].name);
        stocks[i].price = 0.0;
        stocks[i].quantity = 0;
    }

    while (1) {
        printf("\nCurrent Stock Prices:\n");
        for (i = 0; i < numStocks; i++) {
            printf("%-20s $%.2f\n", stocks[i].name, stocks[i].price);
        }

        printf("\nEnter command (buy/sell/update/quit): ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        } else if (strcmp(input, "buy") == 0) {
            printf("Enter the name of the stock to buy: ");
            scanf("%s", input);
            for (i = 0; i < numStocks; i++) {
                if (strcmp(stocks[i].name, input) == 0) {
                    printf("Enter the quantity to buy: ");
                    scanf("%d", &stocks[i].quantity);
                    printf("Enter the purchase price per share: $");
                    scanf("%f", &stocks[i].price);
                    totalValue += stocks[i].price * stocks[i].quantity;
                    break;
                }
            }
        } else if (strcmp(input, "sell") == 0) {
            printf("Enter the name of the stock to sell: ");
            scanf("%s", input);
            for (i = 0; i < numStocks; i++) {
                if (strcmp(stocks[i].name, input) == 0) {
                    printf("Enter the quantity to sell: ");
                    scanf("%d", &stocks[i].quantity);
                    printf("Enter the sale price per share: $");
                    scanf("%f", &stocks[i].price);
                    totalValue -= stocks[i].price * stocks[i].quantity;
                    break;
                }
            }
        } else if (strcmp(input, "update") == 0) {
            printf("Enter the name of the stock to update: ");
            scanf("%s", input);
            for (i = 0; i < numStocks; i++) {
                if (strcmp(stocks[i].name, input) == 0) {
                    printf("Enter the new price per share: $");
                    scanf("%f", &stocks[i].price);
                    totalValue += (stocks[i].price - stocks[i].price) * stocks[i].quantity;
                    break;
                }
            }
        }
    }

    printf("\nTotal value of portfolio: $%.2f\n", totalValue);

    return 0;
}