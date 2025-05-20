//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Define the maximum number of stocks that can be tracked
#define MAX_STOCKS 100

// Define the structure for each stock
typedef struct {
    char name[20];
    double price;
    int quantity;
} stock_t;

int main() {
    // Initialize the stocks array
    stock_t stocks[MAX_STOCKS];
    int num_stocks = 0;

    // Prompt the user to enter the number of stocks they want to track
    printf("Enter the number of stocks you want to track (up to %d): ", MAX_STOCKS);
    scanf("%d", &num_stocks);

    // Loop through each stock and prompt the user for its information
    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the name of stock #%d: ", i+1);
        scanf("%s", stocks[i].name);

        printf("Enter the price of stock #%d: ", i+1);
        scanf("%lf", &stocks[i].price);

        printf("Enter the quantity of stock #%d: ", i+1);
        scanf("%d", &stocks[i].quantity);
    }

    // Prompt the user to enter the current date
    char date[20];
    printf("Enter the current date (YYYY-MM-DD): ");
    scanf("%s", date);

    // Calculate the total value of all stocks
    double total_value = 0.0;
    for (int i = 0; i < num_stocks; i++) {
        total_value += stocks[i].price * stocks[i].quantity;
    }

    // Display the information for each stock
    printf("\nStock Tracker - %s\n", date);
    for (int i = 0; i < num_stocks; i++) {
        printf("Stock #%d: %s\n", i+1, stocks[i].name);
        printf("Price: $%.2f\n", stocks[i].price);
        printf("Quantity: %d\n", stocks[i].quantity);
        printf("Value: $%.2f\n\n", stocks[i].price * stocks[i].quantity);
    }

    // Display the total value of all stocks
    printf("Total Value: $%.2f\n", total_value);

    return 0;
}