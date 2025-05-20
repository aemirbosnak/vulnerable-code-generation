//FormAI DATASET v1.0 Category: Stock market tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10000 //Maximum number of stock prices that can be stored

int main()
{
    float stock_prices[SIZE]; //Array to store stock prices
    int index = 0; //Number of stock prices currently stored
    char input[100]; //String to capture user's input
    float sum = 0; //Sum of all stock prices
    float average = 0; //Average of all stock prices

    printf("Welcome to the Stock Market Tracker. Enter 'q' at any time to quit.\n");

    while(1) //Infinite loop until user enters 'q'
    {
        printf("Enter the stock price: ");
        fgets(input, sizeof(input), stdin);

        if(input[0] == 'q') //If user enters 'q', break out of the loop
        {
            break;
        }

        float price = atof(input); //Convert user's input to float

        if(price <= 0) //If price is negative or zero, ignore it and continue loop
        {
            printf("Invalid price. Please enter a positive number.\n");
            continue;
        }

        if(index >= SIZE) //If maximum number of prices has been reached, break out of loop
        {
            printf("Maximum number of stock prices reached.\n");
            break;
        }

        stock_prices[index] = price; //Add price to array
        index++; //Increment the number of prices

        sum += price; //Add price to sum
        average = sum/index; //Recalculate the average after each price is added

        printf("Average stock price so far: $%.2f\n", average);
    }

    printf("Thank you for using the Stock Market Tracker.\n");

    return 0;
}