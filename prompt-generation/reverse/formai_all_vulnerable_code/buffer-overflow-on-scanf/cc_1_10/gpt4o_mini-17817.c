//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_STOCKS 10
#define NAME_LENGTH 30
#define TICKER_LENGTH 10

typedef struct {
    char name[NAME_LENGTH];
    char ticker[TICKER_LENGTH];
    float price;
    float change;
} Stock;

void displayMenu() {
    printf("===== Stock Market Tracker =====\n");
    printf("1. Add a new stock\n");
    printf("2. Update stock price\n");
    printf("3. Display all stocks\n");
    printf("4. Exit\n");
    printf("================================\n");
    printf("Choose an option: ");
}

void addStock(Stock stocks[], int *stockCount) {
    if (*stockCount >= MAX_STOCKS) {
        printf("Cannot add more stocks, limit reached.\n");
        return;
    }

    Stock newStock;
    printf("Enter the stock name: ");
    scanf("%s", newStock.name);
    printf("Enter the stock ticker: ");
    scanf("%s", newStock.ticker);
    printf("Enter the stock price: ");
    scanf("%f", &newStock.price);
    printf("Enter the price change percentage: ");
    scanf("%f", &newStock.change);

    stocks[*stockCount] = newStock;
    (*stockCount)++;
    printf("Stock added successfully!\n");
}

void updateStockPrice(Stock stocks[], int stockCount) {
    char ticker[TICKER_LENGTH];
    printf("Enter the stock ticker to update: ");
    scanf("%s", ticker);

    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].ticker, ticker) == 0) {
            printf("Current price of %s: %.2f\n", stocks[i].name, stocks[i].price);
            printf("Enter new price: ");
            scanf("%f", &stocks[i].price);
            printf("Price updated successfully!\n");
            return;
        }
    }
    printf("Stock ticker not found!\n");
}

void displayStocks(Stock stocks[], int stockCount) {
    if (stockCount == 0) {
        printf("No stocks available to display.\n");
        return;
    }
    
    printf("===== List of Stocks =====\n");
    for (int i = 0; i < stockCount; i++) {
        printf("Name: %s, Ticker: %s, Price: %.2f, Change: %.2f%%\n", 
                stocks[i].name, stocks[i].ticker, stocks[i].price, stocks[i].change);
    }
    printf("==========================\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStock(stocks, &stockCount);
                break;
            case 2:
                updateStockPrice(stocks, stockCount);
                break;
            case 3:
                displayStocks(stocks, stockCount);
                break;
            case 4:
                printf("Exiting Stock Market Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again!\n");
                break;
        }
        sleep(1);  // Pause for a second before showing the menu again
    }

    return 0;
}