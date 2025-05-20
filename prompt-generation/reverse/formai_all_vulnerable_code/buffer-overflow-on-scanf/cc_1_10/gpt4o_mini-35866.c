//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float price;
    float change; // Percentage change
} Stock;

void displayMenu();
void addStock(Stock stocks[], int *totalStocks);
void updateStock(Stock stocks[], int totalStocks);
void displayStocks(const Stock stocks[], int totalStocks);
void searchStock(const Stock stocks[], int totalStocks);
void randomStockPriceUpdate(Stock stocks[], int totalStocks);
void randomizeChange(Stock *stock);

int main() {
    Stock stocks[MAX_STOCKS];
    int totalStocks = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(stocks, &totalStocks);
                break;
            case 2:
                updateStock(stocks, totalStocks);
                break;
            case 3:
                displayStocks(stocks, totalStocks);
                break;
            case 4:
                searchStock(stocks, totalStocks);
                break;
            case 5:
                randomStockPriceUpdate(stocks, totalStocks);
                break;
            case 6:
                printf("Exiting the Stock Market Tracker. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

void displayMenu() {
    printf("\n--- Stock Market Tracker ---\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock\n");
    printf("3. Display Stocks\n");
    printf("4. Search Stock\n");
    printf("5. Random Update Prices\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void addStock(Stock stocks[], int *totalStocks) {
    if (*totalStocks >= MAX_STOCKS) {
        printf("Stock list is full. Cannot add more stocks.\n");
        return;
    }
    
    Stock newStock;
    printf("Enter stock name: ");
    scanf("%s", newStock.name);
    printf("Enter stock price: ");
    scanf("%f", &newStock.price);
    newStock.change = 0; // Initial change is 0

    stocks[*totalStocks] = newStock;
    (*totalStocks)++;
    printf("Stock added successfully!\n");
}

void updateStock(Stock stocks[], int totalStocks) {
    char name[NAME_LENGTH];
    printf("Enter stock name to update: ");
    scanf("%s", name);

    for (int i = 0; i < totalStocks; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Current price: %.2f\n", stocks[i].price);
            printf("Enter new price: ");
            scanf("%f", &stocks[i].price);
            randomizeChange(&stocks[i]);
            printf("Price updated successfully!\n");
            return;
        }
    }
    printf("Stock not found!\n");
}

void displayStocks(const Stock stocks[], int totalStocks) {
    printf("\n--- Current Stocks ---\n");
    if (totalStocks == 0) {
        printf("No stocks available.\n");
        return;
    }
    for (int i = 0; i < totalStocks; i++) {
        printf("Stock: %s | Price: %.2f | Change: %.2f%%\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

void searchStock(const Stock stocks[], int totalStocks) {
    char name[NAME_LENGTH];
    printf("Enter stock name to search: ");
    scanf("%s", name);

    for (int i = 0; i < totalStocks; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Found Stock: %s | Price: %.2f | Change: %.2f%%\n", stocks[i].name, stocks[i].price, stocks[i].change);
            return;
        }
    }
    printf("Stock not found!\n");
}

void randomStockPriceUpdate(Stock stocks[], int totalStocks) {
    for (int i = 0; i < totalStocks; i++) {
        randomizeChange(&stocks[i]);
    }
    printf("Random updates applied to all stocks!\n");
}

void randomizeChange(Stock *stock) {
    float change = ((float)rand() / RAND_MAX) * 10.0f - 5.0f; // Random change between -5% and +5%
    stock->price += stock->price * (change / 100.0f);
    stock->change = change;
}