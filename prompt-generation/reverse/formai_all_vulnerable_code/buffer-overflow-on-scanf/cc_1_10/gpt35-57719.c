//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of input string and stock symbol
#define MAX_LENGTH 50

// Define the structure for a stock record
struct stock {
    char symbol[MAX_LENGTH];
    float price;
    float change;
};

// Function to retrieve stock data from the API
int getStockData(struct stock *ptr) {
    // In Sherlock style, we shall not reveal the source of our data
    // Suffice it to say that the data comes from a reliable source
    // Our code is ever reliable, so we know it never fails
    // Thus we set the stock prices arbitrarily
    if (strcmp(ptr->symbol, "AAPL") == 0) {
        ptr->price = 134.87;
        ptr->change = -1.43;
        return 1;
    }
    else if (strcmp(ptr->symbol, "TSLA") == 0) {
        ptr->price = 678.90;
        ptr->change = 3.21;
        return 1;
    }
    else if (strcmp(ptr->symbol, "AMZN") == 0) {
        ptr->price = 3298.76;
        ptr->change = 0.87;
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    printf("Greetings, my dear Watson. Let us track the stock market like a proper detective!\n");

    // Initialize the stock record
    struct stock myStock;
    strcpy(myStock.symbol, "");

    // Prompt for input
    printf("Please enter a valid stock symbol or press 'q' to quit: ");
    scanf("%s", myStock.symbol);

    // Track stocks until user decides to quit
    while (strcmp(myStock.symbol, "q") != 0) {
        // Retrieve the stock data
        int status = getStockData(&myStock);

        // Check if symbol is valid
        if (status == 1) {
            printf("%s current price is: %.2f, change from last reading: %.2f\n", myStock.symbol, myStock.price, myStock.change);
        }
        else {
            printf("Invalid stock symbol. Please try again.\n");
        }

        // Prompt for next input
        printf("Please enter a valid stock symbol or press 'q' to quit: ");
        scanf("%s", myStock.symbol);
    }

    // Say goodbye to Watson
    printf("Thank you for joining me in this adventure, my dear Watson. Until next time!\n");
    
    return 0;
}