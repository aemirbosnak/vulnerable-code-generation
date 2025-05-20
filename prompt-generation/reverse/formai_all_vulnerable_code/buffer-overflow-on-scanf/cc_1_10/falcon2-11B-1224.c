//Falcon2-11B DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main() {

    printf("Welcome to the Stock Market Tracker!\n\n");

    char name[100];
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Welcome, %s!\n", name);

    int num_trades;
    printf("How many trades would you like to track? ");
    scanf("%d", &num_trades);

    double *prices = (double*) malloc(num_trades * sizeof(double));
    double *quantities = (double*) malloc(num_trades * sizeof(double));
    double *profits = (double*) malloc(num_trades * sizeof(double));

    for (int i = 0; i < num_trades; i++) {
        printf("Enter price for trade %d: ", i+1);
        scanf("%lf", &prices[i]);
        printf("Enter quantity for trade %d: ", i+1);
        scanf("%lf", &quantities[i]);
        printf("Enter profit for trade %d: ", i+1);
        scanf("%lf", &profits[i]);
    }

    double total_cost = 0.0;
    double total_profit = 0.0;
    double total_quantity = 0.0;
    double avg_price = 0.0;

    for (int i = 0; i < num_trades; i++) {
        total_cost += prices[i] * quantities[i];
        total_profit += profits[i];
        total_quantity += quantities[i];
        avg_price = total_cost / total_quantity;
    }

    printf("Total Cost: %.2f\n", total_cost);
    printf("Total Profit: %.2f\n", total_profit);
    printf("Average Price: %.2f\n", avg_price);

    free(prices);
    free(quantities);
    free(profits);

    return 0;
}