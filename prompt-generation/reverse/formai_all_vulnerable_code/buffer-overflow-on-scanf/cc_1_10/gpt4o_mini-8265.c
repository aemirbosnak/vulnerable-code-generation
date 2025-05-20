//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    float price;
    float change;
} Stock;

void addStock(Stock* stocks, int* count) {
    if (*count == MAX_STOCKS) {
        printf("Stock market full! Cannot add more stocks.\n");
        return;
    }
    
    printf("Enter stock name: ");
    scanf("%s", stocks[*count].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[*count].price);
    stocks[*count].change = ((rand() % 2000) / 100.0) - 10.0; // Simulate change (-10 to +10)
    
    (*count)++;
    printf("Stock %s added successfully!\n", stocks[*count - 1].name);
}

void displayStocks(Stock* stocks, int count) {
    printf("\n--- Stock Market Tracker ---\n");
    for (int i = 0; i < count; i++) {
        printf("%s: $%.2f (Change: %.2f)\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
    printf("----------------------------\n");
}

void updateStockPrice(Stock* stocks, int count) {
    char name[NAME_LENGTH];
    printf("Enter the stock name to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Current price of %s: $%.2f\n", stocks[i].name, stocks[i].price);
            printf("Enter new price: ");
            scanf("%f", &stocks[i].price);
            stocks[i].change = ((rand() % 2000) / 100.0) - 10.0; // Update change
            printf("Stock %s price updated to $%.2f!\n", stocks[i].name, stocks[i].price);
            return;
        }
    }
    
    printf("Stock %s not found!\n", name);
}

void simulateMarket(Stock* stocks, int count) {
    printf("Simulating market conditions...\n");
    for (int i = 0; i < count; i++) {
        float fluctuation = ((rand() % 3000) / 1000.0) - 1.5; // +/- 1.5 fluctuation
        stocks[i].price += fluctuation;
        stocks[i].change = fluctuation; // Update change;
    }
    printf("Market simulation completed!\n");
}

void deleteStock(Stock* stocks, int* count) {
    char name[NAME_LENGTH];
    printf("Enter the stock name to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Deleting stock %s...\n", stocks[i].name);
            for (int j = i; j < (*count - 1); j++) {
                stocks[j] = stocks[j + 1]; // Shift left
            }
            (*count)--; // Decrease stock count
            printf("Stock %s deleted successfully!\n", name);
            return;
        }
    }

    printf("Stock %s not found!\n", name);
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;
    srand(time(NULL)); // Seed for random number generator
    int choice;

    while (1) {
        printf("\n--- Welcome to the Stock Market Tracker ---\n");
        printf("1. Add Stock\n");
        printf("2. Display Stocks\n");
        printf("3. Update Stock Price\n");
        printf("4. Simulate Market\n");
        printf("5. Delete Stock\n");
        printf("6. Exit\n");
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
                deleteStock(stocks, &stockCount);
                break;
            case 6:
                printf("Thank you for using the Stock Market Tracker! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}