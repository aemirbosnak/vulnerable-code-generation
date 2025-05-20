//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Structure to hold stock information
typedef struct {
    char name[30];
    char symbol[10];
    float price;
    float change;
} Stock;

// Function prototypes
void displayStocks(Stock *stocks, int count);
void updateStockPrice(Stock *stock);
void searchStock(Stock *stocks, int count, const char *symbol);
void sortStocksByPrice(Stock *stocks, int count);
void addStock(Stock *stocks, int *count, Stock stock);

int main() {
    Stock stocks[100]; // Array of stocks
    int stockCount = 0; // Number of stocks in the array
    int choice;
    
    // Sample Data
    Stock google = {"Google Inc.", "GOOGL", 2730.00, 0.00};
    Stock apple = {"Apple Inc.", "AAPL", 150.00, 0.00};
    Stock amazon = {"Amazon.com Inc.", "AMZN", 3450.00, 0.00};
    
    // Add sample stocks
    addStock(stocks, &stockCount, google);
    addStock(stocks, &stockCount, apple);
    addStock(stocks, &stockCount, amazon);
    
    // Main loop
    while (1) {
        printf("\n--- Stock Market Tracker ---\n");
        printf("1. Display All Stocks\n");
        printf("2. Update Stock Price\n");
        printf("3. Search Stock by Symbol\n");
        printf("4. Sort Stocks by Price\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayStocks(stocks, stockCount);
                break;
            case 2: {
                char symbol[10];
                printf("Enter stock symbol to update: ");
                scanf("%s", symbol);
                searchStock(stocks, stockCount, symbol);
                break;
            }
            case 3: {
                char symbol[10];
                printf("Enter stock symbol to search: ");
                scanf("%s", symbol);
                searchStock(stocks, stockCount, symbol);
                break;
            }
            case 4:
                sortStocksByPrice(stocks, stockCount);
                printf("Stocks sorted by price.\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void displayStocks(Stock *stocks, int count) {
    printf("\n--- List of Stocks ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Symbol: %s, Price: %.2f, Change: %.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].change);
    }
}

void updateStockPrice(Stock *stock) {
    float newPrice;
    printf("Enter new price for %s (%s): ", stock->name, stock->symbol);
    scanf("%f", &newPrice);
    stock->change = newPrice - stock->price;
    stock->price = newPrice;
    printf("Updated %s (%s) price to %.2f with change %.2f\n", stock->name, stock->symbol, stock->price, stock->change);
}

void searchStock(Stock *stocks, int count, const char *symbol) {
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            printf("Found stock: %s (%s), Price: %.2f, Change: %.2f\n", stocks[i].name, stocks[i].symbol, stocks[i].price, stocks[i].change);
            updateStockPrice(&stocks[i]);
            return;
        }
    }
    printf("Stock with symbol %s not found.\n", symbol);
}

void sortStocksByPrice(Stock *stocks, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (stocks[j].price > stocks[j + 1].price) {
                Stock temp = stocks[j];
                stocks[j] = stocks[j + 1];
                stocks[j + 1] = temp;
            }
        }
    }
}

void addStock(Stock *stocks, int *count, Stock stock) {
    stocks[*count] = stock;
    (*count)++;
}