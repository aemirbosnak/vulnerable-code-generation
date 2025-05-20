//FormAI DATASET v1.0 Category: Stock market tracker ; Style: light-weight
#include<stdio.h>
#define NUM_STOCKS 5 //number of stocks to track
#define MAX_LEN 20 //maximum length of stock name

//function to get the index of a stock in the array based on its symbol
int getStockIndex(char symbol[], char stocks[][MAX_LEN], int numStocks){
    int i;
    for(i=0; i<numStocks; i++){
        if(strcmp(symbol, stocks[i])==0){
            return i;
        }
    }
    return -1; //if the stock is not found
}

int main(){
    char stocks[NUM_STOCKS][MAX_LEN] = {"AAPL", "GOOG", "NFLX", "MSFT", "AMZN"}; //array of stocks to track
    float prices[NUM_STOCKS] = {148.48, 796.10, 411.81, 266.73, 3057.16}; //array of prices for each stock
    char input[MAX_LEN];
    int index;
    float newPrice;

    //print initial prices
    printf("Initial prices:\n");
    for(int i=0; i<NUM_STOCKS; i++){
        printf("%s: $%.2f\n", stocks[i], prices[i]);
    }
    printf("\n");

    //ask user for stock symbol and new price until user enters "done"
    while(1){
        printf("Enter stock symbol (or 'done' to exit): ");
        scanf("%s", input);
        if(strcmp(input, "done")==0){
            break;
        }
        index = getStockIndex(input, stocks, NUM_STOCKS);
        if(index==-1){
            printf("Invalid stock symbol\n\n");
            continue;
        }
        printf("Enter new price: ");
        scanf("%f", &newPrice);
        printf("\n");
        prices[index] = newPrice;
    }

    //print final prices
    printf("Final prices:\n");
    for(int i=0; i<NUM_STOCKS; i++){
        printf("%s: $%.2f\n", stocks[i], prices[i]);
    }

    return 0;
}