//FormAI DATASET v1.0 Category: Stock market tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display a welcome message
void displayWelcome() {
    printf("Hey there! Welcome to the stock market tracker program. Let's get started!\n\n");
}

// Function to get the user's favorite stock
void getFavoriteStock(char *favoriteStock) {
    printf("What is your favorite stock? ");
    scanf("%s", favoriteStock);
    printf("Great choice! Your favorite stock is %s.\n\n", favoriteStock);
}

// Function to get the user's starting capital
float getStartingCapital() {
    float startingCapital;
    printf("How much starting capital do you have? ");
    scanf("%f", &startingCapital);
    printf("Awesome! Your starting capital is $%.2f.\n\n", startingCapital);
    return startingCapital;
}

// Function to get the stock's current price
float getCurrentPrice(char *stockSymbol) {
    float currentPrice;
    printf("What is the current price of %s? $", stockSymbol);
    scanf("%f", &currentPrice);
    printf("%s is currently priced at $%.2f per share.\n\n", stockSymbol, currentPrice);
    return currentPrice;
}

// Function to calculate the user's profit/loss
float calculateProfit(float startingCapital, float currentPrice) {
    float profit;
    profit = (currentPrice - startingCapital) / startingCapital * 100;
    return profit;
}

int main() {
    char favoriteStock[10];
    float startingCapital, currentPrice, profit;
    int marketOpen = 1;

    // Display welcome message
    displayWelcome();

    // Get the user's favorite stock
    getFavoriteStock(favoriteStock);

    // Get the user's starting capital
    startingCapital = getStartingCapital();

    while (marketOpen == 1) {
        // Get the current price of the user's favorite stock
        currentPrice = getCurrentPrice(favoriteStock);

        // Calculate the user's profit/loss
        profit = calculateProfit(startingCapital, currentPrice);

        printf("You have made %.2f%% profit/loss since you started tracking %s.\n\n", profit, favoriteStock);
        printf("Would you like to keep track of %s? Type '1' for YES or '0' for NO: ", favoriteStock);

        scanf("%d", &marketOpen);
    }

    printf("\nThank you for using the stock market tracker program. Goodbye!\n");

    return 0;
}