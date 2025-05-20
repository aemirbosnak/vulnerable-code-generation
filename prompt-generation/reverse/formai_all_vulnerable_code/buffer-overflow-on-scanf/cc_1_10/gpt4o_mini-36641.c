//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    double price;
    double change; // Change in price
} Stock;

void displayMarket(Stock stocks[], int count) {
    printf("\n===== Stock Market Tracker =====\n");
    printf("%-20s %-10s %-10s\n", "Company Name", "Price", "Change");
    printf("===========================================\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s $%-9.2f %+9.2f%%\n", stocks[i].name, stocks[i].price, stocks[i].change * 100);
    }
    printf("===========================================\n");
}

void updateStockPrices(Stock stocks[], int count) {
    srand(time(NULL)); // Seed random number generator
    for (int i = 0; i < count; i++) {
        double fluctuation = ((rand() % 2000) - 1000) / 10000.0; // Price fluctuation between -10% and +10%
        stocks[i].price += stocks[i].price * fluctuation;
        stocks[i].change = fluctuation;
    }
}

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Cannot add more stocks. Maximum limit reached.\n");
        return;
    }
    Stock new_stock;
    
    printf("Enter the company name: ");
    scanf("%s", new_stock.name);
    
    printf("Enter the initial price: $");
    scanf("%lf", &new_stock.price);
    
    new_stock.change = 0.0; // Initialize change to 0
    stocks[*count] = new_stock;
    (*count)++;
    printf("Stock added successfully!\n");
}

void removeStock(Stock stocks[], int *count) {
    char name[NAME_LEN];
    printf("Enter the company name to remove: ");
    scanf("%s", name);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                stocks[j] = stocks[j + 1]; // Shift left
            }
            (*count)--; // reduce stock count
            printf("Stock removed successfully!\n");
            return;
        }
    }
    printf("Stock with name '%s' not found.\n", name);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stock_count = 0;
    int choice;

    while (1) {
        printf("\n===== Stock Market Management =====\n");
        printf("1. Add Stock\n");
        printf("2. Remove Stock\n");
        printf("3. Update Stock Prices\n");
        printf("4. Display Market\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(stocks, &stock_count);
                break;
            case 2:
                removeStock(stocks, &stock_count);
                break;
            case 3:
                updateStockPrices(stocks, stock_count);
                printf("Stock prices updated successfully!\n");
                break;
            case 4:
                displayMarket(stocks, stock_count);
                break;
            case 5:
                printf("Exiting the stock market tracker.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}