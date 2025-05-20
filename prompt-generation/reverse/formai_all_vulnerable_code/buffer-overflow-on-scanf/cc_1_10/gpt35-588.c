//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 10

// Structure to keep stock information
struct Stock {
    char symbol[10];
    float price;
};

// Function to update the stock price
void update_price(struct Stock* stock, float new_price) {
    stock->price = new_price;
}

// Function to display all the stocks
void display_stocks(struct Stock* stocks, int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        printf("Stock symbol: %s\n", stocks[i].symbol);
        printf("Price: %.2f\n", stocks[i].price);
        printf("\n");
    }
}

int main() {
    struct Stock stocks[MAX_STOCKS];
    int num_stocks = 0;
    char user_input;

    printf("Welcome to C Stock Market Tracker!\n");

    while (1) {
        printf("Enter a command (a for add, u for update, d for display): ");
        scanf(" %c", &user_input);

        if (user_input == 'a') {
            if (num_stocks == MAX_STOCKS) {
                printf("Maximum number of stocks reached.\n");
                continue;
            }

            printf("Enter stock symbol: ");
            scanf(" %s", stocks[num_stocks].symbol);

            printf("Enter stock price: ");
            scanf(" %f", &stocks[num_stocks].price);

            num_stocks++;
            printf("Stock successfully added!\n");
        }
        else if (user_input == 'u') {
            if (num_stocks == 0) {
                printf("No stocks have been added yet.\n");
                continue;
            }

            printf("Enter stock symbol: ");
            char symbol[10];
            scanf(" %s", symbol);

            int found_index = -1;
            for (int i = 0; i < num_stocks; i++) {
                if (strcmp(stocks[i].symbol, symbol) == 0) {
                    found_index = i;
                    break;
                }
            }

            if (found_index == -1) {
                printf("Stock not found.\n");
                continue;
            }

            printf("Enter new stock price: ");
            float new_price;
            scanf(" %f", &new_price);

            update_price(&stocks[found_index], new_price);

            printf("Stock price successfully updated!\n");
        }
        else if (user_input == 'd') {
            if (num_stocks == 0) {
                printf("No stocks have been added yet.\n");
                continue;
            }

            printf("Current stock prices:\n");
            display_stocks(stocks, num_stocks);
        }
        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}