//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float price;
    float change;
} Stock;

void addStock(Stock *stocks, int *stockCount) {
    if (*stockCount >= MAX_STOCKS) {
        printf("Maximum stock limit reached!\n");
        return;
    }
    printf("Enter stock name: ");
    scanf("%s", stocks[*stockCount].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[*stockCount].price);
    stocks[*stockCount].change = ((rand() % 200 - 100) / 100.0) * stocks[*stockCount].price; // Random change
    (*stockCount)++;
}

void displayStocks(Stock *stocks, int stockCount) {
    printf("\nStock Market Tracker\n");
    printf("---------------------\n");
    for (int i = 0; i < stockCount; i++) {
        printf("Stock: %s | Price: %.2f | Change: %.2f\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
    printf("---------------------\n");
}

void updateStockPrice(Stock *stocks, int stockCount) {
    char name[NAME_LENGTH];
    printf("Enter stock name to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Current price: %.2f\n", stocks[i].price);
            printf("Enter new price: ");
            scanf("%f", &stocks[i].price);
            stocks[i].change = ((rand() % 200 - 100) / 100.0) * stocks[i].price; // Random change
            printf("Price updated successfully!\n");
            return;
        }
    }
    
    printf("Stock '%s' not found!\n", name);
}

void simulateMarket(Stock *stocks, int stockCount) {
    printf("Simulating market fluctuations...\n");
    
    for (int i = 0; i < stockCount; i++) {
        float fluctuation = ((rand() % 200 - 100) / 100.0); // Random change between -1.0 and 1.0
        stocks[i].price += fluctuation;
        stocks[i].change = fluctuation * stocks[i].price; 
    }
    
    printf("Market simulation complete!\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;
    int choice;

    srand(time(0)); // Seed the random number generator

    while (1) {
        printf("\nWelcome to the Stock Market Tracker!\n");
        printf("1. Add Stock\n");
        printf("2. Display Stocks\n");
        printf("3. Update Stock Price\n");
        printf("4. Simulate Market\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(stocks, &stockCount);
                break;
            case 2:
                displayStocks(stocks, stockCount);
                break;
            case 3:
                updateStockPrice(stocks, stockCount);
                break;
            case 4:
                simulateMarket(stocks, stockCount);
                break;
            case 5:
                printf("Exiting the Stock Market Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
    }

    return 0;
}