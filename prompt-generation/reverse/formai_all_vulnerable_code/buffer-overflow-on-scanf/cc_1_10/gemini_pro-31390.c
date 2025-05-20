//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: retro
// Welcome to the Coin Collector's Adventure!

#include <stdio.h>
#include <stdlib.h>

// Constants for the game
#define MAX_COINS 100
#define MAX_COINS_TO_COLLECT 50
#define COIN_VALUE 1

// Function prototypes
int get_coins(int coins[], int max_coins);
void sort_coins(int coins[], int num_coins);
int get_best_combination(int coins[], int num_coins, int max_coins_to_collect);

// Main function
int main() {
    // Get the coins from the user
    int coins[MAX_COINS];
    int num_coins = get_coins(coins, MAX_COINS);

    // Sort the coins in ascending order
    sort_coins(coins, num_coins);

    // Get the best combination of coins to collect
    int best_combination = get_best_combination(coins, num_coins, MAX_COINS_TO_COLLECT);

    // Print the best combination of coins
    printf("The best combination of coins to collect is: %d\n", best_combination);

    return 0;
}

// Get the coins from the user
int get_coins(int coins[], int max_coins) {
    // Get the number of coins from the user
    int num_coins;
    printf("How many coins do you have? ");
    scanf("%d", &num_coins);

    // Get the value of each coin from the user
    for (int i = 0; i < num_coins; i++) {
        printf("What is the value of coin %d? ", i + 1);
        scanf("%d", &coins[i]);
    }

    return num_coins;
}

// Sort the coins in ascending order
void sort_coins(int coins[], int num_coins) {
    // For each coin
    for (int i = 0; i < num_coins; i++) {
        // Find the smallest coin
        int smallest_coin = i;
        for (int j = i + 1; j < num_coins; j++) {
            if (coins[j] < coins[smallest_coin]) {
                smallest_coin = j;
            }
        }

        // Swap the smallest coin with the current coin
        int temp = coins[i];
        coins[i] = coins[smallest_coin];
        coins[smallest_coin] = temp;
    }
}

// Get the best combination of coins to collect
int get_best_combination(int coins[], int num_coins, int max_coins_to_collect) {
    // Initialize the best combination to 0
    int best_combination = 0;

    // For each coin
    for (int i = 0; i < num_coins; i++) {
        // If the coin is less than or equal to the maximum number of coins to collect
        if (coins[i] <= max_coins_to_collect) {
            // Add the coin to the best combination
            best_combination += coins[i] * COIN_VALUE;

            // Recursively get the best combination of the remaining coins
            int remaining_coins = max_coins_to_collect - coins[i];
            int remaining_combination = get_best_combination(coins + i + 1, num_coins - i - 1, remaining_coins);

            // If the remaining combination is greater than the best combination
            if (remaining_combination > best_combination) {
                // Set the best combination to the remaining combination
                best_combination = remaining_combination;
            }
        }
    }

    return best_combination;
}