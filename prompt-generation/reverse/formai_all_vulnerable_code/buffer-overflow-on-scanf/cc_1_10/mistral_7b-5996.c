//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_AMOUNT 10000 // Maximum amount to make change for

// Function to find the minimum number of coins to make change for a given amount
int minCoins(int amount) {
    int coins[5] = {1, 5, 10, 25, 50}; // Coins supported
    int count[MAX_AMOUNT + 1]; // Array to store the minimum number of coins required to make change for each amount

    // Initialize all elements of count array as infinite
    for (int i = 0; i <= MAX_AMOUNT; i++) {
        count[i] = i + 1;
    }

    // Initialize the first element of count array as 0 (as no coin is required to make change for 0 amount)
    count[0] = 0;

    // Use Greedy approach to fill the count array
    for (int i = 0; i < 5; i++) {
        for (int j = coins[i]; j <= MAX_AMOUNT; j++) {
            if (count[j] > count[j - coins[i]] + 1) {
                count[j] = count[j - coins[i]] + 1;
            }
        }
    }

    return count[amount];
}

int main() {
    int amount;

    printf("Enter the amount: ");
    scanf("%d", &amount);

    // Check if the amount is valid
    if (amount < 0 || amount > MAX_AMOUNT) {
        printf("Invalid amount!\n");
        return 1;
    }

    // Find the minimum number of coins required to make change for the given amount
    int coinsRequired = minCoins(amount);

    // Print the result
    printf("Minimum number of coins required to make change for %d cents: %d\n", amount, coinsRequired);

    return 0;
}