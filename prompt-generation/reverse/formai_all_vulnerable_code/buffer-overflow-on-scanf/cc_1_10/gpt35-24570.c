//FormAI DATASET v1.0 Category: Stock market tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_STOCKS 10
#define MAX_NAME_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    float change;
} Stock;

void printHeader() {
    printf("%-12s %-12s %-12s\n", "Name", "Price", "Change");
}

void printStock(Stock stock) {
    printf("%-12s $%.2f      ", stock.name, stock.price);

    if (stock.change > 0) {
        printf("+%.2f\n", stock.change);
    } else {
        printf("%.2f\n", stock.change);
    }
}

void printStocks(Stock stocks[], int numStocks) {
    printHeader();
    for (int i = 0; i < numStocks; i++) {
        printStock(stocks[i]);
    }
}

void updateStocks(Stock stocks[], int numStocks) {
    for (int i = 0; i < numStocks; i++) {
        stocks[i].price += (1 + (rand() % 10) / 100.0) * (rand() % 2 == 0 ? 1 : -1);
        stocks[i].change = (stocks[i].price - 10) / 10 * 100;
        if (stocks[i].change > 0 && stocks[i].change < 0.01) {
            stocks[i].change = 0.01;
        } else if (stocks[i].change < 0 && stocks[i].change > -0.01) {
            stocks[i].change = -0.01;
        }
    }
}

int getStockChoice(int numStocks) {
    int choice;

    do {
        printf("Select a stock to view (1-%d): ", numStocks);
        scanf("%d", &choice);
    } while (choice < 1 || choice > numStocks);

    return choice - 1;
}

void clearInput() {
    while (getchar() != '\n');
}

bool addStock(Stock stocks[], int numStocks) {
    if (numStocks >= MAX_STOCKS) {
        printf("You have reached the maximum number of stocks.\n");
        return false;
    }

    Stock stock;

    printf("Enter the stock name: ");
    scanf("%s", stock.name);

    printf("Enter the stock price: ");
    scanf("%f", &stock.price);

    stock.change = (stock.price - 10) / 10 * 100;
    if (stock.change > 0 && stock.change < 0.01) {
        stock.change = 0.01;
    } else if (stock.change < 0 && stock.change > -0.01) {
        stock.change = -0.01;
    }

    stocks[numStocks] = stock;

    return true;
}

int main() {
    int choice;
    int numStocks = 0;
    Stock stocks[MAX_STOCKS];

    do {
        printf("\nMenu:\n");
        printf("1. View all stocks\n");
        printf("2. View one stock\n");
        printf("3. Add a new stock\n");
        printf("4. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printStocks(stocks, numStocks);
                break;
            case 2:
                if (numStocks == 0) {
                    printf("There are no stocks to view.\n");
                } else {
                    printStock(stocks[getStockChoice(numStocks)]);
                }
                break;
            case 3:
                if (addStock(stocks, numStocks)) {
                    printf("The stock has been added.\n");
                    numStocks += 1;
                }
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        updateStocks(stocks, numStocks);
    } while (choice != 4);

    return 0;
}