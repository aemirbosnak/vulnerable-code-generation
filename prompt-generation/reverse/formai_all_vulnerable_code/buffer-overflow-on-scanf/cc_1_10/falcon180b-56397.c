//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 10
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 10
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    char price[MAX_PRICE_LENGTH];
} Stock;

void add_stock(Stock *stocks, int num_stocks) {
    printf("Enter the name of the stock: ");
    scanf("%s", stocks[num_stocks].name);

    printf("Enter the symbol of the stock: ");
    scanf("%s", stocks[num_stocks].symbol);

    printf("Enter the price of the stock: ");
    scanf("%s", stocks[num_stocks].price);

    printf("\n");
}

void display_stocks(Stock *stocks, int num_stocks) {
    printf("\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("Name: %s\n", stocks[i].name);
        printf("Symbol: %s\n", stocks[i].symbol);
        printf("Price: $%s\n\n", stocks[i].price);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    printf("Welcome to the Stock Market Tracker!\n\n");

    while (num_stocks < MAX_STOCKS) {
        printf("Enter 1 to add a stock or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_stock(stocks, num_stocks);
            num_stocks++;
        } else if (choice!= 0) {
            printf("Invalid input. Please try again.\n");
        }
    }

    printf("You have added %d stocks.\n", num_stocks);
    printf("Here are the stocks you have added:\n");

    display_stocks(stocks, num_stocks);

    return 0;
}