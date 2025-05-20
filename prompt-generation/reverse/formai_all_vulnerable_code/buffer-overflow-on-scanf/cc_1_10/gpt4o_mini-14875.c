//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100

typedef struct {
    char symbol[10];
    double price;
    double change;
    int volume;
} Stock;

void displayMenu() {
    printf("\nStock Market Tracker - Menu:\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock\n");
    printf("3. Display Stocks\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

void addStock(Stock stocks[], int *stockCount) {
    if (*stockCount >= MAX_STOCKS) {
        printf("Cannot add more stocks. Limit reached.\n");
        return;
    }
    
    Stock newStock;
    printf("Enter stock symbol: ");
    scanf("%s", newStock.symbol);
    printf("Enter stock price: ");
    scanf("%lf", &newStock.price);
    printf("Enter stock change: ");
    scanf("%lf", &newStock.change);
    printf("Enter volume: ");
    scanf("%d", &newStock.volume);

    stocks[*stockCount] = newStock;
    (*stockCount)++;
    printf("Stock %s added successfully!\n", newStock.symbol);
}

void updateStock(Stock stocks[], int stockCount) {
    char symbol[10];
    printf("Enter stock symbol to update: ");
    scanf("%s", symbol);
    
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            printf("Updating stock %s:\n", stocks[i].symbol);
            printf("Enter new price: ");
            scanf("%lf", &stocks[i].price);
            printf("Enter new change: ");
            scanf("%lf", &stocks[i].change);
            printf("Enter new volume: ");
            scanf("%d", &stocks[i].volume);
            printf("Stock %s updated successfully!\n", stocks[i].symbol);
            return;
        }
    }
    printf("Stock %s not found!\n", symbol);
}

void displayStocks(Stock stocks[], int stockCount) {
    if (stockCount == 0) {
        printf("No stocks available.\n");
        return;
    }
    
    printf("\nCurrent Stocks:\n");
    printf("%-10s %-10s %-10s %-10s\n", "Symbol", "Price", "Change", "Volume");
    for (int i = 0; i < stockCount; i++) {
        printf("%-10s %-10.2f %-10.2f %-10d\n", stocks[i].symbol, stocks[i].price, stocks[i].change, stocks[i].volume);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addStock(stocks, &stockCount);
                break;
            case 2:
                updateStock(stocks, stockCount);
                break;
            case 3:
                displayStocks(stocks, stockCount);
                break;
            case 4:
                printf("Exiting the Stock Market Tracker.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}