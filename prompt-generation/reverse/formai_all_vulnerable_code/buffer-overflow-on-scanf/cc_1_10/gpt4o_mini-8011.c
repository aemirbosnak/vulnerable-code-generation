//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold stock information
struct Stock {
    char name[50];
    float price;
    float change;
};

// Function prototypes
void addStock(struct Stock* stocks, int* count);
void displayStocks(struct Stock* stocks, int count);
void trackPriceChange(struct Stock* stocks, int count);

int main() {
    // A dynamic array of stocks
    struct Stock* stocks = NULL;
    int count = 0;  // Number of stocks in the array
    int choice;

    // Console instructions for the user
    printf("Welcome to the Stock Market Tracker!\n");
    do {
        printf("\nMenu:\n");
        printf("1. Add Stock\n");
        printf("2. Display Stocks\n");
        printf("3. Track Price Change\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // User wants to add a stock
                addStock(stocks, &count);
                break;
            case 2:
                // Display all stocks currently being tracked
                displayStocks(stocks, count);
                break;
            case 3:
                // Track price changes of existing stocks
                trackPriceChange(stocks, count);
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    // Clean-up to prevent memory leaks
    free(stocks);
    return 0;
}

// Function to add a new stock
void addStock(struct Stock* stocks, int* count) {
    // Reallocate memory for the new stock
    stocks = realloc(stocks, (*count + 1) * sizeof(struct Stock));
    if (stocks == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    // Input details for the new stock
    printf("Enter stock name: ");
    scanf("%s", stocks[*count].name);
    printf("Enter current price: ");
    scanf("%f", &stocks[*count].price);
    printf("Enter price change percentage: ");
    scanf("%f", &stocks[*count].change);

    (*count)++;
    printf("Stock '%s' added successfully!\n", stocks[*count - 1].name);
}

// Function to display all tracked stocks
void displayStocks(struct Stock* stocks, int count) {
    // Check if there are any stocks to display
    if (count == 0) {
        printf("No stocks available to display.\n");
        return;
    }

    printf("\nTracked Stocks:\n");
    printf("%-20s %-10s %-15s\n", "Name", "Price", "Change (%)");
    for (int i = 0; i < count; i++) {
        printf("%-20s $%-9.2f %-14.2f\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

// Function to track price change; updates prices based on a simulated market change
void trackPriceChange(struct Stock* stocks, int count) {
    // If there are no stocks, notify the user
    if (count == 0) {
        printf("No stocks available for price change tracking.\n");
        return;
    }

    printf("\nUpdating stock prices based on market trends...\n");
    for (int i = 0; i < count; i++) {
        // Simulate a change in price
        float priceChangeAmount = stocks[i].price * (stocks[i].change / 100);
        stocks[i].price += priceChangeAmount; // Update the stock price
        printf("Updated %s to new price: $%.2f\n", stocks[i].name, stocks[i].price);
    }
}