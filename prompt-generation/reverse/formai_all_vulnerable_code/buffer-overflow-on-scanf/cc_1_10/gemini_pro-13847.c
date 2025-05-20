//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of stocks to track
#define MAX_STOCKS 100

// Define the structure of a stock
typedef struct {
    char *name;
    double price;
    double change;
    double volume;
} stock_t;

// Create an array of stocks
stock_t stocks[MAX_STOCKS];

// Get the number of stocks from the user
int get_num_stocks() {
    int num_stocks;
    printf("Enter the number of stocks to track: ");
    scanf("%d", &num_stocks);
    return num_stocks;
}

// Get the data for a stock from the user
void get_stock_data(stock_t *stock) {
    printf("Enter the name of the stock: ");
    scanf("%s", stock->name);
    printf("Enter the price of the stock: ");
    scanf("%lf", &stock->price);
    printf("Enter the change in the stock price: ");
    scanf("%lf", &stock->change);
    printf("Enter the volume of the stock: ");
    scanf("%lf", &stock->volume);
}

// Calculate the mean price of the stocks
double calculate_mean_price(int num_stocks) {
    double mean_price = 0.0;
    for (int i = 0; i < num_stocks; i++) {
        mean_price += stocks[i].price;
    }
    mean_price /= num_stocks;
    return mean_price;
}

// Calculate the standard deviation of the stock prices
double calculate_standard_deviation(int num_stocks, double mean_price) {
    double standard_deviation = 0.0;
    for (int i = 0; i < num_stocks; i++) {
        standard_deviation += pow(stocks[i].price - mean_price, 2);
    }
    standard_deviation /= num_stocks;
    standard_deviation = sqrt(standard_deviation);
    return standard_deviation;
}

// Print the stock data
void print_stock_data(int num_stocks) {
    printf("Stock Data:\n");
    for (int i = 0; i < num_stocks; i++) {
        printf("%s: $%.2f (%.2f%%), Volume: %.2f\n", stocks[i].name, stocks[i].price, stocks[i].change, stocks[i].volume);
    }
}

// Print the summary statistics
void print_summary_statistics(int num_stocks, double mean_price, double standard_deviation) {
    printf("\nSummary Statistics:\n");
    printf("Mean Price: $%.2f\n", mean_price);
    printf("Standard Deviation: $%.2f\n", standard_deviation);
}

// Main function
int main() {
    // Get the number of stocks from the user
    int num_stocks = get_num_stocks();

    // Get the data for each stock
    for (int i = 0; i < num_stocks; i++) {
        get_stock_data(&stocks[i]);
    }

    // Calculate the mean price of the stocks
    double mean_price = calculate_mean_price(num_stocks);

    // Calculate the standard deviation of the stock prices
    double standard_deviation = calculate_standard_deviation(num_stocks, mean_price);

    // Print the stock data
    print_stock_data(num_stocks);

    // Print the summary statistics
    print_summary_statistics(num_stocks, mean_price, standard_deviation);

    return 0;
}