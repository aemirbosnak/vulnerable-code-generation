//FormAI DATASET v1.0 Category: Stock market tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STOCKS 10

struct Stock {
    char symbol[10];
    float price;
};
typedef struct Stock Stock;

int stockCount = 0; // number of stocks in the system
Stock stockList[MAX_STOCKS]; // list of stocks

// function to add a stock to the system
void addStock(Stock stock) {
    if (stockCount < MAX_STOCKS) {
        stockList[stockCount++] = stock;
        printf("Stock added.\n");
    } else {
        printf("Cannot add stock. Maximum number of stocks reached.\n");
    }
}

// function to remove a stock from the system
void removeStock(char symbol[]) {
    int i;
    for (i = 0; i < stockCount; i++) {
        if (strcmp(stockList[i].symbol, symbol) == 0) {
            // found the stock, remove it from the list
            int j;
            for (j = i; j < stockCount - 1; j++) {
                stockList[j] = stockList[j+1]; // shift the remaining stocks backwards
            }
            stockCount--;
            printf("Stock removed.\n");
            return;
        }
    }
    printf("Cannot remove stock. Stock not found.\n");
}

// function to update the price of a stock
void updatePrice(char symbol[], float price) {
    int i;
    for (i = 0; i < stockCount; i++) {
        if (strcmp(stockList[i].symbol, symbol) == 0) {
            // found the stock, update its price
            stockList[i].price = price;
            printf("Price updated.\n");
            return;
        }
    }
    printf("Cannot update price. Stock not found.\n");
}

// function to display the list of stocks
void displayStocks() {
    int i;
    for (i = 0; i < stockCount; i++) {
        printf("%s - $%.2f\n", stockList[i].symbol, stockList[i].price);
    }
}

int main() {
    // start with some sample data
    Stock AAPL = {"AAPL", 128.46};
    Stock MSFT = {"MSFT", 259.50};
    Stock TSLA = {"TSLA", 1080.03};
    addStock(AAPL);
    addStock(MSFT);
    addStock(TSLA);

    int choice;
    char symbol[10];
    float price;

    do {
        printf("Enter choice:\n");
        printf("1. Add stock\n");
        printf("2. Remove stock\n");
        printf("3. Update price\n");
        printf("4. Display stocks\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stock symbol: ");
                scanf("%s", symbol);
                printf("Enter stock price: ");
                scanf("%f", &price);
                Stock newStock = {symbol, price};
                addStock(newStock);
                break;

            case 2:
                printf("Enter stock symbol: ");
                scanf("%s", symbol);
                removeStock(symbol);
                break;

            case 3:
                printf("Enter stock symbol: ");
                scanf("%s", symbol);
                printf("Enter new price: ");
                scanf("%f", &price);
                updatePrice(symbol, price);
                break;

            case 4:
                displayStocks();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}