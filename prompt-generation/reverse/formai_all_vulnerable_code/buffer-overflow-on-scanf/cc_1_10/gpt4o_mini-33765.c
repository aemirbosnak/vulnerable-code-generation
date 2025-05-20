//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_SYMBOL_LENGTH 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char symbol[MAX_SYMBOL_LENGTH];
    char name[MAX_NAME_LENGTH];
    float price;
} Stock;

void displayMenu() {
    printf("\n*** Stock Market Tracker ***\n");
    printf("1. Add Stock\n");
    printf("2. View Stocks\n");
    printf("3. Update Stock Price\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
}

void addStock(Stock stocks[], int *stockCount) {
    if (*stockCount >= MAX_STOCKS) {
        printf("Stock limit reached. Cannot add more stocks.\n");
        return;
    }
    
    Stock newStock;
    printf("Enter stock symbol: ");
    scanf("%s", newStock.symbol);
    printf("Enter stock name: ");
    scanf(" %[^\n]", newStock.name); // Read string with spaces
    printf("Enter initial price: ");
    scanf("%f", &newStock.price);

    stocks[*stockCount] = newStock;
    (*stockCount)++;
    printf("Stock %s added successfully.\n", newStock.symbol);
}

void viewStocks(Stock stocks[], int stockCount) {
    if (stockCount == 0) {
        printf("No stocks to display.\n");
        return;
    }
    
    printf("\nList of Stocks:\n");
    for (int i = 0; i < stockCount; i++) {
        printf("Symbol: %s, Name: %s, Price: %.2f\n", stocks[i].symbol, stocks[i].name, stocks[i].price);
    }
}

void updateStockPrice(Stock stocks[], int stockCount) {
    char symbol[MAX_SYMBOL_LENGTH];
    float newPrice;
    printf("Enter stock symbol to update: ");
    scanf("%s", symbol);
    
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            printf("Current price of %s is %.2f. Enter new price: ", stocks[i].symbol, stocks[i].price);
            scanf("%f", &newPrice);
            stocks[i].price = newPrice;
            printf("Price for %s updated to %.2f.\n", stocks[i].symbol, stocks[i].price);
            return;
        }
    }
    printf("Stock symbol %s not found.\n", symbol);
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
                viewStocks(stocks, stockCount);
                break;
            case 3:
                updateStockPrice(stocks, stockCount);
                break;
            case 4:
                printf("Exiting the Stock Market Tracker. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}