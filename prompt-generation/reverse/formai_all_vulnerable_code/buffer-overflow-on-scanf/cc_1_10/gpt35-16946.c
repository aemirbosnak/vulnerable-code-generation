//FormAI DATASET v1.0 Category: Stock market tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    int numStocks;
    bool marketOpen = true;
    
    printf("Welcome to the C Stock Market Tracker!\n\n");
    
    printf("Enter the number of stocks you want to track: ");
    scanf("%d", &numStocks);
    
    float currentPrices[numStocks];
    char stockNames[numStocks][50];
    
    // Get stock names and prices from user
    printf("\nEnter stock names and current prices:\n");
    
    for(int i=0; i<numStocks; i++){
        printf("\nStock %d name: ", i+1);
        scanf("%s", stockNames[i]);
        printf("Stock %s current price: ", stockNames[i]);
        scanf("%f", &currentPrices[i]);
    }
    
    // Display initial stock prices
    printf("\nInitial Stock Prices:\n\n");
    for(int i=0; i<numStocks; i++){
        printf("%s: %.2f\n", stockNames[i], currentPrices[i]);
    }
    
    while(marketOpen){
        srand(time(NULL));
        
        // Simulate change in stock prices
        for(int i=0; i<numStocks; i++){
            float change = ((float)rand()/(float)(RAND_MAX)) * 10.0 - 5.0;
            currentPrices[i] += change;
        }
        
        // Display updated stock prices
        printf("\nUpdated Stock Prices:\n\n");
        for(int i=0; i<numStocks; i++){
            printf("%s: %.2f\n", stockNames[i], currentPrices[i]);
        }
        
        // Prompt user to continue or quit
        char choice;
        printf("\nEnter 'q' to quit or any other key to continue: ");
        scanf(" %c", &choice);
        
        if(choice == 'q'){
            marketOpen = false;
        }
    }
    
    printf("\nThank you for using the C Stock Market Tracker!\n");
    
    return 0;
}