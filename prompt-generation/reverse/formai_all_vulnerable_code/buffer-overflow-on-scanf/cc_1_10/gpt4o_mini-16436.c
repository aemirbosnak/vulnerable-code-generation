//GPT-4o-mini DATASET v1.0 Category: Stock market tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100

typedef struct {
    char symbol[10];
    double price;
    double change;
} Stock;

void display_menu() {
    printf("\nStock Market Tracker Menu:\n");
    printf("1. Add Stock\n");
    printf("2. Update Stock Price\n");
    printf("3. Display All Stocks\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

void add_stock(Stock stocks[], int *count) {
    if (*count >= MAX_STOCKS) {
        printf("Maximum number of stocks reached.\n");
        return;
    }
    
    Stock new_stock;
    printf("Enter stock symbol: ");
    scanf("%s", new_stock.symbol);
    printf("Enter stock price: ");
    scanf("%lf", &new_stock.price);
    
    new_stock.change = 0.0; // Initial change is 0
    stocks[(*count)++] = new_stock;
    printf("Stock added successfully!\n");
}

void update_stock_price(Stock stocks[], int count) {
    char symbol[10];
    double new_price;
    
    printf("Enter stock symbol to update: ");
    scanf("%s", symbol);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(stocks[i].symbol, symbol) == 0) {
            printf("Current price of %s: %.2f\n", stocks[i].symbol, stocks[i].price);
            printf("Enter new price: ");
            scanf("%lf", &new_price);
            
            stocks[i].change = new_price - stocks[i].price;
            stocks[i].price = new_price;
            printf("Stock price updated successfully!\n");
            return;
        }
    }
    printf("Stock with symbol '%s' not found.\n", symbol);
}

void display_stocks(Stock stocks[], int count) {
    if (count == 0) {
        printf("No stocks to display.\n");
        return;
    }
    
    printf("\nCurrent Stocks:\n");
    printf("%-10s %-10s %-10s\n", "Symbol", "Price", "Change");
    for (int i = 0; i < count; i++) {
        printf("%-10s %-10.2f %-10.2f\n", stocks[i].symbol, stocks[i].price, stocks[i].change);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int count = 0;
    int option;
    
    while (1) {
        display_menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_stock(stocks, &count);
                break;
            case 2:
                update_stock_price(stocks, count);
                break;
            case 3:
                display_stocks(stocks, count);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}