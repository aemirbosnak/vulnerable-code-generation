//FormAI DATASET v1.0 Category: Stock market tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of stocks
#define MAX_STOCKS 5

// Struct for a single stock
struct Stock {
    char name[20]; // name of the stock
    float price; // current price of the stock
    float daily_high; // highest price the stock reached during the day
    float daily_low; // lowest price the stock reached during the day
};

// Function to get the input for a single stock
void get_stock_input(struct Stock *stock) {
    printf("Enter the name of the stock: ");
    scanf("%s", stock->name);
    printf("Enter the current price of the stock: ");
    scanf("%f", &stock->price);
    printf("Enter the daily high of the stock: ");
    scanf("%f", &stock->daily_high);
    printf("Enter the daily low of the stock: ");
    scanf("%f", &stock->daily_low);
}

// Function to print the current status of a single stock
void print_stock_status(struct Stock stock) {
    printf("Stock: %s\n", stock.name);
    printf("Current price: %.2f\n", stock.price);
    printf("Daily high: %.2f\n", stock.daily_high);
    printf("Daily low: %.2f\n", stock.daily_low);
    printf("============================\n");
}

int main() {
    struct Stock stocks[MAX_STOCKS]; // Create an array of MAX_STOCKS stocks
    int num_stocks; // variable to store the user input for the number of stocks to track

    // Get the number of stocks to track
    printf("How many stocks do you want to track? (max %d): ", MAX_STOCKS);
    scanf("%d", &num_stocks);

    // Make sure the number of stocks is within the allowed range
    num_stocks = (num_stocks > MAX_STOCKS) ? MAX_STOCKS : num_stocks;

    // Get input for each stock and store it in the stocks array
    for (int i = 0; i < num_stocks; i++) {
        printf("Enter details for stock %d.\n", i+1);
        get_stock_input(&stocks[i]);
    }

    // Print the current status of each stock
    for (int i = 0; i < num_stocks; i++) {
        print_stock_status(stocks[i]);
    }

    return 0;
}