//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Stock;

typedef struct {
    Stock stocks[MAX_STOCKS];
    int stockCount;
} StockMarket;

void initializeMarket(StockMarket *market) {
    market->stockCount = 0;
}

int addStock(StockMarket *market, char *name, float price) {
    if (market->stockCount < MAX_STOCKS) {
        strncpy(market->stocks[market->stockCount].name, name, NAME_LENGTH);
        market->stocks[market->stockCount].price = price;
        market->stocks[market->stockCount].quantity = 0;
        market->stockCount++;
        return 1; // Success
    } else {
        printf("Stock market is full! Cannot add more stocks.\n");
        return 0; // Failure
    }
}

void updateStockPrice(StockMarket *market, char *name, float newPrice) {
    for (int i = 0; i < market->stockCount; i++) {
        if (strcmp(market->stocks[i].name, name) == 0) {
            market->stocks[i].price = newPrice;
            return;
        }
    }
    printf("Stock not found: %s\n", name);
}

void buyStock(StockMarket *market, char *name, int quantity) {
    for (int i = 0; i < market->stockCount; i++) {
        if (strcmp(market->stocks[i].name, name) == 0) {
            market->stocks[i].quantity += quantity;
            printf("Bought %d shares of %s at $%.2f each.\n", quantity, name, market->stocks[i].price);
            return;
        }
    }
    printf("Stock not found: %s\n", name);
}

void displayStocks(StockMarket *market) {
    printf("\nStock Market Overview:\n");
    printf("--------------------------------------------------\n");
    printf("| %-30s | Price     | Quantity   |\n", "Stock Name");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < market->stockCount; i++) {
        printf("| %-30s | $%-8.2f | %-10d |\n", market->stocks[i].name, market->stocks[i].price, market->stocks[i].quantity);
    }
    printf("--------------------------------------------------\n");
}

int main() {
    StockMarket market;
    initializeMarket(&market);
    
    int choice;
    char stockName[NAME_LENGTH];
    float stockPrice;
    int quantity;

    do {
        printf("\nStock Market Tracker\n");
        printf("1. Add Stock\n");
        printf("2. Update Stock Price\n");
        printf("3. Buy Stock\n");
        printf("4. Display Stocks\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                scanf("%s", stockName);
                printf("Enter stock price: ");
                scanf("%f", &stockPrice);
                addStock(&market, stockName, stockPrice);
                break;
            case 2:
                printf("Enter stock name to update: ");
                scanf("%s", stockName);
                printf("Enter new stock price: ");
                scanf("%f", &stockPrice);
                updateStockPrice(&market, stockName, stockPrice);
                break;
            case 3:
                printf("Enter stock name to buy: ");
                scanf("%s", stockName);
                printf("Enter quantity to buy: ");
                scanf("%d", &quantity);
                buyStock(&market, stockName, quantity);
                break;
            case 4:
                displayStocks(&market);
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}