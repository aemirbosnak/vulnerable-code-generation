//Gemma-7B DATASET v1.0 Category: Stock market tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    system("clear");
    printf("-------------------------------------------------------------------\n");
    printf("Welcome to the Wall Street Oracle, my friend!\n");
    printf("-------------------------------------------------------------------\n");

    char ticker[20];
    printf("Enter ticker symbol: ");
    scanf("%s", ticker);

    int stock_price = rand() % 1000;
    printf("Current stock price: $%d\n", stock_price);

    char direction;
    printf("Enter direction (up/down): ");
    scanf(" %c", &direction);

    int change = 0;
    switch (direction)
    {
        case 'u':
            change = rand() % 20;
            if (change > 0)
            {
                printf("Stock price has increased by $%d.\n", change);
                stock_price += change;
            }
            else
            {
                printf("Sorry, there has been no change in price.\n");
            }
            break;
        case 'd':
            change = rand() % 20;
            if (change > 0)
            {
                printf("Stock price has decreased by $%d.\n", change);
                stock_price -= change;
            }
            else
            {
                printf("Sorry, there has been no change in price.\n");
            }
            break;
        default:
            printf("Invalid input. Please try again.\n");
    }

    printf("Updated stock price: $%d\n", stock_price);
    time_t t = time(NULL);
    printf("Last updated at: %s\n", ctime(&t));

    return 0;
}