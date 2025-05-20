//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100

typedef struct {
    char symbol[10];
    float price;
    float change;
} Stock;

typedef struct {
    Stock stocks[MAX_STOCKS];
    int count;
} StockMarket;

void add_stock(StockMarket *market, const char *symbol, float price);
void update_stock_price(StockMarket *market, const char *symbol, float new_price);
void print_stock_prices(const StockMarket *market);
void sort_stocks_by_price(StockMarket *market);
void simulate_market_changes(StockMarket *market);
void display_menu();
void process_choice(StockMarket *market, int choice);

int main() {
    StockMarket market = { .count = 0 };
    int choice;

    printf("Welcome to the Stock Market Tracker!\n");

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting... Goodbye!\n");
            break;
        }

        process_choice(&market, choice);
    }
    return 0;
}

void display_menu() {
    printf("\nMenu:\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. View Stock Prices\n");
    printf("4. Simulate Market Changes\n");
    printf("0. Exit\n");
}

void process_choice(StockMarket *market, int choice) {
    char symbol[10];
    float price, new_price;

    switch (choice) {
        case 1:
            printf("Enter stock symbol: ");
            scanf("%s", symbol);
            printf("Enter stock price: ");
            scanf("%f", &price);
            add_stock(market, symbol, price);
            break;

        case 2:
            printf("Enter stock symbol to update: ");
            scanf("%s", symbol);
            printf("Enter new stock price: ");
            scanf("%f", &new_price);
            update_stock_price(market, symbol, new_price);
            break;

        case 3:
            print_stock_prices(market);
            break;

        case 4:
            simulate_market_changes(market);
            break;

        default:
            printf("Invalid choice! Please try again.\n");
    }
}

void add_stock(StockMarket *market, const char *symbol, float price) {
    if (market->count >= MAX_STOCKS) {
        printf("Stock market is full! Cannot add more stocks.\n");
        return;
    }

    strcpy(market->stocks[market->count].symbol, symbol);
    market->stocks[market->count].price = price;
    market->stocks[market->count].change = 0.0;
    market->count++;
    printf("Stock %s added with price $%.2f.\n", symbol, price);
}

void update_stock_price(StockMarket *market, const char *symbol, float new_price) {
    for (int i = 0; i < market->count; i++) {
        if (strcmp(market->stocks[i].symbol, symbol) == 0) {
            market->stocks[i].change = new_price - market->stocks[i].price;
            market->stocks[i].price = new_price;
            printf("Stock %s updated to $%.2f.\n", symbol, new_price);
            return;
        }
    }
    printf("Stock %s not found!\n", symbol);
}

void print_stock_prices(const StockMarket *market) {
    if (market->count == 0) {
        printf("No stocks available in the market.\n");
        return;
    }

    sort_stocks_by_price((StockMarket *)market);
    printf("\nStock Prices:\n");
    for (int i = 0; i < market->count; i++) {
        printf("Symbol: %s, Price: $%.2f, Change: $%.2f\n",
                market->stocks[i].symbol,
                market->stocks[i].price,
                market->stocks[i].change);
    }
}

void sort_stocks_by_price(StockMarket *market) {
    for (int i = 0; i < market->count - 1; i++) {
        for (int j = i + 1; j < market->count; j++) {
            if (market->stocks[i].price > market->stocks[j].price) {
                Stock temp = market->stocks[i];
                market->stocks[i] = market->stocks[j];
                market->stocks[j] = temp;
            }
        }
    }
}

void simulate_market_changes(StockMarket *market) {
    srand(time(NULL));
    for (int i = 0; i < market->count; i++) {
        float change = ((rand() % 2000 - 1000) / 100.0);  // Random change between -10 and 10
        update_stock_price(market, market->stocks[i].symbol, market->stocks[i].price + change);
    }
    printf("Market changes simulated.\n");
}