//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10

typedef struct Stock {
    char name[20];
    double price;
    double change;
    double volat;
} Stock;

int main() {
    Stock stocks[N];
    int i;

    // Initialize stocks
    for (i = 0; i < N; i++) {
        stocks[i].name[0] = '\0';
        stocks[i].price = 0.0;
        stocks[i].change = 0.0;
        stocks[i].volat = 0.0;
    }

    // Get stock data
    for (i = 0; i < N; i++) {
        printf("Enter the name of the stock: ");
        scanf("%s", stocks[i].name);

        printf("Enter the current price of the stock: ");
        scanf("%lf", &stocks[i].price);

        printf("Enter the change in the stock price: ");
        scanf("%lf", &stocks[i].change);

        printf("Enter the volatility of the stock: ");
        scanf("%lf", &stocks[i].volat);
    }

    // Print stock data
    for (i = 0; i < N; i++) {
        printf("Stock name: %s\n", stocks[i].name);
        printf("Current price: %.2lf\n", stocks[i].price);
        printf("Change: %.2lf%\n", stocks[i].change);
        printf("Volatility: %.2lf%\n", stocks[i].volat);
        printf("\n");
    }

    return 0;
}