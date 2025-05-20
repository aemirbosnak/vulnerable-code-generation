//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_STOCKS 50

typedef struct {
    char name[20];
    char symbol[10];
    double price;
} Stock;

void addStock(Stock *stocks, int numStocks) {
    printf("Enter stock name: ");
    scanf("%s", stocks[numStocks].name);
    printf("Enter stock symbol: ");
    scanf("%s", stocks[numStocks].symbol);
    printf("Enter stock price: ");
    scanf("%lf", &stocks[numStocks].price);
    numStocks++;
}

void displayStocks(Stock stocks[], int numStocks) {
    printf("\nStock Name\tStock Symbol\tStock Price\n");
    for (int i = 0; i < numStocks; i++) {
        printf("%s\t%s\t%.2lf\n", stocks[i].name, stocks[i].symbol, stocks[i].price);
    }
}

void searchStock(Stock stocks[], int numStocks, char searchSymbol[]) {
    bool found = false;
    for (int i = 0; i < numStocks; i++) {
        if (strcmp(stocks[i].symbol, searchSymbol) == 0) {
            printf("\nStock Details:\n");
            printf("Stock Name: %s\n", stocks[i].name);
            printf("Stock Symbol: %s\n", stocks[i].symbol);
            printf("Stock Price: %.2lf\n", stocks[i].price);
            found = true;
            break;
        }
    }
    if (!found) {
        printf("Stock not found.\n");
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;

    while (numStocks < MAX_STOCKS) {
        printf("\nEnter 1 to add a stock or 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            addStock(stocks, numStocks);
        } else if (choice == 0) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    while (true) {
        printf("\nEnter 1 to display all stocks or 2 to search for a stock: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            displayStocks(stocks, numStocks);
        } else if (choice == 2) {
            char searchSymbol[10];
            printf("\nEnter stock symbol to search: ");
            scanf("%s", searchSymbol);
            searchStock(stocks, numStocks, searchSymbol);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}