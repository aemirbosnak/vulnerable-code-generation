//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_NUMBERS 100
#define MAX_VALUE 1000

// Function to find the minimum number of coins required for a given value
int minCoins(int value, int coins[], int n) {
    int min_coins = INT_MAX;

    // Iterate through all the coins and find the minimum number of coins required
    for(int i=0; i<n; i++) {
        if(value >= coins[i]) {
            int subResult = minCoins(value-coins[i], coins, n);

            if(subResult!= -1) {
                if(subResult + 1 < min_coins) {
                    min_coins = subResult + 1;
                }
            }
        }
    }

    if(min_coins == INT_MAX) {
        return -1;
    } else {
        return min_coins;
    }
}

int main() {
    int coins[] = {1, 5, 10, 25};
    int n = sizeof(coins)/sizeof(coins[0]);
    int value = 63;

    // Get user input for the value
    printf("Enter the value: ");
    scanf("%d", &value);

    // Find the minimum number of coins required
    int min_coins = minCoins(value, coins, n);

    if(min_coins == -1) {
        printf("Cannot find the minimum number of coins required.\n");
    } else {
        printf("Minimum number of coins required: %d\n", min_coins);
    }

    return 0;
}