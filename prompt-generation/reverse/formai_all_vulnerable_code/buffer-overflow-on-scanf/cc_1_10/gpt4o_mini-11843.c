//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10
#define STOCK_NAME_LEN 20

typedef struct {
    char name[STOCK_NAME_LEN];
    float price;
} Stock;

void displayMenu() {
    printf("\n======== Stock Market Tracker ========\n");
    printf("1. Add Stock\n");
    printf("2. Display Stocks\n");
    printf("3. Update Stock Price\n");
    printf("4. Exit\n");
    printf("======================================\n");
    printf("Select an option: ");
}

void addStock(Stock stocks[], int *stockCount) {
    if (*stockCount >= MAX_STOCKS) {
        printf("Maximum stock limit reached! Cannot add more stocks.\n");
        return;
    }
    
    printf("Enter stock name: ");
    scanf("%s", stocks[*stockCount].name);
    
    printf("Enter stock price: ");
    scanf("%f", &stocks[*stockCount].price);
    
    (*stockCount)++;
    printf("Stock added successfully!\n");
}

void displayStocks(Stock stocks[], int stockCount) {
    if (stockCount == 0) {
        printf("No stocks available to display.\n");
        return;
    }
    
    printf("\n===== Current Stocks =====\n");
    for (int i = 0; i < stockCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, stocks[i].name, stocks[i].price);
    }
}

void updateStockPrice(Stock stocks[], int stockCount) {
    int index;
    float newPrice;

    displayStocks(stocks, stockCount);
    printf("Enter the stock number to update price: ");
    scanf("%d", &index);
    
    if (index < 1 || index > stockCount) {
        printf("Invalid stock number!\n");
        return;
    }

    printf("Enter new price for %s: ", stocks[index - 1].name);
    scanf("%f", &newPrice);
    
    stocks[index - 1].price = newPrice;
    printf("Stock price updated successfully!\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;
    int choice;

    do {
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
                printf("Exiting the Stock Market Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 4);
    
    return 0;
}