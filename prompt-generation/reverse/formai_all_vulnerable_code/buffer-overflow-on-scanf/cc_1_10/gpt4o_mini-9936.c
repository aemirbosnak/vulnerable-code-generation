//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPANIES 100

typedef struct {
    char name[50];
    char ticker[10];
    float price;
    int shares;
} Stock;

typedef struct {
    Stock stocks[MAX_COMPANIES];
    int count;
} StockMarket;

void addStock(StockMarket *market, char *name, char *ticker, float price, int shares) {
    if (market->count < MAX_COMPANIES) {
        strncpy(market->stocks[market->count].name, name, sizeof(market->stocks[market->count].name) - 1);
        strncpy(market->stocks[market->count].ticker, ticker, sizeof(market->stocks[market->count].ticker) - 1);
        market->stocks[market->count].price = price;
        market->stocks[market->count].shares = shares;
        market->count++;
        printf("Added stock: %s (%s) - Price: %.2f, Shares: %d\n", name, ticker, price, shares);
    } else {
        printf("Stock market can only handle %d companies.\n", MAX_COMPANIES);
    }
}

void displayStocks(const StockMarket *market) {
    printf("\nCurrent Stock Market:\n");
    printf("-------------------------------------------------\n");
    printf("| %-25s | %-8s | %-10s | %-8s |\n", "Company Name", "Ticker", "Price", "Shares");
    printf("-------------------------------------------------\n");
    
    for (int i = 0; i < market->count; i++) {
        printf("| %-25s | %-8s | $%-9.2f | %-8d |\n", market->stocks[i].name, market->stocks[i].ticker, market->stocks[i].price, market->stocks[i].shares);
    }
    printf("-------------------------------------------------\n");
}

void updateStockPrice(StockMarket *market, char *ticker, float newPrice) {
    for (int i = 0; i < market->count; i++) {
        if (strcmp(market->stocks[i].ticker, ticker) == 0) {
            market->stocks[i].price = newPrice;
            printf("Updated price of %s to $%.2f\n", ticker, newPrice);
            return;
        }
    }
    printf("Stock with ticker %s not found.\n", ticker);
}

void sellShares(StockMarket *market, char *ticker, int numberOfShares) {
    for (int i = 0; i < market->count; i++) {
        if (strcmp(market->stocks[i].ticker, ticker) == 0) {
            if (market->stocks[i].shares >= numberOfShares) {
                market->stocks[i].shares -= numberOfShares;
                printf("Sold %d shares of %s.\n", numberOfShares, ticker);
                return;
            } else {
                printf("Not enough shares to sell from %s.\n", ticker);
                return;
            }
        }
    }
    printf("Stock with ticker %s not found.\n", ticker);
}

void menu() {
    printf("********** Welcome to the Stock Market Tracker **********\n");
    printf("1. Add a new stock\n");
    printf("2. Display all stocks\n");
    printf("3. Update stock price\n");
    printf("4. Sell shares\n");
    printf("5. Exit\n");
    printf("*******************************************************\n");
}

int main() {
    StockMarket market;
    market.count = 0;

    int choice;
    char name[50], ticker[10];
    float price;
    int shares;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter company name: ");
                scanf(" %[^\n]s", name);
                printf("Enter stock ticker: ");
                scanf(" %[^\n]s", ticker);
                printf("Enter stock price: ");
                scanf("%f", &price);
                printf("Enter number of shares: ");
                scanf("%d", &shares);
                addStock(&market, name, ticker, price, shares);
                break;

            case 2:
                displayStocks(&market);
                break;

            case 3:
                printf("Enter stock ticker to update: ");
                scanf(" %[^\n]s", ticker);
                printf("Enter new price: ");
                scanf("%f", &price);
                updateStockPrice(&market, ticker, price);
                break;

            case 4:
                printf("Enter stock ticker to sell shares: ");
                scanf(" %[^\n]s", ticker);
                printf("Enter number of shares to sell: ");
                scanf("%d", &shares);
                sellShares(&market, ticker, shares);
                break;

            case 5:
                printf("Exiting the Stock Market Tracker. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}