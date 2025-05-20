//FormAI DATASET v1.0 Category: Stock market tracker ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// struct to hold stock information
struct stock{
    char symbol[10];
    float price;
    float change;
};

void printStock(struct stock s){
    printf("%s\t%.2f\t%.2f%%\n", s.symbol, s.price, s.change);
}

int main()
{
    printf("Welcome to the C Stock Market Tracker!\n\n");

    // create an array of stock structs with three hardcoded examples
    struct stock stocks[3] = {
        {"AAPL", 152.51, -0.35},
        {"GOOG", 832.15, 0.01},
        {"TSLA", 357.90, 0.75}
    };

    // print the initial stock information
    printf("Symbol\tPrice\tChange\n");
    for(int i=0; i<3; i++){
        printStock(stocks[i]);
    }

    // prompt the user for a stock symbol to track
    char trackSymbol[10];
    printf("\nEnter a stock symbol to track: ");
    scanf("%s", trackSymbol);

    // track the stock symbol
    struct stock trackedStock;
    for(int i=0; i<3; i++){
        if(strcmp(stocks[i].symbol, trackSymbol)==0){
            trackedStock = stocks[i];
            break;
        }
    }

    // keep updating the tracked stock's price and change until the user quits
    char quit = 'n';
    while(quit != 'y'){
        printf("\n%s's current price is %.2f.\n", trackedStock.symbol, trackedStock.price);
        printf("Enter the new price: ");
        scanf("%f", &trackedStock.price);
        trackedStock.change = ((trackedStock.price - stocks[0].price) / stocks[0].price) * 100;
        printf("The percentage change for %s is %.2f%%.\n", trackedStock.symbol, trackedStock.change);
        printf("Do you want to quit? (y/n): ");
        scanf(" %c", &quit);
    }

    printf("\nGoodbye!\n");

    return 0;
}