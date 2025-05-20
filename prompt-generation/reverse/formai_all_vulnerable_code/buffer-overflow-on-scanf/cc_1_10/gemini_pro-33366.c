//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cheerful stock market tracker!

// Define some stock data
typedef struct {
    char *name;
    double price;
    double change;
} Stock;

Stock stocks[] = {
    { "Apple", 120.00, 1.00 },
    { "Microsoft", 90.00, -0.50 },
    { "Amazon", 150.00, 2.00 },
    { "Google", 110.00, 0.00 },
    { "Tesla", 70.00, -1.00 },
};

// Function to print the stock data
void print_stocks(Stock *stocks, int num_stocks) {
    printf("** Welcome to the Stock Market Tracker! **\n\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("Stock: %s\n", stocks[i].name);
        printf("Price: %.2f\n", stocks[i].price);
        printf("Change: %.2f\n\n", stocks[i].change);
    }
}

// Function to get the user's input
int get_user_input() {
    int choice;
    printf("Please enter a number (1-%d) to view stock data: ", 5);
    scanf("%d", &choice);
    return choice;
}

// Function to handle the user's choice
void handle_user_choice(int choice) {
    switch (choice) {
        case 1:
            print_stocks(stocks, 5);
            break;
        case 2:
            printf("You entered 2.\n");
            break;
        case 3:
            printf("You entered 3.\n");
            break;
        case 4:
            printf("You entered 4.\n");
            break;
        case 5:
            printf("You entered 5.\n");
            break;
        default:
            printf("Invalid input. Please enter a number between 1 and 5.\n");
    }
}

// Main function
int main() {
    int choice;
    do {
        choice = get_user_input();
        handle_user_choice(choice);
    } while (choice != 0);
    return 0;
}