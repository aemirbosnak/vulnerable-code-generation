//FormAI DATASET v1.0 Category: Stock market tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000

struct Stocks {
    char name[30];
    int price;
};

int main() {
    int i, j, k;
    int numOfStocks;
    printf("Enter the number of stocks to track: ");
    scanf("%d", &numOfStocks);
    struct Stocks stock[numOfStocks];

    //Get the names and prices for each stock
    for (i = 0; i < numOfStocks; i++) {
        printf("\nEnter the name of stock %d: ", i + 1);
        scanf("%s", stock[i].name);
        printf("\nEnter the price of stock %d: ", i + 1);
        scanf("%d", &stock[i].price);
    }

    //Print out the stocks entered
    printf("The list of stocks entered include:\n");
    for (i = 0; i < numOfStocks; i++) {
        printf("%d. %s - $%d\n", i + 1, stock[i].name, stock[i].price);
    }

    //Keep track of the highest and lowest stock prices
    int highestPrice = stock[0].price;
    int lowestPrice = stock[0].price;
    int highestIndex = 0;
    int lowestIndex = 0;
    for (j = 1; j < numOfStocks; j++) {
        if (highestPrice < stock[j].price) {
            highestPrice = stock[j].price;
            highestIndex = j;
        }
        if (lowestPrice > stock[j].price) {
            lowestPrice = stock[j].price;
            lowestIndex = j;
        }
    }

    //Print out the highest and lowest stocks
    printf("\nThe stock with the highest price is: %s - $%d\n", stock[highestIndex].name, stock[highestIndex].price);
    printf("The stock with the lowest price is: %s - $%d\n", stock[lowestIndex].name, stock[lowestIndex].price);

    //Calculate the average stock price
    float sum = 0;
    for (k = 0; k < numOfStocks; k++) {
        sum += stock[k].price;
    }
    float averagePrice = sum / numOfStocks;

    //Print out the average stock price
    printf("\nThe average stock price is: $%.2f\n", averagePrice);

    return 0;
}