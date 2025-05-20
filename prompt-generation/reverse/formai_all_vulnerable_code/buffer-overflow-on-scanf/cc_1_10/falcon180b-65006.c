//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50

// Define the structure for a stock
typedef struct {
    char name[MAX_NAME_LENGTH];
    double current_price;
    double previous_price;
    double change;
    int change_percentage;
} stock_t;

void main() {
    int num_stocks;
    printf("Enter the number of stocks you want to track: ");
    scanf("%d", &num_stocks);

    // Initialize the array of stocks
    stock_t stocks[num_stocks];

    // Get the names of the stocks from the user
    for (int i = 0; i < num_stocks; i++) {
        printf("Enter the name of stock %d: ", i + 1);
        scanf("%s", stocks[i].name);
        stocks[i].current_price = 0;
        stocks[i].previous_price = 0;
        stocks[i].change = 0;
        stocks[i].change_percentage = 0;
    }

    // Main loop for tracking the stocks
    while (1) {
        printf("\nCurrent prices:\n");
        for (int i = 0; i < num_stocks; i++) {
            printf("%s: $%.2f\n", stocks[i].name, stocks[i].current_price);
        }

        // Get the updated prices from the user
        printf("\nEnter the updated prices:\n");
        for (int i = 0; i < num_stocks; i++) {
            scanf("%lf", &stocks[i].current_price);

            // Calculate the change and percentage change
            if (stocks[i].previous_price > 0) {
                stocks[i].change = stocks[i].current_price - stocks[i].previous_price;
                stocks[i].change_percentage = (stocks[i].change / stocks[i].previous_price) * 100;
            } else {
                stocks[i].change = 0;
                stocks[i].change_percentage = 0;
            }

            stocks[i].previous_price = stocks[i].current_price;
        }

        // Print the changes and percentage changes
        printf("\nChanges:\n");
        for (int i = 0; i < num_stocks; i++) {
            printf("%s: $%.2f (%d%%)\n", stocks[i].name, stocks[i].change, stocks[i].change_percentage);
        }

        printf("\nPress enter to continue...\n");
        getchar();
    }
}