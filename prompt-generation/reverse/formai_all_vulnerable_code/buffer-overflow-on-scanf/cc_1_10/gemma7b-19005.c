//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    // Declare variables
    double stockPrice = 100.0;
    double currentPrice = 0.0;
    double change = 0.0;
    int i = 0;
    char symbol[20];

    // Get the stock symbol from the user
    printf("Enter the symbol of the stock you want to track: ");
    scanf("%s", symbol);

    // Loop to get the current price of the stock
    while (currentPrice == 0.0)
    {
        printf("Enter the current price of the stock: ");
        scanf("%lf", &currentPrice);

        if (currentPrice == 0.0)
        {
            printf("Invalid input. Please try again.\n");
        }
    }

    // Calculate the change in the stock price
    change = (currentPrice - stockPrice) / stockPrice * 100.0;

    // Print the stock price and change
    printf("\nStock symbol: %s\n", symbol);
    printf("Current price: $%.2lf\n", currentPrice);
    printf("Change: %.2lf%%", change);

    // Calculate the moving average
    double movingAverage = 0.0;
    for (i = 0; i < 5; i++)
    {
        movingAverage += currentPrice / 5.0;
    }

    // Print the moving average
    printf("\nMoving average: $%.2lf", movingAverage);

    return 0;
}