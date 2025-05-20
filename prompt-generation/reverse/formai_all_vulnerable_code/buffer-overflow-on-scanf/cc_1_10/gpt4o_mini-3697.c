//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOL_LENGTH 10
#define MAX_COMPANIES 100

typedef struct {
    char symbol[MAX_SYMBOL_LENGTH];
    float price;
} Stock;

typedef struct {
    Stock stocks[MAX_COMPANIES];
    int count;
} StockTracker;

void initializeTracker(StockTracker* tracker) {
    tracker->count = 0;
}

void addStock(StockTracker* tracker, const char* symbol, float price) {
    if (tracker->count < MAX_COMPANIES) {
        strncpy(tracker->stocks[tracker->count].symbol, symbol, MAX_SYMBOL_LENGTH);
        tracker->stocks[tracker->count].price = price;
        tracker->count++;
    } else {
        printf("Stock Tracker is full! Cannot add more stocks.\n");
    }
}

void displayStocks(const StockTracker* tracker) {
    printf("Current Stock Prices:\n");
    printf("----------------------\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%s: $%.2f\n", tracker->stocks[i].symbol, tracker->stocks[i].price);
    }
    printf("----------------------\n");
}

void updateStockPrice(StockTracker* tracker, const char* symbol, float newPrice) {
    for (int i = 0; i < tracker->count; i++) {
        if (strcmp(tracker->stocks[i].symbol, symbol) == 0) {
            tracker->stocks[i].price = newPrice;
            printf("Updated %s: $%.2f\n", symbol, newPrice);
            return;
        }
    }
    printf("Stock symbol %s not found in tracker.\n", symbol);
}

int main() {
    StockTracker myTracker;
    initializeTracker(&myTracker);

    int choice;
    char symbol[MAX_SYMBOL_LENGTH];
    float price;

    while (1) {
        printf("Welcome to the Stock Market Tracker\n");
        printf("1. Add Stock\n");
        printf("2. Display Stocks\n");
        printf("3. Update Stock Price\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stock symbol: ");
                scanf("%s", symbol);
                printf("Enter stock price: ");
                scanf("%f", &price);
                addStock(&myTracker, symbol, price);
                break;
            case 2:
                displayStocks(&myTracker);
                break;
            case 3:
                printf("Enter stock symbol to update: ");
                scanf("%s", symbol);
                printf("Enter new stock price: ");
                scanf("%f", &price);
                updateStockPrice(&myTracker, symbol, price);
                break;
            case 4:
                printf("Exiting Stock Market Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}