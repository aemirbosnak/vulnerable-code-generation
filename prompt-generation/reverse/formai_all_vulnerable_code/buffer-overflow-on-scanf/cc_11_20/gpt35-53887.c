//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks we want to track
#define MAX_STOCKS 10

// Define a struct to hold information about a stock
struct Stock {
    char symbol[10];
    float price;
    int volume;
};

// Define a function to display the menu and get the user's choice
int getMenuChoice() {
    int choice;
    printf("\n\nStock Tracker App Menu\n");
    printf("-----------------------\n");
    printf("1. Add a stock\n");
    printf("2. Remove a stock\n");
    printf("3. Update stock price\n");
    printf("4. Update stock volume\n");
    printf("5. View all stocks\n");
    printf("6. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    // Define an array to hold the stocks
    struct Stock stocks[MAX_STOCKS];

    // Set the initial number of stocks to 0
    int numStocks = 0;

    // Define variables to hold the user's menu choice and stock index
    int choice, index;

    // Start the program loop
    while (1) {
        // Get the user's menu choice
        choice = getMenuChoice();

        // Switch on the user's choice
        switch(choice) {
            // Add a stock
            case 1:
                printf("\nAdd a Stock\n");
                printf("-------------\n");

                // Make sure there is room to add another stock
                if (numStocks >= MAX_STOCKS) {
                    printf("Sorry, you cannot add more stocks.\n");
                    break;
                }

                // Prompt the user for the stock information
                printf("Enter symbol: ");
                scanf("%s", stocks[numStocks].symbol);
                printf("Enter price: ");
                scanf("%f", &stocks[numStocks].price);
                printf("Enter volume: ");
                scanf("%d", &stocks[numStocks].volume);

                // Increment the number of stocks
                numStocks++;

                // Sort the stocks by symbol
                qsort(stocks, numStocks, sizeof(struct Stock), 
                    (int (*)(const void *, const void *))strcmp);

                printf("Stock added successfully.\n");
                break;

            // Remove a stock
            case 2:
                printf("\nRemove a Stock\n");
                printf("----------------\n");

                // Make sure there are stocks to remove
                if (numStocks == 0) {
                    printf("Sorry, there are no stocks to remove.\n");
                    break;
                }

                // Prompt the user for the stock symbol
                printf("Enter symbol: ");
                char symbol[10];
                scanf("%s", symbol);

                // Search for the stock with the matching symbol
                index = -1;
                for (int i = 0; i < numStocks; i++) {
                    if (strcmp(stocks[i].symbol, symbol) == 0) {
                        index = i;
                        break;
                    }
                }

                // If the stock is not found, display a message and break
                if (index == -1) {
                    printf("Stock not found.\n");
                    break;
                }

                // Shift all the stocks after the removed stock up one position
                for (int i = index + 1; i < numStocks; i++) {
                    stocks[i-1] = stocks[i];
                }

                // Decrement the number of stocks
                numStocks--;

                printf("Stock removed successfully.\n");
                break;

            // Update stock price
            case 3:
                printf("\nUpdate Stock Price\n");
                printf("------------------\n");

                // Make sure there are stocks to update
                if (numStocks == 0) {
                    printf("Sorry, there are no stocks to update.\n");
                    break;
                }

                // Prompt the user for the stock symbol
                printf("Enter symbol: ");
                scanf("%s", symbol);

                // Search for the stock with the matching symbol
                index = -1;
                for (int i = 0; i < numStocks; i++) {
                    if (strcmp(stocks[i].symbol, symbol) == 0) {
                        index = i;
                        break;
                    }
                }

                // If the stock is not found, display a message and break
                if (index == -1) {
                    printf("Stock not found.\n");
                    break;
                }

                // Prompt the user for the new price
                printf("Enter new price: ");
                scanf("%f", &stocks[index].price);

                printf("Stock price updated successfully.\n");
                break;

            // Update stock volume
            case 4:
                printf("\nUpdate Stock Volume\n");
                printf("-------------------\n");

                // Make sure there are stocks to update
                if (numStocks == 0) {
                    printf("Sorry, there are no stocks to update.\n");
                    break;
                }

                // Prompt the user for the stock symbol
                printf("Enter symbol: ");
                scanf("%s", symbol);

                // Search for the stock with the matching symbol
                index = -1;
                for (int i = 0; i < numStocks; i++) {
                    if (strcmp(stocks[i].symbol, symbol) == 0) {
                        index = i;
                        break;
                    }
                }

                // If the stock is not found, display a message and break
                if (index == -1) {
                    printf("Stock not found.\n");
                    break;
                }

                // Prompt the user for the new volume
                printf("Enter new volume: ");
                scanf("%d", &stocks[index].volume);

                printf("Stock volume updated successfully.\n");
                break;

            // View all stocks
            case 5:
                printf("\nAll stocks\n");
                printf("----------\n");

                // Make sure there are stocks to view
                if (numStocks == 0) {
                    printf("There are no stocks to display.\n");
                    break;
                }

                // Print the headers
                printf("%-10s%-10s%-10s\n", "Symbol", "Price", "Volume");

                // Print each stock
                for (int i = 0; i < numStocks; i++) {
                    printf("%-10s$%-9.2f%-10d\n", stocks[i].symbol, stocks[i].price, stocks[i].volume);
                }

                break;

            // Quit
            case 6:
                printf("\nGoodbye!\n");
                exit(0);

            // Default case for invalid choices
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }
    return 0;
}