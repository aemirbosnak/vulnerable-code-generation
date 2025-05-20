//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float price;
    float change;
} Stock;

void displayMenu() {
    printf("==== Stock Market Tracker ====\n");
    printf("1. Add Stock\n");
    printf("2. View Stocks\n");
    printf("3. Update Stock Price\n");
    printf("4. Exit\n");
    printf("=============================\n");
    printf("Select an option (1-4): ");
}

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Stock list is full!\n");
        return;
    }
    
    Stock newStock;
    printf("Enter stock name: ");
    scanf("%s", newStock.name);
    printf("Enter stock price: ");
    scanf("%f", &newStock.price);
    newStock.change = 0.0;

    stocks[*count] = newStock;
    (*count)++;
    printf("Stock added successfully!\n");
}

void viewStocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks to display.\n");
        return;
    }

    printf("Current Stocks:\n");
    printf("-------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s: $%.2f, Change: %.2f%%\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
    printf("-------------------------------\n");
}

void updateStockPrice(Stock stocks[], int count) {
    char stockName[NAME_LENGTH];
    float newPrice;

    printf("Enter the stock name to update: ");
    scanf("%s", stockName);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, stockName) == 0) {
            printf("Enter new price for %s: ", stocks[i].name);
            scanf("%f", &newPrice);
            stocks[i].change = ((newPrice - stocks[i].price) / stocks[i].price) * 100;
            stocks[i].price = newPrice;
            printf("Stock price updated!\n");
            return;
        }
    }
    
    printf("Stock not found!\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;
    int option;

    do {
        displayMenu();
        scanf("%d", &option);
        switch(option) {
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
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid option, please select again.\n");
        }
    } while (option != 4);
    
    return 0;
}