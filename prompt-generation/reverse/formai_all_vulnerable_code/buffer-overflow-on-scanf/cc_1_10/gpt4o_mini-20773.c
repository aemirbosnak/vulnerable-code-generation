//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Stock;

// Function to display the menu
void displayMenu() {
    printf("==== Stock Market Tracker ====\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. View Stocks\n");
    printf("4. Remove Stock\n");
    printf("5. Exit\n");
    printf("==============================\n");
    printf("Choose an option: ");
}

// Function to add a stock
void addStock(Stock stocks[], int *stockCount) {
    if (*stockCount >= MAX_STOCKS) {
        printf("Stock limit reached!\n");
        return;
    }
    printf("Enter stock name: ");
    scanf("%s", stocks[*stockCount].name);
    printf("Enter stock price: ");
    scanf("%f", &stocks[*stockCount].price);
    printf("Enter stock quantity: ");
    scanf("%d", &stocks[*stockCount].quantity);
    (*stockCount)++;
    printf("Stock added successfully!\n");
}

// Function to update the stock price
void updateStockPrice(Stock stocks[], int stockCount) {
    char name[MAX_NAME_LENGTH];
    printf("Enter stock name to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            printf("Enter new price for %s: ", stocks[i].name);
            scanf("%f", &stocks[i].price);
            printf("Stock price updated successfully!\n");
            return;
        }
    }
    printf("Stock not found!\n");
}

// Function to view all stocks
void viewStocks(Stock stocks[], int stockCount) {
    if (stockCount == 0) {
        printf("No stocks to display!\n");
        return;
    }
    printf("==== List of Stocks ====\n");
    printf("%-20s %-10s %-10s\n", "Name", "Price", "Quantity");
    for (int i = 0; i < stockCount; i++) {
        printf("%-20s $%-9.2f %-10d\n", stocks[i].name, stocks[i].price, stocks[i].quantity);
    }
    printf("=========================\n");
}

// Function to remove a stock
void removeStock(Stock stocks[], int *stockCount) {
    char name[MAX_NAME_LENGTH];
    printf("Enter stock name to remove: ");
    scanf("%s", name);
    
    for (int i = 0; i < *stockCount; i++) {
        if (strcmp(stocks[i].name, name) == 0) {
            // Shift stocks down to fill the gap
            for (int j = i; j < *stockCount - 1; j++) {
                stocks[j] = stocks[j + 1];
            }
            (*stockCount)--;
            printf("Stock removed successfully!\n");
            return;
        }
    }
    printf("Stock not found!\n");
}

// Main function
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
                viewStocks(stocks, stockCount);
                break;
            case 4:
                removeStock(stocks, &stockCount);
                break;
            case 5:
                printf("Exiting the Stock Market Tracker...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
        sleep(1);  // Adding a little delay for better user experience
    }

    return 0;
}