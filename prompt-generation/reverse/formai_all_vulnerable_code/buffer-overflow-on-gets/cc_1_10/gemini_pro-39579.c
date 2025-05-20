//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    double price;
} Stock;

int main() {
    Stock stocks[5] = {
        { "Apple", 120.0 },
        { "Google", 100.0 },
        { "Amazon", 150.0 },
        { "Microsoft", 90.0 },
        { "Tesla", 180.0 }
    };

    printf("Current Stock Prices:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
    }

    while (1) {
        // Get the user's input.
        char input[100];
        printf("Enter a stock name to track (or quit to exit): ");
        gets(input);

        // Exit if the user entered "quit".
        if (strcmp(input, "quit") == 0) {
            break;
        }

        // Find the stock in the array.
        int index = -1;
        for (int i = 0; i < 5; i++) {
            if (strcmp(input, stocks[i].name) == 0) {
                index = i;
                break;
            }
        }

        // If the stock was not found, display an error message.
        if (index == -1) {
            printf("Invalid stock name.\n");
            continue;
        }

        // Track the stock price.
        while (1) {
            // Get the current price of the stock.
            double price = stocks[index].price;

            // Display the current price of the stock.
            printf("Current price of %s: $%.2f\n", stocks[index].name, price);

            // Wait for the user to enter a new price.
            printf("Enter a new price (or quit to exit): ");
            gets(input);

            // Exit if the user entered "quit".
            if (strcmp(input, "quit") == 0) {
                break;
            }

            // Update the price of the stock.
            stocks[index].price = atof(input);
        }
    }

    return 0;
}