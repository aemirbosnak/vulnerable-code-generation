//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float price;
    float change; // Percentage change
} Stock;

void printMenu() {
    printf("\n--- Stock Market Tracker ---\n");
    printf("1. Add Stock\n");
    printf("2. View Stocks\n");
    printf("3. Update Stock Prices\n");
    printf("4. Exit\n");
    printf("----------------------------\n");
}

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Error: Cannot add more stocks.\n");
        return;
    }
    
    printf("Enter stock name: ");
    scanf(" %[^\n]", stocks[*count].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[*count].price);
    stocks[*count].change = 0.0f;
    (*count)++;
    printf("Stock added successfully!\n");
}

void viewStocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks to display.\n");
        return;
    }
    
    printf("\n--- Current Stocks ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f (Change: %.2f%%)\n", i + 1, stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

void updateStockPrices(Stock stocks[], int count) {
    printf("\n--- Updating Stock Prices ---\n");
    
    for (int i = 0; i < count; i++) {
        float oldPrice = stocks[i].price;
        // Simulate the price change
        float priceChange = ((rand() % 200) - 100) / 100.0; // Between -1.0 and 1.0
        stocks[i].price *= (1 + priceChange);
        stocks[i].change = (stocks[i].price - oldPrice) / oldPrice * 100.0f;
        
        printf("Updated price for %s: $%.2f (Change: %.2f%%)\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
    
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int choice;
    
    do {
        printMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStock(stocks, &count);
                break;
            case 2:
                viewStocks(stocks, count);
                break;
            case 3:
                updateStockPrices(stocks, count);
                break;
            case 4:
                printf("Exiting the program. Happy trading!\n");
                break;
            default:
                printf("Error: Invalid choice, please try again.\n");
        }
        
        sleep(1); // Pause before the next iteration
    } while (choice != 4);
    
    return 0;
}