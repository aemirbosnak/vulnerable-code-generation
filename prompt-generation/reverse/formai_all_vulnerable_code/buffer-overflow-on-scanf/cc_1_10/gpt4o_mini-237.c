//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define SYMBOL_LENGTH 10

typedef struct {
    char symbol[SYMBOL_LENGTH];
    float price;
} Stock;

Stock stocks[MAX_STOCKS];
int stockCount = 0;

void addStock();
void displayStocks(int index);
void updateStock();
void deleteStock();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    printf("Stock Market Tracker\n");
    printf("1. Add Stock\n");
    printf("2. Display Stocks\n");
    printf("3. Update Stock\n");
    printf("4. Delete Stock\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: 
            addStock(); 
            break;
        case 2: 
            displayStocks(0); 
            break;
        case 3: 
            updateStock(); 
            break;
        case 4: 
            deleteStock(); 
            break;
        case 5: 
            printf("Exiting...\n"); 
            exit(0);
        default: 
            printf("Invalid choice! Try again.\n");
    }
    menu(); // Recursive call to display the menu again
}

void addStock() {
    if (stockCount < MAX_STOCKS) {
        printf("Enter stock symbol: ");
        scanf("%s", stocks[stockCount].symbol);
        printf("Enter stock price: ");
        scanf("%f", &stocks[stockCount].price);
        stockCount++;
        printf("Stock added successfully!\n");
    } else {
        printf("Stock limit reached! Cannot add more stocks.\n");
    }
}

void displayStocks(int index) {
    if (index < stockCount) {
        printf("Stock Symbol: %s, Price: %.2f\n", stocks[index].symbol, stocks[index].price);
        displayStocks(index + 1); // Recursive call to display the next stock
    } else {
        printf("No more stocks to display.\n");
    }
}

void updateStock() {
    char symbol[SYMBOL_LENGTH];
    printf("Enter the stock symbol to update: ");
    scanf("%s", symbol);
    
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            printf("Current price of %s is %.2f. Enter new price: ", stocks[i].symbol, stocks[i].price);
            scanf("%f", &stocks[i].price);
            printf("Stock updated successfully!\n");
            return;
        }
    }
    
    printf("Stock with symbol %s not found.\n", symbol);
}

void deleteStock() {
    char symbol[SYMBOL_LENGTH];
    printf("Enter the stock symbol to delete: ");
    scanf("%s", symbol);
    
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            for (int j = i; j < stockCount - 1; j++) {
                stocks[j] = stocks[j + 1];
            }
            stockCount--;
            printf("Stock deleted successfully!\n");
            return;
        }
    }
    
    printf("Stock with symbol %s not found.\n", symbol);
}