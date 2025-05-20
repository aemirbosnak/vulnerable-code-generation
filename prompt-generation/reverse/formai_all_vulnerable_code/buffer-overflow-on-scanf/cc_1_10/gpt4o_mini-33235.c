//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    float change;
} Stock;

void printHeader() {
    printf("\n====================================\n");
    printf("       WELCOME TO STOCK TRACKER     \n");
    printf("====================================\n");
}

void printStock(Stock stock) {
    printf("%-20s: $%.2f (Change: %.2f%%)\n", stock.name, stock.price, stock.change);
}

void displayStocks(Stock stocks[], int count) {
    printf("\nCurrent Stock Prices:\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printStock(stocks[i]);
    }
    printf("-------------------------------------------------\n");
}

void updateStock(Stock *stock) {
    // Simulate price change
    float priceChange = ((rand() % 100) - 50) / 100.0; // Price change between -0.50 to +0.49
    stock->price += priceChange;
    stock->change = (priceChange / (stock->price - priceChange)) * 100;
}

void addStock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Maximum number of stocks reached.\n");
        return;
    }

    printf("Enter stock name: ");
    scanf("%s", stocks[*count].name);
    stocks[*count].price = (float)(rand() % 1000) / 10; // Price between $0.00 to $99.90
    stocks[*count].change = 0.0;
    (*count)++;
    printf("%s has been added with an initial price of $%.2f!\n", stocks[*count - 1].name, stocks[*count - 1].price);
}

void removeStock(Stock stocks[], int *count) {
    char name[MAX_NAME_LENGTH];
    printf("Enter the stock name to remove: ");
    scanf("%s", name);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            stocks[i] = stocks[*count - 1]; // Replace with last stock
            (*count)--;
            printf("%s has been removed from the tracker!\n", name);
            return;
        }
    }
    printf("Stock %s not found in the tracker.\n", name);
}

void runTracker() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int option;

    while (1) {
        printHeader();
        printf("1. Add Stock\n");
        printf("2. Remove Stock\n");
        printf("3. Update Prices\n");
        printf("4. Display Stocks\n");
        printf("5. Exit\n");
        printf("Choose an option: ");

        scanf("%d", &option);

        switch (option) {
            case 1:
                addStock(stocks, &count);
                break;
            case 2:
                removeStock(stocks, &count);
                break;
            case 3:
                for (int i = 0; i < count; i++) {
                    updateStock(&stocks[i]);
                }
                printf("Stock prices updated!\n");
                break;
            case 4:
                displayStocks(stocks, count);
                break;
            case 5:
                printf("Exiting Stock Tracker. Stay profitable! 📈\n");
                exit(0);
            default:
                printf("Invalid option. Please try again!\n");
        }
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed
    runTracker();
    return 0;
}