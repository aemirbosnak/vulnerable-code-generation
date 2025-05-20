//FormAI DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int stockPrices[5] = {10, 20, 30, 40, 50};
    int totalStocks = 5;
    int currentStockPrice;
    int highestStockPrice = stockPrices[0];
    int lowestStockPrice = stockPrices[0];
    int totalStockValue = 0;
    float averageStockPrice;
    
    printf("**STOCK MARKET TRACKER**\n\n");
    
    //calculate the highest and lowest stock prices
    for (int i = 1; i < totalStocks; i++) {
        if (stockPrices[i] > highestStockPrice) {
            highestStockPrice = stockPrices[i];
        }
        if (stockPrices[i] < lowestStockPrice) {
            lowestStockPrice = stockPrices[i];
        }
    }
    
    //calculate the total stock value and average stock price
    for (int i = 0; i < totalStocks; i++) {
        totalStockValue += stockPrices[i];
    }
    averageStockPrice = (float) totalStockValue / totalStocks;
    
    //output results
    printf("Highest stock price: $%d\n", highestStockPrice);
    printf("Lowest stock price: $%d\n", lowestStockPrice);
    printf("Total stock value: $%d\n", totalStockValue);
    printf("Average stock price: $%.2f\n", averageStockPrice);
    
    //check current stock price
    printf("\nEnter the current stock price: ");
    scanf("%d", &currentStockPrice);
    
    //determine if the current stock price is a good buy or not
    if (currentStockPrice > averageStockPrice) {
        printf("The current stock price is higher than the average price.\n");
        printf("This may not be a good time to buy.\n");
    } else if (currentStockPrice < averageStockPrice) {
        printf("The current stock price is lower than the average price.\n");
        printf("This may be a good time to buy.\n");
    } else {
        printf("The current stock price is the same as the average price.\n");
        printf("It's up to you to decide if it's a good time to buy or not.\n");
    }
    
    return 0;
}