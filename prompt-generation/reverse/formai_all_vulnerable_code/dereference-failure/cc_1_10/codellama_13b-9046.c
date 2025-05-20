//Code Llama-13B DATASET v1.0 Category: Stock market tracker ; Style: Dennis Ritchie
// Stock Market Tracker
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define struct for stock data
struct Stock {
    char name[30];
    float price;
    float change;
};

// Define struct for portfolio
struct Portfolio {
    struct Stock* stocks;
    int num_stocks;
};

// Define struct for stock market data
struct StockMarket {
    struct Portfolio* portfolios;
    int num_portfolios;
};

// Function to add stock to portfolio
void add_stock(struct Portfolio* portfolio, char* name, float price) {
    // Check if portfolio is full
    if (portfolio->num_stocks >= 10) {
        printf("Portfolio is full\n");
        return;
    }

    // Add stock to portfolio
    struct Stock* stock = &portfolio->stocks[portfolio->num_stocks];
    strcpy(stock->name, name);
    stock->price = price;
    stock->change = 0.0f;
    portfolio->num_stocks++;
}

// Function to update stock prices
void update_prices(struct StockMarket* market) {
    // Loop through each portfolio
    for (int i = 0; i < market->num_portfolios; i++) {
        struct Portfolio* portfolio = &market->portfolios[i];

        // Loop through each stock in portfolio
        for (int j = 0; j < portfolio->num_stocks; j++) {
            struct Stock* stock = &portfolio->stocks[j];

            // Update stock price
            stock->price += (float)rand() / RAND_MAX;
        }
    }
}

// Function to calculate stock changes
void calculate_changes(struct StockMarket* market) {
    // Loop through each portfolio
    for (int i = 0; i < market->num_portfolios; i++) {
        struct Portfolio* portfolio = &market->portfolios[i];

        // Loop through each stock in portfolio
        for (int j = 0; j < portfolio->num_stocks; j++) {
            struct Stock* stock = &portfolio->stocks[j];

            // Calculate stock change
            stock->change = (stock->price - stock->price) / stock->price;
        }
    }
}

// Function to print stock market data
void print_market(struct StockMarket* market) {
    // Loop through each portfolio
    for (int i = 0; i < market->num_portfolios; i++) {
        struct Portfolio* portfolio = &market->portfolios[i];

        // Loop through each stock in portfolio
        for (int j = 0; j < portfolio->num_stocks; j++) {
            struct Stock* stock = &portfolio->stocks[j];

            // Print stock data
            printf("Stock: %s\n", stock->name);
            printf("Price: %f\n", stock->price);
            printf("Change: %f%%\n", stock->change * 100);
        }
    }
}

int main() {
    // Initialize stock market data
    struct StockMarket market;
    market.num_portfolios = 5;
    market.portfolios = malloc(market.num_portfolios * sizeof(struct Portfolio));
    for (int i = 0; i < market.num_portfolios; i++) {
        struct Portfolio* portfolio = &market.portfolios[i];
        portfolio->num_stocks = 0;
        portfolio->stocks = malloc(10 * sizeof(struct Stock));
    }

    // Add stocks to portfolios
    add_stock(&market.portfolios[0], "Apple", 100.0f);
    add_stock(&market.portfolios[1], "Google", 500.0f);
    add_stock(&market.portfolios[2], "Microsoft", 200.0f);
    add_stock(&market.portfolios[3], "Amazon", 300.0f);
    add_stock(&market.portfolios[4], "Facebook", 50.0f);

    // Update stock prices
    update_prices(&market);

    // Calculate stock changes
    calculate_changes(&market);

    // Print stock market data
    print_market(&market);

    // Clean up memory
    for (int i = 0; i < market.num_portfolios; i++) {
        struct Portfolio* portfolio = &market.portfolios[i];
        free(portfolio->stocks);
    }
    free(market.portfolios);

    return 0;
}