//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100

typedef struct {
    char name[50];
    float price;
    float change;
} Stock;

void displayStocks(Stock stocks[], int count) {
    printf("\n*** Stock Market Tracker ***\n");
    printf("--------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s |\n", "Stock Name", "Price", "Change (%)");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("| %-20s | $%-9.2f | %+8.2f |\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
    printf("--------------------------------------------------\n\n");
}

void updateStockPrices(Stock stocks[], int count) {
    for (int i = 0; i < count; i++) {
        // Randomly change the prices and the change percentages
        float priceChange = ((rand() % 200) - 100) / 100.0; // Change up to +/- $1.00 
        stocks[i].price += priceChange;
        stocks[i].change = ((priceChange / (stocks[i].price - priceChange)) * 100);
    }
}

void addStock(Stock stocks[], int *count) {
    if (*count < MAX_STOCKS) {
        printf("Enter stock name: ");
        scanf("%s", stocks[*count].name);
        stocks[*count].price = rand() % 200 + 1; // Random price between $1 and $200
        stocks[*count].change = 0.0;
        (*count)++;
    } else {
        printf("Maximum stock limit reached!\n");
    }
}

void removeStock(Stock stocks[], int *count) {
    if (*count <= 0) {
        printf("No stocks to remove!\n");
        return;
    }
    
    printf("Enter stock name to remove: ");
    char stockName[50];
    scanf("%s", stockName);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(stocks[i].name, stockName) == 0) {
            // Shift stocks left
            for (int j = i; j < *count - 1; j++) {
                stocks[j] = stocks[j + 1];
            }
            (*count)--;
            printf("Stock %s removed successfully!\n", stockName);
            return;
        }
    }
    printf("Stock %s not found!\n", stockName);
}

void runTracker() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    srand(time(NULL));
    
    int choice;
    while (1) {
        printf("1. Add Stock\n");
        printf("2. Remove Stock\n");
        printf("3. Update Stock Prices\n");
        printf("4. Display Stock Prices\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStock(stocks, &count);
                break;
            case 2:
                removeStock(stocks, &count);
                break;
            case 3:
                updateStockPrices(stocks, count);
                break;
            case 4:
                displayStocks(stocks, count);
                break;
            case 5:
                printf("Exiting the Stock Market Tracker. Happy Trading!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Exciting Stock Market Tracker!\n");
    runTracker();
    return 0;
}