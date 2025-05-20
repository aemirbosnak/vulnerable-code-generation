//FormAI DATASET v1.0 Category: Stock market tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 10
#define SYMBOL_LENGTH 5

struct Stock {
    char symbol[SYMBOL_LENGTH];
    float price;
    int volume;
    time_t last_updated;
};

struct StockPortfolio {
    struct Stock stocks[MAX_STOCKS];
    int num_stocks;
};

void update_stock_price(struct Stock *stock) {
    float new_price = (float)rand()/(float)(RAND_MAX/100);
    stock->price = new_price;
    stock->last_updated = time(NULL);
}

void display_stock(struct Stock stock) {
    printf("%s: $%.2f (%d shares, last updated: %s)", stock.symbol, stock.price, stock.volume, ctime(&stock.last_updated));
}

void display_portfolio(struct StockPortfolio portfolio) {
    printf("Portfolio:\n");
    for (int i=0; i<portfolio.num_stocks; i++) {
        display_stock(portfolio.stocks[i]);
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator
    
    struct StockPortfolio portfolio;
    portfolio.num_stocks = 0;
    
    // add some initial stocks to the portfolio
    struct Stock stock1 = {"AAPL", 123.45, 100, time(NULL)};
    struct Stock stock2 = {"GOOG", 567.89, 50, time(NULL)};
    portfolio.stocks[0] = stock1;
    portfolio.stocks[1] = stock2;
    portfolio.num_stocks = 2;
    
    // update the stock prices and display the portfolio
    for (int i=0; i<portfolio.num_stocks; i++) {
        update_stock_price(&portfolio.stocks[i]);
    }
    display_portfolio(portfolio);
    
    // let the user add a new stock to the portfolio
    char new_symbol[SYMBOL_LENGTH];
    printf("Enter a new stock symbol: ");
    scanf("%s", new_symbol);
    struct Stock new_stock = {new_symbol, 0.0, 0, time(NULL)};
    portfolio.stocks[portfolio.num_stocks] = new_stock;
    portfolio.num_stocks++;

    // update the stock prices and display the portfolio
    for (int i=0; i<portfolio.num_stocks; i++) {
        update_stock_price(&portfolio.stocks[i]);
    }
    display_portfolio(portfolio);
    
    return 0;
}