//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Stock;

void displayMenu() {
    printf("--------------------------------------------------\n");
    printf("Stock Market Tracker\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. View All Stocks\n");
    printf("4. Search Stock\n");
    printf("5. Calculate Total Value\n");
    printf("6. Exit\n");
    printf("--------------------------------------------------\n");
}

void addStock(Stock stocks[], int *stockCount) {
    if (*stockCount >= MAX_STOCKS) {
        printf("Cannot add more stocks, maximum capacity reached.\n");
        return;
    }

    printf("Enter stock name: ");
    scanf("%s", stocks[*stockCount].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[*stockCount].price);
    printf("Enter stock quantity: ");
    scanf("%d", &stocks[*stockCount].quantity);

    (*stockCount)++;
    printf("Stock added successfully.\n");
}

void updateStockPrice(Stock stocks[], int stockCount) {
    char stockName[MAX_NAME_LENGTH];
    printf("Enter stock name to update: ");
    scanf("%s", stockName);

    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].name, stockName) == 0) {
            printf("Enter new price for %s: ", stocks[i].name);
            scanf("%f", &stocks[i].price);
            printf("Stock price updated successfully.\n");
            return;
        }
    }
    printf("Stock not found.\n");
}

void viewAllStocks(Stock stocks[], int stockCount) {
    printf("--------------------------------------------------\n");
    printf("Stocks in the market:\n");
    for (int i = 0; i < stockCount; i++) {
        printf("Stock Name: %s, Price: %.2f, Quantity: %d\n", 
                stocks[i].name, stocks[i].price, stocks[i].quantity);
    }
    printf("--------------------------------------------------\n");
}

void searchStock(Stock stocks[], int stockCount) {
    char stockName[MAX_NAME_LENGTH];
    printf("Enter stock name to search: ");
    scanf("%s", stockName);

    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].name, stockName) == 0) {
            printf("Stock Name: %s, Price: %.2f, Quantity: %d\n", 
                    stocks[i].name, stocks[i].price, stocks[i].quantity);
            return;
        }
    }
    printf("Stock not found.\n");
}

void calculateTotalValue(Stock stocks[], int stockCount) {
    float totalValue = 0;
    for (int i = 0; i < stockCount; i++) {
        totalValue += stocks[i].price * stocks[i].quantity;
    }
    printf("Total value of all stocks: %.2f\n", totalValue);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(stocks, &stockCount);
                break;
            case 2:
                updateStockPrice(stocks, stockCount);
                break;
            case 3:
                viewAllStocks(stocks, stockCount);
                break;
            case 4:
                searchStock(stocks, stockCount);
                break;
            case 5:
                calculateTotalValue(stocks, stockCount);
                break;
            case 6:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}