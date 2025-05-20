//FormAI DATASET v1.0 Category: Stock market tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // declare and initialize variables
    double stock_price = 0.00;
    double percent_change = 0.00;
    double previous_price = 0.00;
    char stock_name[50];
    int stock_id = 0;

    printf("\n--- C STOCK TRACKER ---\n\n");

    printf("Enter stock ID: ");
    scanf("%d", &stock_id);

    printf("Enter stock name: ");
    scanf("%s", &stock_name);

    printf("Enter current stock price: ");
    scanf("%lf", &stock_price);

    printf("Enter previous stock price: ");
    scanf("%lf", &previous_price);

    // perform calculations to determine percent change
    if (previous_price == 0)
    {
        percent_change = 0.00;
    }
    else
    {
        percent_change = ((stock_price - previous_price) / previous_price) * 100.00;
    }

    // output results to user
    printf("\nStock ID: %d\n", stock_id);
    printf("Stock Name: %s\n", stock_name);
    printf("Current Stock Price: $%.2lf\n", stock_price);
    printf("Previous Stock Price: $%.2lf\n", previous_price);

    if (percent_change > 0)
    {
        printf("Percent Change: +%.2lf%%\n", percent_change);
    }
    else if (percent_change < 0)
    {
        printf("Percent Change: %.2lf%%\n", percent_change);
    }
    else
    {
        printf("Percent Change: %.2lf%%\n", percent_change);
    }

    printf("\nThank you for using C Stock Tracker. Goodbye!\n\n");

    return 0;
}