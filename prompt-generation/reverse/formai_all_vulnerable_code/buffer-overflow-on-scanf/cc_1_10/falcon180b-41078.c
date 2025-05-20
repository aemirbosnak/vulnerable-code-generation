//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50
#define MAX_SYMBOL_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char symbol[MAX_SYMBOL_LEN];
    double price;
    int quantity;
} Stock;

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;
    char input[100];

    printf("Welcome to the Stock Market Tracker!\n");
    printf("Enter 'add' to add a stock or 'exit' to quit:\n");

    while (strcmp(input, "exit")!= 0) {
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            printf("Enter the name of the stock:\n");
            scanf("%s", stocks[numStocks].name);

            printf("Enter the symbol of the stock:\n");
            scanf("%s", stocks[numStocks].symbol);

            printf("Enter the price of the stock:\n");
            scanf("%lf", &stocks[numStocks].price);

            printf("Enter the quantity of the stock:\n");
            scanf("%d", &stocks[numStocks].quantity);

            numStocks++;
        } else {
            printf("Invalid command.\n");
        }
    }

    printf("\nYour stocks:\n");
    for (int i = 0; i < numStocks; i++) {
        printf("Name: %s\nSymbol: %s\nPrice: $%.2f\nQuantity: %d\n",
               stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].quantity);
    }

    return 0;
}