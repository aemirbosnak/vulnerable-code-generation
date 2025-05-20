//Code Llama-13B DATASET v1.0 Category: Stock market tracker ; Style: puzzling
// Stock market tracker program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LEN 50

// Structure to store stock information
typedef struct {
    char name[MAX_NAME_LEN];
    float price;
    float change;
} Stock;

// Function to get stock information from user
void get_stock_info(Stock* stock) {
    printf("Enter stock name: ");
    scanf("%s", stock->name);
    printf("Enter stock price: ");
    scanf("%f", &stock->price);
    printf("Enter stock change: ");
    scanf("%f", &stock->change);
}

// Function to print stock information
void print_stock_info(Stock* stock) {
    printf("Stock: %s\n", stock->name);
    printf("Price: %.2f\n", stock->price);
    printf("Change: %.2f\n", stock->change);
}

// Function to sort stocks by name
void sort_stocks(Stock* stocks, int num_stocks) {
    int i, j;
    Stock temp;
    for (i = 0; i < num_stocks - 1; i++) {
        for (j = i + 1; j < num_stocks; j++) {
            if (strcmp(stocks[i].name, stocks[j].name) > 0) {
                temp = stocks[i];
                stocks[i] = stocks[j];
                stocks[j] = temp;
            }
        }
    }
}

// Function to calculate total change
float calc_total_change(Stock* stocks, int num_stocks) {
    int i;
    float total = 0.0;
    for (i = 0; i < num_stocks; i++) {
        total += stocks[i].change;
    }
    return total;
}

int main() {
    int i, num_stocks;
    Stock stocks[MAX_STOCKS];

    // Get number of stocks
    printf("Enter number of stocks: ");
    scanf("%d", &num_stocks);

    // Get stock information
    for (i = 0; i < num_stocks; i++) {
        get_stock_info(&stocks[i]);
    }

    // Sort stocks by name
    sort_stocks(stocks, num_stocks);

    // Print stock information
    for (i = 0; i < num_stocks; i++) {
        print_stock_info(&stocks[i]);
    }

    // Calculate total change
    float total_change = calc_total_change(stocks, num_stocks);
    printf("Total change: %.2f\n", total_change);

    return 0;
}