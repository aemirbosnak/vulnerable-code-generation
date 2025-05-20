//FormAI DATASET v1.0 Category: Stock market tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCKS 10

int main() {
    // Declare Variables
    int num_of_stocks = 0;
    char stock_names[MAX_STOCKS][20];
    float current_prices[MAX_STOCKS];
    float previous_prices[MAX_STOCKS];
    float price_changes[MAX_STOCKS];

    // Get user input for number of stocks
    printf("Enter number of stocks: ");
    scanf("%d", &num_of_stocks);

    // Get user input for stock information
    for (int i = 0; i < num_of_stocks; i++) {
        printf("\nEnter stock #%d name: ", i + 1);
        scanf("%s", stock_names[i]);

        printf("\nEnter current price of %s: ", stock_names[i]);
        scanf("%f", &current_prices[i]);

        printf("\nEnter previous price of %s: ", stock_names[i]);
        scanf("%f", &previous_prices[i]);

        // Calculate price change
        price_changes[i] = ((current_prices[i] - previous_prices[i]) / previous_prices[i]) * 100;
    }

    printf("\nStock Name\tCurrent Price\tPrev. Price\tChange\n");
    printf("-------------------------------------------------------------\n");

    // Print each stock's information
    for (int i = 0; i < num_of_stocks; i++) {
        printf("%-20s $%10.2f\t$%10.2f\t%10.2f%%\n", stock_names[i], current_prices[i], 
                                                  previous_prices[i], price_changes[i]);
    }

    // Find highest and lowest price changes
    int max_index = 0, min_index = 0;
    for (int i = 1; i < num_of_stocks; i++) {
        if (price_changes[i] > price_changes[max_index]) {
            max_index = i;
        }
        if (price_changes[i] < price_changes[min_index]) {
            min_index = i;
        }
    }

    printf("\n%s had the highest price change of %0.2f%%.\n", stock_names[max_index], price_changes[max_index]);
    printf("%s had the lowest price change of %0.2f%%.\n", stock_names[min_index], price_changes[min_index]);

    return 0;
}