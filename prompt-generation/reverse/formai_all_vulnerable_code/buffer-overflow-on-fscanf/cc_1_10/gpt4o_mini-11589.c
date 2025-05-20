//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    float change;
} Stock;

void displayStocks(Stock stocks[], int count) {
    printf("\n====== Stock Market Tracker ======\n");
    printf("Name\t\tPrice\t\tChange\n");
    printf("----------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-15s $%-10.2f %+-10.2f%%\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
    printf("\n==================================\n");
}

void updateStockPrices(Stock stocks[], int count) {
    srand(time(NULL)); // Seed random number generator
    for (int i = 0; i < count; i++) {
        // Simulating random price change between -5% and +5%
        float changePercent = ((rand() % 100) / 100.0f) * 10 - 5; // Random number between -5 and 5
        stocks[i].change = changePercent;
        stocks[i].price += stocks[i].price * (changePercent / 100.0f);
        
        // Ensure the price doesn’t drop below zero
        if (stocks[i].price < 0) stocks[i].price = 0;
    }
}

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Unable to add more stocks!\n");
        return;
    }
    printf("Enter stock name: ");
    scanf("%s", stocks[*count].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[*count].price);
    stocks[*count].change = 0; // initial change is zero
    (*count)++;
}

void removeStock(Stock stocks[], int *count) {
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the stock to remove: ");
    scanf("%s", name);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                stocks[j] = stocks[j + 1];
            }
            (*count)--;
            printf("Stock %s removed successfully.\n", name);
            return;
        }
    }
    printf("Stock %s not found!\n", name);
}

void saveStocksToFile(Stock stocks[], int count) {
    FILE *file = fopen("stocks.txt", "w");
    if (!file) {
        printf("Error opening file to save stocks!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %.2f %.2f\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
    fclose(file);
    printf("Stocks saved successfully!\n");
}

void loadStocksFromFile(Stock stocks[], int *count) {
    FILE *file = fopen("stocks.txt", "r");
    if (!file) {
        printf("No saved stocks found!\n");
        return;
    }
    while (fscanf(file, "%s %f %f", stocks[*count].name, &stocks[*count].price, &stocks[*count].change) == 3) {
        (*count)++;
    }
    fclose(file);
    printf("Stocks loaded successfully!\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int choice;
    
    loadStocksFromFile(stocks, &count);
    
    do {
        printf("\n1. Display Stocks\n");
        printf("2. Add Stock\n");
        printf("3. Remove Stock\n");
        printf("4. Update Stock Prices\n");
        printf("5. Save Stocks\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayStocks(stocks, count);
                break;
            case 2:
                addStock(stocks, &count);
                break;
            case 3:
                removeStock(stocks, &count);
                break;
            case 4:
                updateStockPrices(stocks, count);
                break;
            case 5:
                saveStocksToFile(stocks, count);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);
    
    return 0;
}