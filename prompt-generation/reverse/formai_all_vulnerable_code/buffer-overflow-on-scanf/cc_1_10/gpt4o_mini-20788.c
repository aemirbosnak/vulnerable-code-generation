//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define STOCK_NAME_LENGTH 20

typedef struct {
    char name[STOCK_NAME_LENGTH];
    float price;
    int volume;
} Stock;

void displayMenu() {
    printf("**************************************************\n");
    printf("                 STOCK MARKET TRACKER\n");
    printf("**************************************************\n");
    printf("1. Add a new stock\n");
    printf("2. Update stock price\n");
    printf("3. Display all stocks\n");
    printf("4. Simulate stock price changes\n");
    printf("5. Exit the program\n");
    printf("**************************************************\n");
    printf("Choose an action (1-5): ");
}

void addStock(Stock *stocks, int *stockCount) {
    if (*stockCount >= MAX_STOCKS) {
        printf("ERROR: Stock list is full!\n\n");
        return;
    }
    
    Stock newStock;
    printf("Enter the stock name: ");
    scanf("%s", newStock.name);
    printf("Enter the stock price: ");
    scanf("%f", &newStock.price);
    printf("Enter the stock volume: ");
    scanf("%d", &newStock.volume);
    
    stocks[*stockCount] = newStock;
    (*stockCount)++;
    
    printf("SUCCESS: Stock %s added!\n\n", newStock.name);
}

void updateStockPrice(Stock *stocks, int stockCount) {
    char stockName[STOCK_NAME_LENGTH];
    float newPrice;
    int found = 0;

    printf("Enter the stock name to update: ");
    scanf("%s", stockName);
    
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].name, stockName) == 0) {
            printf("Enter the new price for %s: ", stocks[i].name);
            scanf("%f", &newPrice);
            stocks[i].price = newPrice;
            found = 1;
            printf("SUCCESS: Stock %s price updated to %.2f!\n\n", stocks[i].name, newPrice);
            break;
        }
    }
    
    if (!found) {
        printf("ERROR: Stock %s not found!\n\n", stockName);
    }
}

void displayStocks(Stock *stocks, int stockCount) {
    if (stockCount == 0) {
        printf("ERROR: No stocks available!\n\n");
        return;
    }

    printf("Current Stock Portfolio:\n");
    printf("--------------------------------------------------\n");
    printf("%-20s %-10s %-10s\n", "Stock Name", "Price", "Volume");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < stockCount; i++) {
        printf("%-20s $%-9.2f %-10d\n", stocks[i].name, stocks[i].price, stocks[i].volume);
    }
    
    printf("--------------------------------------------------\n\n");
}

void simulatePriceChanges(Stock *stocks, int stockCount) {
    if (stockCount == 0) {
        printf("ERROR: No stocks available to simulate!\n\n");
        return;
    }

    srand(time(NULL)); // Seed the random number generator
    float changePercentage;

    printf("Simulating price changes for all stocks...\n");
    for (int i = 0; i < stockCount; i++) {
        changePercentage = (rand() % 61 - 30) / 100.0; // Random change between -30% and +30%
        stocks[i].price += stocks[i].price * changePercentage;
        printf("Stock %s new price: $%.2f (%.2f%% change)\n", stocks[i].name, stocks[i].price, changePercentage * 100);
    }
    
    printf("Simulation complete!\n\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(stocks, &stockCount);
                break;
            case 2:
                updateStockPrice(stocks, stockCount);
                break;
            case 3:
                displayStocks(stocks, stockCount);
                break;
            case 4:
                simulatePriceChanges(stocks, stockCount);
                break;
            case 5:
                printf("Exiting the Stock Market Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("ERROR: Invalid choice. Please select between 1 and 5.\n\n");
                break;
        }
    }
    
    return 0;
}