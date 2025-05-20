//FormAI DATASET v1.0 Category: Stock market tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stock
{
    char name[20];
    float price;
};

int main()
{
    struct Stock stock_list[10]; // array of 10 Stock structures
    int num_stocks = 0, choice, i, j;
    float total_price = 0;
    char stock_name[20];

    while (1)
    {
        printf("\n\nStock Market Tracker\n");
        printf("1. Add Stock\n");
        printf("2. Remove Stock\n");
        printf("3. View All Stocks\n");
        printf("4. Total Portfolio Value\n");
        printf("5. Exit Program\n");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (num_stocks == 10)
            {
                printf("\nCannot add more stocks, list is full\n");
                break;
            }
            printf("\nEnter the name of the stock: ");
            scanf("%s", stock_name);

            // check if the stock already exists in the list
            for (i = 0; i < num_stocks; i++)
            {
                if (strcmp(stock_name, stock_list[i].name) == 0)
                {
                    printf("\n%s is already in the list\n", stock_name);
                    break;
                }
            }

            // add the new stock to the list
            if (i == num_stocks)
            {
                printf("\nEnter the price of the stock: ");
                scanf("%f", &stock_list[num_stocks].price);
                strcpy(stock_list[num_stocks].name, stock_name);
                printf("\n%s has been added to the list\n", stock_name);
                num_stocks++;
            }
            break;

        case 2:
            printf("\nEnter the name of the stock to remove: ");
            scanf("%s", stock_name);

            // find the index of the stock to remove
            for (i = 0; i < num_stocks; i++)
            {
                if (strcmp(stock_name, stock_list[i].name) == 0)
                {
                    printf("\n%s has been removed from the list\n", stock_name);

                    // shift all the elements after i back by one position
                    for (j = i; j < num_stocks - 1; j++)
                    {
                        stock_list[j] = stock_list[j + 1];
                    }

                    num_stocks--;
                    break;
                }
            }

            // stock not found
            if (i == num_stocks)
            {
                printf("\n%s is not in the list\n", stock_name);
            }
            break;

        case 3:
            if (num_stocks == 0)
            {
                printf("\nList is empty. No stocks to display.\n");
                break;
            }

            printf("\nAll Stocks\n");
            printf("%-20s%-20s\n", "Stock Name", "Price");

            for (i = 0; i < num_stocks; i++)
            {
                printf("%-20s%-20.2f\n", stock_list[i].name, stock_list[i].price);
            }
            break;

        case 4:
            if (num_stocks == 0)
            {
                printf("\nList is empty. Portfolio Value is 0.\n");
                break;
            }

            total_price = 0;

            for (i = 0; i < num_stocks; i++)
            {
                total_price += stock_list[i].price;
            }

            printf("\nPortfolio Value: %.2f\n", total_price);
            break;

        case 5:
            printf("\nExiting Program...\n");
            exit(0);

        default:
            printf("\nInvalid Choice. Please try again...\n");
        }
    }
    return 0;
}