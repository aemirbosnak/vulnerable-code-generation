//FormAI DATASET v1.0 Category: Stock market tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10  // Define maximum number of stocks to track

typedef struct stock {
    char name[20];
    float price;
    float change;
} Stock;  // Define structure for each stock tracked

void displayStock(Stock *s) {  // Function to display stock information
    printf("%-10s%-10.2f%-10.2f\n", s->name, s->price, s->change);
}

int main() {
    Stock stocks[MAX_STOCKS];  // Create array of stocks
    int numStocks = 0;  // Set initial number of stocks tracked to 0
    char choice;  // Variable to store user choice
    int i, j;  // Counter variables

    do {
        printf("Select an option:\n");
        printf("1. Add stock\n");
        printf("2. Remove stock\n");
        printf("3. Update stock prices\n");
        printf("4. View stock information\n");
        printf("5. Quit\n");
        fflush(stdin);  // Clear input buffer
        scanf("%c", &choice);

        switch(choice) {
            case '1':  // Add stock
                if (numStocks < MAX_STOCKS) {  // Check if maximum number of stocks has been reached
                    printf("Enter stock name: ");
                    fflush(stdin);
                    gets(stocks[numStocks].name);  // Get stock name
                    printf("Enter stock price: ");
                    fflush(stdin);
                    scanf("%f", &stocks[numStocks].price);  // Get stock price
                    stocks[numStocks].change = 0;  // Set initial change to 0
                    numStocks++;  // Increment number of stocks tracked
                }
                else {  // Maximum number of stocks reached
                    printf("Maximum number of stocks reached\n");
                }
                break;
            case '2':  // Remove stock
                if (numStocks > 0) {  // Check if there are any stocks to remove
                    printf("Enter stock name: ");
                    fflush(stdin);
                    char stockName[20];
                    gets(stockName);  // Get stock name to remove
                    int found = 0;  // Initialize found flag
                    for (i = 0; i < numStocks; i++) {
                        if (strcmp(stocks[i].name, stockName) == 0) {  // Stock found
                            found = 1;  // Set found flag
                            for (j = i; j < numStocks - 1; j++) {  // Shift all stocks after removed stock by one position
                                stocks[j] = stocks[j + 1];
                            }
                            numStocks--;  // Decrement number of stocks tracked
                            printf("Stock removed\n");
                            break;
                        }
                    }
                    if (!found) {  // Stock not found
                        printf("Stock not found\n");
                    }
                }
                else {  // No stocks to remove
                    printf("No stocks to remove\n");
                }
                break;
            case '3':  // Update stock prices
                if (numStocks > 0) {  // Check if there are any stocks to update
                    for (i = 0; i < numStocks; i++) {
                        printf("Enter price for %s: ", stocks[i].name);
                        fflush(stdin);
                        scanf("%f", &stocks[i].price);  // Get updated stock price
                        stocks[i].change = (stocks[i].price - stocks[i].change) / stocks[i].change * 100;  // Calculate stock price change
                    }
                    printf("Stock prices updated\n");
                }
                else {  // No stocks to update
                    printf("No stocks to update\n");
                }
                break;
            case '4':  // View stock information
                printf("%-10s%-10s%-10s\n", "Name", "Price", "Change");
                for (i = 0; i < numStocks; i++) {
                    displayStock(&stocks[i]);  // Display stock information
                }
                break;
            case '5':  // Quit
                printf("Goodbye!\n");
                break;
            default:  // Invalid input
                printf("Invalid input\n");
                break;
        }
    } while (choice != '5');  // Continue until user chooses to quit

    return 0;
}