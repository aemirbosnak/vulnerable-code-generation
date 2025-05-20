//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: relaxed
#include <stdio.h>

// Function to calculate minimum coins needed for the given amount
int minCoins(int coins[], int numCoins, int amount) {
    // Let's remind ourselves that using a greedy approach means
    // we'll go with the largest coin first, as long as we can.
    int count = 0;
    
    // We're starting with the largest denomination, let's say we are greedy like a raccoon with a cookie jar!
    for (int i = 0; i < numCoins; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
            printf("Taking one coin of %d. Remaining amount: %d.\n", coins[i], amount);
        }
    }
    
    // If there's still some amount left, that means we need more coins.
    if (amount > 0) {
        printf("Oh no! Unable to make the exact amount. Leftover amount: %d.\n", amount);
        return -1; // Indicating failure to make change
    }
    
    return count;
}

int main() {
    // Let's define our coin denominations.
    int coins[] = {25, 10, 5, 1}; // We have quarters, dimes, nickels, and pennies
    int numCoins = sizeof(coins) / sizeof(coins[0]);
    
    // Time for the user to enter the amount they wish to change (cash out).
    printf("Welcome to the Greedy Cash Machine!\n");
    int amount;
    
    printf("Please enter the amount of money you want to change (in cents): ");
    scanf("%d", &amount);
    
    if (amount < 0) {
        printf("Really? Negative money? Let's stick with positive vibes! Please enter a valid amount.\n");
        return 1; // Exit with error code
    }
    
    // Get the minimum number of coins
    int result = minCoins(coins, numCoins, amount);
    
    if (result != -1) {
        printf("Success! Total coins used: %d\n", result);
    }
    
    printf("Thank you for using the Greedy Cash Machine! Have a coin-tastic day!\n");
    return 0;
}