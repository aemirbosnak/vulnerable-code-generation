//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define SYMBOL_LENGTH 10
#define NAME_LENGTH 50

typedef struct {
    char symbol[SYMBOL_LENGTH];
    char name[NAME_LENGTH];
    float price;
    float change;
} Stock;

void displayStock(Stock stock);
void updateStockPrice(Stock* stock);
void displayPortfolio(Stock* portfolio, int stockCount);
void addStock(Stock* portfolio, int* stockCount);
void removeStock(Stock* portfolio, int* stockCount);

int main() {
    Stock portfolio[MAX_STOCKS];
    int stockCount = 0;
    int choice;
    
    while (1) {
        printf("\n--- Stock Market Tracker ---\n");
        printf("1. Add Stock\n");
        printf("2. Remove Stock\n");
        printf("3. Update Stock Price\n");
        printf("4. Display Portfolio\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStock(portfolio, &stockCount);
                break;
            case 2:
                removeStock(portfolio, &stockCount);
                break;
            case 3:
                for (int i = 0; i < stockCount; i++) {
                    updateStockPrice(&portfolio[i]);
                }
                printf("Stock prices updated!\n");
                break;
            case 4:
                displayPortfolio(portfolio, stockCount);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addStock(Stock* portfolio, int* stockCount) {
    if (*stockCount >= MAX_STOCKS) {
        printf("Cannot add more stocks. Portfolio is full.\n");
        return;
    }
    
    Stock newStock;
    printf("Enter stock symbol: ");
    scanf("%s", newStock.symbol);
    printf("Enter stock name: ");
    scanf(" %[^\n]", newStock.name);
    printf("Enter stock price: ");
    scanf("%f", &newStock.price);
    newStock.change = ((float)(rand() % 201) - 100) / 100; // Random change between -1 to +1
    
    portfolio[*stockCount] = newStock;
    (*stockCount)++;
    printf("Stock added successfully!\n");
}

void removeStock(Stock* portfolio, int* stockCount) {
    char symbol[SYMBOL_LENGTH];
    printf("Enter the symbol of the stock to remove: ");
    scanf("%s", symbol);

    for (int i = 0; i < *stockCount; i++) {
        if (strcmp(portfolio[i].symbol, symbol) == 0) {
            for (int j = i; j < *stockCount - 1; j++) {
                portfolio[j] = portfolio[j + 1];
            }
            (*stockCount)--;
            printf("Stock '%s' removed successfully!\n", symbol);
            return;
        }
    }
    printf("Stock not found in portfolio.\n");
}

void updateStockPrice(Stock* stock) {
    float volatility = ((float)(rand() % 21) - 10) / 100; // Random change between -0.1 to +0.1
    stock->price += stock->price * volatility;
    stock->change = volatility;
}

void displayStock(Stock stock) {
    printf("Symbol: %s | Name: %s | Price: %.2f | Change: %.2f%%\n",
           stock.symbol, stock.name, stock.price, stock.change * 100);
}

void displayPortfolio(Stock* portfolio, int stockCount) {
    if (stockCount == 0) {
        printf("Your portfolio is empty.\n");
        return;
    }

    printf("\n--- Your Portfolio ---\n");
    for (int i = 0; i < stockCount; i++) {
        displayStock(portfolio[i]);
    }
}