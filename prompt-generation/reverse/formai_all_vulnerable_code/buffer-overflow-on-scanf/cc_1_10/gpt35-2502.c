//FormAI DATASET v1.0 Category: Stock market tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
    double change;
} Stock;

Stock stocks[MAX_STOCKS];
int numStocks = 0;

void addStock() {
    if (numStocks >= MAX_STOCKS) {
        printf("Maximum number of stocks reached.\n");
        return;
    }

    Stock newStock;

    printf("Enter stock name: ");
    scanf("%s", newStock.name);

    printf("Enter current price: ");
    scanf("%lf", &newStock.price);

    printf("Enter today's change: ");
    scanf("%lf", &newStock.change);

    stocks[numStocks] = newStock;
    numStocks++;

    printf("%s has been added to the stock list.\n", newStock.name);
}

void viewStocks() {
    if (numStocks == 0) {
        printf("There are no stocks in the list.\n");
        return;
    }

    printf("Stocks:\n");

    for (int i = 0; i < numStocks; i++) {
        printf("%s:\n", stocks[i].name);
        printf("Current Price: %lf\n", stocks[i].price);
        printf("Today's Change: %lf\n\n", stocks[i].change);
    }
}

int main() {
    printf("Welcome to the Stock Market Tracker!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a stock\n");
        printf("2. View all stocks\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock();
                break;
            case 2:
                viewStocks();
                break;
            case 3:
                printf("Thank you for using the Stock Market Tracker.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}