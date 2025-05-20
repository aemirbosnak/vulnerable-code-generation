//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define STOCK_NAME_LENGTH 30
#define DATE_LENGTH 11

typedef struct {
    char name[STOCK_NAME_LENGTH];
    float price;
    char date[DATE_LENGTH];
} Stock;

Stock stockList[MAX_STOCKS];
int stockCount = 0;

void addStock(const char *name, float price, const char *date) {
    if (stockCount < MAX_STOCKS) {
        strncpy(stockList[stockCount].name, name, STOCK_NAME_LENGTH);
        stockList[stockCount].price = price;
        strncpy(stockList[stockCount].date, date, DATE_LENGTH);
        stockCount++;
    } else {
        printf("Stock list is full! Cannot add more stocks.\n");
    }
}

void displayStocks() {
    printf("\nCurrent Stock List:\n");
    printf("----------------------------------------------------\n");
    printf("%-30s %-10s %s\n", "Stock Name", "Price", "Date");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < stockCount; i++) {
        printf("%-30s $%-9.2f %s\n", stockList[i].name, stockList[i].price, stockList[i].date);
    }
    printf("----------------------------------------------------\n");
}

void updateStockPrice(const char *name, float newPrice, const char *date) {
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stockList[i].name, name) == 0) {
            stockList[i].price = newPrice;
            strncpy(stockList[i].date, date, DATE_LENGTH);
            printf("Updated %s to new price: $%.2f on %s\n", name, newPrice, date);
            return;
        }
    }
    printf("Stock %s not found in the list!\n", name);
}

void removeStock(const char *name) {
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stockList[i].name, name) == 0) {
            for (int j = i; j < stockCount - 1; j++) {
                stockList[j] = stockList[j + 1];
            }
            stockCount--;
            printf("Removed stock: %s\n", name);
            return;
        }
    }
    printf("Stock %s not found in the list!\n", name);
}

void freeResources() {
    // In this simple implementation, we don't have dynamically allocated memory.
    // This function serves as a placeholder for cleanup in a more complex program.
    printf("Cleaning up resources...\n");
}

int main() {
    int choice;
    char name[STOCK_NAME_LENGTH];
    float price;
    char date[DATE_LENGTH];

    printf("Welcome to the Stock Market Tracker!\n");

    do {
        printf("\n1. Add Stock\n");
        printf("2. Display Stocks\n");
        printf("3. Update Stock Price\n");
        printf("4. Remove Stock\n");
        printf("5. Exit\n");
        printf("Please choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                scanf("%s", name);
                printf("Enter stock price: ");
                scanf("%f", &price);
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                addStock(name, price, date);
                break;
            case 2:
                displayStocks();
                break;
            case 3:
                printf("Enter stock name to update: ");
                scanf("%s", name);
                printf("Enter new price: ");
                scanf("%f", &price);
                printf("Enter date (YYYY-MM-DD): ");
                scanf("%s", date);
                updateStockPrice(name, price, date);
                break;
            case 4:
                printf("Enter stock name to remove: ");
                scanf("%s", name);
                removeStock(name);
                break;
            case 5:
                printf("Exiting the tracker. Goodbye!\n");
                freeResources();
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}