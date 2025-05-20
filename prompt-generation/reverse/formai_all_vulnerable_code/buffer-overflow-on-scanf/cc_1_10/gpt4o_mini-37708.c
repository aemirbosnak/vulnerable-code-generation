//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100

typedef struct {
    char name[30];
    char ticker[10];
    float price;
} Stock;

void displayMenu() {
    printf("===================================\n");
    printf("      Stock Market Tracker\n");
    printf("===================================\n");
    printf("1. Add a Stock\n");
    printf("2. Display All Stocks\n");
    printf("3. Update Stock Price\n");
    printf("4. Search Stock by Ticker\n");
    printf("5. Exit\n");
    printf("===================================\n");
    printf("Choose an option (1-5): ");
}

void addStock(Stock stocks[], int* count) {
    if (*count >= MAX_STOCKS) {
        printf("Unable to add stock, maximum number reached!\n");
        return;
    }

    Stock newStock;
    printf("Enter stock name: ");
    scanf(" %[^\n]", newStock.name);
    printf("Enter stock ticker: ");
    scanf(" %[^\n]", newStock.ticker);
    printf("Enter stock price: ");
    scanf("%f", &newStock.price);
    
    stocks[*count] = newStock;
    (*count)++;
    printf("Stock '%s' added successfully!\n", newStock.name);
}

void displayStocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks available to display.\n");
        return;
    }

    printf("\nCurrent Stocks:\n");
    printf("%-30s %-10s %-10s\n", "Name", "Ticker", "Price");
    for (int i = 0; i < count; i++) {
        printf("%-30s %-10s $%.2f\n", stocks[i].name, stocks[i].ticker, stocks[i].price);
    }
}

void updateStockPrice(Stock stocks[], int count) {
    char ticker[10];
    printf("Enter the ticker of the stock you want to update: ");
    scanf(" %[^\n]", ticker);

    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].ticker, ticker) == 0) {
            printf("Current price of %s is $%.2f\n", stocks[i].name, stocks[i].price);
            printf("Enter new price: ");
            scanf("%f", &stocks[i].price);
            printf("Price updated to $%.2f for %s!\n", stocks[i].price, stocks[i].name);
            return;
        }
    }
    printf("Stock with ticker '%s' not found!\n", ticker);
}

void searchStock(Stock stocks[], int count) {
    char ticker[10];
    printf("Enter the ticker of the stock you want to search: ");
    scanf(" %[^\n]", ticker);

    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].ticker, ticker) == 0) {
            printf("Found stock: %s (Ticker: %s) with price: $%.2f\n",
                   stocks[i].name, stocks[i].ticker, stocks[i].price);
            return;
        }
    }
    printf("Stock with ticker '%s' not found!\n", ticker);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;
    int choice;

    printf("Welcome to the Stock Market Tracker!\n");
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(stocks, &stockCount);
                break;
            case 2:
                displayStocks(stocks, stockCount);
                break;
            case 3:
                updateStockPrice(stocks, stockCount);
                break;
            case 4:
                searchStock(stocks, stockCount);
                break;
            case 5:
                printf("Thank you for using the Stock Market Tracker! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
        printf("\n");
    }

    return 0;
}