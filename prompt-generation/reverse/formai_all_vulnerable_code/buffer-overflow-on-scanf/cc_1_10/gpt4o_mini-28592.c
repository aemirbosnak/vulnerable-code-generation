//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 10
#define SYMBOL_LENGTH 10

typedef struct {
    char symbol[SYMBOL_LENGTH];
    float price;
} Stock;

void generate_random_stock_prices(Stock stocks[], int count) {
    srand(time(NULL)); // Seed for randomness
    for (int i = 0; i < count; i++) {
        stocks[i].price = (rand() % 10000) / 100.0; // Random price between 0.00 and 99.99
    }
}

void display_stocks(Stock stocks[], int count) {
    printf("\nHere are the current stock prices:\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Stock Symbol: %s | Current Price: $%.2f\n", stocks[i].symbol, stocks[i].price);
    }
    printf("--------------------------------------\n");
}

int main() {
    Stock stocks[MAX_STOCKS];
    int stock_count = 0;

    printf("💸 Welcome to the Cheerful Stock Market Tracker! 📈\n");
    printf("--------------------------------------------------\n");
    printf("Please enter the stock symbols (up to %d). Type 'exit' to finish:\n", MAX_STOCKS);

    while (stock_count < MAX_STOCKS) {
        char symbol[SYMBOL_LENGTH];
        printf("Enter stock symbol #%d: ", stock_count + 1);
        scanf("%s", symbol);
        
        if (strcmp(symbol, "exit") == 0) {
            break; // Exit the input loop
        }

        strncpy(stocks[stock_count].symbol, symbol, SYMBOL_LENGTH);
        stock_count++;
    }

    printf("\nGenerating stock prices for %d stocks...\n", stock_count);
    generate_random_stock_prices(stocks, stock_count);
    display_stocks(stocks, stock_count);
    
    char choice;
    do {
        printf("Would you like to refresh the stock prices? (y/n): ");
        scanf(" %c", &choice); // Space before %c to consume any stray newline

        if (choice == 'y' || choice == 'Y') {
            printf("Refreshing stock prices...\n");
            generate_random_stock_prices(stocks, stock_count);
            display_stocks(stocks, stock_count);
        }
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Cheerful Stock Market Tracker! Have a great day! 🌟\n");
    return 0;
}