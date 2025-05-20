//FormAI DATASET v1.0 Category: Stock market tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STOCKS 10 // Define maximum number of stocks to track
#define MAX_LENGTH 20 // Define maximum length of stock names/ticker symbols

// Define a struct to store stock information
typedef struct Stock {
    char* name;
    char* tickerSymbol;
    float currentPrice;
    float previousClosingPrice;
    float openingPrice;
    float highestPrice;
    float lowestPrice;
    bool active;
} stock;

// Global variables
stock stocks[MAX_STOCKS]; // Array of stock structs
int numStocks = 0; // Current number of stocks being tracked

// Function prototypes
void addStock();
void removeStock();
void displayStocks();
void updateStocks();

int main() {
    int choice;
    bool active = true;

    printf("Welcome to the Stock Market Tracker!\n");

    // Main menu loop
    while (active) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a stock\n");
        printf("2. Remove a stock\n");
        printf("3. View all tracked stocks\n");
        printf("4. Update stock prices\n");
        printf("5. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock();
                break;
            case 2:
                removeStock();
                break;
            case 3:
                displayStocks();
                break;
            case 4:
                updateStocks();
                break;
            case 5:
                active = false;
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to add a stock to the array
void addStock() {
    // Check if the maximum number of stocks has been reached
    if (numStocks == MAX_STOCKS) {
        printf("Maximum number of stocks tracked reached! Remove a stock to add another.\n");
        return;
    }

    // Allocate memory for new stock struct
    stock* newStock = (stock*) malloc(sizeof(stock));

    // Get user input for new stock information
    char* name = (char*) malloc(MAX_LENGTH * sizeof(char));
    char* tickerSymbol = (char*) malloc(MAX_LENGTH * sizeof(char));

    printf("Enter the name of the stock: ");
    scanf("%s", name);

    printf("Enter the ticker symbol of the stock: ");
    scanf("%s", tickerSymbol);

    // Initialize struct values
    newStock->name = name;
    newStock->tickerSymbol = tickerSymbol;
    newStock->currentPrice = 0.0;
    newStock->previousClosingPrice = 0.0;
    newStock->openingPrice = 0.0;
    newStock->highestPrice = 0.0;
    newStock->lowestPrice = 0.0;
    newStock->active = true;

    // Add new stock to array and increment number of stocks
    stocks[numStocks] = *newStock;
    numStocks++;

    printf("%s (%s) has been added to the list of tracked stocks.\n", name, tickerSymbol);

    // Deallocate memory for new stock struct
    free(newStock);
}

// Function to remove a stock from the array
void removeStock() {
    // Check if any stocks are being tracked
    if (numStocks == 0) {
        printf("There are no stocks being tracked!\n");
        return;
    }

    // Get user input for stock to remove
    char* tickerSymbol = (char*) malloc(MAX_LENGTH * sizeof(char));

    printf("Enter the ticker symbol of the stock to remove: ");
    scanf("%s", tickerSymbol);

    // Search for stock with matching ticker symbol and remove it from array
    for (int i = 0; i < numStocks; i++) {
        if (strcmp(tickerSymbol, stocks[i].tickerSymbol) == 0) {
            printf("%s (%s) has been removed from the list of tracked stocks.\n", stocks[i].name, stocks[i].tickerSymbol);
            stocks[i].active = false;
            return;
        }
    }

    // Display error message if no matching stock was found
    printf("Stock not found! Please try again.\n");

    // Deallocate memory for ticker symbol string
    free(tickerSymbol);
}

// Function to display all tracked stocks and their information
void displayStocks() {
    // Check if any stocks are being tracked
    if (numStocks == 0) {
        printf("There are no stocks being tracked!\n");
        return;
    }

    printf("Tracked stocks:\n");

    // Loop through all tracked stocks and display their information
    for (int i = 0; i < numStocks; i++) {
        if (stocks[i].active) {
            printf("%s (%s)\n", stocks[i].name, stocks[i].tickerSymbol);
            printf("Current price: %.2f\n", stocks[i].currentPrice);
            printf("Previous closing price: %.2f\n", stocks[i].previousClosingPrice);
            printf("Opening price: %.2f\n", stocks[i].openingPrice);
            printf("Highest price: %.2f\n", stocks[i].highestPrice);
            printf("Lowest price: %.2f\n", stocks[i].lowestPrice);
            printf("\n");
        }
    }
}

// Function to update stock prices
void updateStocks() {
    // Check if any stocks are being tracked
    if (numStocks == 0) {
        printf("There are no stocks being tracked!\n");
        return;
    }

    // Loop through all tracked stocks and update their prices
    for (int i = 0; i < numStocks; i++) {
        if (stocks[i].active) {
            printf("Enter the current price of %s (%s): ", stocks[i].name, stocks[i].tickerSymbol);
            scanf("%f", &stocks[i].currentPrice);

            // Update other values based on new price
            if (stocks[i].currentPrice > stocks[i].highestPrice) {
                stocks[i].highestPrice = stocks[i].currentPrice;
            }

            if (stocks[i].currentPrice < stocks[i].lowestPrice || stocks[i].lowestPrice == 0.0) {
                stocks[i].lowestPrice = stocks[i].currentPrice;
            }

            if (stocks[i].openingPrice == 0.0) {
                stocks[i].openingPrice = stocks[i].currentPrice;
            }

            stocks[i].previousClosingPrice = stocks[i].currentPrice;
        }
    }
}