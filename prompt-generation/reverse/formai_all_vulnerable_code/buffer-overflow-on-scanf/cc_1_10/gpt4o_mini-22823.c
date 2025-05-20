//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>

struct Coin {
    int denomination;
    int quantity;
};

// Function to compare two coins based on their denominations for qsort
int compare(const void *a, const void *b) {
    return ((struct Coin*)b)->denomination - ((struct Coin*)a)->denomination; // Sort in descending order
}

// Function to find the minimum number of coins needed to make a given amount
void findMinCoins(int amount, struct Coin coins[], int numCoins) {
    int totalCoins = 0;

    printf("Hello! Let's make change for %d using the following coins:\n", amount);
    for (int i = 0; i < numCoins; i++) {
        printf("Coin of %d with a quantity of %d\n", coins[i].denomination, coins[i].quantity);
    }
    printf("\n");

    // Begin greedy algorithm
    for (int i = 0; i < numCoins; i++) {
        while (amount >= coins[i].denomination && coins[i].quantity > 0) {
            amount -= coins[i].denomination;
            coins[i].quantity--;
            totalCoins++;
            printf("Used one coin of %d! Remaining amount: %d\n", coins[i].denomination, amount);
        }
        if (amount == 0) break; // If we've made the amount, we can break early
    }

    // If amount is still greater than 0, we can't make change
    if (amount > 0) {
        printf("Oops! We could not make the exact change. Remaining amount: %d\n", amount);
    } else {
        printf("Yay! Successfully made change using %d coins!\n", totalCoins);
    }
}

int main() {
    // Define available coins and their quantities
    struct Coin coins[] = {
        {100, 5},  // 5 coins of 100
        {50, 10},  // 10 coins of 50
        {25, 20},  // 20 coins of 25
        {10, 15},  // 15 coins of 10
        {5, 10},   // 10 coins of 5
        {1, 50}    // 50 coins of 1
    };
    
    int numCoins = sizeof(coins) / sizeof(coins[0]);

    // Sort coins in descending order based on denomination
    qsort(coins, numCoins, sizeof(struct Coin), compare);

    // Prompt user for amount
    int amount;
    printf("Welcome to the Happy Coin Change Program! 🎉\n");
    printf("Please enter the amount you want to change: ");
    scanf("%d", &amount);

    // Call function to find minimum coins
    findMinCoins(amount, coins, numCoins);

    printf("Thank you for using the Happy Coin Change Program! Have a wonderful day! 🌞\n");

    return 0;
}