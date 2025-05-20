//FormAI DATASET v1.0 Category: Stock market tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store stock information
struct Stock {
    char* name;
    double price;
    double change;
    double percentChange;
};

int main() {
    // Set up an array of Stock structs
    struct Stock stocks[3];
    
    // Initialize stock information
    stocks[0].name = "AAPL";
    stocks[0].price = 127.14;
    stocks[0].change = 0.25;
    stocks[0].percentChange = 0.20;
    
    stocks[1].name = "GOOG";
    stocks[1].price = 1825.55;
    stocks[1].change = -2.10;
    stocks[1].percentChange = -0.11;
    
    stocks[2].name = "TSLA";
    stocks[2].price = 748.90;
    stocks[2].change = 5.75;
    stocks[2].percentChange = 0.77;
    
    // Set up a loop to print stock information and prompt the user for input
    int input;
    while (1) {
        // Print stock information
        printf("Stocks:\n");
        for (int i = 0; i < 3; i++) {
            printf("%s: $%.2f (%+.2f, %+.2f%%)\n", stocks[i].name, stocks[i].price, stocks[i].change, stocks[i].percentChange);
        }
        
        // Prompt the user for input
        printf("Enter the number of the stock you would like to track (1-3), or enter 0 to quit: ");
        scanf("%d", &input);
        
        // Check if the user wants to quit
        if (input == 0) {
            printf("Exiting program...\n");
            exit(0);
        }
        
        // Check if the user entered a valid number
        if (input < 1 || input > 3) {
            printf("Invalid input. Please enter a number between 1 and 3, or enter 0 to quit.\n");
            continue;
        }
        
        // Update stock information based on user input
        double priceChange;
        printf("Enter the price change for %s: ", stocks[input-1].name);
        scanf("%lf", &priceChange);
        stocks[input-1].change = priceChange - stocks[input-1].price;
        stocks[input-1].percentChange = ((priceChange - stocks[input-1].price) / stocks[input-1].price) * 100;
        stocks[input-1].price = priceChange;
        printf("Updated %s to $%.2f (%+.2f, %+.2f%%)\n", stocks[input-1].name, stocks[input-1].price, stocks[input-1].change, stocks[input-1].percentChange);
    }
    
    return 0;
}