//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50
#define MAX_TICKER_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char ticker[MAX_TICKER_LENGTH];
    float price;
} Stock;

typedef struct {
    Stock stocks[MAX_STOCKS];
    int count;
} StockMarket;

void initializeMarket(StockMarket *market) {
    market->count = 0;
}

int addStock(StockMarket *market, const char *name, const char *ticker, float price) {
    if (market->count >= MAX_STOCKS) {
        printf("Stock market is full. Cannot add more stocks.\n");
        return -1;
    }
    if (strlen(name) >= MAX_NAME_LENGTH || strlen(ticker) >= MAX_TICKER_LENGTH) {
        printf("Name or ticker length exceeds maximum limit.\n");
        return -1;
    }
    if (price < 0) {
        printf("Price cannot be negative.\n");
        return -1;
    }

    strcpy(market->stocks[market->count].name, name);
    strcpy(market->stocks[market->count].ticker, ticker);
    market->stocks[market->count].price = price;
    market->count++;
    printf("Stock added: %s (%s) at $%.2f\n", name, ticker, price);
    return 0;
}

void listStocks(const StockMarket *market) {
    if (market->count == 0) {
        printf("No stocks available.\n");
        return;
    }
    printf("Listing Stocks:\n");
    for (int i = 0; i < market->count; i++) {
        printf("%d. %s (%s): $%.2f\n", i + 1, market->stocks[i].name, market->stocks[i].ticker, market->stocks[i].price);
    }
}

void updateStockPrice(StockMarket *market, const char *ticker, float newPrice) {
    for (int i = 0; i < market->count; i++) {
        if (strcmp(market->stocks[i].ticker, ticker) == 0) {
            if (newPrice < 0) {
                printf("New price cannot be negative.\n");
                return;
            }
            market->stocks[i].price = newPrice;
            printf("Updated %s (%s) to $%.2f\n", market->stocks[i].name, market->stocks[i].ticker, newPrice);
            return;
        }
    }
    printf("Stock with ticker %s not found.\n", ticker);
}

void displayMenu() {
    printf("\n---- Stock Market Tracker ----\n");
    printf("1. Add Stock\n");
    printf("2. List Stocks\n");
    printf("3. Update Stock Price\n");
    printf("4. Exit\n");
    printf("------------------------------\n");
}

int main() {
    StockMarket market;
    initializeMarket(&market);
    
    int choice = 0;
    char name[MAX_NAME_LENGTH];
    char ticker[MAX_TICKER_LENGTH];
    float price;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear invalid input
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                scanf(" %[^\n]", name);
                printf("Enter ticker: ");
                scanf("%s", ticker);
                printf("Enter price: ");
                if (scanf("%f", &price) != 1) {
                    printf("Invalid price. Please enter a float value.\n");
                    while(getchar() != '\n'); // Clear invalid input
                    continue;
                }
                if (addStock(&market, name, ticker, price) != 0) {
                    printf("Failed to add stock. Please try again.\n");
                }
                break;
            case 2:
                listStocks(&market);
                break;
            case 3:
                printf("Enter ticker of the stock to update: ");
                scanf("%s", ticker);
                printf("Enter new price: ");
                if (scanf("%f", &price) != 1) {
                    printf("Invalid price. Please enter a float value.\n");
                    while(getchar() != '\n'); // Clear invalid input
                    continue;
                }
                updateStockPrice(&market, ticker, price);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}