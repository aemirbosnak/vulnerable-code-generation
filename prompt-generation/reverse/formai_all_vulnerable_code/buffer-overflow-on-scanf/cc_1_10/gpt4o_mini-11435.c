//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 30
#define MAX_HISTORY 10

typedef struct {
    char name[NAME_LENGTH];
    float prices[MAX_HISTORY];
    int currentIndex;
} Stock;

typedef struct {
    Stock stocks[MAX_STOCKS];
    int stockCount;
} StockMarket;

void addStock(StockMarket *market, const char *name) {
    if (market->stockCount >= MAX_STOCKS) {
        printf("Cannot add more stocks, limit reached.\n");
        return;
    }
    strncpy(market->stocks[market->stockCount].name, name, NAME_LENGTH);
    market->stocks[market->stockCount].currentIndex = 0;
    market->stockCount++;
    printf("Stock %s added successfully.\n", name);
}

void updateStockPrice(StockMarket *market, const char *name, float price) {
    for (int i = 0; i < market->stockCount; i++) {
        if (strcmp(market->stocks[i].name, name) == 0) {
            Stock *stock = &market->stocks[i];
            stock->prices[stock->currentIndex] = price;
            stock->currentIndex = (stock->currentIndex + 1) % MAX_HISTORY;
            printf("Updated price of stock %s to %.2f.\n", name, price);
            return;
        }
    }
    printf("Stock %s not found.\n", name);
}

void viewStockPrices(const StockMarket *market, const char *name) {
    for (int i = 0; i < market->stockCount; i++) {
        if (strcmp(market->stocks[i].name, name) == 0) {
            printf("Price history for stock %s:\n", name);
            for (int j = 0; j < MAX_HISTORY; j++) {
                if (market->stocks[i].prices[j] != 0) {
                    printf("%.2f ", market->stocks[i].prices[j]);
                }
            }
            printf("\n");
            return;
        }
    }
    printf("Stock %s not found.\n", name);
}

void viewAllStocks(const StockMarket *market) {
    printf("All tracked stocks:\n");
    for (int i = 0; i < market->stockCount; i++) {
        printf("- %s\n", market->stocks[i].name);
    }
}

void statisticalOverview(const StockMarket *market) {
    printf("Statistical overview of tracked stocks:\n");
    for (int i = 0; i < market->stockCount; i++) {
        float total = 0;
        int count = 0;
        Stock stock = market->stocks[i];

        for (int j = 0; j < MAX_HISTORY; j++) {
            if (stock.prices[j] != 0) {
                total += stock.prices[j];
                count++;
            }
        }

        if (count > 0) {
            float average = total / count;
            printf("Stock %s - Average Price: %.2f, Current Price: %.2f\n", stock.name, average, stock.prices[(stock.currentIndex - 1 + MAX_HISTORY) % MAX_HISTORY]);
        } else {
            printf("Stock %s - No prices available.\n", stock.name);
        }
    }
}

int main() {
    StockMarket market = {{}, 0};
    int choice;
    char stockName[NAME_LENGTH];
    float price;

    while (1) {
        printf("\nStock Market Tracker\n");
        printf("1. Add Stock\n");
        printf("2. Update Stock Price\n");
        printf("3. View Stock Prices\n");
        printf("4. View All Stocks\n");
        printf("5. Statistical Overview\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                scanf("%s", stockName);
                addStock(&market, stockName);
                break;
            case 2:
                printf("Enter stock name: ");
                scanf("%s", stockName);
                printf("Enter stock price: ");
                scanf("%f", &price);
                updateStockPrice(&market, stockName, price);
                break;
            case 3:
                printf("Enter stock name: ");
                scanf("%s", stockName);
                viewStockPrices(&market, stockName);
                break;
            case 4:
                viewAllStocks(&market);
                break;
            case 5:
                statisticalOverview(&market);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}