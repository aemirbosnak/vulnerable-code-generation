//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

// Structure to hold stock information
typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Stock;

// Function to display the stock portfolio
void displayStocks(Stock stocks[], int stockCount) {
    printf("\nYour Stock Portfolio:\n");
    printf("%-20s %-10s %-10s\n", "Stock Name", "Price", "Quantity");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < stockCount; i++) {
        printf("%-20s $%-9.2f %-10d\n", stocks[i].name, stocks[i].price, stocks[i].quantity);
    }
    printf("-----------------------------------------------\n");
}

// Function to add a new stock to the portfolio
void addStock(Stock stocks[], int *stockCount) {
    if (*stockCount >= MAX_STOCKS) {
        printf("Portfolio is full! Cannot add more stocks.\n");
        return;
    }
    Stock newStock;

    printf("Enter stock name: ");
    scanf("%s", newStock.name);
    printf("Enter stock price: ");
    scanf("%f", &newStock.price);
    printf("Enter stock quantity: ");
    scanf("%d", &newStock.quantity);

    stocks[*stockCount] = newStock;
    (*stockCount)++;
    printf("Stock added successfully!\n");
}

// Function to update the price of an existing stock
void updateStockPrice(Stock stocks[], int stockCount) {
    char stockName[MAX_NAME_LENGTH];
    printf("Enter stock name to update its price: ");
    scanf("%s", stockName);

    for (int i = 0; i < stockCount; i++) {
        if (strcmp(stocks[i].name, stockName) == 0) {
            printf("Current price of %s is $%.2f\n", stocks[i].name, stocks[i].price);
            printf("Enter new price: ");
            scanf("%f", &stocks[i].price);
            printf("Price updated successfully!\n");
            return;
        }
    }
    printf("Stock not found in the portfolio.\n");
}

// Function to remove a stock from the portfolio
void removeStock(Stock stocks[], int *stockCount) {
    char stockName[MAX_NAME_LENGTH];
    printf("Enter stock name to remove: ");
    scanf("%s", stockName);

    for (int i = 0; i < *stockCount; i++) {
        if (strcmp(stocks[i].name, stockName) == 0) {
            for (int j = i; j < *stockCount - 1; j++) {
                stocks[j] = stocks[j + 1];
            }
            (*stockCount)--;
            printf("Stock removed successfully!\n");
            return;
        }
    }
    printf("Stock not found in the portfolio.\n");
}

// Function to find the total value of the stocks in the portfolio
void totalPortfolioValue(Stock stocks[], int stockCount) {
    float totalValue = 0;
    for (int i = 0; i < stockCount; i++) {
        totalValue += stocks[i].price * stocks[i].quantity;
    }
    printf("Total portfolio value: $%.2f\n", totalValue);
}

// Main function to manage the stock portfolio
int main() {
    Stock stocks[MAX_STOCKS];
    int stockCount = 0;
    int choice;

    printf("Welcome to the Peaceful Stock Market Tracker!\n");
    do {
        printf("\nMenu:\n");
        printf("1. Add a stock\n");
        printf("2. Update stock price\n");
        printf("3. Remove a stock\n");
        printf("4. Display portfolio\n");
        printf("5. Calculate total portfolio value\n");
        printf("6. Exit\n");
        printf("Please select an option (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(stocks, &stockCount);
                break;
            case 2:
                updateStockPrice(stocks, stockCount);
                break;
            case 3:
                removeStock(stocks, &stockCount);
                break;
            case 4:
                displayStocks(stocks, stockCount);
                break;
            case 5:
                totalPortfolioValue(stocks, stockCount);
                break;
            case 6:
                printf("Exiting the stock market tracker. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}