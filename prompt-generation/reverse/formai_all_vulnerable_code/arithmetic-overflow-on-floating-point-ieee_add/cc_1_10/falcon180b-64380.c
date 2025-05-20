//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_DAYS 365

// Define the structure for a stock
typedef struct {
    char name[20];
    double price[MAX_DAYS];
    int num_days;
} Stock;

// Function to initialize a stock with a name and price
void init_stock(Stock* s, char* name, double price) {
    strcpy(s->name, name);
    s->price[0] = price;
    s->num_days = 1;
}

// Function to add a price to a stock
void add_price(Stock* s, double price) {
    s->price[(s->num_days) % MAX_DAYS] = price;
    s->num_days++;
}

// Function to calculate the average price of a stock
double calc_average(Stock* s) {
    double sum = 0;
    int count = 0;
    for (int i = 0; i < MAX_DAYS; i++) {
        if (s->price[i]!= 0) {
            sum += s->price[i];
            count++;
        }
    }
    return sum / count;
}

// Function to display a stock
void display_stock(Stock* s) {
    printf("Name: %s\n", s->name);
    printf("Average price: $%.2f\n", calc_average(s));
}

// Function to display all stocks
void display_stocks(Stock* stocks, int num_stocks) {
    for (int i = 0; i < num_stocks; i++) {
        display_stock(&stocks[i]);
    }
}

int main() {
    Stock stocks[MAX_STOCKS];
    int num_stocks = 0;
    char input[100];

    // Initialize stocks
    init_stock(&stocks[0], "AAPL", 100);
    init_stock(&stocks[1], "GOOG", 200);
    init_stock(&stocks[2], "MSFT", 300);
    num_stocks = 3;

    // Add prices
    add_price(&stocks[0], 101);
    add_price(&stocks[0], 102);
    add_price(&stocks[0], 103);
    add_price(&stocks[1], 201);
    add_price(&stocks[1], 202);
    add_price(&stocks[1], 203);
    add_price(&stocks[2], 301);
    add_price(&stocks[2], 302);
    add_price(&stocks[2], 303);

    // Display all stocks
    display_stocks(stocks, num_stocks);

    return 0;
}