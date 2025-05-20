//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
    double change;
} Stock;

void displayMenu() {
    printf("=== Stock Market Tracker ===\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. View All Stocks\n");
    printf("4. Sort Stocks by Price\n");
    printf("5. Exit\n");
    printf("============================\n");
}

void addStock(Stock *stocks, int *stockCount) {
    if (*stockCount >= MAX_STOCKS) {
        printf("Stock limit reached. Cannot add more stocks.\n");
        return;
    }

    Stock newStock;
    printf("Enter stock name: ");
    scanf("%s", newStock.name);
    printf("Enter current price: ");
    scanf("%lf", &newStock.price);
    newStock.change = 0.0;

    stocks[(*stockCount)++] = newStock;
    printf("Stock added successfully!\n");
}

void updateStockPrice(Stock *stocks, int stockCount) {
    char stockName[MAX_NAME_LENGTH];
    printf("Enter the stock name to update: ");
    scanf("%s", stockName);

    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].name, stockName) == 0) {
            double newPrice;
            printf("Enter new price for %s: ", stockName);
            scanf("%lf", &newPrice);
            stocks[i].change = ((newPrice - stocks[i].price) / stocks[i].price) * 100.0;
            stocks[i].price = newPrice;
            printf("Stock price updated successfully!\n");
            return;
        }
    }
    printf("Stock not found.\n");
}

void viewAllStocks(Stock *stocks, int stockCount) {
    printf("=== Current Stock Portfolio ===\n");
    for (int i = 0; i < stockCount; i++) {
        printf("Name: %s, Price: %.2lf, Change: %.2lf%%\n", 
            stocks[i].name, stocks[i].price, stocks[i].change);
    }
    printf("===============================\n");
}

int compareStocks(const void *a, const void *b) {
    Stock *stockA = (Stock *)a;
    Stock *stockB = (Stock *)b;
    return (stockA->price > stockB->price) - (stockA->price < stockB->price);
}

void sortStocks(Stock *stocks, int stockCount) {
    qsort(stocks, stockCount, sizeof(Stock), compareStocks);
    printf("Stocks sorted by price successfully!\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(stocks, &stockCount);
                break;
            case 2:
                updateStockPrice(stocks, stockCount);
                break;
            case 3:
                viewAllStocks(stocks, stockCount);
                break;
            case 4:
                sortStocks(stocks, stockCount);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}