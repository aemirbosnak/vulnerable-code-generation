//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 10

// Define the structure of a stock
typedef struct {
    char *name;
    double price;
    double change;
    double percent_change;
} Stock;

// Create an array of stocks
Stock stocks[MAX_STOCKS];

// Get the stock data from the user
void get_stock_data() {
    for (int i = 0; i < MAX_STOCKS; i++) {
        printf("Enter the name of stock %d: ", i + 1);
        scanf("%s", stocks[i].name);
        printf("Enter the price of stock %d: ", i + 1);
        scanf("%lf", &stocks[i].price);
        printf("Enter the change in price of stock %d: ", i + 1);
        scanf("%lf", &stocks[i].change);
        printf("Enter the percent change in price of stock %d: ", i + 1);
        scanf("%lf", &stocks[i].percent_change);
    }
}

// Calculate the total value of the stocks
double get_total_value() {
    double total_value = 0;
    for (int i = 0; i < MAX_STOCKS; i++) {
        total_value += stocks[i].price;
    }
    return total_value;
}

// Calculate the average price of the stocks
double get_average_price() {
    double average_price = 0;
    for (int i = 0; i < MAX_STOCKS; i++) {
        average_price += stocks[i].price;
    }
    return average_price / MAX_STOCKS;
}

// Calculate the highest price of the stocks
double get_highest_price() {
    double highest_price = 0;
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].price > highest_price) {
            highest_price = stocks[i].price;
        }
    }
    return highest_price;
}

// Calculate the lowest price of the stocks
double get_lowest_price() {
    double lowest_price = 0;
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (stocks[i].price < lowest_price) {
            lowest_price = stocks[i].price;
        }
    }
    return lowest_price;
}

// Print the stock data
void print_stock_data() {
    printf("\nStock Data\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("| Name | Price | Change | Percent Change |\n");
    printf("-----------------------------------------------------------------------------\n");
    for (int i = 0; i < MAX_STOCKS; i++) {
        printf("| %s | %.2lf | %.2lf | %.2lf% |\n", stocks[i].name, stocks[i].price, stocks[i].change, stocks[i].percent_change);
    }
    printf("-----------------------------------------------------------------------------\n");
}

// Print the stock summary
void print_stock_summary() {
    printf("\nStock Summary\n");
    printf("-------------------------------------\n");
    printf("Total Value: $%.2lf\n", get_total_value());
    printf("Average Price: $%.2lf\n", get_average_price());
    printf("Highest Price: $%.2lf\n", get_highest_price());
    printf("Lowest Price: $%.2lf\n", get_lowest_price());
    printf("-------------------------------------\n");
}

// Main function
int main() {
    // Get the stock data from the user
    get_stock_data();

    // Print the stock data
    print_stock_data();

    // Print the stock summary
    print_stock_summary();

    return 0;
}