//FormAI DATASET v1.0 Category: Stock market tracker ; Style: intelligent
#include <stdio.h>

int main() {
    float stock_price = 1000.00; // starting stock price
    float fluctuation_rate = 0.05; // rate of fluctuation
    float max_price = 0, min_price = 0; // variables to track max and min prices
    int days = 1; // number of days
    char option; // variable to get user input
    
    printf("Welcome to the Stock Market Tracker!\n");
    
    while(1) { // continue until user exits
        
        printf("======== Day %d ========\n", days);
        printf("Current stock price: $%.2f\n", stock_price);
        
        // Update stock price based on fluctuation rate
        if(stock_price < 1) { // If stock price is negative, game over!
            printf("Game over!\n");
            break;
        }
        else {
            int rand_num = rand() % 100; // generate random number between 0 and 99
            if(rand_num < 50) {
                stock_price -= stock_price * fluctuation_rate;
                printf("Stock price decreased by %.2f%%\n", fluctuation_rate * 100);
            }
            else {
                stock_price += stock_price * fluctuation_rate;
                printf("Stock price increased by %.2f%%\n", fluctuation_rate * 100);
            }
        }
        
        // Check if current price is max or min
        if(stock_price > max_price) {
            max_price = stock_price;
            printf("New maximum price achieved!\n");
        }
        else if(stock_price < min_price || min_price == 0) {
            min_price = stock_price;
            printf("New minimum price achieved!\n");
        }
        
         // Get user input to continue or exit
        printf("Press 'Q' to exit or any other key to continue: ");
        scanf(" %c", &option);
        
        if(option == 'Q' || option == 'q') {
            break;
        }
        
        days++;
    }
    
    printf("Thank you for using the Stock Market Tracker!\n");
    printf("Maximum stock price achieved: $%.2f\n", max_price);
    printf("Minimum stock price achieved: $%.2f\n", min_price);
    
    return 0;
}