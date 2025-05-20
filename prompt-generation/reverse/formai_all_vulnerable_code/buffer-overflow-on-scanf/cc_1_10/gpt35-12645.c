//FormAI DATASET v1.0 Category: Stock market tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declarations
void initializePrices(double prices[], int num_stock);
void printPrices(double prices[], int num_stock);
int getRandInt(int min, int max);
void updatePrices(double prices[], int num_stock);
void buyShares(double balance, double prices[], int num_stock);
void sellShares(double balance, double prices[], int num_stock);

int main() {
    int num_stock = 5;
    double prices[num_stock];
    double balance = 10000.00;
    int choice, loop_counter = 0;

    // initialize random number generator
    srand((unsigned int)time(NULL));
    
    // initialize prices array
    initializePrices(prices, num_stock);

    // menu loop
    while(1) {
        printf("\n\n");
        printf("*************************************************\n");
        printf("********** Welcome to the Stock Tracker! *********\n");
        printf("*************************************************\n\n");
        printf("Current Balance: $%.2f\n", balance);
        printf("1. View current stock prices\n");
        printf("2. Buy shares\n");
        printf("3. Sell shares\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printPrices(prices, num_stock);
                break;
            case 2:
                buyShares(balance, prices, num_stock);
                break;
            case 3:
                sellShares(balance, prices, num_stock);
                break;
            case 4:
                printf("Exiting program...");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }

        // update stock prices every 5 loops
        if(++loop_counter == 5) {
            updatePrices(prices, num_stock);
            loop_counter = 0;
        }
    }

    return 0;
}

// function definitions

// initializes the prices array with random starting values
void initializePrices(double prices[], int num_stock) {
    for(int i = 0; i < num_stock; i++) {
        prices[i] = (double)getRandInt(50, 150);
    }
}

// prints the current stock prices
void printPrices(double prices[], int num_stock) {
    printf("Current Stock Prices:\n");
    printf("------------------------------\n");
    for(int i = 0; i < num_stock; i++) {
        printf("Stock %d: $%.2f\n", i + 1, prices[i]);
    }
}

// generates a random integer between min and max (inclusive)
int getRandInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// updates the prices array with new values
void updatePrices(double prices[], int num_stock) {
    for(int i = 0; i < num_stock; i++) {
        prices[i] += (double)getRandInt(-10, 10) / 100.0 * prices[i];
    }
}

// buys shares of stock based on user input
void buyShares(double balance, double prices[], int num_stock) {
    printf("Which stock would you like to buy shares of? (1-%d): ", num_stock);
    int stock_choice;
    scanf("%d", &stock_choice);
    if(stock_choice < 1 || stock_choice > num_stock) {
        printf("Invalid stock choice.\n");
        return;
    }

    double stock_price = prices[stock_choice - 1];

    printf("Current %d price: $%.2f\n", stock_choice, stock_price);
    printf("Enter the number of shares you would like to buy: ");
    int num_shares;
    scanf("%d", &num_shares);

    double total_cost = num_shares * stock_price;
    if(total_cost > balance) {
        printf("Insufficient funds.\n");
        return;
    }

    printf("Buying %d shares of Stock %d for $%.2f.\n", num_shares, stock_choice, total_cost);

    balance -= total_cost;
}

// sells shares of stock based on user input
void sellShares(double balance, double prices[], int num_stock) {
    printf("Which stock would you like to sell shares of? (1-%d): ", num_stock);
    int stock_choice;
    scanf("%d", &stock_choice);
    if(stock_choice < 1 || stock_choice > num_stock) {
        printf("Invalid stock choice.\n");
        return;
    }

    double stock_price = prices[stock_choice - 1];

    printf("Current %d price: $%.2f\n", stock_choice, stock_price);
    printf("Enter the number of shares you would like to sell: ");
    int num_shares;
    scanf("%d", &num_shares);

    double total_cost = num_shares * stock_price;
    balance += total_cost;

    printf("Selling %d shares of Stock %d for $%.2f.\n", num_shares, stock_choice, total_cost);
}