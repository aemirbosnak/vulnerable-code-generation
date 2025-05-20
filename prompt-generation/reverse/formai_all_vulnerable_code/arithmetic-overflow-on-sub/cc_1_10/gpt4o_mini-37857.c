//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a coin
typedef struct {
    int value;
    int count;
} Coin;

// Function prototype
void calculate_min_coins(Coin *coins, int num_coins, int amount);

int main() {
    int num_coins, amount, i;

    printf("Enter the number of different coin denominations: ");
    scanf("%d", &num_coins);

    // Dynamically allocate memory for coins
    Coin *coins = malloc(num_coins * sizeof(Coin));
    if (coins == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Input coin denominations
    printf("Enter the coin denominations:\n");
    for (i = 0; i < num_coins; i++) {
        printf("Coin %d: ", i + 1);
        scanf("%d", &coins[i].value);
        coins[i].count = 0; // Initialize the count to zero
    }

    // Input the amount to change
    printf("Enter the amount to change: ");
    scanf("%d", &amount);

    // Calculate minimum coins needed
    calculate_min_coins(coins, num_coins, amount);

    // Free allocated memory
    free(coins);
    
    return 0;
}

// Function to calculate the minimum coins needed for a given amount
void calculate_min_coins(Coin *coins, int num_coins, int amount) {
    // Sort coins in descending order
    for (int i = 0; i < num_coins - 1; i++) {
        for (int j = 0; j < num_coins - i - 1; j++) {
            if (coins[j].value < coins[j + 1].value) {
                Coin temp = coins[j];
                coins[j] = coins[j + 1];
                coins[j + 1] = temp;
            }
        }
    }

    printf("Calculating minimum coins needed for %d:\n", amount);
    for (int i = 0; i < num_coins; i++) {
        if (amount == 0) {
            break; // If no amount left, exit the loop
        }

        if (coins[i].value <= amount) {
            coins[i].count = amount / coins[i].value; // Maximum coins of this denomination
            amount = amount % coins[i].value; // Update remaining amount
        }
    }

    // Print the result
    printf("Minimum coins needed:\n");
    for (int i = 0; i < num_coins; i++) {
        if (coins[i].count > 0) {
            printf("Coin %d : %d\n", coins[i].value, coins[i].count);
        }
    }

    if (amount > 0) {
        printf("The amount cannot be changed with the given denominations\n");
    }
}