//FormAI DATASET v1.0 Category: Stock market tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STOCKS 100
#define MAX_NAME_LENGTH 20

// Structure to hold information for each stock
typedef struct Stock
{
    char name[MAX_NAME_LENGTH];
    double price;
} Stock;

// Function to print the menu options
void printMenu()
{
    printf("Stock Market Tracker\n\n");
    printf("1. Add a new stock\n");
    printf("2. Remove a stock\n");
    printf("3. Update stock prices\n");
    printf("4. View all stocks\n");
    printf("5. View stock details\n");
    printf("6. Exit\n\n");
    printf("Enter your choice: ");
}

// Function to add a new stock
void addStock(Stock stocks[], int *numStocks)
{
    char name[MAX_NAME_LENGTH];
    double price;

    if (*numStocks < MAX_STOCKS)
    {
        printf("\nEnter stock name (max %d characters): ", MAX_NAME_LENGTH - 1);
        scanf("%s", name);

        printf("Enter stock price: $");
        scanf("%lf", &price);

        strcpy(stocks[*numStocks].name, name);
        stocks[*numStocks].price = price;

        printf("\nStock added successfully.\n");

        (*numStocks)++;
    }
    else
    {
        printf("\nError: Maximum number of stocks already reached.\n");
    }
}

// Function to remove a stock
void removeStock(Stock stocks[], int *numStocks)
{
    char name[MAX_NAME_LENGTH];
    int i, j, stockRemoved = 0;

    printf("\nEnter the name of the stock to remove: ");
    scanf("%s", name);

    for (i = 0; i < *numStocks; i++)
    {
        if (strcmp(stocks[i].name, name) == 0)
        {
            // Shift all stocks after the removed one back one position
            for (j = i + 1; j < *numStocks; j++)
            {
                strcpy(stocks[j - 1].name, stocks[j].name);
                stocks[j - 1].price = stocks[j].price;
            }

            // Decrement the number of stocks
            (*numStocks)--;
            stockRemoved = 1;

            printf("\nStock removed successfully.\n");

            break;
        }
    }

    if (!stockRemoved)
    {
        printf("\nError: Stock not found.\n");
    }
}

// Function to update stock prices
void updatePrices(Stock stocks[], int numStocks)
{
    int i;
    double newPrice;

    printf("\n");

    for (i = 0; i < numStocks; i++)
    {
        printf("%d. %s ($%.2lf)\n", i + 1, stocks[i].name, stocks[i].price);
    }

    printf("\nEnter the number of the stock to update: ");
    scanf("%d", &i);

    if (i >= 1 && i <= numStocks)
    {
        printf("Enter the new stock price: $");
        scanf("%lf", &newPrice);

        stocks[i - 1].price = newPrice;

        printf("\nStock price updated successfully.\n");
    }
    else
    {
        printf("\nError: Invalid stock number.\n");
    }
}

// Function to view all stocks
void viewAllStocks(Stock stocks[], int numStocks)
{
    int i;

    printf("\n");

    for (i = 0; i < numStocks; i++)
    {
        printf("%d. %s ($%.2lf)\n", i + 1, stocks[i].name, stocks[i].price);
    }
}

// Function to view stock details
void viewStockDetails(Stock stocks[], int numStocks)
{
    char name[MAX_NAME_LENGTH];
    int i;

    printf("\nEnter the name of the stock to view: ");
    scanf("%s", name);

    for (i = 0; i < numStocks; i++)
    {
        if (strcmp(stocks[i].name, name) == 0)
        {
            printf("\n%s\nCurrent price: $%.2lf\n", stocks[i].name, stocks[i].price);

            // Generate a random movement in the stock price (up to 5%)
            srand(time(NULL));
            double movement = ((double)rand() / RAND_MAX) * 0.05;

            if (rand() % 2 == 0)
            {
                stocks[i].price += stocks[i].price * movement;
                printf("Price change: +%.2lf%%\n", movement * 100);
            }
            else
            {
                stocks[i].price -= stocks[i].price * movement;
                printf("Price change: -%.2lf%%\n", movement * 100);
            }

            printf("New price: $%.2lf\n", stocks[i].price);

            break;
        }
    }

    if (i == numStocks)
    {
        printf("\nError: Stock not found.\n");
    }
}

int main()
{
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;
    int choice = 0;

    while (choice != 6)
    {
        printMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStock(stocks, &numStocks);
                break;
            case 2:
                removeStock(stocks, &numStocks);
                break;
            case 3:
                updatePrices(stocks, numStocks);
                break;
            case 4:
                viewAllStocks(stocks, numStocks);
                break;
            case 5:
                viewStockDetails(stocks, numStocks);
                break;
            case 6:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nError: Invalid choice.\n");
                break;
        }
    }

    return 0;
}