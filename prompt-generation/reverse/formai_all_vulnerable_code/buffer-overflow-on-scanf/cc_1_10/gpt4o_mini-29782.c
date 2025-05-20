//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float price;
} Stock;

void displayStocks(Stock stocks[], int count) {
    printf("\n=== Current Stock Market Tracker ===\n");
    printf("No. | Stock Name                      | Price\n");
    printf("-----------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-3d | %-30s | $%.2f\n", i + 1, stocks[i].name, stocks[i].price);
    }
    printf("-----------------------------------------\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;
    char continueInput = 'y';

    printf("🎉 Welcome to the Cheerful Stock Market Tracker! 🎉\n");

    while (continueInput == 'y' && stockCount < MAX_STOCKS) {
        printf("\nEnter the stock name: ");
        fgets(stocks[stockCount].name, NAME_LENGTH, stdin);
        // Remove newline character from fgets
        stocks[stockCount].name[strcspn(stocks[stockCount].name, "\n")] = 0;

        printf("Enter the current price for %s: ", stocks[stockCount].name);
        scanf("%f", &stocks[stockCount].price);
        getchar();  // Clear newline character left in buffer

        stockCount++;

        if (stockCount < MAX_STOCKS) {
            printf("Would you like to add another stock? (y/n): ");
            scanf("%c", &continueInput);
            getchar();  // Clear newline character
        } else {
            printf("You've reached the limit of %d stocks! No more can be added.\n", MAX_STOCKS);
            continueInput = 'n'; // Stop the loop
        }
    }

    displayStocks(stocks, stockCount);

    printf("\nThank you for using the Cheerful Stock Market Tracker! 🌟\n");
    
    return 0;
}