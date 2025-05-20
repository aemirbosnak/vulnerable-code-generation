//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCK_NUM 10
#define MAX_STOCK_NAME_LEN 20

typedef struct Stock {
    char name[MAX_STOCK_NAME_LEN];
    double price;
    double change;
    double prev_price;
} Stock;

int main() {
    Stock stocks[MAX_STOCK_NUM];
    int i, j, k;
    char input[MAX_STOCK_NAME_LEN];
    double target_price;
    time_t t;

    // Initialize the stock list
    for (i = 0; i < MAX_STOCK_NUM; i++) {
        stocks[i].name[0] = '\0';
        stocks[i].price = 0.0;
        stocks[i].change = 0.0;
        stocks[i].prev_price = 0.0;
    }

    // Get the current time
    t = time(NULL);

    // Loop to get the stock name
    printf("Enter the name of the stock you want to track: ");
    scanf("%s", input);

    // Search for the stock in the list
    for (i = 0; i < MAX_STOCK_NUM; i++) {
        if (strcmp(stocks[i].name, input) == 0) {
            break;
        }
    }

    // If the stock is found, get its current price
    if (i < MAX_STOCK_NUM) {
        printf("The current price of %s is $%.2f.", stocks[i].name, stocks[i].price);
    } else {
        printf("Error: Stock not found.");
    }

    // Get the target price
    printf("\nEnter the target price for the stock: $");
    scanf("%lf", &target_price);

    // Calculate the change in price
    stocks[i].change = (target_price - stocks[i].prev_price) / stocks[i].prev_price * 100.0;

    // Print the change in price
    printf("\nThe change in price for %s is %d%.2f%.", stocks[i].name, (int)stocks[i].change, stocks[i].change);

    // Record the previous price
    stocks[i].prev_price = stocks[i].price;

    // Print the time
    printf("\nThe current time is: %s",ctime(&t));

    return 0;
}