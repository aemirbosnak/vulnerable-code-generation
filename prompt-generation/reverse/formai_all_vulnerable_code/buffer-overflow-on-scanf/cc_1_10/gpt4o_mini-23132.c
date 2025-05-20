//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STOCKS 100
#define TICKER_LENGTH 10
#define NAME_LENGTH 50

typedef struct {
    char ticker[TICKER_LENGTH];
    char name[NAME_LENGTH];
    float price;
    int shares;
} Stock;

typedef struct {
    Stock stocks[MAX_STOCKS];
    int count;
} StockPortfolio;

void initializePortfolio(StockPortfolio *portfolio) {
    portfolio->count = 0;
}

bool addStock(StockPortfolio *portfolio, const char *ticker, const char *name, float price, int shares) {
    if (portfolio->count >= MAX_STOCKS) {
        printf("Portfolio is full. Cannot add more stocks.\n");
        return false;
    }
    
    strncpy(portfolio->stocks[portfolio->count].ticker, ticker, TICKER_LENGTH);
    strncpy(portfolio->stocks[portfolio->count].name, name, NAME_LENGTH);
    portfolio->stocks[portfolio->count].price = price;
    portfolio->stocks[portfolio->count].shares = shares;
    portfolio->count++;
    return true;
}

void displayPortfolio(const StockPortfolio *portfolio) {
    printf("\nCurrent Stock Portfolio:\n");
    printf("-----------------------------------------------------\n");
    printf("%-10s %-50s %-10s %-10s\n", "Ticker", "Name", "Price", "Shares");
    printf("-----------------------------------------------------\n");
    
    for (int i = 0; i < portfolio->count; i++) {
        printf("%-10s %-50s %-10.2f %-10d\n", 
                portfolio->stocks[i].ticker, 
                portfolio->stocks[i].name, 
                portfolio->stocks[i].price, 
                portfolio->stocks[i].shares);
    }
    printf("-----------------------------------------------------\n");
}

float calculatePortfolioValue(const StockPortfolio *portfolio) {
    float totalValue = 0.0;
    for (int i = 0; i < portfolio->count; i++) {
        totalValue += portfolio->stocks[i].price * portfolio->stocks[i].shares;
    }
    return totalValue;
}

void updateStockPrice(StockPortfolio *portfolio, const char *ticker, float newPrice) {
    for (int i = 0; i < portfolio->count; i++) {
        if (strcmp(portfolio->stocks[i].ticker, ticker) == 0) {
            portfolio->stocks[i].price = newPrice;
            printf("Price updated for stock %s: New price is %.2f\n", ticker, newPrice);
            return;
        }
    }
    printf("Stock with ticker %s not found in portfolio.\n", ticker);
}

void removeStock(StockPortfolio *portfolio, const char *ticker) {
    for (int i = 0; i < portfolio->count; i++) {
        if (strcmp(portfolio->stocks[i].ticker, ticker) == 0) {
            for (int j = i; j < portfolio->count - 1; j++) {
                portfolio->stocks[j] = portfolio->stocks[j + 1];
            }
            portfolio->count--;
            printf("Stock %s removed from the portfolio.\n", ticker);
            return;
        }
    }
    printf("Stock with ticker %s not found in portfolio.\n", ticker);
}

void showMenu() {
    printf("\nStock Market Tracker Menu:\n");
    printf("1. Add Stock\n");
    printf("2. Display Portfolio\n");
    printf("3. Update Stock Price\n");
    printf("4. Remove Stock\n");
    printf("5. Calculate Total Portfolio Value\n");
    printf("6. Exit\n");
}

int main() {
    StockPortfolio myPortfolio;
    initializePortfolio(&myPortfolio);
    
    int choice;
    while (true) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                char ticker[TICKER_LENGTH], name[NAME_LENGTH];
                float price;
                int shares;

                printf("Enter ticker: ");
                scanf("%s", ticker);
                printf("Enter name: ");
                scanf(" %[^\n]s", name); // Read line with spaces
                printf("Enter price: ");
                scanf("%f", &price);
                printf("Enter shares: ");
                scanf("%d", &shares);
                addStock(&myPortfolio, ticker, name, price, shares);
                break;
            }
            case 2:
                displayPortfolio(&myPortfolio);
                break;
            case 3: {
                char ticker[TICKER_LENGTH];
                float newPrice;

                printf("Enter ticker of stock to update: ");
                scanf("%s", ticker);
                printf("Enter new price: ");
                scanf("%f", &newPrice);
                updateStockPrice(&myPortfolio, ticker, newPrice);
                break;
            }
            case 4: {
                char ticker[TICKER_LENGTH];
                printf("Enter ticker of stock to remove: ");
                scanf("%s", ticker);
                removeStock(&myPortfolio, ticker);
                break;
            }
            case 5: {
                float totalValue = calculatePortfolioValue(&myPortfolio);
                printf("Total Portfolio Value: %.2f\n", totalValue);
                break;
            }
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}