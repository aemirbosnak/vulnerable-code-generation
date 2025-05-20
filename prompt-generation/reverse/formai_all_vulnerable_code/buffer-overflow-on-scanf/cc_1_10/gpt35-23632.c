//FormAI DATASET v1.0 Category: Stock market tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STOCKS 1000
#define MAX_NAME_LENGTH 20

double rand_range(double min, double max)
{
    double range = max - min;
    double num = (double) rand() / RAND_MAX;
    return min + (num * range);
}

typedef struct
{
    char name[MAX_NAME_LENGTH];
    double price;
} stock;

void print_stock_info(stock s)
{
    printf("%s: $%.2f\n", s.name, s.price);
}

void update_prices(stock *stocks, int num_stocks)
{
    for(int i=0; i<num_stocks; i++)
    {
        stocks[i].price = rand_range(1.00, 500.00);
    }
}

int main()
{
    srand(time(NULL));
    stock stocks[MAX_STOCKS];
    int num_stocks = 0;

    printf("Welcome to the stock market tracker!\n\n");

    while(1)
    {
        printf("What would you like to do?\n");
        printf("(a) Add a stock\n");
        printf("(b) Print the current prices\n");
        printf("(c) Quit\n");

        char option;
        scanf(" %c", &option);

        if(option == 'a')
        {
            if(num_stocks >= MAX_STOCKS)
            {
                printf("Sorry, we can't add any more stocks.\n");
                continue;
            }

            printf("Enter the name of the stock: ");
            scanf("%s", stocks[num_stocks].name);
            stocks[num_stocks].price = rand_range(1.00, 500.00);

            printf("Added:\n");
            print_stock_info(stocks[num_stocks]);

            num_stocks++;
        }
        else if(option == 'b')
        {
            if(num_stocks == 0)
            {
                printf("Sorry, there are no stocks to print.\n");
                continue;
            }

            printf("Current stock prices:\n");

            for(int i=0; i<num_stocks; i++)
            {
                print_stock_info(stocks[i]);
            }
        }
        else if(option == 'c')
        {
            printf("Thanks for using the stock market tracker!\n");
            break;
        }
        else
        {
            printf("Sorry, that's not a valid option.\n");
        }

        printf("\n");

        // update stock prices every loop
        update_prices(stocks, num_stocks);
    }

    return 0;
}