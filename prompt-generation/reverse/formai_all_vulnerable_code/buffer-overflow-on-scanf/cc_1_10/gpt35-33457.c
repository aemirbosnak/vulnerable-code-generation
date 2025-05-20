//FormAI DATASET v1.0 Category: Stock market tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int stock_price = 100;  //initialize stock price to 100
    int user_input = 0;     //initialize user input to 0

    srand(time(NULL));     //seed for random number generator

    printf("Welcome to the Stock Market Puzzle!\n\n");

    while(1) //infinite loop
    {
        printf("The current stock price is: %d\n", stock_price);

        if(stock_price <= 50) //if stock price drops below 50
        {
            printf("Uh oh! The stock price has dropped below 50! Game over.\n");
            break; //exit loop
        }

        printf("Enter 1 to buy stock, 2 to sell stock, or 3 to skip: ");
        scanf("%d", &user_input);

        if(user_input == 1) //if user chooses to buy stock
        {
            int random_num = rand() % 11 - 5; //generate a random number between -5 and 5

            if(stock_price + random_num <= 0) //if stock price drops to 0 or below
            {
                printf("Oh no! You bought stock at %d, but the stock price dropped to %d. You lose!\n", stock_price, stock_price+random_num);
                break; //exit loop
            }

            stock_price += random_num; //update stock price
            printf("You bought stock at %d. The stock price is now %d.\n", stock_price-random_num, stock_price);
        }

        else if(user_input == 2) //if user chooses to sell stock
        {
            int random_num = rand() % 11 - 5; //generate a random number between -5 and 5

            if(stock_price - random_num <= 0) //if user sells stock and stock price drops to 0 or below
            {
                printf("Oh no! You sold stock at %d, but the stock price dropped to %d. You lose!\n", stock_price, stock_price-random_num);
                break; //exit loop
            }

            stock_price -= random_num; //update stock price
            printf("You sold stock at %d. The stock price is now %d.\n", stock_price+random_num, stock_price);
        }

        else if(user_input == 3) //if user chooses to skip a turn
        {
            printf("You skipped a turn. The stock price is still %d.\n", stock_price);
        }

        else //if user inputs an invalid number
        {
            printf("Invalid input. Please enter 1, 2, or 3.\n");
        }

        printf("\n"); //add spacing between rounds
    }

    printf("Thank you for playing the Stock Market Puzzle!\n");

    return 0;
}