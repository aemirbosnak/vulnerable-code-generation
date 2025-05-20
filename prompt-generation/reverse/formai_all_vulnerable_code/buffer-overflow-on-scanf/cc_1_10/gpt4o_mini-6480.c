//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} Stock;

void displayMenu() {
    printf("\n--- Stock Market Tracker ---\n");
    printf("1. Add a Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. Display All Stocks\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int findStockIndex(Stock stocks[], int stockCount, const char* name) {
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Not found
}

void addStock(Stock stocks[], int* stockCount) {
    if (*stockCount >= MAX_STOCKS) {
        printf("Error: Maximum stock limit reached.\n");
        return;
    }
    
    Stock newStock;
    printf("Enter stock name: ");
    scanf("%s", newStock.name);
    printf("Enter stock price: ");
    scanf("%f", &newStock.price);

    stocks[*stockCount] = newStock;
    (*stockCount)++;
    printf("Stock added successfully.\n");
}

void updateStockPrice(Stock stocks[], int stockCount) {
    char name[MAX_NAME_LENGTH];
    printf("Enter stock name to update: ");
    scanf("%s", name);
    
    int index = findStockIndex(stocks, stockCount, name);
    if (index == -1) {
        printf("Stock not found.\n");
        return;
    }

    printf("Enter new price for %s: ", stocks[index].name);
    scanf("%f", &stocks[index].price);
    printf("Stock price updated.\n");
}

void displayStocks(Stock stocks[], int stockCount) {
    if (stockCount == 0) {
        printf("No stocks available.\n");
        return;
    }
    
    printf("\n--- List of Stocks ---\n");
    for (int i = 0; i < stockCount; i++) {
        printf("Stock: %s, Price: $%.2f\n", stocks[i].name, stocks[i].price);
    }
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
                updateStockPrice(stocks, stockCount);
                break;
            case 3:
                displayStocks(stocks, stockCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}