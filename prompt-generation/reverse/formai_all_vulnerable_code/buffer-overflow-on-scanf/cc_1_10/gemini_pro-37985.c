//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A happy stock market tracker!

int main() {
    // Declare some variables.
    int num_stocks;
    char stock_names[10][20];
    float stock_prices[10];
    float stock_changes[10];

    // Get the number of stocks from the user.
    printf("How many stocks do you want to track? ");
    scanf("%d", &num_stocks);

    // Get the stock names and prices from the user.
    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the name of stock %d: ", i + 1);
        scanf("%s", stock_names[i]);

        printf("Enter the price of stock %d: ", i + 1);
        scanf("%f", &stock_prices[i]);
    }

    // Calculate the stock changes.
    for (int i = 0; i < num_stocks; i++) {
        stock_changes[i] = stock_prices[i] - stock_prices[i-1];
    }

    // Print the stock information.
    printf("\nHere is the stock information you entered:\n");
    printf("--------------------------------------------------------\n");
    printf("| Name | Price | Change |\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("| %-20s | $%-10.2f | %-10.2f |\n", stock_names[i], stock_prices[i], stock_changes[i]);
    }
    printf("--------------------------------------------------------\n");

    // Check if any stocks have gone up or down.
    int num_up = 0;
    int num_down = 0;
    for (int i = 0; i < num_stocks; i++) {
        if (stock_changes[i] > 0) {
            num_up++;
        } else if (stock_changes[i] < 0) {
            num_down++;
        }
    }

    // Print the number of stocks that have gone up or down.
    printf("\n%d stocks have gone up in price.\n", num_up);
    printf("%d stocks have gone down in price.\n", num_down);

    // Print a happy message!
    printf("\nYay! You're a happy stock market tracker!\n");

    return 0;
}