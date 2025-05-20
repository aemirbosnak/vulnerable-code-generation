//FormAI DATASET v1.0 Category: Stock market tracker ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int stock_price[10] = {0}; //initialize array for 10 random stock prices
    srand(time(0)); //seed for generating random numbers
    printf("Welcome to the C Stock Market Tracker\n\n");
    printf("Current prices for today:\n");

    //generate 10 random stock prices between 50 and 150
    for(int i=0; i<10; i++) {
        stock_price[i] = rand() % (150 - 50 + 1) + 50;
        printf("Stock %d: $%d\n", i+1, stock_price[i]);
    }
    printf("\n");

    //option to buy or sell a stock
    printf("Would you like to buy or sell a stock? (B/s): ");
    char choice;
    scanf("%c", &choice);

    //if user chooses to buy
    if(choice == 'B' || choice == 'b') {
        printf("Choose a stock to buy (1-10): ");
        int buy_choice;
        scanf("%d", &buy_choice);
        printf("You have bought 1 share of Stock %d for $%d\n\n", buy_choice, stock_price[buy_choice-1]);
    }
    //if user chooses to sell
    else if(choice == 'S' || choice == 's') {
        printf("Choose a stock to sell (1-10): ");
        int sell_choice;
        scanf("%d", &sell_choice);
        printf("You have sold 1 share of Stock %d for $%d\n\n", sell_choice, stock_price[sell_choice-1]);
    }
    //if input is invalid
    else {
        printf("Invalid choice!");
    }

    //display new prices after transaction
    printf("New prices for today:\n");
    for(int i=0; i<10; i++) {
        //randomly increase or decrease stock price by 1-10%
        int rand_percent = rand() % 10 + 1;
        int diff = stock_price[i] * rand_percent/100;
        if(rand()%2 == 0) {
            stock_price[i] += diff;
        }
        else {
            stock_price[i] -= diff;
        }
        printf("Stock %d: $%d\n", i+1, stock_price[i]);
    }
    return 0;
}