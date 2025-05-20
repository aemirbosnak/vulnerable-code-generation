//FormAI DATASET v1.0 Category: Stock market tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 50
#define PRICE_RANGE 1000

typedef struct 
{
    char name[MAX_NAME_LENGTH];
    double price;
    int volume;
} Stock;

int main()
{
    srand(time(NULL)); // set random seed based on current time

    Stock stocks[MAX_STOCKS];
    int n_stocks;
    double total_value = 0;

    // read in number of stocks to track
    printf("Enter the number of stocks you want to track: ");
    scanf("%d", &n_stocks);

    // read in information for each stock
    for (int i = 0; i < n_stocks; i++)
    {
        printf("Enter information for Stock #%d:\n", i + 1);
        
        // read in name
        printf("Name: ");
        scanf("%s", stocks[i].name);

        // randomly generate price between 0 and PRICE_RANGE
        stocks[i].price = (double)rand() / (double)RAND_MAX * PRICE_RANGE;

        // randomly generate volume between 0 and 10000
        stocks[i].volume = rand() % 10000;

        // print out information for stock
        printf("Price: $%.2lf\n", stocks[i].price);
        printf("Volume: %d\n", stocks[i].volume);

        // calculate total value of stock by multiplying price and volume
        double stock_value = stocks[i].price * stocks[i].volume;
        printf("Value: $%.2lf\n", stock_value);

        // add stock value to total value of all stocks
        total_value += stock_value;

        printf("\n");
    }

    // print out total value of all stocks
    printf("Total Value of Stocks: $%.2lf\n", total_value);

    return 0;
}