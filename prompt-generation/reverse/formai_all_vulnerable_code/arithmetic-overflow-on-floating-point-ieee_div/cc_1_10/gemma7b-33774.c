//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
    char stock_name[20];
    int current_price, previous_price, change, percentage_change;
    FILE *fp;

    // Open a file to store stock data
    fp = fopen("stock_data.txt", "a");

    // Get the current time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // Format the time
    char timestamp[20];
    strftime(timestamp, 20, "%d/%m/%Y %H:%M:%S", tm);

    // Get the stock name from the user
    printf("Enter the name of the stock you want to track: ");
    scanf("%s", stock_name);

    // Get the current price of the stock
    printf("Enter the current price of the stock: ");
    scanf("%d", &current_price);

    // Calculate the change in the stock price
    previous_price = read_stock_price(stock_name);
    change = current_price - previous_price;

    // Calculate the percentage change in the stock price
    percentage_change = (change * 100.0) / previous_price;

    // Write the stock data to the file
    fprintf(fp, "%s, %d, %d, %f\n", timestamp, current_price, previous_price, percentage_change);

    // Close the file
    fclose(fp);

    // Print the stock data
    printf("Stock name: %s\n", stock_name);
    printf("Current price: %d\n", current_price);
    printf("Previous price: %d\n", previous_price);
    printf("Change: %d\n", change);
    printf("Percentage change: %.2f%%\n", percentage_change);

    return 0;
}

int read_stock_price(char *stock_name)
{
    FILE *fp;
    int price;

    // Open the stock data file
    fp = fopen("stock_data.txt", "r");

    // Search for the stock name in the file
    while (fscanf(fp, "%s, %d, %d, %f\n", stock_name, &price, NULL, NULL) != EOF)
    {
        if (strcmp(stock_name, stock_name) == 0)
        {
            break;
        }
    }

    // Close the file
    fclose(fp);

    // Return the stock price
    return price;
}