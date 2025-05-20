//FormAI DATASET v1.0 Category: Stock market tracker ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stock{
    char ticker[10];
    float price;
    float change;
};

void introduce(){
    printf("\n\nWelcome to the C Stock Market Tracker!\n\n");
    printf("You can track the latest prices and changes of your favorite stocks.\n");
    printf("Enter the ticker symbol of the stock you want to track.\n");
    printf("Enter 'done' when finished.\n\n");
}

void printStock(struct stock stk){
    printf("\nTicker: %s\n", stk.ticker);
    printf("Price: $%.2f\n", stk.price);
    printf("Change: %.2f%%\n", stk.change);
}

int main(){
    struct stock s[100];
    char input[10];
    int i = 0, j;

    introduce();

    while(strcmp(input, "done") != 0){
        printf("Enter stock ticker (e.g. AAPL): ");
        scanf("%s", input);

        if(strcmp(input, "done") == 0){
            break;
        }

        //check if stock already exists
        for(j = 0; j < i; j++){
            if(strcmp(s[j].ticker, input) == 0){
                printf("Stock already added. Enter a different ticker symbol.\n\n");
                goto endloop;
            }
        }

        //add new stock
        strcpy(s[i].ticker, input);

        printf("Enter stock price: $");
        scanf("%f", &s[i].price);

        printf("Enter percent change: ");
        scanf("%f", &s[i].change);

        i++;
        printf("\n");

        endloop: continue;
    }

    //print all stocks
    printf("\n\n*** Your Tracked Stocks ***\n\n");
    for(j = 0; j < i; j++){
        printStock(s[j]);
    }

    return 0;
}