//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define STOCK_NAME_LEN 50
#define FILE_NAME "stocks.dat"

typedef struct {
    char name[STOCK_NAME_LEN];
    float price;
} Stock;

// Function prototypes
void addStock(Stock *stocks, int *count);
void updateStockPrice(Stock *stocks, int count);
void viewStocks(Stock *stocks, int count);
void searchStock(Stock *stocks, int count);
void saveStocksToFile(Stock *stocks, int count);
void loadStocksFromFile(Stock *stocks, int *count);

int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;
    int choice;

    loadStocksFromFile(stocks, &stockCount);

    while (1) {
        printf("\nStock Market Tracker\n");
        printf("1. Add Stock\n");
        printf("2. Update Stock Price\n");
        printf("3. View Stocks\n");
        printf("4. Search Stock\n");
        printf("5. Exit\n");
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
                viewStocks(stocks, stockCount);
                break;
            case 4:
                searchStock(stocks, stockCount);
                break;
            case 5:
                saveStocksToFile(stocks, stockCount);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addStock(Stock *stocks, int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Stock list is full. Cannot add more stocks.\n");
        return;
    }
    printf("Enter stock name: ");
    scanf("%s", stocks[*count].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[*count].price);
    (*count)++;
    printf("Stock added successfully!\n");
}

void updateStockPrice(Stock *stocks, int count) {
    char stockName[STOCK_NAME_LEN];
    float newPrice;
    int found = 0;

    printf("Enter stock name to update: ");
    scanf("%s", stockName);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, stockName) == 0) {
            printf("Current price of %s: %.2f\n", stocks[i].name, stocks[i].price);
            printf("Enter new price: ");
            scanf("%f", &newPrice);
            stocks[i].price = newPrice;
            found = 1;
            printf("Stock price updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Stock not found!\n");
    }
}

void viewStocks(Stock *stocks, int count) {
    if (count == 0) {
        printf("No stocks to display.\n");
        return;
    }
    printf("\nList of Stocks:\n");
    for (int i = 0; i < count; i++) {
        printf("Stock Name: %s, Price: %.2f\n", stocks[i].name, stocks[i].price);
    }
}

void searchStock(Stock *stocks, int count) {
    char stockName[STOCK_NAME_LEN];
    int found = 0;

    printf("Enter stock name to search: ");
    scanf("%s", stockName);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, stockName) == 0) {
            printf("Stock found! Name: %s, Price: %.2f\n", stocks[i].name, stocks[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Stock not found!\n");
    }
}

void saveStocksToFile(Stock *stocks, int count) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file) {
        fwrite(stocks, sizeof(Stock), count, file);
        fclose(file);
        printf("Stocks saved to file successfully.\n");
    } else {
        printf("Error saving stocks to file!\n");
    }
}

void loadStocksFromFile(Stock *stocks, int *count) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file) {
        *count = fread(stocks, sizeof(Stock), MAX_STOCKS, file);
        fclose(file);
        printf("Stocks loaded from file successfully. Count: %d\n", *count);
    } else {
        printf("No existing stock data found.\n");
    }
}