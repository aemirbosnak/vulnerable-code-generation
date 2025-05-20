//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
} Stock;

Stock stockMarket[MAX_STOCKS];
int stockCount = 0;

void addStock(const char* name, float price) {
    if (stockCount >= MAX_STOCKS) {
        printf("Stock market is full! Cannot add more stocks.\n");
        return;
    }
    strncpy(stockMarket[stockCount].name, name, MAX_NAME_LENGTH);
    stockMarket[stockCount].price = price;
    stockCount++;
    printf("Added stock: %s at price: %.2f\n", name, price);
}

void updateStockPrice(const char* name, float newPrice) {
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stockMarket[i].name, name) == 0) {
            stockMarket[i].price = newPrice;
            printf("Updated %s price to %.2f\n", name, newPrice);
            return;
        }
    }
    printf("Stock %s not found!\n", name);
}

void listStocks() {
    printf("\nCurrent Stocks in Market:\n");
    printf("Name\t\tPrice\n");
    printf("-------------------------------\n");
    for (int i = 0; i < stockCount; i++) {
        printf("%s\t%.2f\n", stockMarket[i].name, stockMarket[i].price);
    }
    printf("-------------------------------\n");
}

void deleteStock(const char* name) {
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stockMarket[i].name, name) == 0) {
            for (int j = i; j < stockCount - 1; j++) {
                stockMarket[j] = stockMarket[j + 1];
            }
            stockCount--;
            printf("Deleted stock: %s\n", name);
            return;
        }
    }
    printf("Stock %s not found!\n", name);
}

void saveStocksToFile(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Failed to open file for writing.\n");
        return;
    }
    for (int i = 0; i < stockCount; i++) {
        fprintf(file, "%s,%.2f\n", stockMarket[i].name, stockMarket[i].price);
    }
    fclose(file);
    printf("Stocks saved to %s\n", filename);
}

void loadStocksFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file for reading.\n");
        return;
    }
    while (fscanf(file, "%49[^,],%f\n", stockMarket[stockCount].name, &stockMarket[stockCount].price) == 2) {
        stockCount++;
    }
    fclose(file);
    printf("Stocks loaded from %s\n", filename);
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    float price;

    do {
        printf("\n--- Stock Market Tracker Menu ---\n");
        printf("1. Add Stock\n");
        printf("2. Update Stock Price\n");
        printf("3. Delete Stock\n");
        printf("4. List Stocks\n");
        printf("5. Save Stocks to File\n");
        printf("6. Load Stocks from File\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter stock name: ");
                scanf("%s", name);
                printf("Enter stock price: ");
                scanf("%f", &price);
                addStock(name, price);
                break;
            case 2:
                printf("Enter stock name to update: ");
                scanf("%s", name);
                printf("Enter new stock price: ");
                scanf("%f", &price);
                updateStockPrice(name, price);
                break;
            case 3:
                printf("Enter stock name to delete: ");
                scanf("%s", name);
                deleteStock(name);
                break;
            case 4:
                listStocks();
                break;
            case 5:
                saveStocksToFile("stocks.txt");
                break;
            case 6:
                loadStocksFromFile("stocks.txt");
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 7);

    return 0;
}