//FormAI DATASET v1.0 Category: Stock market tracker ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STOCKS 50

// Structure to hold details of a stock
struct stock {
    char name[20];
    float price;
    float previous_day_price;
    float percentage_change;
};

// Function to populate stock details
void get_stock_details(struct stock *s) {
    printf("Enter the name of the stock: ");
    scanf("%s", s->name);
    printf("Enter the stock price: ");
    scanf("%f", &s->price);
    printf("Enter the previous day's stock price: ");
    scanf("%f", &s->previous_day_price);
    s->percentage_change = ((s->price - s->previous_day_price) / s->previous_day_price) * 100;
}

// Function to display stock details
void display_stock_details(struct stock s) {
    printf("\n");
    printf("Stock Name: %s\n", s.name);
    printf("Current Price: %.2f\n", s.price);
    printf("Previous Day's Price: %.2f\n", s.previous_day_price);
    printf("Percentage Change: %.2f%%\n", s.percentage_change);
}

int main() {
    struct stock stocks[MAX_STOCKS];
    int num_of_stocks;

    printf("Welcome to the Stock Market Tracker!\n");
    printf("Enter the number of stocks you want to track (max %d): ", MAX_STOCKS);
    scanf("%d", &num_of_stocks);

    // Populate stock details
    for(int i=0; i<num_of_stocks; i++) {
        printf("\n----- Stock %d -----\n", i+1);
        get_stock_details(&stocks[i]);
    }

    // Display stock details
    printf("\nStock Details:\n");
    for(int i=0; i<num_of_stocks; i++) {
        printf("\n----- Stock %d -----\n", i+1);
        display_stock_details(stocks[i]);
    }

    return 0;
}