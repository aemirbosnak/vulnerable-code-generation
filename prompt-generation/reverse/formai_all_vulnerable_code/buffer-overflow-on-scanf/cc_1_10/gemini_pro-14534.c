//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the minimum number of coins required to make change for a given amount
int minCoins(int amount) {
    // Initialize the number of coins to 0
    int coins = 0;

    // While the amount is greater than 0
    while (amount > 0) {
        // If the amount is greater than or equal to 50
        if (amount >= 50) {
            // Add a 50-cent coin to the number of coins
            coins++;
            // Subtract 50 from the amount
            amount -= 50;
        }
        // Else if the amount is greater than or equal to 25
        else if (amount >= 25) {
            // Add a 25-cent coin to the number of coins
            coins++;
            // Subtract 25 from the amount
            amount -= 25;
        }
        // Else if the amount is greater than or equal to 10
        else if (amount >= 10) {
            // Add a 10-cent coin to the number of coins
            coins++;
            // Subtract 10 from the amount
            amount -= 10;
        }
        // Else if the amount is greater than or equal to 5
        else if (amount >= 5) {
            // Add a 5-cent coin to the number of coins
            coins++;
            // Subtract 5 from the amount
            amount -= 5;
        }
        // Else, the amount must be less than 5, so add a 1-cent coin to the number of coins
        else {
            coins++;
            amount -= 1;
        }
    }

    // Return the number of coins
    return coins;
}

// Main function
int main() {
    // Get the amount from the user
    int amount;
    printf("Enter the amount: ");
    scanf("%d", &amount);

    // Calculate the minimum number of coins required to make change for the amount
    int coins = minCoins(amount);

    // Print the minimum number of coins
    printf("The minimum number of coins required to make change for %d is %d\n", amount, coins);

    return 0;
}