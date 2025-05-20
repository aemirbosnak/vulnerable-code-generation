//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 10

// Define the structure of a stock
typedef struct {
    char symbol[10];
    char name[50];
    float price;
    float change;
} Stock;

// Define the array of stocks to track
Stock stocks[MAX_STOCKS];

// Function to get the stock data from a file
void getStockData(char *filename) {
    FILE *fp;
    int i = 0;

    // Open the file
    fp = fopen(filename, "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Read the stock data from the file
    while (fscanf(fp, "%s %s %f %f", stocks[i].symbol, stocks[i].name, &stocks[i].price, &stocks[i].change) != EOF) {
        i++;
    }

    // Close the file
    fclose(fp);
}

// Function to print the stock data
void printStockData() {
    int i;

    // Print the header
    printf("%-10s %-50s %-10s %-10s\n", "Symbol", "Name", "Price", "Change");

    // Print the stock data
    for (i = 0; i < MAX_STOCKS; i++) {
        printf("%-10s %-50s %-10.2f %-10.2f\n", stocks[i].symbol, stocks[i].name, stocks[i].price, stocks[i].change);
    }
}

// Function to get the stock symbol from the user
void getStockSymbol(char *symbol) {
    printf("Enter the stock symbol: ");
    scanf("%s", symbol);
}

// Function to get the stock price from the user
float getStockPrice() {
    float price;

    printf("Enter the stock price: ");
    scanf("%f", &price);

    return price;
}

// Function to update the stock data
void updateStockData(char *symbol, float price) {
    int i;

    // Find the stock with the specified symbol
    for (i = 0; i < MAX_STOCKS; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            // Update the stock price
            stocks[i].price = price;

            // Calculate the stock change
            stocks[i].change = price - stocks[i].price;

            // Print the updated stock data
            printf("Stock data updated:\n");
            printf("%-10s %-50s %-10.2f %-10.2f\n", stocks[i].symbol, stocks[i].name, stocks[i].price, stocks[i].change);

            break;
        }
    }

    // If the stock was not found, print an error message
    if (i == MAX_STOCKS) {
        printf("Stock not found\n");
    }
}

// Main function
int main() {
    char filename[] = "stocks.txt";
    char symbol[10];
    float price;
    int choice;

    // Get the stock data from the file
    getStockData(filename);

    // Print the stock data
    printStockData();

    // Get the user's choice
    do {
        printf("\n1. Update stock data\n");
        printf("2. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Get the stock symbol from the user
                getStockSymbol(symbol);

                // Get the stock price from the user
                price = getStockPrice();

                // Update the stock data
                updateStockData(symbol, price);

                break;
            case 2:
                // Quit the program
                break;
            default:
                // Print an error message
                printf("Invalid choice\n");
        }
    } while (choice != 2);

    return 0;
}