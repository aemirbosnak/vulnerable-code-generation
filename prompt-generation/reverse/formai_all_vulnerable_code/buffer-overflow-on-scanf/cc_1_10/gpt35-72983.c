//FormAI DATASET v1.0 Category: Stock market tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store information about stocks
typedef struct Stock {
    char name[20];
    float current_price;
    float change;
} Stock;

// Function to print the stock information
void print_stock(Stock *s) {
    printf("Name: %s\n", s->name);
    printf("Current price: %.2f\n", s->current_price);
    printf("Change: %.2f\n", s->change);
}

// Function to update the stock information
void update_stock(Stock *s, float new_price) {
    float old_price = s->current_price;
    s->current_price = new_price;
    s->change = (new_price - old_price) / old_price * 100;
}

int main() {
    // Declare variables
    char input[20];
    Stock stock_list[3] = {{"AAPL", 123.45, 0.0}, {"GOOG", 678.90, 0.0}, {"AMZN", 987.65, 0.0}};

    // Print the initial stock information
    printf("Initial stock information:\n");
    for (int i = 0; i < 3; i++) {
        print_stock(&stock_list[i]);
    }

    // Get user input for which stock to update
    printf("Enter the name of the stock to update: ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline character

    // Update the stock information based on user input
    for (int i = 0; i < 3; i++) {
        if (strcmp(input, stock_list[i].name) == 0) {
            float new_price;
            printf("Enter the new price for %s: ", input);
            scanf("%f", &new_price);
            update_stock(&stock_list[i], new_price);
            printf("Updated stock information:\n");
            print_stock(&stock_list[i]);
            break;
        }
    }

    return 0;
}