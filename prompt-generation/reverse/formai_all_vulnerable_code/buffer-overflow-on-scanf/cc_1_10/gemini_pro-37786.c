//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stock {
    char *name;
    float price;
    float change;
} stock;

int main() {
    // Create an array of stocks
    stock stocks[] = {
        {"Apple", 178.55, 1.23},
        {"Microsoft", 312.01, 2.45},
        {"Amazon", 2378.23, 5.67},
        {"Tesla", 899.99, 3.12},
        {"Google", 2847.52, 4.36}
    };

    // Get the number of stocks
    int num_stocks = sizeof(stocks) / sizeof(stock);

    // Print the header
    printf("Stock Market Tracker\n");
    printf("---------------------\n");
    printf("%-15s %-10s %-10s\n", "Name", "Price", "Change");

    // Print the stocks
    for (int i = 0; i < num_stocks; i++) {
        printf("%-15s $%-9.2f %+.2f%%\n", stocks[i].name, stocks[i].price, stocks[i].change);
    }

    // Get the user's input
    char input[100];
    printf("\nEnter a stock name to get more information, or quit to exit: ");
    scanf("%s", input);

    // Find the stock by name
    int found = 0;
    for (int i = 0; i < num_stocks; i++) {
        if (strcmp(input, stocks[i].name) == 0) {
            found = 1;

            // Print the stock information
            printf("\nStock Information\n");
            printf("-----------------\n");
            printf("Name: %s\n", stocks[i].name);
            printf("Price: $%.2f\n", stocks[i].price);
            printf("Change: %+.2f%%\n", stocks[i].change);

            // Get the user's input
            char input2[100];
            printf("\nEnter buy or sell to trade this stock, or quit to exit: ");
            scanf("%s", input2);

            // Trade the stock
            if (strcmp(input2, "buy") == 0) {
                int quantity;
                printf("Enter the quantity to buy: ");
                scanf("%d", &quantity);

                // Buy the stock
                stocks[i].price += 0.50; // Simulate a 50 cent increase in price
                printf("You have bought %d shares of %s for a total of $%.2f.\n", quantity, stocks[i].name, quantity * stocks[i].price);
            } else if (strcmp(input2, "sell") == 0) {
                int quantity;
                printf("Enter the quantity to sell: ");
                scanf("%d", &quantity);

                // Sell the stock
                stocks[i].price -= 0.50; // Simulate a 50 cent decrease in price
                printf("You have sold %d shares of %s for a total of $%.2f.\n", quantity, stocks[i].name, quantity * stocks[i].price);
            } else if (strcmp(input2, "quit") == 0) {
                break;
            } else {
                printf("Invalid input.\n");
            }
        }
    }

    // Exit the program
    if (!found) {
        printf("Invalid stock name.\n");
    }
    printf("\nExiting the program.\n");

    return 0;
}