//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the stock structure
typedef struct {
    char *name;
    double price;
} Stock;

// Create an array of stocks
Stock stocks[] = {
    { "Apple", 120.0 },
    { "Google", 100.0 },
    { "Microsoft", 90.0 },
    { "Amazon", 80.0 },
    { "Tesla", 70.0 }
};

// Get the number of stocks
int num_stocks = sizeof(stocks) / sizeof(Stock);

// Print the stock information
void print_stocks() {
    for (int i = 0; i < num_stocks; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
    }
}

// Update the stock prices
void update_prices() {
    for (int i = 0; i < num_stocks; i++) {
        // Get a random price change
        double change = (rand() % 10) / 10.0;

        // Update the stock price
        stocks[i].price += change;
    }
}

// Get the user's input
void get_input() {
    char input[10];

    while (1) {
        printf("Enter a command (p to print, u to update, q to quit): ");
        scanf("%s", input);

        if (strcmp(input, "p") == 0) {
            print_stocks();
        } else if (strcmp(input, "u") == 0) {
            update_prices();
        } else if (strcmp(input, "q") == 0) {
            exit(0);
        } else {
            printf("Invalid command.\n");
        }
    }
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Print the welcome message
    printf("Welcome to the stock market tracker!\n");

    // Get the user's input
    get_input();

    return 0;
}