//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_Stocks 10

typedef struct Stock {
    char name[20];
    double currentPrice;
    double previousPrice;
    double change;
} Stock;

int main() {

    // Define an array of stocks
    Stock stocks[MAX_Stocks];

    // Initialize the stocks
    for (int i = 0; i < MAX_Stocks; i++) {
        stocks[i].name[0] = '\0';
        stocks[i].currentPrice = 0.0;
        stocks[i].previousPrice = 0.0;
        stocks[i].change = 0.0;
    }

    // Get the current time
    time_t now = time(NULL);

    // Loop over the stocks
    for (int i = 0; i < MAX_Stocks; i++) {

        // Get the stock's name
        printf("Enter the name of the stock: ");
        scanf("%s", stocks[i].name);

        // Get the stock's current price
        printf("Enter the current price of the stock: ");
        scanf("%lf", &stocks[i].currentPrice);

        // Calculate the stock's change
        stocks[i].change = (stocks[i].currentPrice - stocks[i].previousPrice) / stocks[i].previousPrice * 100;

        // Display the stock's information
        printf("Stock name: %s\n", stocks[i].name);
        printf("Current price: %.2lf\n", stocks[i].currentPrice);
        printf("Previous price: %.2lf\n", stocks[i].previousPrice);
        printf("Change: %.2lf%\n", stocks[i].change);

        // Update the previous price of the stock
        stocks[i].previousPrice = stocks[i].currentPrice;
    }

    // Display the current time
    printf("The current time is: %s",ctime(&now));

    return 0;
}