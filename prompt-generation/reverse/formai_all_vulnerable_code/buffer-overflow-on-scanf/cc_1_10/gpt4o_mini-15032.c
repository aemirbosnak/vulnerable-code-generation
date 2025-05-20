//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_NAME_LENGTH];
    float price;
    int shares;
} Stock;

Stock stocks[MAX_STOCKS];
int stockCount = 0;

void addStock() {
    if (stockCount >= MAX_STOCKS) {
        printf("Stock limit reached. Cannot add more stocks.\n");
        return;
    }
    
    Stock newStock;
    
    printf("Enter stock name: ");
    scanf(" %[^\n]%*c", newStock.name);
    
    printf("Enter stock symbol: ");
    scanf(" %[^\n]%*c", newStock.symbol);
    
    printf("Enter stock price: ");
    scanf("%f", &newStock.price);
    
    printf("Enter number of shares: ");
    scanf("%d", &newStock.shares);
    
    stocks[stockCount] = newStock;
    stockCount++;
    printf("Stock %s (%s) added successfully.\n", newStock.name, newStock.symbol);
}

void updateStockPrice() {
    char symbol[MAX_NAME_LENGTH];
    printf("Enter stock symbol to update: ");
    scanf(" %[^\n]%*c", symbol);
    
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            printf("Current price of %s: %.2f\n", stocks[i].name, stocks[i].price);
            printf("Enter new price: ");
            scanf("%f", &stocks[i].price);
            printf("Price of %s updated successfully to %.2f.\n", stocks[i].name, stocks[i].price);
            return;
        }
    }
    
    printf("Stock with symbol %s not found.\n", symbol);
}

void sellShares() {
    char symbol[MAX_NAME_LENGTH];
    int sharesToSell;

    printf("Enter stock symbol to sell: ");
    scanf(" %[^\n]%*c", symbol);
    
    printf("Enter number of shares to sell: ");
    scanf("%d", &sharesToSell);
    
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            if (sharesToSell > stocks[i].shares) {
                printf("Not enough shares to sell. Current shares: %d\n", stocks[i].shares);
            } else {
                stocks[i].shares -= sharesToSell;
                printf("Sold %d shares of %s. Remaining shares: %d\n", sharesToSell, stocks[i].name, stocks[i].shares);
            }
            return;
        }
    }
    
    printf("Stock with symbol %s not found.\n", symbol);
}

void displayStocks() {
    printf("\nCurrent Stock Portfolio:\n");
    printf("----------------------------------------------\n");
    printf("%-20s %-10s %-10s %-10s\n", "Name", "Symbol", "Price", "Shares");
    printf("----------------------------------------------\n");
    for (int i = 0; i < stockCount; i++) {
        printf("%-20s %-10s %.2f %-10d\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].shares);
    }
    printf("----------------------------------------------\n");
}

void displayMenu() {
    printf("\nStock Market Tracker\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. Sell Shares\n");
    printf("4. Display Stocks\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStock();
                break;
            case 2:
                updateStockPrice();
                break;
            case 3:
                sellShares();
                break;
            case 4:
                displayStocks();
                break;
            case 5:
                printf("Exiting Stock Market Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}