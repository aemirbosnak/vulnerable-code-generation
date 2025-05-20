//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stock {
    char *name;
    double price;
    double change;
};

int main() {
    // The stock market is wild today! Let's keep track of it.

    // Create an array of stocks.
    struct stock stocks[] = {
        {"Apple", 120.00, 1.00},
        {"Google", 100.00, -0.50},
        {"Microsoft", 90.00, 0.00},
        {"Amazon", 150.00, 2.00},
        {"Tesla", 200.00, 5.00}
    };

    // Get the number of stocks in the array.
    int num_stocks = sizeof(stocks) / sizeof(stocks[0]);

    // Print the header.
    printf("** Stock Market Tracker **\n");
    printf("--------------------------\n");
    printf("%-15s %-10s %-10s\n", "Name", "Price", "Change");
    printf("--------------------------\n");

    // Print the stocks.
    for (int i = 0; i < num_stocks; i++) {
        printf("%-15s %-10.2f %-10.2f\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }

    // Print the footer.
    printf("--------------------------\n");

    // Get the user's input.
    char input[100];
    printf("Enter a stock name to track: ");
    scanf("%s", input);

    // Find the stock in the array.
    int index = -1;
    for (int i = 0; i < num_stocks; i++) {
        if (strcmp(input, stocks[i].name) == 0) {
            index = i;
            break;
        }
    }

    // If the stock was not found, print an error message.
    if (index == -1) {
        printf("Stock not found.\n");
        return 1;
    }

    // Print the stock's information.
    printf("** Stock Information **\n");
    printf("--------------------------\n");
    printf("%-15s %-10s %-10s\n", "Name", "Price", "Change");
    printf("--------------------------\n");
    printf("%-15s %-10.2f %-10.2f\n", stocks[index].name, stocks[index].price, stocks[index].change);
    printf("--------------------------\n");

    // Get the user's input.
    char input2[100];
    printf("Enter a new price for the stock: ");
    scanf("%s", input2);

    // Update the stock's price.
    stocks[index].price = atof(input2);

    // Print the stock's information.
    printf("** Stock Information **\n");
    printf("--------------------------\n");
    printf("%-15s %-10s %-10s\n", "Name", "Price", "Change");
    printf("--------------------------\n");
    printf("%-15s %-10.2f %-10.2f\n", stocks[index].name, stocks[index].price, stocks[index].change);
    printf("--------------------------\n");

    return 0;
}