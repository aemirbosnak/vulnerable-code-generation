//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 6

// Function to find the minimum number of coins required to
// make a given amount of money
int min_coins(int amount, int coins[], int n) {
    int i, min_coins = MAX_COINS;

    // Initialize the minimum number of coins required to
    // make the given amount of money
    for (i = 0; i < n; i++) {
        if (coins[i] <= amount) {
            min_coins = coins[i];
            break;
        }
    }

    // Use a greedy algorithm to find the minimum number of
    // coins required to make the given amount of money
    while (amount > 0) {
        for (i = 0; i < n; i++) {
            if (coins[i] <= amount) {
                amount -= coins[i];
                min_coins++;
                break;
            }
        }
    }

    return min_coins;
}

int main() {
    int coins[] = {1, 2, 5, 10, 20, 50};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount;

    // Prompt the user to enter the amount of money
    printf("Enter the amount of money: ");
    scanf("%d", &amount);

    // Find the minimum number of coins required to make the
    // given amount of money
    int min_coins_required = min_coins(amount, coins, n);

    // Print the result
    printf("The minimum number of coins required to make %d is %d\n", amount, min_coins_required);

    return 0;
}