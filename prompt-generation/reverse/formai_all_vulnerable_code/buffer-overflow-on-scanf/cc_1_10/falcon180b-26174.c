//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 6
#define MAX_AMOUNT 1000

// Function to find minimum number of coins required to make a given amount
int min_coins(int amount, int coins[], int n) {
    int i, j, min_coins = MAX_COINS;

    // Initialize the minimum coins required to make the given amount
    for (i = 0; i <= amount; i++) {
        min_coins = i < min_coins? i : min_coins;
    }

    // Initialize the starting index of the coins array
    int start_index = 0;

    // Initialize the ending index of the coins array
    int end_index = n - 1;

    // Initialize the index of the coins array to start with
    int index = start_index;

    // Initialize the amount left to make
    int amount_left = amount;

    // Initialize the number of coins used to make the given amount
    int coins_used = 0;

    // Initialize the first coin to use
    int coin = coins[start_index];

    // Loop until the given amount is made or the last coin is reached
    while (amount_left > 0 && index <= end_index) {
        // Subtract the value of the current coin from the amount left
        amount_left -= coin;

        // Increment the number of coins used
        coins_used++;

        // Check if the amount left becomes negative
        if (amount_left < 0) {
            // Backtrack and try the next coin
            index--;
            amount_left += coin;
            coins_used--;
        }
        // Move to the next coin
        else {
            // Check if a smaller coin can be used
            for (j = index + 1; j <= end_index; j++) {
                if (coins[j] < coins[index]) {
                    index = j;
                    break;
                }
            }
            // Use the current coin if no smaller coin is found
            if (j == end_index + 1) {
                coin = coins[index];
            }
        }
    }

    // Return the minimum number of coins required to make the given amount
    return coins_used;
}

int main() {
    // Initialize the coins array
    int coins[] = { 1, 5, 10, 25, 50, 100 };

    // Initialize the number of coins in the coins array
    int n = sizeof(coins) / sizeof(coins[0]);

    // Initialize the amount to make
    int amount;

    // Loop until the user enters a valid amount
    do {
        // Prompt the user to enter the amount to make
        printf("Enter the amount to make (1 to %d): ", MAX_AMOUNT);

        // Read the amount from the user
        scanf("%d", &amount);

        // Check if the amount is valid
        if (amount < 1 || amount > MAX_AMOUNT) {
            printf("Invalid amount. Please enter a number between 1 and %d.\n", MAX_AMOUNT);
        }
    } while (amount < 1 || amount > MAX_AMOUNT);

    // Find the minimum number of coins required to make the given amount
    int min_coins_required = min_coins(amount, coins, n);

    // Print the minimum number of coins required to make the given amount
    printf("Minimum number of coins required to make %d: %d\n", amount, min_coins_required);

    return 0;
}