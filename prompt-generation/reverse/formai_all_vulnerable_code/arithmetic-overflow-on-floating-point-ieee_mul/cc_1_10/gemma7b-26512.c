//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STOCK_NUM 10

typedef struct Stock {
    char name[20];
    double current_price;
    double previous_price;
    double change_percentage;
} Stock;

void calculate_change_percentage(Stock *stock) {
    double change = stock->current_price - stock->previous_price;
    stock->change_percentage = (change / stock->previous_price) * 100;
}

int main() {
    Stock stocks[MAX_STOCK_NUM];

    // Initialize stocks
    for (int i = 0; i < MAX_STOCK_NUM; i++) {
        stocks[i].name[0] = '\0';
        stocks[i].current_price = 0.0;
        stocks[i].previous_price = 0.0;
        stocks[i].change_percentage = 0.0;
    }

    // Get stock data
    printf("Enter the name of the stock: ");
    scanf("%s", stocks[0].name);

    printf("Enter the current price of the stock: ");
    scanf("%lf", &stocks[0].current_price);

    printf("Enter the previous price of the stock: ");
    scanf("%lf", &stocks[0].previous_price);

    // Calculate change percentage
    calculate_change_percentage(&stocks[0]);

    // Display results
    printf("The name of the stock is: %s\n", stocks[0].name);
    printf("The current price of the stock is: %.2lf\n", stocks[0].current_price);
    printf("The previous price of the stock is: %.2lf\n", stocks[0].previous_price);
    printf("The change percentage of the stock is: %.2lf%%\n", stocks[0].change_percentage);

    return 0;
}